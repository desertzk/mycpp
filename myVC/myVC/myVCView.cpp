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

// myVCView.cpp : CmyVCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "myVC.h"
#endif

#include "myVCDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "myVCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyVCView

IMPLEMENT_DYNCREATE(CmyVCView, CRichEditView)

BEGIN_MESSAGE_MAP(CmyVCView, CRichEditView)
	ON_WM_DESTROY()
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmyVCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmyVCView ����/����

CmyVCView::CmyVCView()
{
	EnableActiveAccessibility();
	// TODO:  �ڴ˴���ӹ������

}

CmyVCView::~CmyVCView()
{
}

BOOL CmyVCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRichEditView::PreCreateWindow(cs);
}

void CmyVCView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// ���ô�ӡ�߾�(720 � = 1/2 Ӣ��)
	SetMargins(CRect(720, 720, 720, 720));
}


// CmyVCView ��ӡ


void CmyVCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmyVCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}


void CmyVCView::OnDestroy()
{
	// ����ʱͣ�ô������
	// ʹ�ò����ͼʱ�ǳ���Ҫ 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CmyVCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmyVCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmyVCView ���

#ifdef _DEBUG
void CmyVCView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CmyVCView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CmyVCDoc* CmyVCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmyVCDoc)));
	return (CmyVCDoc*)m_pDocument;
}
#endif //_DEBUG


// CmyVCView ��Ϣ�������
