// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include"iostream"


int *pBase = (int *)0x007794F8;
unsigned char *pPause = (unsigned char *)0x00472b50;

void fuckPause(){
	DWORD oldProtect;
	//�����Ĵ����������޸�����Ҫ���ǿ��ڴ�ռ��Ϊ��д
	VirtualProtect(pPause,3,PAGE_EXECUTE_READWRITE,&oldProtect);//��һ��������Ҫ�޸ĵĵ�ַ,second parameter is the sizeof memory size you want modify ,third is memory permission,���ĸ����������Ժ�Ҫ��Ȩ�޷��ص�ԭ��״̬

	pPause[0] = 0xC2;//��Ϊ������unsigned char *���Կ���ͨ��һ�ֽ�һ�ֽڵĸ�
	pPause[1] = 0x04;
	pPause[2] = 0x00;
}


int *p3(int base, int offset2, int offset3,int value){
	int address;
	if (IsBadReadPtr((int *)(base + offset2), 4) != 0)
	{
		return NULL;
	}
	address = *(int *)(base + offset2);
	address = (address + offset3);

	if (IsBadWritePtr((int *)address, 4) != 0){
		return NULL;
	}
	*(int *)address = value;
	/*if (*(int *)address < 9000){
		*(int *)address = value;
	}*/
	//*(int *)(address + offset3) = 8000;
	return NULL;
}
//��ȡ����
int *p4(int base, int offset2, int offset3, int offset4,int value){

	int address;
	if (IsBadReadPtr((int *)(base + offset2), 4) == 0)
	{
		address = *(int *)(base + offset2);
	}
	else{
		return 0;
	}
	//address = (address + offset3);
	if (IsBadReadPtr((int *)(address+offset3), 4) == 0){
		address = *(int *)(address + offset3);
		address = address + offset4;
	}
	else{
		return 0;
	}

	if (value != -1){
		if (IsBadWritePtr((int *)address, 4) == 0){
			*(int *)address = value;
		}
	}
	else{
		return (int *)address;
	}
	



	//if (value == -1){
	//	return (int *)(*(int *)(*(int *)(base + offset2) + offset3) + offset4);
	//}
	//else{
	//	*(int *)(*(int *)(*(int *)(base + offset2) + offset3) + offset4)=value ;
	//}
	return 0;
}

DWORD WINAPI myThread(PVOID par){
	


	/*char buf[3] = { 0 };

	sprintf(buf, "%d", count);*/
	//MessageBox(0, buf, 0, 0);


	while (1){
		Sleep(100);
		if (IsBadReadPtr(pBase, 4)){
			continue;
		}

		int *pcount = p4(*pBase, 0x868, 0x15c, 0x24, -1);
		if (IsBadReadPtr(pcount, 4)){
			continue;
		}
		int count = *pcount;
		int *pCurrent = p4(*pBase, 0x868, 0x15c, 0x4c, -1);
		int *pTotal = p4(*pBase, 0x868, 0x15c, 0x50, -1);
		if (pCurrent == NULL || pTotal == NULL){
			continue;
		}
		for (int i = 0; i < count; i++){
			if (IsBadReadPtr(pTotal, 4)){
				break;
			}
			if (IsBadWritePtr(pCurrent, 4) != 0){
				break;
			}
			*pCurrent = *pTotal;
			pCurrent = (int *)((int)pCurrent + 0x50);//�����+0x50������һ��ֲ��
			pTotal = (int *)((int)pTotal + 0x50);
			/*pCurrent += 0x50;
			pTotal += 0x50;*/
		}
		Sleep(100);
	}
	return 0;
}

void fuckColdTime(){
	//MessageBox(0, "sucess", 0, 0);
	//�����߳�
	CreateThread(0, 0, myThread, 0, 0, 0);

	

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		
		p3(*pBase, 0x868, 0x5578,10000);
		fuckPause();
		fuckColdTime();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

