#include<stdio.h>
#include<stdlib.h>
#define BODYBUF 1024
typedef struct
{
	unsigned char head[4];
	unsigned int userid;
	unsigned int friendid;
	unsigned int len;
}MsgHead;


typedef struct msg_t
{
	MsgHead msghead;
	char body[BODYBUF];
}Msg;
void main(){
	Msg msg;
	memset(&msg, 0, sizeof(msg));
	printf("%p\n", &msg);
	printf("%p\n", (&msg)->msghead);
	system("pause");
}