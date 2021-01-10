// ScreenShare.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "ScreenShare.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
static HDC g_srcmemDc;
static HDC disDc;
static RECT rect;
bool isselect=false;
bool isdown = false;
static void getScreenCapture();
static void CopyBitmapToCipBoard();
// 此代码模块中包含的函数的前向声明: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);



void getScreenSize(int *px, int *py)
{
	
	int x = GetDeviceCaps(disDc, HORZRES);//桌面水平大小
	int y = GetDeviceCaps(disDc, VERTRES);//桌面y大小
	*px = x;
	*py = y;
}


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SCREENSHARE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SCREENSHARE));

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW |CS_DBLCLKS;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SCREENSHARE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = NULL;//MAKEINTRESOURCE(IDC_SCREENSHARE);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_POPUP,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, /*nCmdShow*/SW_MAXIMIZE);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//改变为透明的画刷
	LOGBRUSH brush;
	brush.lbStyle = BS_NULL;
	HBRUSH hBrush = CreateBrushIndirect(&brush);

	LOGPEN pen;
	POINT pt;
	pt.x = 2;
	pt.y = 2;
	pen.lopnColor = 0x000000FF;
	pen.lopnStyle = PS_SOLID;
	pen.lopnWidth = pt;

	HPEN hpen = CreatePenIndirect(&pen);

		 

	int srcx = 0, srcy = 0;
	switch (message)//message means messageid
	{
	case WM_LBUTTONDOWN:
		//MessageBox(hWnd,L"left down",L"info",MB_OK);
	{
			if (!isselect){
				POINT pt;
				GetCursorPos(&pt);
				rect.left = pt.x;
				rect.top = pt.y;
				rect.right = pt.x;
				rect.bottom = pt.y;
				//refresh screen
				InvalidateRect(hWnd, 0, true);
				isdown = true;
			}
			
	}
		
		break;
	case WM_LBUTTONUP:
	{
		if (isdown&&!isselect)
		{
			POINT pt;
			GetCursorPos(&pt);

			rect.right = pt.x;
			rect.bottom = pt.y;
			//refresh screen
			InvalidateRect(hWnd, 0, true);
			isdown = false;
			isselect = true;
		}
		
	}
		
		break;
	case WM_MOUSEMOVE:
	{
		POINT pt;
		GetCursorPos(&pt);

		rect.right = pt.x;
		rect.bottom = pt.y;
		//refresh screen
		//InvalidateRect(hWnd, 0, true);
	}
		break;
	case WM_LBUTTONDBLCLK:
		if (isselect)
		CopyBitmapToCipBoard();
		isselect = false;
		break;

	case WM_CREATE:
		disDc = CreateDC(L"DISPLAY", 0, 0, 0);//driver context DISPLAY 代表桌面
		getScreenCapture();
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT: //屏幕绘制
		hdc = BeginPaint(hWnd, &ps);//代表当前窗口
		
		getScreenSize(&srcx, &srcy);
		//讲整个桌面放到了全局的窗口上
		BitBlt(hdc, 0, 0, srcx, srcy, g_srcmemDc, 0, 0, SRCCOPY);
		// TODO:  在此添加任意绘图代码...
		//把画刷选到笔里来
		SelectObject(hdc, hBrush);
		//选笔
		SelectObject(hdc, hpen);
		// draw rect
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);


		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

//复制鼠标选中区域
void CopyBitmapToCipBoard()
{
	int width = rect.right - rect.left;

	int height = rect.bottom - rect.top;
	HDC hSrcDc = CreateDC(L"DISPLAY", 0, 0, 0);
	HDC memDc = CreateCompatibleDC(hSrcDc);
	HBITMAP bmp = CreateCompatibleBitmap(hSrcDc, width,height);//模拟画布
	HBITMAP oldbmp = (HBITMAP)SelectObject(memDc, bmp);
	//将桌面的一部分画到画板上
	BitBlt(memDc, 0, 0, width, height, hSrcDc, rect.left, rect.top, SRCCOPY);
	HBITMAP newbmp = (HBITMAP)SelectObject(memDc, oldbmp);//返回的之前那个 newbmp是截图
	if (OpenClipboard(0))
	{
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, newbmp);
		CloseClipboard();
	}
}


//
void getScreenCapture()
{
	
	int x=0,y = 0;
	getScreenSize(&x, &y);
	//获取桌面截图
	g_srcmemDc = CreateCompatibleDC(disDc);
	//模拟一张画布
	HBITMAP hbitmap=CreateCompatibleBitmap(disDc, x, y);
	SelectObject(g_srcmemDc, hbitmap);
	BitBlt(g_srcmemDc, 0, 0, x, y, disDc,0,0, SRCCOPY);
}