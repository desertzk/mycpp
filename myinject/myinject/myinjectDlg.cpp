
// myinjectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "myinject.h"
#include "myinjectDlg.h"
#include "afxdialogex.h"

#include<TlHelp32.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmyinjectDlg 对话框



CmyinjectDlg::CmyinjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmyinjectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmyinjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, mEditBrowse);
	DDX_Control(pDX, IDC_LIST1, mProcListBox);
}

BEGIN_MESSAGE_MAP(CmyinjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CmyinjectDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CmyinjectDlg 消息处理程序

BOOL CmyinjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmyinjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmyinjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmyinjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmyinjectDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	//AfxMessageBox(TEXT("hehe"));
	mProcListBox.ResetContent();
	HANDLE hProces=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//windows对资源的集合称为句柄
	if (INVALID_HANDLE_VALUE == hProces)
	{
		AfxMessageBox(TEXT("error"));
		return;
	}
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);
	if (!Process32First(hProces, &pe))
	{
		AfxMessageBox(TEXT("error"));
		return;
	}
	
	while (Process32Next(hProces, &pe))
	{
		//AfxMessageBox(pe.szExeFile);
		//判断进程32位还是64位
		SYSTEM_INFO si;
		GetNativeSystemInfo(&si);
		if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		{
			//从进程id获取进程句柄
			HANDLE hpro64=OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
			if (NULL == hpro64)
			{
				AfxMessageBox(TEXT("error on OpenProcess"));
				return;
			}
			//有可能是64进程
			BOOL bWow64;
			if (!IsWow64Process(hpro64, &bWow64))
			{
				AfxMessageBox(TEXT("error on IsWow64Process"));
				return;
			}
		}
		else if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
		{
			//32
		}
		else{
			//dont know
		}
		mProcListBox.AddString(pe.szExeFile);
	}

}
