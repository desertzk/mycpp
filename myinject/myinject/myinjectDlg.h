
// myinjectDlg.h : ͷ�ļ�
//

#pragma once
#include "afxeditbrowsectrl.h"
#include "afxwin.h"


// CmyinjectDlg �Ի���
class CmyinjectDlg : public CDialogEx
{
// ����
public:
	CmyinjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYINJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCEditBrowseCtrl mEditBrowse;
	CListBox mProcListBox;
	afx_msg void OnBnClickedOk();
};
