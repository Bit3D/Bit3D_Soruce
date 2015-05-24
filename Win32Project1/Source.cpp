#include<windowsx.h>
#include<Windows.h>
#include"WindowManager.h"
#include"DXApp.h"
#include"resource.h"
#include"Graphics\Model.h"

// Preprocessor directories
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

//Function prototypes

// Window Messagge fuinction prototype
LRESULT CALLBACK windowProc(HWND hwnd,UINT Message,WPARAM wparam,LPARAM lparam);
WindowManager * WindManager;
DXAPP dxapp;
// Main function
int WINAPI WinMain(HINSTANCE hinst,HINSTANCE previnst,LPSTR lpcmdline,int cmdshow)
{

	#pragma region WindowCreate
	HWND hwnd,hwnd2,hwnd3,hwnd4;
	WNDCLASSEX classex;
	CModel * ModelImporter ;

	SecureZeroMemory(&hwnd,sizeof(hwnd));
	SecureZeroMemory(&hwnd2,sizeof(hwnd));
	SecureZeroMemory(&hwnd3,sizeof(hwnd)); // Alkolocate memory to the new window
	SecureZeroMemory(&hwnd4,sizeof(hwnd)); 
	SecureZeroMemory(&classex,sizeof(classex));



				classex.cbSize = sizeof(classex);
				classex.style = CS_HREDRAW | CS_VREDRAW;
				classex.hInstance = hinst;
				classex.hCursor = LoadCursor(NULL,IDC_ARROW);
				classex.lpfnWndProc = windowProc;
				classex.lpszMenuName= L"Test_Menu";
				classex.lpszClassName = L"DXAPP";
				classex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);;
					
					RegisterClassEx(&classex);

 WindManager = new WindowManager();

 Rect rect1;
 
 SecureZeroMemory(&rect1,sizeof(rect1));

 
	
	SecureZeroMemory(&dxapp,sizeof(dxapp));
	
 dxapp.DebugHelper.StartBenchmark("Testi");
 rect1.Height = 700;
 rect1.Width = 1024;
 rect1.X = 0;
 rect1.Y= 0;

 WindManager->CreateNewWindow(hinst,&classex,L"Whirl ",NULL,&hwnd,rect1,true);
  rect1.BorderX =1;
 rect1.BorderY =1;
 rect1.Height = 700;
 rect1.Width = 900;
 rect1.X = 0;
 rect1.Y= 0;
 classex.lpszMenuName = L"";
 WindManager->CreateNewWindow(hinst,&classex,L"Test Window",&hwnd,&hwnd2,rect1,false);
	 rect1.BorderX =1;
 rect1.BorderY =1;
 rect1.Height = 700;
 rect1.Width = 900;
 rect1.X = 0;
 rect1.Y= 0;
  classex.lpszMenuName = L"";

  Rect rect2;
  SecureZeroMemory(&rect2,sizeof(rect2));
  rect2.Height = 512;
  rect2.Width = 256;
  rect2.X = 100;
  rect2.Y = 100;
	// Create new window using thje class i created
 WindManager->CreateNewWindow(hinst,&classex,L"Windo3",&hwnd,&hwnd3,rect2,false);

 Rect rect3;
 SecureZeroMemory(&rect3,sizeof(rect3));
 rect3.Height=1024;
 rect3.Width=512;
 rect3.X=50;
 rect3.Y=50;
 WindManager->CreateNewWindow(hinst,&classex,L"wind4",&hwnd,&hwnd4,rect3,false);



	RECT rect;
	SecureZeroMemory(&rect,sizeof(rect));
	rect.left = 0;
	rect.right = 100; // width is set in right
	rect.top = 0;
	rect.bottom = 100; // height

	ModelImporter = new CModel(hwnd);
	

	dxapp.CreateD3DDevice(hwnd,WindManager->GetRect(rect2));
		dxapp.CreateD3DDevice(hwnd2,rect);
		dxapp.CreateD3DDevice(hwnd3,rect);
		dxapp.CreateD3DDevice(hwnd4,WindManager->GetRect(rect3));
	
	/*hwnd = CreateWindowEx(NULL,L"DXAPP",L"Firswt Window",WS_OVERLAPPEDWINDOW,0,0,SCREEN_WIDTH,SCREEN_HEIGHT,NULL,NULL,hinst,NULL);
	hwnd2 = CreateWindowEx(NULL,L"DXAPP",L"second Window",WS_CHILD | WS_CLIPCHILDREN | WS_VISIBLE,0,0,SCREEN_WIDTH/2,SCREEN_HEIGHT/2,hwnd,NULL,hinst,NULL);
	ShowWindow(hwnd,cmdshow);
	UpdateWindow(hwnd);
	ShowWindow(hwnd2,cmdshow);*/



		WindManager->ShowWindows(cmdshow);
	MSG msg;
	SecureZeroMemory(&msg,sizeof(msg));

	dxapp.DebugHelper.StopBenchmark();
#pragma endregion

	while(true)
	{
		if(WindManager->HandleMseeages())
		{
			
			
				
		//	WindManager->Update();
			dxapp.DebugHelper.StartBenchmark("dxapp.clear");
		  dxapp.Clear(hwnd,D3DXCOLOR(0,0,0,255));
		  dxapp.Clear(hwnd2,D3DXCOLOR(1,0,0,255));
		  dxapp.Clear(hwnd3,D3DXCOLOR(00,0,0,0));
	    	dxapp.SwapChain();
			dxapp.DebugHelper.StopBenchmark();
		  
		}
	}



	return msg.wParam;
}


LRESULT CALLBACK windowProc(HWND hwnd,UINT message,WPARAM wparam,LPARAM lparam)
{
	switch (message)
	{
	
	case WM_NCACTIVATE:
		return DefWindowProc(hwnd,message,TRUE,lparam);
		break;
	case WM_QUIT:
		DestroyWindow(hwnd);
			dxapp.DebugHelper.DisplayResults();
	break;


	case WM_DESTROY:
		PostQuitMessage(message);
			dxapp.DebugHelper.DisplayResults();
		break;
	case WM_SIZE:

		break;
	default:
		break;
	}

	return DefWindowProc(hwnd,message,wparam,lparam);
}
