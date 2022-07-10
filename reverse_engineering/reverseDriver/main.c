#include <ssdt.h>

extern PSSDT_TABLE KeServiceDescriptorTable;
NTSTATUS __stdcall MYNtReadVirtualMemory(HANDLE ProcessHandle, 
	PVOID BaseAddress, PVOID Buffer, ULONG BufferLength, PULONG ReturnLength);


OLD_HOOK oldHook[50] = {0};

PSSDT_TABLE mySSDT = NULL;

HANDLE hThread = NULL;

BOOLEAN isWorkdThread = TRUE;

ULONG findFuncAddress(ULONG newFuncAddress)
{
	int funcIndex = -1;
	ULONG resultFuncAddress = 0;
	for (int i = 0; i < 50; i++)
	{
		if (oldHook[i].isHookSuccess == 1)
		{
			if (oldHook[i].newFunc == newFuncAddress)
			{
				funcIndex = i;
				break;
			}
		}
	}

	if (funcIndex != -1)
	{
		resultFuncAddress = oldHook[funcIndex].oldFunc;
	}

	return resultFuncAddress;
}

NTSTATUS __stdcall MYNtReadVirtualMemory(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG BufferLength, PULONG ReturnLength)
{
	NTSTATUS result = 0;
	ULONG funcAddress = findFuncAddress((ULONG)MYNtReadVirtualMemory);
	KdPrint(("被我HOOK了 MYNtReadVirtualMemory"));
	//查找函数
	
	
	if (funcAddress != 0)
	{
		__asm
		{
			
			push ReturnLength;
			push BufferLength;
			push Buffer;
			push BaseAddress;
			push ProcessHandle;
			
			call funcAddress;

			mov result, eax;
		}
	}

	return result;
}

__declspec(naked) void wp_off()
{
	__asm
	{
		
		cli;
		mov eax, cr0;
		and eax,0xfffeffff;
		mov cr0, eax;
		ret;
	}
}

__declspec(naked) void wp_on()
{
	__asm
	{
		mov eax, cr0;
		or eax, 0x10000;
		mov cr0, eax;
		sti;
		ret;
	}
}

void setHook(ULONG num, ULONG newFuncAddress)
{
	int funcIndex = -1;
	
	for (int i = 0; i < 50; i++)
	{
		if (oldHook[i].isHookSuccess == 0)
		{
			funcIndex = i;
			break;
		}
	}

	if (funcIndex != -1)
	{
		//resultFuncAddress = oldHook[funcIndex].oldFunc;
		
		oldHook[funcIndex].oldFunc = *(mySSDT->serviceTable.funcTable + num);
		
		wp_off();
		*(mySSDT->serviceTable.funcTable + num) = newFuncAddress;
		wp_on();

		oldHook[funcIndex].newFunc = newFuncAddress;
		oldHook[funcIndex].number = num;
		oldHook[funcIndex].isHookSuccess = 1;
	}

	
}


void unHook(ULONG newFuncAddress)
{
	int funcIndex = -1;
	
	ULONG resultFuncAddress = 0;
	for (int i = 0; i < 50; i++)
	{
		if (oldHook[i].isHookSuccess == 1)
		{
			if (oldHook[i].newFunc == newFuncAddress)
			{
				funcIndex = i;
				break;
			}
		}
	}

	if (funcIndex != -1)
	{
		
		wp_off();
		*(mySSDT->serviceTable.funcTable + oldHook[funcIndex].number) = oldHook[funcIndex].oldFunc;
		wp_on();
		oldHook[funcIndex].isHookSuccess = 0;
	}


}

//首先 找到自己进程， 进程遍历
//遍历线程
//替换E0
//COPY SSDT
//定时器



PSSDT_TABLE getSSDTShadow()
{
	ULONG shadow = *(PULONG)(&KeServiceDescriptorTable);
	return (PSSDT_TABLE)(shadow - 0x40);
}

ULONG findProcess(char * name)
{
	ULONG curProcess;
	__asm
	{
		mov eax, dword ptr fs : [0x124];
		mov ecx, [eax + 0x44];
		mov curProcess, ecx;
	}

	PLIST_ENTRY plistProcess = (PLIST_ENTRY)(curProcess + 0x88);
	BOOLEAN isFlags = FALSE;
	
	while (plistProcess->Flink != (PLIST_ENTRY)(curProcess + 0x88))
	{
		ULONG nextProcess = ((ULONG)(plistProcess)) - 0x88;
		plistProcess = plistProcess->Flink;
		//KdPrint(("%s\n", (PCHAR)(nextProcess + 0x174)));
		if (strcmp(name, (PCHAR)(nextProcess + 0x174)) == 0)
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


void replaceThreadE0(ULONG eprocess)
{
	if (eprocess == NULL)
	{
		return;
	}

	//__asm int 3;
	//ULONG ntAddress = *(mySSDT->serviceTable.funcTable);
	//ntAddress = *(PULONG)(ntAddress + 0xC8 + 1);
	//ExAcquireFastMutex((PFAST_MUTEX)ntAddress);

	PLIST_ENTRY threadList = ((PLIST_ENTRY)(eprocess + 0x190));
	PLIST_ENTRY curList = (PLIST_ENTRY)(eprocess + 0x190);
	threadList = threadList->Flink;
	
	while (curList != threadList)
	{
		ULONG curThread = ((ULONG)(threadList)) - 0x22c;
		threadList = threadList->Flink;
		if (curThread < 0x80000000) continue;
		//if (*(PULONG)(curThread + 0x130) != 0) continue;
		//if (*(PULONG)(curThread + 0xE0) == (PULONG)getSSDTShadow()) continue;
		if (*(PULONG)(curThread + 0xE0) == (PULONG)mySSDT) continue;
		*(PULONG)(curThread + 0xE0) = (PULONG)mySSDT;
		
	}

	//ExReleaseFastMutex((PFAST_MUTEX)ntAddress);

	/*
	ULONG nextThread = 0;
	__asm
	{
		mov eax, fs:[0x128];
		mov nextThread, eax;
	}

	KdPrint(("替换成功1 %X\n", nextThread));

	
	if (nextThread != 0)
	{
		ULONG ntAddress = *(((PULONG)*(mySSDT->serviceTable.funcTable)));
		ntAddress = *(PULONG)(ntAddress + 0xC8 + 1);
		ExAcquireFastMutex((PFAST_MUTEX)ntAddress);
		if (eprocess == *(PULONG *)(nextThread + 0x44))
		{
			if (*(PULONG)(nextThread + 0xE0) != (PULONG)mySSDT)
			{
				
				
				*(PULONG)(nextThread + 0xE0) = (PULONG)mySSDT;
				KdPrint(("替换成功2 %X\n", nextThread));
			}
			
		}
		ExReleaseFastMutex((PFAST_MUTEX)ntAddress);
	}

	*/
}

NTSTATUS initSSDT()
{
	mySSDT = (PSSDT_TABLE)ExAllocatePoolWithTag(NonPagedPool, sizeof(SSDT_TABLE), 'myst');
	if (mySSDT == NULL)
	{
		KdPrint(("mySSDT 失败1\n"));
		return STATUS_UNSUCCESSFUL;
	}
	memset(mySSDT, 0, sizeof(SSDT_TABLE));
	mySSDT->serviceTable.funcTable = (PULONG)ExAllocatePoolWithTag(NonPagedPool,
		KeServiceDescriptorTable->serviceTable.limit * 4, 'mysf');

	if (mySSDT->serviceTable.funcTable == NULL)
	{
		ExFreePoolWithTag(mySSDT, 'myst');
		KdPrint(("mySSDT 失败2\n"));
		return STATUS_UNSUCCESSFUL;
	}

	memcpy((PVOID)mySSDT->serviceTable.funcTable, (PVOID)KeServiceDescriptorTable->serviceTable.funcTable,
		KeServiceDescriptorTable->serviceTable.limit * 4);

	mySSDT->serviceTable.limit = KeServiceDescriptorTable->serviceTable.limit;
	mySSDT->serviceTable.paramTable = KeServiceDescriptorTable->serviceTable.paramTable;

	PSSDT_TABLE myshadow = getSSDTShadow();
	mySSDT->serviceTableShadow.funcTable = myshadow->serviceTableShadow.funcTable;
	mySSDT->serviceTableShadow.limit = myshadow->serviceTableShadow.limit;
	mySSDT->serviceTableShadow.paramTable = myshadow->serviceTableShadow.paramTable;

	return STATUS_SUCCESS;
}

void destorySSDT()
{
	if (mySSDT != NULL)
	{
		if (mySSDT->serviceTable.funcTable != NULL)
		{
			ExFreePoolWithTag(mySSDT->serviceTable.funcTable, 'mysf');
		}
		ExFreePoolWithTag(mySSDT, 'myst');
	}

	mySSDT = NULL; 
}


VOID workThreadFunc( PVOID StartContext)
{
	LARGE_INTEGER timer = {0};

	timer.QuadPart = -10 * 1000 * 1000;
	KdPrint(("进来了\n"));
	while (isWorkdThread)
	{
		KeDelayExecutionThread(KernelMode, FALSE, &timer);
		
		ULONG process = findProcess("debugvieww.exe");
		replaceThreadE0(process);
	}
	
	KdPrint(("出去了\n"));
	ZwClose(hThread);
	
}


VOID DriverUnload(PDRIVER_OBJECT pDriver)
{
	
	unHook((ULONG)MYNtReadVirtualMemory);
	isWorkdThread = FALSE;
	LARGE_INTEGER timer = { 0 };
	timer.QuadPart = -30 * 1000 * 1000;
	KeDelayExecutionThread(KernelMode, TRUE, &timer);
	destorySSDT();
	KdPrint(("卸载了\n"));
}


NTSTATUS DriverEntry(PDRIVER_OBJECT pDriver, PUNICODE_STRING pReg)
{
	pDriver->DriverUnload = DriverUnload;
	
	NTSTATUS status =initSSDT();

	
	if (!NT_SUCCESS(status))
	{
		destorySSDT();
		return status;
	}
	setHook(0xBA, (ULONG)MYNtReadVirtualMemory);
	
	PsCreateSystemThread(&hThread, 0, NULL, NULL, NULL, workThreadFunc, NULL);

	KdPrint(("%X\n", mySSDT));
	//ULONG p =findProcess("PCHunter32.exe");
	//KdPrint(("%X\n", p));
	
	
	return status;
}