#include<iostream>

using namespace std;
class A1{
public:

	int b;
	static int c;
protected:
private:
};
int A1::c = 1;
void main(){
	
	A1 *a=new A1();
	system("pause");
}