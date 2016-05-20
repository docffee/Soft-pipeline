//
//����Ⱦ����
//2016��5�� by moonightlei
//

#include<Windows.h>
#include<iostream>
using namespace std;

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT  600
#define WINDOW_TITLE L"����Ⱦ����"

HDC g_hdc = NULL; //ȫ���豸�������

//���ڹ��̺���������
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL Program_Init(HWND hwnd);
VOID Program_Paint(HWND hwnd);
BOOL Program_CleanUp(HWND hwnd);

//Ӧ�ó�����ں���
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//ʵ���������࣬���趨����
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc; //�趨���ڹ��̺����ĺ���ָ��
	wndClass.cbWndExtra = 0;
	wndClass.cbClsExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = L"MainInterfaceWnd";

	//ע�ᴰ����
	if (!RegisterClassEx(&wndClass))	return -1;

	//��������
	HWND hwnd = CreateWindow(L"MainInterfaceWnd", WINDOW_TITLE,
		WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH,
		WINDOW_HEIGHT, NULL,NULL, hInstance, NULL);

	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	if (!Program_Init(hwnd)) {
		MessageBox(hwnd, L"��Դ��ʼ��ʧ��", L"��Ϣ����", 0);
		return FALSE;
	}

	if (AllocConsole())
	{
		//MessageBox(hwnd, L"��������̨�ɹ�", L"��Ϣ����", 0);
		//freopen("CONIN$", "r+t", stdin);
		//freopen_s(&_stream,"CONOUT$", "w+t", stdout);
		freopen("CONOUT$", "w+t", stdout);
	}

	//��Ϣѭ��
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
	case WM_PAINT://�ͻ����ػ���Ϣ
		g_hdc = BeginPaint(hwnd, &painStruct);
		Program_Paint(hwnd);
		EndPaint(hwnd,&painStruct);
		ValidateRect(hwnd, NULL);
		break;
	case WM_KEYDOWN://������Ϣ
		if (wParam == VK_ESCAPE)//ESC��
			DestroyWindow(hwnd);
		break;
	case WM_DESTROY://����������Ϣ
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