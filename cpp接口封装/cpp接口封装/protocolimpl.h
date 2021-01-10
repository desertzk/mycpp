#include"protocol.h"
class ProtocolImpl :public SocketIF
{
public:
	ProtocolImpl(void);
	~ProtocolImpl(void);

public:
	int cltSocketInit();

	//客户端发报文
	int cltSocketSend(unsigned char *buf, int buflen);

	//客户端收报文
	int cltSocketRev(unsigned char *buf, int *buflen);

	//客户端释放资源
	int cltSocketDestory();
private:
	char *pcommon;
	int len;
};

