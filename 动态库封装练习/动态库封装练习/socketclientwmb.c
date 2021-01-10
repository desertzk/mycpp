#include<stdio.h>
#include<stdlib.h>

//�����������ܽӿ� ָ������
//����һ��ָ����������
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



//------------------��һ��api�ӿ�---Begin--------------------------------//
__declspec(dllexport)
//�ͻ��˳�ʼ�� ��ȡhandle����
int cltSocketInit(void **handle /*out*/){
	SCK_HANDLE *sh = NULL;
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
		return -1;
	strcpy(sh->version, "1.0.0");
	strcpy(sh->serverip, "127.0.0.1");
	sh->serverport = 8888;
	*handle = sh;
	return 1;
}
__declspec(dllexport)
//�ͻ��˷�����
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/)
{

	

	int ret = 0;
	SCK_HANDLE *sh = NULL;
	

	if (handle == NULL || buf == NULL || 0 == buflen){
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;


	//ִ�лص�����
	char encout[128] = { 0 };
	sh->myEncDataFunc(buf, buflen, &encout, 128, NULL, 0);





	
	
	sh->pbuf = malloc(buflen*sizeof(char));
	if (sh->pbuf == NULL)
	{
		ret = -2;
		return ret;
	}
	memcpy(sh->pbuf, buf, buflen);
	sh->buflen = buflen;

	return ret;
}
__declspec(dllexport)
//�ͻ����ձ���
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL || buf == NULL || 0 == buflen){
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;

	memcpy(buf, sh->pbuf, sh->buflen);
	*buflen = sh->buflen;

	return *buflen;
}
 __declspec(dllexport)
//�ͻ����ͷ���Դ
int cltSocketDestory(void *handle/*in*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	if (handle == NULL){
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;

	if (sh->pbuf != NULL)
	{
		free(sh->pbuf);
	}
	free(sh);
	return ret;
}
//------------------��һ��api�ӿ�---End-----------------------------------//
__declspec(dllexport)
int clitSocket_SetEncFunc(void *handle, EncDataFun encDataCallbak, void *ref, int refLen)
{
	SCK_HANDLE *sh = NULL;
	sh = (SCK_HANDLE *)handle;
	sh->myEncDataFunc = encDataCallbak;
	
	if (refLen > 0)
	{
		sh->encRef = malloc(refLen);
		if (sh->encRef == NULL)
		{
			return -1;
		}
		memcpy(sh->encRef, ref, refLen);
		sh->encRefLen = refLen;
	}
	return 0;
}