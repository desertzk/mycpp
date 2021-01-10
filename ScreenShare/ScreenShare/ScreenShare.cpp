// ScreenShare.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ScreenShare.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������
static HDC g_srcmemDc;
static HDC disDc;
static RECT rect;
bool isselect=false;
bool isdown = false;
static void getScreenCapture();
static void CopyBitmapToCipBoard();
// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);



void getScreenSize(int *px, int *py)
{
	
	int x = GetDeviceCaps(disDc, HORZRES);//����ˮƽ��С
	int y = GetDeviceCaps(disDc, VERTRES);//����y��С
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

 	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SCREENSHARE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SCREENSHARE));

	// ����Ϣѭ��: 
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
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
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
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

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
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//�ı�Ϊ͸���Ļ�ˢ
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
		disDc = CreateDC(L"DISPLAY", 0, 0, 0);//driver context DISPLAY ��������
		getScreenCapture();
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
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
	case WM_PAINT: //��Ļ����
		hdc = BeginPaint(hWnd, &ps);//����ǰ����
		
		getScreenSize(&srcx, &srcy);
		//����������ŵ���ȫ�ֵĴ�����
		BitBlt(hdc, 0, 0, srcx, srcy, g_srcmemDc, 0, 0, SRCCOPY);
		// TODO:  �ڴ���������ͼ����...
		//�ѻ�ˢѡ��������
		SelectObject(hdc, hBrush);
		//ѡ��
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

// �����ڡ������Ϣ�������
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

//�������ѡ������
void CopyBitmapToCipBoard()
{
	int width = rect.right - rect.left;

	int height = rect.bottom - rect.top;
	HDC hSrcDc = CreateDC(L"DISPLAY", 0, 0, 0);
	HDC memDc = CreateCompatibleDC(hSrcDc);
	HBITMAP bmp = CreateCompatibleBitmap(hSrcDc, width,height);//ģ�⻭��
	HBITMAP oldbmp = (HBITMAP)SelectObject(memDc, bmp);
	//�������һ���ֻ���������
	BitBlt(memDc, 0, 0, width, height, hSrcDc, rect.left, rect.top, SRCCOPY);
	HBITMAP newbmp = (HBITMAP)SelectObject(memDc, oldbmp);//���ص�֮ǰ�Ǹ� newbmp�ǽ�ͼ
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
	//��ȡ�����ͼ
	g_srcmemDc = CreateCompatibleDC(disDc);
	//ģ��һ�Ż���
	HBITMAP hbitmap=CreateCompatibleBitmap(disDc, x, y);
	SelectObject(g_srcmemDc, hbitmap);
	BitBlt(g_srcmemDc, 0, 0, x, y, disDc,0,0, SRCCOPY);
}