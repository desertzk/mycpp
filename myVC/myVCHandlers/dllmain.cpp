// dllmain.cpp: DllMain ��ʵ�֡�

#include "stdafx.h"
#include "resource.h"
#include "myVCHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CmyVCHandlersModule _AtlModule;

class CmyVCHandlersApp : public CWinApp
{
public:

// ��д
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CmyVCHandlersApp, CWinApp)
END_MESSAGE_MAP()

CmyVCHandlersApp theApp;

BOOL CmyVCHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
	return CWinApp::InitInstance();
}

int CmyVCHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
