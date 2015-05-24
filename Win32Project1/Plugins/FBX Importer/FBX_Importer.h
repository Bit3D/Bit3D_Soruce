#pragma once

#ifndef FBX_IMPORTER
#define FBX_IMPORTER

#include"../../Graphics/Graphics.h"
#include<fbxsdk.h>
#include<vector>

using namespace std;


class FBX_Importer
{
public:
	FBX_Importer(void);
	~FBX_Importer(void);

	HRESULT LoadFBX(WMesh* Mot,string Path); // Return vertex list from fbx file
	
	
private:
	FbxManager* fbx_Manager ;
	FbxNode * Node;
	void init(string Path);
	void GetPositions();

};




#endif