#include"protocol.h"
class ProtocolImpl :public SocketIF
{
public:
	ProtocolImpl(void);
	~ProtocolImpl(void);

public:
	int cltSocketInit();

	//�ͻ��˷�����
	int cltSocketSend(unsigned char *buf, int buflen);

	//�ͻ����ձ���
	int cltSocketRev(unsigned char *buf, int *buflen);

	//�ͻ����ͷ���Դ
	int cltSocketDestory();
private:
	char *pcommon;
	int len;
};

