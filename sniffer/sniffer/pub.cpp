//#ifdef WIN
//#include <WinSock2.h>
//#else
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <errno.h>
//#include <string.h>
//#define SOCKET int
//#endif

//#include <stdio.h>
#include "pub.h"

#define BUFSIZE 262144  //256k


char *Get_proto_name(unsigned char proto)
{
	switch (proto)
	{
	case IPPROTO_IP:
		return "IP";
	case IPPROTO_ICMP:
		return "ICMP";
	case IPPROTO_IGMP:
		return "IGMP";
	case IPPROTO_GGP:
		return "GGP";
	case IPPROTO_TCP:
		return "TCP";
	case IPPROTO_PUP:
		return "PUP";
	case IPPROTO_UDP:
		return "UDP";
	case IPPROTO_IDP:
		return "IDP";
	case IPPROTO_ND:
		return "ND";
	case IPPROTO_RAW:
		return "RAW";
	case IPPROTO_MAX:
		return "MAX";
	default:
		return "UNKNOW";
	}
}

//void getfilename(const char *filename, char *name)//从完整路径名中解析出文件名称，例如：/home/test/abc.txt,解析完成后为abc.txt
//{
//	int len = strlen(filename);
//	int i;
//	for (i = (len - 1); i >= 0; i--)
//	{
//		if ((filename[i] == '\\') || (filename[i] == '/'))
//		{
//			break;
//		}
//	}
//	strcpy(name, &filename[i + 1]);
//	return;
//}

void PrintByte(const char *Buf, size_t BufSize)
{
	for (size_t i = 0; i < BufSize; i++)
	{
		printf("%.2x", (unsigned char)Buf[i]);
	}
}

SOCKET SocketCreate(SOCKET &sock,const char *IPAddr,unsigned short Port)//初始化socket
{
	//如果是windows，执行如下代码

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return -1;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return -1;
	}
#ifdef WIN
#endif
	//创建原始socket   ipsocket
	sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if (sock == INVALID_SOCKET)
		return WSAGetLastError();

	//设置超时选项
	int iRecTime = 50000;//设置接收超时
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&iRecTime, sizeof(iRecTime)))
		return WSAGetLastError();

	//绑定具体端口和地址
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(Port);//指定port为要连接的端口号
	addr.sin_addr.s_addr = inet_addr(IPAddr);//指定hostname为要连接的IP地址

	if (bind(sock, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		return WSAGetLastError();
	}

	

	//设置socket模式，当调用WSAIoctl函数的时候为了能让socket能接收网络的所有IP包
	//传给WSAIoctl函数的socket句柄必须设置成AF_INET, SOCK_RAW, IPPROTO_IP协议而且这个socket必须显示的bind到本地的一个端口地址
	DWORD dwBufferInLen = 1;
	DWORD dwBufferLen[10];
	DWORD dwBytesReturned = 0;

	//LINUX 应该就叫ioctl  调用WSAIoctl设置socket可以接受所有ip包
	if (WSAIoctl(sock, SIO_RCVALL, &dwBufferInLen, sizeof(dwBufferInLen),
		&dwBufferLen, sizeof(dwBufferLen), &dwBytesReturned, NULL, NULL) == SOCKET_ERROR)
	{
		return WSAGetLastError();
	}

	return 0;
}


int SnifferReceive(SOCKET &sock, bool ShowByte)
{
	IPHEADER *ipHeader = NULL;
	TCPPacketHead *tcpHeader = NULL;
	ICMPPacketHead *icmpHeader = NULL;
	UDPPacketHead *udpHeader = NULL;
	BYTE *pDate = NULL;
	char *pLastBuf = NULL;

	WORD wSrcPort, wDestPort;
	char sSrcIPAddr[32], sDestIPAddr[32], sProtoName[32];
	memset(sSrcIPAddr, 0, sizeof(sSrcIPAddr));
	memset(sDestIPAddr, 0, sizeof(sDestIPAddr));
	memset(sProtoName, 0, sizeof(sProtoName));

	in_addr inaddr;
	char sBuf[8192];//socket默认的buffer为8k
	char *pBuf = sBuf;
	memset(sBuf, 0, sizeof(sBuf));
	int iRes = recv(sock, sBuf, sizeof(sBuf), 0);//从socket接收数据
	if (iRes == SOCKET_ERROR)
		return WSAGetLastError();

	//得到IP包头
	ipHeader = (IPHEADER *)pBuf;
	//得到ip包头总长度
	WORD iLen = ntohs(ipHeader->total_len);

	while (true)
	{
		if (iLen <= iRes)
		{
			//得到IP包源地址
			inaddr.S_un.S_addr = ipHeader->sourceIP;
			strcpy(sSrcIPAddr, inet_ntoa(inaddr));
			//得到IP包的目的地址
			inaddr.S_un.S_addr = ipHeader->destIP;
			strcpy(sDestIPAddr, inet_ntoa(inaddr));

			//得到协议名称
			strcpy(sProtoName, Get_proto_name(ipHeader->proto));
			//得到IP包头的长度（因为header_len为4比特的数据，所以需要这样计算）
			int iHdrLen = ipHeader->header_len & 0xf;
			iHdrLen *= 4;//ip协议规定要如此转化
			//总长度减包头长度得到数据长度
			int iTotalLen = ntohs(ipHeader->total_len);
			iTotalLen -= iHdrLen;
			switch (ipHeader->proto)
			{
			case IPPROTO_ICMP:
			{
								 icmpHeader = (ICMPPacketHead *)(sBuf + iHdrLen);
								 pDate = ((BYTE *)icmpHeader) + ICMP_HEAD_LEN;
								 iTotalLen -= ICMP_HEAD_LEN;
								 break;
			}

			case IPPROTO_TCP:
			{
								tcpHeader = (TCPPacketHead *)(sBuf + iHdrLen);
								wSrcPort = ntohs(tcpHeader->SourPort);

								wDestPort = ntohs(tcpHeader->DestPort);
								iHdrLen = tcpHeader->HLen >> 4;
								iHdrLen *= 4;
								pDate = ((BYTE *)tcpHeader) + iHdrLen;
								iTotalLen -= iHdrLen;
								break;
			}
			case IPPROTO_UDP:
			{
								udpHeader = (UDPPacketHead *)(&sBuf[iHdrLen]);
								wSrcPort = ntohs(udpHeader->SourcePort);

								wDestPort = ntohs(udpHeader->DestPort);

								pDate = ((BYTE *)udpHeader) + UDP_HEAD_LEN;
								iTotalLen -= UDP_HEAD_LEN;
								break;
			}
			}
			static unsigned int iSequence = 0;
			iSequence++;
			printf("----------------------begin%.10u---------------------\n", iSequence);
			printf("Protoname:%s\n srcaddr:%s\n destaddr:%s\n srcport:%d\n destport:%d\n",
				sProtoName, sSrcIPAddr, sDestIPAddr, wSrcPort, wDestPort);
			/*
			internet 组管理协议IGMP是因特网协议家族中的一个组播协议，
			用于IP主机向任一个直接相邻的路由器报告他们的组成员情况
			*/
			if (strcmp(sProtoName, "IGMP") != 0)
			{
				if (ShowByte)//如果加了参数就把2进制数据打印出来
				{
					printf("Bytes :\n");
					PrintByte((char *)pDate, iTotalLen);
				}
				printf("\nASCII:\n%s\n", (char *)pDate);
			}
			printf("-------------end%.10u---------------\n");
			if (iLen < iRes)
			{
				iRes -= iLen;
				pBuf += iLen;
				ipHeader = (IPHEADER *)(pBuf);
			}
			else
			{
				break;
			}
		}
		else{//已经读到了buffer的最后部分，即包的长度
			int iLast = iLen - iRes;
			if (pLastBuf)
				delete[]pLastBuf;
			pLastBuf = new char[iLen];
			int iReaden = iRes;
			memcpy(pLastBuf, pBuf, iReaden);
			iRes = recv(sock, pLastBuf + iReaden, iLast, 0);
			if (iRes == SOCKET_ERROR)
				return WSAGetLastError();

			pBuf = pLastBuf;
			ipHeader = (IPHEADER *)pBuf;
			if (iRes == iLast)
				iRes = iLen;
			else
			{
				//读取所有数据
				iReaden += iRes;
				iLast -= iRes;
				while (true)
				{
					iRes = recv(sock, pLastBuf + iReaden, iLast, 0);
					if (iRes == SOCKET_ERROR)
						return WSAGetLastError();
					iReaden += iRes;
					iLast -= iRes;
					if (iLast <= 0)
						break;
				}
			}

		}
	}
	return 0;
}



/*
SOCKET socket_connect(const char *hostname, int port)//连接到指定的主机和端口号
{
	if (init_socket() == -1)
		return 0;

	SOCKET st = socket(AF_INET, SOCK_STREAM, 0);//建立TCP socket
	if (st == 0)
		return 0;
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);//指定port为要连接的端口号
	addr.sin_addr.s_addr = inet_addr(hostname);//指定hostname为要连接的IP地址
	if (connect(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)
	{
		printf("connect to %s:%d failed %s\n", hostname, port, strerror(errno));
		return 0;//连接失败，返回0
	}
	else
	{
		return st;//连接成功，返回socket描述符
	}
}

SOCKET socket_create(int port)//在port指定的端口上建立server端socket
{
	if (init_socket() == -1)
		return 0;

	SOCKET st = socket(AF_INET, SOCK_STREAM, 0);//建立TCP socket
	if (st == 0)
		return 0;//如果建立socket失败，返回0

#ifdef WIN
	const char on = 0;
#else
	int on = 0;
#endif

	if (setsockopt(st, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
	{
		printf("setsockopt failed %s\n", strerror(errno));
		return 0;
	}
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)//server端socket，所以需要绑定IP地址
	{
		printf("bind failed %s\n", strerror(errno));
		return 0;
	}
	if (listen(st, 20) == -1)
	{
		printf("listen failed %s\n", strerror(errno));
		return 0;
	}
	printf("listen %d success\n", port);
	return st;//server端socket建立成功,返回server端socket描述符
}

SOCKET socket_accept(SOCKET listen_st)//server端socket开始accept的函数
{
	struct sockaddr_in client_addr;

#ifdef WIN
	int len = 0;
#else
	unsigned int len = 1;
#endif

	len = sizeof(client_addr);
	memset(&client_addr, 0, sizeof(client_addr));
	SOCKET client_st = accept(listen_st, (struct sockaddr *) &client_addr,
		&len);//accept阻塞，直到有client连接到server才返回
	if (client_st == -1)
	{
		printf("accept failed %s\n", strerror(errno));
		return 0;
	}
	else
	{
		printf("accept by %s\n", inet_ntoa(client_addr.sin_addr));
		return client_st;//有client连接到server，返回client的socket描述符
	}
}

int send_work(const char *hostname, int port, const char *filename)//向hostname指定的IP地址发送filename指定的文件
{
	SOCKET st = socket_connect(hostname, port);//连接到hostname指定的IP地址和port指定的端口号
	if (st == 0)//连接失败，函数返回
		return 0;

	FILE *fd = fopen(filename, "rb");//以只读方式打开filename指定的文件
	if (fd == NULL)//如果文件打开失败，函数返回
	{
		printf("open %s failed %s\n", filename, strerror(errno));
		return 0;
	}

	char *buf = malloc(BUFSIZE);//申请一个缓冲区，存放接收到的文件内容
	memset(buf, 0, BUFSIZE);
	getfilename(filename, buf);//从完整路径名中解析出文件名称，例如：/home/test/abc.txt,解析完成后为abc.txt
	size_t rc = send(st, buf, strlen(buf), 0);//客户端第一次给server端发送的数据为要传递的文件名称，将解析完成后的文件名通过socket发送给server端
	if (rc <= 0)
	{
		if (rc < 0)
			printf("send failed %s\n", strerror(errno));
		else
			printf("socket disconnect\n");

	}
	else
	{

		memset(buf, 0, BUFSIZE);
		if (recv(st, buf, BUFSIZE, 0) <= 0)//接收来自server端的回复
		{
			if (rc < 0)
				printf("recv failed %s\n", strerror(errno));
			else
				printf("socket disconnect\n");
		}
		else
		{
			if (strncmp(buf, "OK", 2) == 0)//如果收到来自服务端的回复，代表服务端认可，可以发送文件了
			{
				while (1)
				{
					memset(buf, 0, BUFSIZE);
					rc = fread(buf, 1, BUFSIZE, fd);//循环读取文件，直到读到文件尾，循环break
					if (rc <= 0)
					{
						if (rc < 0)
							printf("fread failed %s\n", strerror(errno));
						break;
					}
					else
					{
						rc = send(st, buf, rc, 0);//将从文件中读到的数据，通过socket发送到server端，其中rc为从文件中读到的数据大小
						if (rc <= 0)//如果发送失败，代表TCP连接出错，循环break
						{
							if (rc < 0)
								printf("send failed %s\n", strerror(errno));
							else
								printf("socket disconnect\n");
							break;
						}
					}
				}
			}
		}
	}

	fclose(fd);
	free(buf);

#ifdef WIN	
	closesocket(st);
	WSACleanup();
#else	
	close(st);
#endif
	return 1;
}

int recv_work(int port)//server端socket在port指定的端口上listen，接收来自client发送的文件
{
	SOCKET listen_st = socket_create(port);//建立server端socket，在port指定端口listen
	if (listen_st == 0)//如果创建服务端socket失败，函数返回0
		return 0;
	SOCKET st = socket_accept(listen_st);//如果有client连接到达，socket_accept函数返回client的socket描述符
	if (st == 0)
		return 0;

	char *buf = malloc(BUFSIZE);//建立接收文件数据缓冲区
	FILE *fd = NULL;

	memset(buf, 0, BUFSIZE);
	size_t rc = recv(st, buf, BUFSIZE, 0);//接收来自client的数据，客户端第一次要发送的文件名称
	if (rc <= 0)
	{
		if (rc < 0)
			printf("recv failed %s\n", strerror(errno));
		else
			printf("socket disconnect\n");

	}
	else
	{
		printf("receiving %s\n", buf);

		fd = fopen(buf, "wb");//以只写方式打开文件
		if (fd == NULL)
		{
			printf("open %s failed %s\n", buf, strerror(errno));
		}
		else
		{
			memset(buf, 0, BUFSIZE);
			strcpy(buf, "OK");
			rc = send(st, buf, strlen(buf), 0);//回复客户端，同意接收文件
			if (rc <= 0)
			{
				if (rc < 0)
					printf("send failed %s\n", strerror(errno));
				else
					printf("socket disconnect\n");
			}

			while (1)
			{
				memset(buf, 0, BUFSIZE);
				rc = recv(st, buf, BUFSIZE, 0);//循环接收来自client的数据，数据为发送文件的内容
				if (rc <= 0)//如果client连接断开，代表文件传递完成，或者网络意外中断,循环break
				{
					if (rc < 0)
						printf("recv failed %s\n", strerror(errno));
					else
						printf("socket disconnect\n");
					break;
				}
				else
				{
					fwrite(buf, 1, rc, fd);//将从client端收到的内容写入文件
				}
			}
		}
	}

	if (fd)
		fclose(fd);//关闭打开的文件
	free(buf);

#ifdef WIN	
	closesocket(st);
	closesocket(listen_st);
	WSACleanup();
#else	
	close(st);
	close(listen_st);
#endif
	return 1;
}*/
