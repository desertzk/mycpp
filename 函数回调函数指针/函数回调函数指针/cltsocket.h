#ifndef _CLT_SOCKET_H_
#define _CLT_SOCKET_H_
typedef int(*EncDataFun)(unsigned char*inData, int inDataLen, unsigned char **outData, int *outDataLen, void *Ref, int RefLen);
typedef int(*DecDataFun)(unsigned char*inData, int inDataLen, unsigned char **outData, int *outDataLen, void *Ref, int RefLen);


typedef struct _SCK_HANDLE{
	char  version[16];
	char  serverip[16];
	int   serverport;
	char  *pbuf;
	int   buflen;

	EncDataFun   myEncDataFunc;
	void * encRef;
	int encRefLen;
	DecDataFun   myDecDataFun;


}SCK_HANDLE;

int cltSocket_init(void **handle);


int cltSocket_senddata(void *handle,unsigned char *buf,int buflen);

int cltSocket_resvdata(void *handle, unsigned char *buf,int *buflen);


int cltSocket_destory(void *handle);

int clitSocket_SetEncFunc(void *handle, EncDataFun encDataCallbak, void *ref, int refLen);

#endif