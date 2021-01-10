//#include<iostream>
#include"pub.h"
//#include<Windows.h>
using namespace std;

int main(int argc,char *argv[])
{
	if (argc < 3)
		return -1;

	SOCKET sock;
	//int iPort = atoi(argv[2]);
	
	//int iRes = SocketCreate(sock, argv[1], (unsigned short)iPort);
	int iRes = SocketCreate(sock, "192.168.32.1", (unsigned short)8888);
	if (iRes != 0)//这里代表SocketCreate出错
	{
		LPVOID lpMsgBuf;
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			iRes,//这里放了lasterror的返回值
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),//defaultlanguage
			(LPTSTR)&lpMsgBuf,
			0,
			NULL
			);
		printf("Error : %d %s\n", iRes, (LPCTSTR)lpMsgBuf);
		LocalFree(lpMsgBuf);

		return -1;
	}

	while (true)
	{
		if (argc == 4)
			iRes = SnifferReceive(sock, true);
		else
			iRes = SnifferReceive(sock);
		if (iRes != 0)//这里代表SocketCreate出错
		{
			LPVOID lpMsgBuf;
			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				iRes,//这里放了lasterror的返回值
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),//defaultlanguage
				(LPTSTR)&lpMsgBuf,
				0,
				NULL
				);
			printf("Error : %d %s\n", iRes, (LPCTSTR)lpMsgBuf);
			LocalFree(lpMsgBuf);

			return -1;
		}
	}

	system("pause");
}