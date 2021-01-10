#ifndef _CLT_SOCKET_H_
#define _CLT_SOCKET_H_


int cltSocket_init(void **handle);


int cltSocket_senddata(void *handle,unsigned char *buf,int buflen);

int cltSocket_resvdata(void *handle, unsigned char *buf,int *buflen);


int cltSocket_destory(void *handle);

#endif