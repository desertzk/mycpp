#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void main(){
	
	keybd_event(0x5b,0,0,0);//���̰���
	keybd_event('R', 0, 0, 0);//���̰���
	keybd_event('R', 0, 2, 0);//�����ɿ�
	keybd_event(0x5b,0,2,0);//�����ɿ�
	mouse_event()
	//0x0D   ENTER key.

}