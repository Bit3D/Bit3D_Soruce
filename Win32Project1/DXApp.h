//// Author: Karthik Hebbar M N
//// Website FissionSpark.weebly.com
//// Engine Whirl engine
#ifndef DXAPP_H
#define DXAPP_H

#include<d3d11.h>
#include<D3DX11.h>
#include<D3DX10.h>
#include<d3dx9.h>
#include<xnamath.h>
#include<vector>
#include<fstream>
#include<ctime>
#include<iostream>
#include<string>


using namespace std;


class DXAPP
{

	class DxDebugHelper
	{
	   private:
		   time_t BegineClock;
		   time_t EndClock;
		   string EntryName,LastEntry;
	   public:
		DxDebugHelper();
		HWND _hwnd;
		void CheckForHRESULTError(HRESULT,LPCWSTR,LPCWSTR);
		void StartBenchmark(string);
		void StopBenchmark();
		float GetStepTimeVal();
		float StartStepTimeVal();
		void DisplayResults();
	};
private:
	vector<ID3D11Device*> d3devices;
	vector<HWND> d3dwnds;
	vector<ID3D11DeviceContext*> d3dcon;
	vector<ID3D11RenderTargetView*> RenderTargets;
	vector<ID3D11DepthStencilView*> DepthViews;
	vector<IDXGISwapChain*> SwapChains;	

	D3D_FEATURE_LEVEL RefFeatureLevel;
	

	void Clean();
public:
	DXAPP(); // Constructor
	 // Destructor
	DxDebugHelper DebugHelper;
	void CreateD3DDevice(HWND hwnd,RECT rect);
	void Clear(HWND hwnd,D3DXCOLOR color);
	ID3D11DeviceContext* GetDevicCon(HWND hwnd);
	void SwapChain();  //Swap tjhe back and front buffer .This must be called at the end of rendering process 
	void HR(HRESULT,LPCWSTR,LPCWSTR);
	bool IsEditor,IsEditorPlay;
	
};

#endif