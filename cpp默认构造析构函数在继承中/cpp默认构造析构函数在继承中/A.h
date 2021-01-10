
#ifndef __A_H__
#define __A_H__
class A
{
		
public:
	virtual ~A()
	{
		std::cout << "A destory" << std::endl;
	}
	virtual void show() = 0;
protected:
private:
};	
#endif