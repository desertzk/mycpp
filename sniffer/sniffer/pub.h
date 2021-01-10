#define _CRT_SECURE_NO_WARNINGS
#ifndef PUB_H
#define PUB_H

#include<iostream>
#include<WinSock2.h>
#include<Windows.h>
//#include<string>

#include<string.h>

#pragma comment(lib,"Ws2_32.lib")

//新的WSAIoctl选项，在winsock2.h中没有
#define SIO_RCVALL		_WSAIOW(IOC_VENDOR,1)
#define SIO_RCVALL_MCAST		_WSAIOW(IOC_VENDOR,2)
#define SIO_RCVALL_IGMPMCAST		_WSAIOW(IOC_VENDOR,3)
#define SIO_KEEPALIVE_VALS		_WSAIOW(IOC_VENDOR,4)
#define SIO_ABSORB_RTRALERT		_WSAIOW(IOC_VENDOR,5)
#define SIO_UCAST_IF		_WSAIOW(IOC_VENDOR,6)
#define SIO_LIMIT_BROADCASTS		_WSAIOW(IOC_VENDOR,7)
#define SIO_INDEX_BIND		_WSAIOW(IOC_VENDOR,8)
#define SIO_INDEX_MCASTIF		_WSAIOW(IOC_VENDOR,9)
#define SIO_INDEX_ADD_MCAST		_WSAIOW(IOC_VENDOR,10)
#define SIO_INDEX_DEL_MCAST		_WSAIOW(IOC_VENDOR,11)

//定义协议的名称结构通过协议的号能返回协议的名称
typedef struct _PROTN2T
{
	int proto;
	char *pprototext;
}PROTN2T;

//协议数
#define PROTO_NUM 11

//ip头结构
typedef struct _IPHEADER
{
	unsigned char header_len : 4;//（位字段）头长度，4个位长
	unsigned char version : 4;//版本号，4个位长
	unsigned char tos;//服务类型（主要定义包的优先级）
	unsigned short total_len;//包整个长度的字节数
	unsigned short ident;//标识，由于IP包发送时候在网络传送时可能还要分割为更小的包（应该是以太帧），标识唯一确定每个发送的数据包
	unsigned short flags;//综合标志位（前3位：标志，后13位：分块偏移，用来重组分割的IP数据包
	unsigned char ttl;//生存时间，代表网络上存活寿命
	unsigned char proto;//协议
	unsigned short checksum;//头校验和，确保目的主机接收数据和发送数据相同
	unsigned int sourceIP;
	unsigned int destIP;
}IPHEADER;

#define UDP_HEAD_LEN 8
#define PSEUDO_HEAD_LEN 12

#define ICMP_HEAD_LEN 4

struct TCPPacketHead
{
	WORD SourPort;//16位源端口
	WORD DestPort;//16位目的端口
	DWORD SeqNo;//32位序列号，指出了TCP段数据区其实数据数据位置
	DWORD AckNo;//32位确认号指出连接期望从数据流中接收的下一字节数据，例如如果收到最后一个字节序号为630，那么tcp将发一个为631的确认号，让他下次发631包
	BYTE HLen;//头长度
	BYTE Flag;//标识位。紧急（URG)确认(ACK)推送(PSH)重置(RST)同步(SYN)完成(FIN)
	WORD WndSize;//16位窗口大小
	WORD ChkSum;//16位TCP校验和
	WORD UrgPtr;//16位紧急指针

};

struct ICMPPacketHead
{
	BYTE Type;//类型
	BYTE Code;//编码
	WORD ChkSum;//16位TCP校验和
};


struct UDPPacketHead
{
	WORD SourcePort;//源端口
	WORD DestPort;//目的端口
	WORD Len;//消息包长度
	WORD ChkSum;//16位校验和
};

char *Get_proto_name(unsigned char proto);

void PrintByte(const char *Buf, size_t BufSize);

SOCKET SocketCreate(SOCKET &sock, const char*IPAddr, unsigned short Port);

int SnifferReceive(SOCKET &sock, bool ShowByte = false);

#endif  PUB_H_/* */