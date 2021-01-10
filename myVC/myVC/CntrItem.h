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

// CntrItem.h : CmyVCCntrItem ��Ľӿ�
//

#pragma once

class CmyVCDoc;
class CmyVCView;

class CmyVCCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CmyVCCntrItem)

// ���캯��
public:
	CmyVCCntrItem(REOBJECT* preo = NULL, CmyVCDoc* pContainer = NULL);
		// ע��:  ���� pContainer Ϊ NULL ������ IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE Ҫ������д���
		//  �����Ĺ��캯����  OLE ��ͨ������
		//  �� NULL �ĵ�ָ�빹���

// ����
public:
	CmyVCDoc* GetDocument()
		{ return reinterpret_cast<CmyVCDoc*>(CRichEditCntrItem::GetDocument()); }
	CmyVCView* GetActiveView()
		{ return reinterpret_cast<CmyVCView*>(CRichEditCntrItem::GetActiveView()); }

// ʵ��
public:
	~CmyVCCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

