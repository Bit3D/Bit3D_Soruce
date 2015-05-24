#include<D3D11.h>
#include<D3DX10math.h>
#include<string>
#include"../Plugins/OBJ importer/ObjImporter.h"

#include"../Common.h"

using namespace std;

#pragma region Extensio_Types

#define TYPE_OBJ 0
#define TYPE_FBX 1
#define TYPE_X 2

#pragma endregion






class CModel
{

private:
#pragma region Extensions

#pragma endregion

public:
	ObjImporter * ImporterOBJ;
	CModel(HWND _hwnd);
	CModel(){ImporterOBJ = new ObjImporter();}
	~CModel(void);
	short GetExtension(string);
	void LoadObject(string FileName, WhirlVertex ** CVertexOut,int ** outindex,int Type);
};

