#pragma once
#include<iostream>
using namespace std;

class SocketIF
{
public:
	//客户端初始化 获取handle 上下文信息
	virtual int cltSocketInit() = 0;

	//客户端发报文
	virtual int cltSocketSend(unsigned char *buf, int buflen) = 0;

	//客户端收报文
	virtual int cltSocketRev(unsigned char *buf, int *buflen) = 0;

	//客户端释放资源
	virtual int cltSocketDestory() = 0;
public:
	virtual ~SocketIF(){//这里不加virtual将导致子类析构函数不调用
		cout << "socketif 析构" << endl;
	}
};