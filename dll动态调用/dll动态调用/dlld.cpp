#include<iostream>

typedef int(*cltSocketInit)(void **handle /*out*/);

typedef int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/);

typedef int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);

typedef int cltSocketDestory(void *handle/*in*/);

void main(){

	HINSTANCE hInstance=NULL;
	char* path = "D:/ccppworkplace/Projects/¶¯Ì¬¿â·â×°Á·Ï°/Debug/¶¯Ì¬¿â·â×°Á·Ï°.dll";

	hInstance = ::LoadLibrary(path);
	cltSocketInit csi = (cltSocketInit)::GetProcAddress(hInstance, "cltSocketInit");
	cltSocketSend *css = (cltSocketSend*)::GetProcAddress(hInstance, "cltSocketSend");
	cltSocketRev *csr = (cltSocketRev *)::GetProcAddress(hInstance, "cltSocketRev");
	cltSocketDestory *csd = (cltSocketDestory *)::GetProcAddress(hInstance, "cltSocketDestory");
	void *handle = NULL;
	int ret = csi(&handle);
	unsigned char buf[100];
	int buflen = 20;
	memcpy(buf, "dfasdgdsgsdfg", buflen);

	unsigned char out[100];
	int outlen = 0;
	css(handle, buf, buflen);
	ret=csr(handle, out, &outlen);
	csd(handle);
	printf("%s", out);
}