// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// CntrItem.cpp : CmyVCCntrItem 类的实现
//

#include "stdafx.h"
#include "myVC.h"

#include "myVCDoc.h"
#include "myVCView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyVCCntrItem 的实现

IMPLEMENT_SERIAL(CmyVCCntrItem, CRichEditCntrItem, 0)

CmyVCCntrItem::CmyVCCntrItem(REOBJECT* preo, CmyVCDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO:  在此添加一次性构造代码
}

CmyVCCntrItem::~CmyVCCntrItem()
{
	// TODO:  在此处添加清理代码
}


// CmyVCCntrItem 诊断

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

