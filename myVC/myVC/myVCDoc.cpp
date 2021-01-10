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

// myVCDoc.cpp : CmyVCDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 启用默认的 OLE 容器实现
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CmyVCDoc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_FILE_SEND_MAIL, &CmyVCDoc::OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, &CmyVCDoc::OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CmyVCDoc, CRichEditDoc)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_ImyVC 的支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {DE938E8F-BDAF-464B-92B4-963184508CA3}
static const IID IID_ImyVC =
{ 0xDE938E8F, 0xBDAF, 0x464B, { 0x92, 0xB4, 0x96, 0x31, 0x84, 0x50, 0x8C, 0xA3 } };

BEGIN_INTERFACE_MAP(CmyVCDoc, CRichEditDoc)
	INTERFACE_PART(CmyVCDoc, IID_ImyVC, Dispatch)
END_INTERFACE_MAP()


// CmyVCDoc 构造/析构

CmyVCDoc::CmyVCDoc()
{
	// TODO:  在此添加一次性构造代码

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

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

CRichEditCntrItem* CmyVCDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CmyVCCntrItem(preo, const_cast<CmyVCDoc*>(this));
}




// CmyVCDoc 序列化

void CmyVCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}

	// 调用基类 CRichEditDoc 将启用
	//  容器文档的 COleClientItem 对象的序列化。
	// TODO: 如果作为文本进行序列化，则设置 
	CRichEditDoc::m_bRTF = FALSE;
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CmyVCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CmyVCDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CmyVCDoc 诊断

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


// CmyVCDoc 命令
