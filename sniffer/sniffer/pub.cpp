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

//void getfilename(const char *filename, char *name)//������·�����н������ļ����ƣ����磺/home/test/abc.txt,������ɺ�Ϊabc.txt
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

SOCKET SocketCreate(SOCKET &sock,const char *IPAddr,unsigned short Port)//��ʼ��socket
{
	//�����windows��ִ�����´���

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
	//����ԭʼsocket   ipsocket
	sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if (sock == INVALID_SOCKET)
		return WSAGetLastError();

	//���ó�ʱѡ��
	int iRecTime = 50000;//���ý��ճ�ʱ
	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&iRecTime, sizeof(iRecTime)))
		return WSAGetLastError();

	//�󶨾���˿ں͵�ַ
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(Port);//ָ��portΪҪ���ӵĶ˿ں�
	addr.sin_addr.s_addr = inet_addr(IPAddr);//ָ��hostnameΪҪ���ӵ�IP��ַ

	if (bind(sock, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		return WSAGetLastError();
	}

	

	//����socketģʽ��������WSAIoctl������ʱ��Ϊ������socket�ܽ������������IP��
	//����WSAIoctl������socket����������ó�AF_INET, SOCK_RAW, IPPROTO_IPЭ��������socket������ʾ��bind�����ص�һ���˿ڵ�ַ
	DWORD dwBufferInLen = 1;
	DWORD dwBufferLen[10];
	DWORD dwBytesReturned = 0;

	//LINUX Ӧ�þͽ�ioctl  ����WSAIoctl����socket���Խ�������ip��
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
	char sBuf[8192];//socketĬ�ϵ�bufferΪ8k
	char *pBuf = sBuf;
	memset(sBuf, 0, sizeof(sBuf));
	int iRes = recv(sock, sBuf, sizeof(sBuf), 0);//��socket��������
	if (iRes == SOCKET_ERROR)
		return WSAGetLastError();

	//�õ�IP��ͷ
	ipHeader = (IPHEADER *)pBuf;
	//�õ�ip��ͷ�ܳ���
	WORD iLen = ntohs(ipHeader->total_len);

	while (true)
	{
		if (iLen <= iRes)
		{
			//�õ�IP��Դ��ַ
			inaddr.S_un.S_addr = ipHeader->sourceIP;
			strcpy(sSrcIPAddr, inet_ntoa(inaddr));
			//�õ�IP����Ŀ�ĵ�ַ
			inaddr.S_un.S_addr = ipHeader->destIP;
			strcpy(sDestIPAddr, inet_ntoa(inaddr));

			//�õ�Э������
			strcpy(sProtoName, Get_proto_name(ipHeader->proto));
			//�õ�IP��ͷ�ĳ��ȣ���Ϊheader_lenΪ4���ص����ݣ�������Ҫ�������㣩
			int iHdrLen = ipHeader->header_len & 0xf;
			iHdrLen *= 4;//ipЭ��涨Ҫ���ת��
			//�ܳ��ȼ���ͷ���ȵõ����ݳ���
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
			internet �����Э��IGMP��������Э������е�һ���鲥Э�飬
			����IP��������һ��ֱ�����ڵ�·�����������ǵ����Ա���
			*/
			if (strcmp(sProtoName, "IGMP") != 0)
			{
				if (ShowByte)//������˲����Ͱ�2�������ݴ�ӡ����
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
		else{//�Ѿ�������buffer����󲿷֣������ĳ���
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
				//��ȡ��������
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
SOCKET socket_connect(const char *hostname, int port)//���ӵ�ָ���������Ͷ˿ں�
{
	if (init_socket() == -1)
		return 0;

	SOCKET st = socket(AF_INET, SOCK_STREAM, 0);//����TCP socket
	if (st == 0)
		return 0;
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);//ָ��portΪҪ���ӵĶ˿ں�
	addr.sin_addr.s_addr = inet_addr(hostname);//ָ��hostnameΪҪ���ӵ�IP��ַ
	if (connect(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)
	{
		printf("connect to %s:%d failed %s\n", hostname, port, strerror(errno));
		return 0;//����ʧ�ܣ�����0
	}
	else
	{
		return st;//���ӳɹ�������socket������
	}
}

SOCKET socket_create(int port)//��portָ���Ķ˿��Ͻ���server��socket
{
	if (init_socket() == -1)
		return 0;

	SOCKET st = socket(AF_INET, SOCK_STREAM, 0);//����TCP socket
	if (st == 0)
		return 0;//�������socketʧ�ܣ�����0

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
	if (bind(st, (struct sockaddr *) &addr, sizeof(addr)) == -1)//server��socket��������Ҫ��IP��ַ
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
	return st;//server��socket�����ɹ�,����server��socket������
}

SOCKET socket_accept(SOCKET listen_st)//server��socket��ʼaccept�ĺ���
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
		&len);//accept������ֱ����client���ӵ�server�ŷ���
	if (client_st == -1)
	{
		printf("accept failed %s\n", strerror(errno));
		return 0;
	}
	else
	{
		printf("accept by %s\n", inet_ntoa(client_addr.sin_addr));
		return client_st;//��client���ӵ�server������client��socket������
	}
}

int send_work(const char *hostname, int port, const char *filename)//��hostnameָ����IP��ַ����filenameָ�����ļ�
{
	SOCKET st = socket_connect(hostname, port);//���ӵ�hostnameָ����IP��ַ��portָ���Ķ˿ں�
	if (st == 0)//����ʧ�ܣ���������
		return 0;

	FILE *fd = fopen(filename, "rb");//��ֻ����ʽ��filenameָ�����ļ�
	if (fd == NULL)//����ļ���ʧ�ܣ���������
	{
		printf("open %s failed %s\n", filename, strerror(errno));
		return 0;
	}

	char *buf = malloc(BUFSIZE);//����һ������������Ž��յ����ļ�����
	memset(buf, 0, BUFSIZE);
	getfilename(filename, buf);//������·�����н������ļ����ƣ����磺/home/test/abc.txt,������ɺ�Ϊabc.txt
	size_t rc = send(st, buf, strlen(buf), 0);//�ͻ��˵�һ�θ�server�˷��͵�����ΪҪ���ݵ��ļ����ƣ���������ɺ���ļ���ͨ��socket���͸�server��
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
		if (recv(st, buf, BUFSIZE, 0) <= 0)//��������server�˵Ļظ�
		{
			if (rc < 0)
				printf("recv failed %s\n", strerror(errno));
			else
				printf("socket disconnect\n");
		}
		else
		{
			if (strncmp(buf, "OK", 2) == 0)//����յ����Է���˵Ļظ������������Ͽɣ����Է����ļ���
			{
				while (1)
				{
					memset(buf, 0, BUFSIZE);
					rc = fread(buf, 1, BUFSIZE, fd);//ѭ����ȡ�ļ���ֱ�������ļ�β��ѭ��break
					if (rc <= 0)
					{
						if (rc < 0)
							printf("fread failed %s\n", strerror(errno));
						break;
					}
					else
					{
						rc = send(st, buf, rc, 0);//�����ļ��ж��������ݣ�ͨ��socket���͵�server�ˣ�����rcΪ���ļ��ж��������ݴ�С
						if (rc <= 0)//�������ʧ�ܣ�����TCP���ӳ���ѭ��break
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

int recv_work(int port)//server��socket��portָ���Ķ˿���listen����������client���͵��ļ�
{
	SOCKET listen_st = socket_create(port);//����server��socket����portָ���˿�listen
	if (listen_st == 0)//������������socketʧ�ܣ���������0
		return 0;
	SOCKET st = socket_accept(listen_st);//�����client���ӵ��socket_accept��������client��socket������
	if (st == 0)
		return 0;

	char *buf = malloc(BUFSIZE);//���������ļ����ݻ�����
	FILE *fd = NULL;

	memset(buf, 0, BUFSIZE);
	size_t rc = recv(st, buf, BUFSIZE, 0);//��������client�����ݣ��ͻ��˵�һ��Ҫ���͵��ļ�����
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

		fd = fopen(buf, "wb");//��ֻд��ʽ���ļ�
		if (fd == NULL)
		{
			printf("open %s failed %s\n", buf, strerror(errno));
		}
		else
		{
			memset(buf, 0, BUFSIZE);
			strcpy(buf, "OK");
			rc = send(st, buf, strlen(buf), 0);//�ظ��ͻ��ˣ�ͬ������ļ�
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
				rc = recv(st, buf, BUFSIZE, 0);//ѭ����������client�����ݣ�����Ϊ�����ļ�������
				if (rc <= 0)//���client���ӶϿ��������ļ�������ɣ��������������ж�,ѭ��break
				{
					if (rc < 0)
						printf("recv failed %s\n", strerror(errno));
					else
						printf("socket disconnect\n");
					break;
				}
				else
				{
					fwrite(buf, 1, rc, fd);//����client���յ�������д���ļ�
				}
			}
		}
	}

	if (fd)
		fclose(fd);//�رմ򿪵��ļ�
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
