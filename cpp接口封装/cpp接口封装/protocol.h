#pragma once
#include<iostream>
using namespace std;

class SocketIF
{
public:
	//�ͻ��˳�ʼ�� ��ȡhandle ��������Ϣ
	virtual int cltSocketInit() = 0;

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char *buf, int buflen) = 0;

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char *buf, int *buflen) = 0;

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory() = 0;
public:
	virtual ~SocketIF(){//���ﲻ��virtual������������������������
		cout << "socketif ����" << endl;
	}
};