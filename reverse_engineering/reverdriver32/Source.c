#include<ntddk.h>
// windbg lm -l nt start
ULONG64 g_NT_BASE = 0xfffff80357e00000;
ULONG64 g_PTE_BASE;
ULONG64 g_PDE_BASE;
ULONG64 g_PPE_BASE;
ULONG64 g_PXE_BASE;

PULONG64 GetPxeAddress(PVOID addr) {
	return ((((ULONG64)addr & 0xffffffffffff) >> 39) << 3) + g_PXE_BASE;
}

PULONG64 GetPpeAddress(PVOID addr) {
	return ((((ULONG64)addr & 0xffffffffffff) >> 30) << 3) + g_PPE_BASE;
}

PULONG64 GetPdeAddress(PVOID addr) {
	return ((((ULONG64)addr & 0xffffffffffff) >> 21) << 3) + g_PDE_BASE;
}

PULONG64 GetPteAddress(PVOID addr) {
	return ((((ULONG64)addr & 0xffffffffffff) >> 12) << 3) + g_PTE_BASE;
}


ULONG findProcess(char* name)
{
	ULONG curProcess;
	// 
	//gs  _KPCR  +0x180 Prcb             : _KPRCB    +0x008 CurrentThread    : Ptr64 _KTHREAD
	//_KTHREAD
	 //+0x098 ApcState         : _KAPC_STATE       +0x020 Process          : Ptr64 _KPROCESS
	__asm
	{
		mov eax, dword ptr gs : [0x188] ;
		mov ecx, [eax + 0xB8];
		mov curProcess, ecx;
	}
	//_EPROCESS   0x448 ActiveProcessLinks
	PLIST_ENTRY plistProcess = (PLIST_ENTRY)(curProcess + 0x448);
	BOOLEAN isFlags = FALSE;
	DbgPrint("curProcess %p \r\n", curProcess);
	while (plistProcess->Flink != (PLIST_ENTRY)(curProcess + 0x448))
	{
		ULONG nextProcess = ((ULONG)(plistProcess)) - 0x448;
		plistProcess = plistProcess->Flink;
		//+0x5a8 ImageFileName    : [15]
		KdPrint(("%s\n", (PCHAR)(nextProcess + 0x5a8)));
		if (strcmp(name, (PCHAR)(nextProcess + 0x5a8)) == 0)
		{
			curProcess = nextProcess;
			isFlags = TRUE;
			break;

		}
	}

	if (!isFlags)
	{
		curProcess = 0;
	}

	return curProcess;
}



VOID DriverUnload(PDRIVER_OBJECT driver)
{
	DbgPrint("driver exit \r\n");
}





NTSTATUS
DriverEntry(PDRIVER_OBJECT driver,
	PUNICODE_STRING RegisterPath)
{
	DbgPrint("driver enterd! \r\n");
	driver->DriverUnload = DriverUnload;

	findProcess("notepad.exe");
	//0xCB3C 这个偏移在我电脑不行 需要windbg获取！pte 0    g_PTE_BASE
	g_PTE_BASE = *(PULONG64)(g_NT_BASE + 0xCB3C);
	g_PDE_BASE = (ULONG64)GetPteAddress((PVOID)g_PTE_BASE);
	g_PPE_BASE = (ULONG64)GetPteAddress((PVOID)g_PDE_BASE);
	g_PXE_BASE = (ULONG64)GetPteAddress((PVOID)g_PPE_BASE);


	DbgPrint("PXE %p \r\n", GetPxeAddress(0));
	DbgPrint("PPE %p \r\n", GetPpeAddress(0));
	DbgPrint("PDE %p \r\n", GetPdeAddress(0));
	DbgPrint("PTE %p \r\n", GetPteAddress(0));
	return STATUS_SUCCESS;

}

