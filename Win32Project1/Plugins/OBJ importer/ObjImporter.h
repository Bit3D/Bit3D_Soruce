#pragma once
#ifndef OBJIMPORTER_H
#define OBJIMPORTER_H

#include<fstream>
//#include"Model.h"

#include"../../Graphics/Graphics.h"
using namespace std;

class ObjImporter
{

protected:
	//HWND hwnd;
	int TriCount,VertexCount,IndexCount,NormalCount,UVcount;
	

public:
	//ObjImporter(HWND _hwnd){ hwnd = _hwnd;}
	ObjImporter(){}
	~ObjImporter(void);
	void ExporttoFormat(string FileName,string EportTo);
	void Import(string fileName, WhirlVertex ** pVertex,int ** pIndex);
	void LoadFileCounts(string fileName);
};

#endif
