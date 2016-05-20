//
//软渲染程序
//2016年5月 by moonightlei
//

#include<Windows.h>
#include<iostream>
using namespace std;

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT  600
#define WINDOW_TITLE L"软渲染程序"

HDC g_hdc = NULL; //全局设备环境句柄

//窗口过程函数的声明
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Program_Init(HWND hwnd);
VOID Program_Paint(HWND hwnd);
BOOL Program_CleanUp(HWND hwnd);

//应用程序入口函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//实例化窗口类，并设定参数
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc; //设定窗口过程函数的函数指针
	wndClass.cbWndExtra = 0;
	wndClass.cbClsExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = L"MainInterfaceWnd";

	//注册窗口类
	if (!RegisterClassEx(&wndClass))	return -1;

	//创建窗口
	HWND hwnd = CreateWindow(L"MainInterfaceWnd", WINDOW_TITLE,
		WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH,
		WINDOW_HEIGHT, NULL,NULL, hInstance, NULL);

	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	if (!Program_Init(hwnd)) {
		MessageBox(hwnd, L"资源初始化失败", L"消息窗口", 0);
		return FALSE;
	}

	if (AllocConsole())
	{
		//MessageBox(hwnd, L"开启控制台成功", L"消息窗口", 0);
		//freopen("CONIN$", "r+t", stdin);
		//freopen_s(&_stream,"CONOUT$", "w+t", stdout);
		freopen("CONOUT$", "w+t", stdout);
	}

	//消息循环
	MSG msg = { 0 };
	while(msg.message != WM_QUIT ){ 
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	UnregisterClass(L"MainInterfaceWnd", wndClass.hInstance);


	return 0;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParm)
{
	PAINTSTRUCT painStruct;

	switch (message)
	{
	case WM_PAINT://客户区重绘消息
		g_hdc = BeginPaint(hwnd, &painStruct);
		Program_Paint(hwnd);
		EndPaint(hwnd,&painStruct);
		ValidateRect(hwnd, NULL);
		break;
	case WM_KEYDOWN://按键消息
		if (wParam == VK_ESCAPE)//ESC键
			DestroyWindow(hwnd);
		break;
	case WM_DESTROY://窗口销毁消息
		Program_CleanUp(hwnd);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParm);
	}

	return 0;
}


BOOL Program_Init(HWND hwnd)
{
	g_hdc = GetDC(hwnd);
	Program_Paint(hwnd);
	ReleaseDC(hwnd, g_hdc);
	return TRUE;
}

VOID Program_Paint(HWND hwnd)
{
	for (int i = 100; i < 200; ++i)
		for (int j = 100; j < 200; ++j)
			SetPixel(g_hdc, i, j, RGB(255, 0, 0));
}

BOOL Program_CleanUp(HWND hwnd)
{
	FreeConsole();
	return TRUE;
}