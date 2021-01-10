#define _CRT_SECURE_NO_WARNINGS
#ifndef PUB_H
#define PUB_H

#include<iostream>
#include<WinSock2.h>
#include<Windows.h>
//#include<string>

#include<string.h>

#pragma comment(lib,"Ws2_32.lib")

//�µ�WSAIoctlѡ���winsock2.h��û��
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

//����Э������ƽṹͨ��Э��ĺ��ܷ���Э�������
typedef struct _PROTN2T
{
	int proto;
	char *pprototext;
}PROTN2T;

//Э����
#define PROTO_NUM 11

//ipͷ�ṹ
typedef struct _IPHEADER
{
	unsigned char header_len : 4;//��λ�ֶΣ�ͷ���ȣ�4��λ��
	unsigned char version : 4;//�汾�ţ�4��λ��
	unsigned char tos;//�������ͣ���Ҫ����������ȼ���
	unsigned short total_len;//���������ȵ��ֽ���
	unsigned short ident;//��ʶ������IP������ʱ�������紫��ʱ���ܻ�Ҫ�ָ�Ϊ��С�İ���Ӧ������̫֡������ʶΨһȷ��ÿ�����͵����ݰ�
	unsigned short flags;//�ۺϱ�־λ��ǰ3λ����־����13λ���ֿ�ƫ�ƣ���������ָ��IP���ݰ�
	unsigned char ttl;//����ʱ�䣬���������ϴ������
	unsigned char proto;//Э��
	unsigned short checksum;//ͷУ��ͣ�ȷ��Ŀ�������������ݺͷ���������ͬ
	unsigned int sourceIP;
	unsigned int destIP;
}IPHEADER;

#define UDP_HEAD_LEN 8
#define PSEUDO_HEAD_LEN 12

#define ICMP_HEAD_LEN 4

struct TCPPacketHead
{
	WORD SourPort;//16λԴ�˿�
	WORD DestPort;//16λĿ�Ķ˿�
	DWORD SeqNo;//32λ���кţ�ָ����TCP����������ʵ��������λ��
	DWORD AckNo;//32λȷ�Ϻ�ָ�������������������н��յ���һ�ֽ����ݣ���������յ����һ���ֽ����Ϊ630����ôtcp����һ��Ϊ631��ȷ�Ϻţ������´η�631��
	BYTE HLen;//ͷ����
	BYTE Flag;//��ʶλ��������URG)ȷ��(ACK)����(PSH)����(RST)ͬ��(SYN)���(FIN)
	WORD WndSize;//16λ���ڴ�С
	WORD ChkSum;//16λTCPУ���
	WORD UrgPtr;//16λ����ָ��

};

struct ICMPPacketHead
{
	BYTE Type;//����
	BYTE Code;//����
	WORD ChkSum;//16λTCPУ���
};


struct UDPPacketHead
{
	WORD SourcePort;//Դ�˿�
	WORD DestPort;//Ŀ�Ķ˿�
	WORD Len;//��Ϣ������
	WORD ChkSum;//16λУ���
};

char *Get_proto_name(unsigned char proto);

void PrintByte(const char *Buf, size_t BufSize);

SOCKET SocketCreate(SOCKET &sock, const char*IPAddr, unsigned short Port);

int SnifferReceive(SOCKET &sock, bool ShowByte = false);

#endif  PUB_H_/* */