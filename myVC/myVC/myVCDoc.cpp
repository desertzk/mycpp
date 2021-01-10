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

// myVCDoc.cpp : CmyVCDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "myVC.h"
#endif

#include "myVCDoc.h"
#include "CntrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CmyVCDoc

IMPLEMENT_DYNCREATE(CmyVCDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CmyVCDoc, CRichEditDoc)
	// ����Ĭ�ϵ� OLE ����ʵ��
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CmyVCDoc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_FILE_SEND_MAIL, &CmyVCDoc::OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, &CmyVCDoc::OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CmyVCDoc, CRichEditDoc)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_ImyVC ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {DE938E8F-BDAF-464B-92B4-963184508CA3}
static const IID IID_ImyVC =
{ 0xDE938E8F, 0xBDAF, 0x464B, { 0x92, 0xB4, 0x96, 0x31, 0x84, 0x50, 0x8C, 0xA3 } };

BEGIN_INTERFACE_MAP(CmyVCDoc, CRichEditDoc)
	INTERFACE_PART(CmyVCDoc, IID_ImyVC, Dispatch)
END_INTERFACE_MAP()


// CmyVCDoc ����/����

CmyVCDoc::CmyVCDoc()
{
	// TODO:  �ڴ����һ���Թ������

	EnableAutomation();

	AfxOleLockApp();
}

CmyVCDoc::~CmyVCDoc()
{
	AfxOleUnlockApp();
}

BOOL CmyVCDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}

CRichEditCntrItem* CmyVCDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CmyVCCntrItem(preo, const_cast<CmyVCDoc*>(this));
}




// CmyVCDoc ���л�

void CmyVCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}

	// ���û��� CRichEditDoc ������
	//  �����ĵ��� COleClientItem ��������л���
	// TODO: �����Ϊ�ı��������л��������� 
	CRichEditDoc::m_bRTF = FALSE;
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CmyVCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CmyVCDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CmyVCDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CmyVCDoc ���

#ifdef _DEBUG
void CmyVCDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CmyVCDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// CmyVCDoc ����
