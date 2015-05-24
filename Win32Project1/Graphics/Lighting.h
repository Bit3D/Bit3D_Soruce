#include<D3DX11.h>


struct PointLight_NP // Notpackabe Point Light structure
{
 
 float Range;
 float Intensity;
 D3DXCOLOR color;

 bool CastShadow;
};

struct PointLight_P // Packable and can be sent to GPU
{
	XMVECTOR Position; // A -> Range,, RGB  pos
	XMVECTOR Color ;; // A-> Intensity, RGB Color
};


struct  DirectionalLight_NP
{
	float Intensity;
	D3DXCOLOR Color;

	bool CastShadow;

};

struct DirectionalLight_P
{

};

#pragma region Functions
#pragma endregion