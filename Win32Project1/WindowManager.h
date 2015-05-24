/* 
Author: Karthik Hebbar M N 
 Website FissionSpark.weebly.com
 Engine Whirl engine
 NOTE:This code is still a prototype */


#include<windowsx.h>
#include<Windows.h>
#include<vector>
#include<list>
#include<iostream>
using namespace std;


#define CHECK_WND  0
#define CHECK_BORDER_H  1
#define CHECK_BORDER_V  2

#pragma region Docking System

	struct Border{ // Border information about the Window
	 RECT Horizontal; 
	 RECT Vertical;
	};

	struct Rect{
	 short X,Y; // Position of X an y
	 short Width,Height; // Width and height
	 short BorderX;
	 short BorderY;
	};

	class WindowDesc
	{
		// ~WindowDesc(); // Destructor

	public:
		WindowDesc(Rect,short,short);  // Consturctor
	    

	  RECT Pos; // Position of window
	  short Width,Height; // Width and Height
	  short MinWidth,MinHeight;
	 short thisWindow; // The Current Window ID
	 short AttachedWindow; // The Attached Window ID
	 short MainWindow; // ID of the Main Window
	
	  // Funcion prototypes
	 
	
		Border borders;


	};
#pragma endregion

class WindowManager{




private:
	vector<HWND> wnds;
	vector<WindowDesc> WindowsDescs;
	HWND hwnd;
	HWND _MainWindow;
	short MainWindowID;
	

public:
	// Constructor 
	vector<HWND> GetList();
	bool LMBDown;
	WindowManager();
	void CreateNewWindow(HINSTANCE hinst,WNDCLASSEX * ex,LPCWSTR WndName,HWND * Parent,HWND * ReturnWind,Rect rect,bool IsthisMainWindow);
	void ShowWindows(int cShow);
	int HandleMseeages();
	bool CheckPos(WindowDesc * ,short,POINT); 
	void Update();
	int GetIndexOf(HWND);
	 RECT GetRect(Rect);
		// Destructor
	~WindowManager();

};