// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// CntrItem.cpp : CmyVCCntrItem ���ʵ��
//

#include "stdafx.h"
#include "myVC.h"

#include "myVCDoc.h"
#include "myVCView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyVCCntrItem ��ʵ��

IMPLEMENT_SERIAL(CmyVCCntrItem, CRichEditCntrItem, 0)

CmyVCCntrItem::CmyVCCntrItem(REOBJECT* preo, CmyVCDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO:  �ڴ����һ���Թ������
}

CmyVCCntrItem::~CmyVCCntrItem()
{
	// TODO:  �ڴ˴�����������
}


// CmyVCCntrItem ���

#ifdef _DEBUG
void CmyVCCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CmyVCCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

