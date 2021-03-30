#include<ntddk.h>
#include<tdi.h>
#include<tdikrnl.h>
#include<windef.h>
#include<ip2string.h>


PDEVICE_OBJECT pfilterdevobj = NULL;

PDRIVER_OBJECT pdodevobj = NULL;
//typedef  struct _TA_ADDRESS {
//	USHORT AddressLength;       // length in bytes of Address[] in this
//	USHORT AddressType;         // type of this address
//	UCHAR Address[1];           // actually AddressLength bytes long
//} TA_ADDRESS, * PTA_ADDRESS;

VOID DrvUnload(PDRIVER_OBJECT pdriver)
{
	DbgPrint("Unload\n");
	IoDetachDevice(pdodevobj);

	IoDeleteDevice(pfilterdevobj);
}


NTSTATUS NotSupported(PDEVICE_OBJECT pdevice, PIRP pirp)
{
	IoSkipCurrentIrpStackLocation(pirp);//下一层拿到的irp和我们这一层是一样的

	return IoCallDriver(pdodevobj, pirp);
}


NTSTATUS MyCreate(PDEVICE_OBJECT pdevice, PIRP pirp)
{
	DbgPrint("MyCreate kkkkkkkkkkkkkkk\n");
	return STATUS_SUCCESS;
}

NTSTATUS MyWrite(PDEVICE_OBJECT pdevice, PIRP pirp)
{
	DbgPrint("MyWrite kkkkkkkkkkkkkkk\n");
	return STATUS_SUCCESS;
}

NTSTATUS MyRead(PDEVICE_OBJECT pdevice, PIRP pirp)
{
	DbgPrint("MyRead kkkkkkkkkkkkkkk\n");
	NTSTATUS status = STATUS_SUCCESS;
	PIO_STACK_LOCATION pstack = IoGetCurrentIrpStackLocation(pirp);

	ULONG readsize = pstack->Parameters.Read.Length;
	PCHAR readbuffer = pirp->AssociatedIrp.SystemBuffer;
	char* str = "This Message conme from kernel";
	int size = strlen(str);
	RtlCopyMemory(readbuffer, str, size);

	pirp->IoStatus.Status = status;
	pirp->IoStatus.Information = size;

	IoCompleteRequest(pirp, IO_NO_INCREMENT);

	return status;
}


NTSTATUS MyDispath(PDEVICE_OBJECT pdevice, PIRP pirp)
{
	//DbgPrint("this is filter\n");
	PIO_STACK_LOCATION pirpstack = NULL;

	if (pdevice == pfilterdevobj) //确保流入我们这个device
	{
		pirpstack = IoGetCurrentIrpStackLocation(pirp);//获取当前irp栈
		if (pirpstack == NULL)
			return STATUS_UNSUCCESSFUL;
		
		if (pirpstack->MinorFunction == TDI_CONNECT)
		{
			//这些结构由afd.sys封装
			PTDI_REQUEST_KERNEL_CONNECT ptdiconnet = (PTDI_REQUEST_KERNEL_CONNECT)(&pirpstack->Parameters);

			PTA_ADDRESS ta_addr = ((PTRANSPORT_ADDRESS)(ptdiconnet->RequestConnectionInformation->RemoteAddress))->Address;
			
			PTDI_ADDRESS_IP tdi_addr = (PTDI_ADDRESS_IP)(ta_addr->Address);
			//unsigned short port = HTONS(tdi_addr->sin_port);
			DWORD address = tdi_addr->in_addr;
			CHAR SBuffer[16] = { 0 };
			char  first = ((PCHAR)&address)[0];
			char second = ((PCHAR)&address)[1];
			char third = ((PCHAR)&address)[2];
			char fourth = ((PCHAR)&address)[3];
			RtlIpv4AddressToStringA(&address, SBuffer);
			DbgPrint("ip:%d.%d.%d.%d\n", first,second, third, fourth);
			DbgPrint("kernel ip:%s\n", SBuffer);
		}
	}


	IoSkipCurrentIrpStackLocation(pirp);//下一层拿到的irp和我们这一层是一样的

	return IoCallDriver(pdodevobj, pirp);//把irp发送给一个特定的设备对象 这里我们会传给下一层设备
}
 
#define DEVICE_NAME  L"\\Device\\MyFirstDevice"
#define SVC_NAME  L"\\??\\MyFirstSVCDevice"

NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)
{
	

	DbgPrint("DriverEntry kkkkkkkkkkkkkkk \n");
	driver->DriverUnload = DrvUnload;
	//DbgPrint("DriverEntry kkkkkkkkkkkkkkk %wZ\n", reg_path);
	NTSTATUS status = 0;
	HANDLE keyhandle = NULL;
	ULONG keyop = 0;
	PVOID keyinfo = NULL;
	



	//about 注册表
	OBJECT_ATTRIBUTES obja = { 0 };
	InitializeObjectAttributes(&obja,reg_path,OBJ_CASE_INSENSITIVE|OBJ_KERNEL_HANDLE,NULL,NULL);

	status = ZwCreateKey(&keyhandle, KEY_ALL_ACCESS, &obja, 0, NULL, REG_OPTION_NON_VOLATILE, &keyop);
	if (NT_SUCCESS(status))
	{
		if (keyop == REG_CREATED_NEW_KEY)
		{
			DbgPrint("create \n");
		}
		else if (keyop == REG_OPENED_EXISTING_KEY)
		{
			DbgPrint("open \n");
			keyinfo = ExAllocatePool(NonPagedPool, 0x1000);
		}
		else {
			DbgPrint("error \n");
		}


		ZwClose(keyhandle);
	}


	UNICODE_STRING device_name = { 0 };
	RtlInitUnicodeString(&device_name, DEVICE_NAME);
	
	//关于网卡
	status = IoCreateDevice(driver,0, &device_name,FILE_DEVICE_NETWORK,0,TRUE,&pfilterdevobj);
	if (!NT_SUCCESS(status))
	{
		DbgPrint("DriverEntry error create %x\n",status);
		return status;
	}
	//设备创建成功
	pfilterdevobj->Flags |= DO_BUFFERED_IO;
	for (int i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; i++)
	{
		driver->MajorFunction[i] = NotSupported;
	}
	driver->MajorFunction[IRP_MJ_INTERNAL_DEVICE_CONTROL] = MyDispath;
	driver->MajorFunction[IRP_MJ_CREATE] = MyCreate;
	driver->MajorFunction[IRP_MJ_READ] = MyRead;
	driver->MajorFunction[IRP_MJ_WRITE] = MyWrite;

	
	UNICODE_STRING symname = { 0 };
	RtlInitUnicodeString(&symname, SVC_NAME);
	status = IoCreateSymbolicLink(&symname, &device_name);
	DbgPrint("IoCreateSymbolicLink\n");
	if (!NT_SUCCESS(status))
	{
		DbgPrint("DriverEntry error IoCreateSymbolicLink %x\n", status);
		IoDeleteDevice(pfilterdevobj);
		return status;
	}
	//绑定操作
	UNICODE_STRING tcpdevicename = { 0 };
	RtlInitUnicodeString(&tcpdevicename, L"\\Device\\Tcp");
	//pfilterdevobj 我们这一层的下一层 有可能是别人写的过滤驱动
	status = IoAttachDevice(pfilterdevobj, &tcpdevicename, &pdodevobj);
	if (!NT_SUCCESS(status))
	{
		DbgPrint("DriverEntry error create %x\n", status);
		IoDeleteDevice(pfilterdevobj);
		return status;
	}
	return 0;

}