//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
#include"protocolimpl.h"
#include<iostream>


ProtocolImpl::ProtocolImpl(void){
	char *pcommon=NULL;
	int len=0;
}

ProtocolImpl::~ProtocolImpl(void){
	if (this->pcommon)
		free(this->pcommon);

	printf("ProtocolImpl 析构");
}


int ProtocolImpl::cltSocketInit(){
	return 0;
}

//客户端发报文
int ProtocolImpl::cltSocketSend(unsigned char *buf, int buflen){
	if (buf == NULL || buflen > 342432){
		return -1;
	}
	this->pcommon = (char *)malloc(buflen*(sizeof(char)));
	memcpy(pcommon, buf, buflen);
	this->len = buflen;
	return 0;

}

//客户端收报文
int ProtocolImpl::cltSocketRev(unsigned char *buf, int *buflen){
	memcpy(buf, this->pcommon, this->len);
	*buflen = this->len;
	return 0;
}

//客户端释放资源
int ProtocolImpl::cltSocketDestory(){
	return 0;
}