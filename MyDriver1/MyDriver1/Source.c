#include<ntddk.h>
#include<tdi.h>
#include<tdikrnl.h>
#include<windef.h>
#include<ip2string.h>


PDRIVER_OBJECT pfilterdevobj = NULL;

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
	IoSkipCurrentIrpStackLocation(pirp);//��һ���õ���irp��������һ����һ����

	return IoCallDriver(pdodevobj, pirp);
}

NTSTATUS MyDispath(PDEVICE_OBJECT pdevice, PIRP pirp)
{
	//DbgPrint("this is filter\n");
	PIO_STACK_LOCATION pirpstack = NULL;

	if (pdevice == pfilterdevobj) //ȷ�������������device
	{
		pirpstack = IoGetCurrentIrpStackLocation(pirp);//��ȡ��ǰirpջ
		if (pirpstack == NULL)
			return STATUS_UNSUCCESSFUL;
		
		if (pirpstack->MinorFunction == TDI_CONNECT)
		{
			//��Щ�ṹ��afd.sys��װ
			PTDI_REQUEST_KERNEL_CONNECT ptdiconnet = (PTDI_REQUEST_KERNEL_CONNECT)(&pirpstack->Parameters);

			PTA_ADDRESS ta_addr = ((PTRANSPORT_ADDRESS)(ptdiconnet->RequestConnectionInformation->RemoteAddress))->Address;
			
			PTDI_ADDRESS_IP tdi_addr = (PTDI_ADDRESS_IP)(ta_addr->Address);
			//unsigned short port = HTONS(tdi_addr->sin_port);
			DWORD address = tdi_addr->in_addr;
			CHAR SBuffer[16] = { 0 };
			int  first = ((PCHAR)address)[0];
			int second = ((PCHAR)address)[1];
			int third = ((PCHAR)address)[2];
			int fourth = ((PCHAR)address)[3];
			RtlIpv4AddressToStringA(address, SBuffer);
			DbgPrint("ip:%d.%d.%d.%d\n", first,second, third, fourth);
		}
	}


	IoSkipCurrentIrpStackLocation(pirp);//��һ���õ���irp��������һ����һ����

	return IoCallDriver(pdodevobj, pirp);//��irp���͸�һ���ض����豸���� �������ǻᴫ����һ���豸
}


NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)
{
	UNICODE_STRING devicename = { 0 };


	driver->DriverUnload = DrvUnload;
	DbgPrint("DriverEntry kkkkkkkkkkkkkkk\n");
	NTSTATUS status = IoCreateDevice(driver,0,NULL,FILE_DEVICE_NETWORK,FILE_DEVICE_SECURE_OPEN,FALSE,&pfilterdevobj);
	if (!NT_SUCCESS(status))
	{
		DbgPrint("DriverEntry error create %x\n",status);
		return status;
	}
	//�豸�����ɹ�

	for (int i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; i++)
	{
		driver->MajorFunction[i] = NotSupported;
	}
	driver->MajorFunction[IRP_MJ_INTERNAL_DEVICE_CONTROL] = MyDispath;
	
	//�󶨲���
	RtlInitUnicodeString(&devicename, L"\\Device\\Tcp");
	//pfilterdevobj ������һ�����һ�� �п����Ǳ���д�Ĺ�������
	status = IoAttachDevice(pfilterdevobj, &devicename, &pdodevobj);
	if (!NT_SUCCESS(status))
	{
		DbgPrint("DriverEntry error create %x\n", status);
		IoDeleteDevice(pfilterdevobj);
		return status;
	}
	return 0;

}