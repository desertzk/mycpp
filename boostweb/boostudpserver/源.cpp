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