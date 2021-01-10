#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "protocol.h"
#include "protocolimpl.h"
using namespace std;


//Ö÷¿ò¼Ü
void mainOP01()
{
	SocketIF *sIf = new ProtocolImpl();

	unsigned char buf[1024]; 
	strcpy((char *)buf, "ddddddddddddddsssssssssssssssssssss");
	 int buflen = 10;

	 unsigned char out[1024];
	 int outlen = 10;
	sIf->cltSocketInit();
	sIf->cltSocketSend(buf, buflen);
	sIf->cltSocketRev(out, &outlen);
	sIf->cltSocketDestory();

}

int mainOP02(SocketIF *sIf, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sIf->cltSocketInit();
	ret = sIf->cltSocketSend(in, inlen);
	ret = sIf->cltSocketRev(out, outlen);
	ret = sIf->cltSocketDestory();
	return ret;

}

void main()
{
	SocketIF *sIf = new ProtocolImpl();

	unsigned char buf[1024]; 
	strcpy((char *)buf, "ddddddddddddddsssssssssssssssssssss");
	int buflen = 10;

	unsigned char out[1024];
	int outlen = 10;

	 mainOP02(sIf, buf, buflen, out, &outlen);
	 cout<<out<<endl;
	 delete sIf;
	system("pause");
}