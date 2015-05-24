#include "Model.h"


short CModel::GetExtension(string FileName)
{
	
	char * Extension = new char[4];
	bool ExtensionStart;
	int ExtIndex = 0;
	for(char& c : FileName)
	 {
	   if(c == '.')
	   {
		   ExtensionStart = true;
		   ExtIndex =0;
	   }

	   if(ExtensionStart)
	   {
		   Extension[ExtIndex] = c;
		   ExtIndex++;
	   }

	 }

	if( CheckChar(Extension,".obj",ExtIndex))
		return TYPE_OBJ;
	return 0;

}
CModel::CModel(HWND _hwnd)
{
	ImporterOBJ = new ObjImporter();
}


CModel::~CModel(void)
{
}



void CModel::LoadObject(string FileName, WhirlVertex **  WhirlVertexOut,int ** outindex,int Type)
{
	if(GetExtension(FileName) == TYPE_OBJ)
	{
	  ImporterOBJ->LoadFileCounts(FileName);
	 ImporterOBJ->Import(FileName, WhirlVertexOut,outindex);
	}



}



