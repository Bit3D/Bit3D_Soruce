#ifndef _COMMON_H_
#define _COMMON_H_

#include<vector>

#include<d3d11.h>
#include<xnamath.h>

using namespace std;
static bool CheckChar(char * A,char * B,int MaxSize)
{
	int Size = 0;
	for(int i=0; i < MaxSize;++i)
	{
	  if(A[i] == B[i])
	  {
		  Size++;
	  }
	}

	if(Size == MaxSize)
	{
		return true;
	}else{
	 return false;
	}
}




struct PRS
{
	XMFLOAT3 Position;
    XMFLOAT3 Rotation;
	XMFLOAT3 Scale;

	// Transformation
	XMFLOAT3 Forward;
	XMFLOAT3 Right;
	XMFLOAT3 Top;
	XMVECTOR QuatRot;


	
};
#pragma region Base

 class BaseClass
{
public:
	virtual void Update(float);
	virtual void Start();
	virtual void Destroy();

};
#pragma endregion


struct UIDefinition
{
	void * AdressVar;
	int Type;
	string Name;
};


struct ScrtipBinder // Bind scripts
{

	vector<UIDefinition> UIDesgin;


};

struct ClassBinder // Bind base class
{
  vector<UIDefinition> UIDesgin;
  BaseClass * Class;
};


// Operators
static bool operator==(const XMFLOAT3& a,const XMFLOAT3& b)
{
	if(a.x == b.x && a.y == b.y && a.z == b.z )	
		return true ;
	else
		return false;
}

static bool operator==(const XMFLOAT4& a,const XMFLOAT4& b)
{
	if(a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w)
		return true;
	else
		return false;
}

static bool operator!=(const XMFLOAT3& a,const XMFLOAT3& b)
{
	if(a.x == b.x && a.y == b.y && a.z == b.z )	
		return false ;
	else
		return true;
}

static bool operator!=(const XMFLOAT4& a,const XMFLOAT4& b)
{
	if(a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w)
		return false;
	else
		return true;
}

static	bool operator==(const PRS& a,const PRS& b)
{
	if(a.Position == b.Position && a.Rotation == b.Rotation && a.Scale == b.Scale)
		return true;
	else
		return false;
}   

static	bool operator!=(const PRS& a,const PRS& b)
{
	if(a.Position == b.Position && a.Rotation == b.Rotation && a.Scale == b.Scale)
		return false;
	else
		return true;
}   





#endif