#include "ObjImporter.h"


ObjImporter::~ObjImporter(void)
{
}

void ObjImporter::LoadFileCounts(string fileName)
{
	ifstream fin;
	char Input ;
	SecureZeroMemory(&fin,sizeof(fin));

	fin.open(fileName);

	if(fin.fail())
	{
	//	MessageBox(hwnd,L"Could not find the file",L"File not found",0);
	    return;
	}

	fin.get(Input);

	while (!fin.eof())
	{
		if(Input == 'v')
		{
			fin.get(Input); // Get the next character

			if(Input=='t')
				UVcount++;
			if(Input == ' ') VertexCount++;
			if(Input == 'n') NormalCount++;
		
		}

		if (Input == 'f')
		{
			fin.get(Input);

			if(Input == ' ')
				TriCount++;
		}

			while(Input != '\n')
			{
				fin.get(Input);
			}
		
		fin.get(Input);
	}

	fin.close();


	
}

void ObjImporter::Import(string fileName, WhirlVertex ** pVertex,int ** pIndex)
{
	ifstream fin;
	char Input ,Input2;
	 WhirlVertex * vertices;
	int * indices,Vindex,IIndex,TIndex,NIndex =0,FIndex = 0;

	Vindex = IIndex = TIndex = 0;



	// Allocate Memory
	SecureZeroMemory(&fin,sizeof(fin));
	vertices = new  WhirlVertex[VertexCount];
	indices = new int[TriCount * 3];

	fin.open(fileName);

	if(fin.fail())
	{
		//MessageBox(hwnd,L"Could not find the file",L"File not found",0);
	    return;
	}

	fin.get(Input);

		while (!fin.eof())
		{

			if(Input == 'v')
			{
				fin.get(Input); // Get next char

				// Load Vertex positions
				if(Input == ' ')
				{
					if(Vindex <= VertexCount)
				   {
					   fin >> vertices[Vindex].Pos.x >> vertices[Vindex].Pos.y >> vertices[Vindex].Pos.z;					
					}
					
					Vindex++;
				}

				//Load UV Coordinate
				if(Input == 't')
			    {
				   if(TIndex <= UVcount)
				  {
					  fin >> vertices[TIndex].UV.x >>  vertices[TIndex].UV.y >> Input2;

				  }

				   TIndex++;
				}
			
				// Load Normals
				if(Input == 'n')
				{
					if(NIndex < NormalCount)
				  {

					  fin >> vertices[TIndex].Normal.x >> vertices[TIndex].Normal.y >> vertices[TIndex].Normal.z;
				  }
					NIndex++;
				}
			}


			if(Input == 'f')
			{
				
				fin.get(Input);
				if(Input == ' ')
				{
					// Load indices
					if(IIndex <= TriCount *3)
				  {
					  fin >> indices[IIndex] >> Input2 >> Input2 >> Input2 >> Input2; // V/T/N 
					  IIndex++; // Second index

					  fin >> indices[IIndex] >> Input2 >> Input2 >> Input2 >> Input2;
					  IIndex++; // third index

					  fin >> indices[IIndex] >> Input2 >> Input2 >> Input2 >> Input2;
				  }

					
				}
			}
		
			while(Input != '\n')
			{
				fin.get(Input);
			}
			fin.get(Input);
		}

		fin.close();

		*pVertex = vertices;
		*pIndex = indices;

}