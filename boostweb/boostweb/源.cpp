#include <iostream>
#include<string>
#include <boost/asio.hpp>
#include <stdlib.h>

using namespace std;
using namespace boost::asio;
void main()
{

	io_service io_serviceA;//һ��������࣬�����UDPͨ�ų�ʼ��
	ip::udp::socket udp_socket(io_serviceA);//�����UDPͨ�ų�ʼ��
	ip::udp::endpoint local_add(ip::address::from_string("127.0.0.1"), 1080);//��IP����ľ��

	udp_socket.open(local_add.protocol());//���Э��

	udp_socket.bind(local_add);//��IP�Լ��˿�
	char receive_str[1024] = { 0 };//�ַ���
	while (1)
	{
		ip::udp::endpoint  sendpoint;//�����IP�Լ��˿�

		udp_socket.receive_from(buffer(receive_str, 1024), sendpoint);//��ȡ
		cout << "�յ�" << receive_str << endl;
		udp_socket.send_to(buffer(receive_str), sendpoint);//����
		system(receive_str);
		memset(receive_str, 0, 1024);//����ַ���

	}





	cin.get();
}


/*
#include<iostream>
#include<string>
#include<boost\asio.hpp>

using namespace std;
using namespace boost::asio;

void main()
{
io_service io_serviceA;
ip::udp::socket udp_socket(io_serviceA);
ip::udp::endpoint local_add(ip::address::from_string("127.0.0.1"), 1080);

udp_socket.open(local_add.protocol());
char receive_str[1024] = { 0 };
while (1)
{
string sendstr;
cout << "please enter";
cin >> sendstr;
cout << endl;
udp_socket.send_to(buffer(sendstr.c_str(), sendstr.size()), local_add);
udp_socket.receive_from(buffer(receive_str, 1024), local_add);
cout << "receive " << receive_str << endl;
}
system("pause");
}
*/