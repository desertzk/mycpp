
// myinjectDlg.h : 头文件
//

#pragma once
#include "afxeditbrowsectrl.h"
#include "afxwin.h"


// CmyinjectDlg 对话框
class CmyinjectDlg : public CDialogEx
{
// 构造
public:
	CmyinjectDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYINJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
