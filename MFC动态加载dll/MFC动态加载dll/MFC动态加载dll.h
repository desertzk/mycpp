
// MFC��̬����dll.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC��̬����dllApp: 
// �йش����ʵ�֣������ MFC��̬����dll.cpp
//

class CMFC��̬����dllApp : public CWinApp
{
public:
	CMFC��̬����dllApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC��̬����dllApp theApp;