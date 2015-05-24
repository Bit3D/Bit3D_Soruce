//// Author: Karthik Hebbar M N
//// Website FissionSpark.weebly.com
//// Engine Whirl engine

#include"WindowManager.h"

#pragma region Docking System

WindowDesc::WindowDesc(Rect rect,short thisWind,short MainWnd)
{
	SecureZeroMemory(&Pos,sizeof(Pos));
	SecureZeroMemory(&borders,sizeof(borders));
	SecureZeroMemory(this,sizeof(this));

	Width = rect.Width;
	Height = rect.Height;

	Pos.left = rect.X;
	Pos.top = rect.Y;
	Pos.right = Pos.left + Width;
	Pos.bottom = Pos.top + Height;

	borders.Horizontal.left = rect.X + rect.BorderX;
	borders.Horizontal.right = Pos.right - rect.BorderX;
	borders.Horizontal.top = rect.Y;
	borders.Horizontal.bottom = rect.Y + rect.BorderY;

	borders.Vertical.right = Pos.right;
	borders.Vertical.left = Pos.right - rect.BorderX;
	borders.Vertical.top = Pos.top + rect.BorderY;
	borders.Vertical.bottom = Pos.bottom - rect.BorderY;
	
	thisWindow = thisWind;
	MainWindow = MainWnd;

}

RECT WindowManager::GetRect(Rect rect)
{
  RECT _rect;
  SecureZeroMemory(&_rect,sizeof(_rect));

  _rect.left = rect.X ;
  _rect.right = rect.X + rect.Width;
  _rect.top = rect.Y;
  _rect.bottom = rect.Height;

  return _rect;
}

void WindowManager::Update()
{
	POINT p;
	SecureZeroMemory(&p,sizeof(p));

	GetCursorPos(&p);
	ScreenToClient(_MainWindow,&p);
	HWND activeWnd = GetActiveWindow();

	if(GetKeyState(VK_LBUTTON) & 0x8000)
	{
		LMBDown = true;
	}else 
		LMBDown = false;
	if(LMBDown && activeWnd)
	{
		

		if(activeWnd != _MainWindow)
		{
			int IndexofActive = GetIndexOf(activeWnd); // index

			for(unsigned int i=0; i < WindowsDescs.size() ;++i )
			 {
				 if(CheckPos( &WindowsDescs.at(i),CHECK_BORDER_H,p)) // If mouse is in horzontal border
			   {
				   WindowsDescs.at(i).Pos.right =  WindowsDescs.at(i).Pos.right - WindowsDescs.at(IndexofActive).Width;
				   
				   WindowsDescs.at(IndexofActive).Pos.left =  WindowsDescs.at(i).Pos.right;
				   WindowsDescs.at(IndexofActive).Pos.right =   WindowsDescs.at(IndexofActive).Pos.left  +  WindowsDescs.at(IndexofActive).Width;

				   // Update Attached windows width and height
				   WindowsDescs.at(i).Width = WindowsDescs.at(i).Pos.right - WindowsDescs.at(i).Pos.left;
				   WindowsDescs.at(IndexofActive).AttachedWindow = i; // index of attached window


				   if( WindowsDescs.at(IndexofActive).Pos.right >  WindowsDescs.at(MainWindowID).Width)
				   {
				     WindowsDescs.at(IndexofActive).Pos.right = WindowsDescs.at(IndexofActive).Pos.right - (WindowsDescs.at(IndexofActive).Pos.right - WindowsDescs.at(MainWindowID).Pos.right);
				   }

				   SetWindowPos(wnds.at(WindowsDescs.at(i).thisWindow),NULL,
					   WindowsDescs.at(i).Pos.left,
					   WindowsDescs.at(i).Pos.top,
					   WindowsDescs.at(i).Width,
					   WindowsDescs.at(i).Height,0
					   );

				   SetWindowPos(activeWnd,NULL, 
					   WindowsDescs.at(IndexofActive).Pos.left,
					   WindowsDescs.at(IndexofActive).Pos.top, 
					   WindowsDescs.at(IndexofActive).Width, 
					   WindowsDescs.at(IndexofActive).Height,0
					   );


				   
			   }
			 }
		}

	}

}



bool WindowManager::CheckPos(WindowDesc * desc,short CheckType,POINT p)
{
	if(CheckType == CHECK_BORDER_H)
	{
		if(p.x > desc->borders.Horizontal.left && 
			p.x < desc->borders.Horizontal.right &&
			p.y > p.x > desc->borders.Horizontal.top && 
			p.y < p.x > desc->borders.Horizontal.bottom
			)
	 {
		 return true;
	 }
	}
}
#pragma endregion

#pragma region Winodw Creatioin and Update
WindowManager::WindowManager()
{
	
	
}

void WindowManager::CreateNewWindow(HINSTANCE hinst,WNDCLASSEX * ex,LPCWSTR WndName,HWND * Parent,HWND * ReturnWind,Rect rect,bool IsMainWindow)
{
	if(Parent == NULL)
	{
		hwnd = CreateWindowEx(NULL,ex->lpszClassName,WndName,WS_OVERLAPPEDWINDOW,rect.X,rect.Y,rect.Width,rect.Height,NULL,NULL,hinst,NULL);
		wnds.push_back(hwnd);
		*ReturnWind = hwnd;

	
	}else{
		
		hwnd = CreateWindowEx(NULL,ex->lpszClassName,WndName, WS_EX_LAYERED ,rect.X,rect.Y,rect.Width,rect.Height,*Parent,NULL,hinst,NULL);
	//	SetParent(hwnd,*Parent);
		wnds.push_back(hwnd);
		*ReturnWind = hwnd;
	}

		if(IsMainWindow)
		{
			_MainWindow = hwnd;
			MainWindowID = wnds.size() -1;
		}


		WindowDesc desc(rect,wnds.size() -1,MainWindowID);
		WindowsDescs.push_back(desc);
}

void WindowManager::ShowWindows(int show)
{
	//Update();

	for(vector<HWND>::iterator it = wnds.begin();it != wnds.end() ; ++it)
	{
		UpdateWindow(*it);
		ShowWindow(*it,show);
	}
}


int WindowManager::HandleMseeages()
{
	MSG msg;

 for(int i=0;i< wnds.size();++i)
	{
		if(PeekMessage(&msg,wnds[i],0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if(msg.message == WM_QUIT)
				return 0;
		}
	}
 

 return 1;
}



vector<HWND> WindowManager::GetList()
{
	return wnds;
}


int WindowManager::GetIndexOf(HWND _hwnd)
{
	for(int i=0;i < wnds.size();++i)
	{
		if(wnds.at(i) == _hwnd)
	  {
		  return i;
	  }
	}
}
#pragma endregion