#pragma once
#include"Includes.h"

//--- Materail Information----
struct Texture2d_NP  // Notpackable
{
	ID3D11Texture2D * Texture2d;
	ID3D11ShaderResourceView * ResourceView;
	int Slot;

};

struct Material_NP // Notpackable
{
	XMFLOAT4 Diffuse;
	XMFLOAT4 Specular;
	
};

// Vertex information
struct WhirlVertex
{
	D3DXVECTOR3 Pos;
	D3DXVECTOR3  Normal;
	D3DXVECTOR2 UV;
//	D3DXVECTOR2 UV2;
	
};

// Shader imformationm
struct Shader
{
	ID3D11VertexShader * VertexShader;
	ID3D11PixelShader * PixelShader;
	ID3D11GeometryShader * GeometryShader;
	ID3D11HullShader * HullShader;
	ID3D11DomainShader * DomainShader;
	ID3D11ComputeShader * ComputeShader;

};

//--------Graphics Class-------------------------------- 
class Graphics
{
public:
	Graphics(void);
	virtual ~Graphics(void);
};

