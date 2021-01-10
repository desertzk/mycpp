#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void main(){
	
	keybd_event(0x5b,0,0,0);//键盘按下
	keybd_event('R', 0, 0, 0);//键盘按下
	keybd_event('R', 0, 2, 0);//键盘松开
	keybd_event(0x5b,0,2,0);//键盘松开
	mouse_event()
	//0x0D   ENTER key.

}