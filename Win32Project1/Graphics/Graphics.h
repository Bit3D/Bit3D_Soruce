#pragma once
#ifndef GRAPHICS_H // if not defined graphics.h
#define GRAPHICS_H

#include"../Includes.h"
#include"Lighting.h"
using namespace std;

#pragma region Base Classes and Structures

// Color field
struct ColorField
{
	D3DXCOLOR Color;
	string FieldName;
};

// Texture information
struct Texture
{
	ID3D11Texture2D * Tex2D;
	ID3D11ShaderResourceView  * SRV2D;
	string Name;
};


// Vertex information
struct WhirlVertex
{
	D3DXVECTOR3 Pos;
	D3DXVECTOR3  Normal;
	D3DXVECTOR2 UV;
	int MaterialID;
	int TextureID;
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

struct WMaterial
{
	Shader shader;
	vector<Texture> Textures;
	vector<ColorField> Colors;

};

struct WMeshInstance 
{
	XMMATRIX World;
	INT TexId;
	short InsId; // Instance Id : its id to the mesh in array of meshes

};

struct Cbuffer_perFrame
{
	XMMATRIX ViewProject;
	XMMATRIX World;
	XMMATRIX WorldINV;

};


#pragma endregion

// Class attached to each Wactor
class WMesh
{
private:
		ID3D11Buffer * VertexBuffer; // vertex Buffer
	    ID3D11Buffer * IndexBuffer;// Index Buffer
		ID3D11Buffer * InstanceBuffer; 

public :
	WMesh();

	vector<WMeshInstance> Instances;
	

	short MaxInstanceCount;
	short CurrentInstances; // Number of isntances in the list 
	short IUnstanceId; // Psecifc Id so that  can be used to access it whenever necessary 
	
	vector<WhirlVertex> vertices;
	vector<int> Indices;

	ID3D11InputLayout * InputLayout; // Inputlasyout describing the toipology
	WMaterial Material;


	// Set this to true if not uniques
	bool IsUnique; 
	bool Rigid;
	

	void Destroy(); // Call only this if you want to destroy whole material and all its contents
	void Destroy(WMaterial&);
	void Destroy(Shader&);

	// Initialize
	void Init();

	// Draw Methods
	void Draw();
	void Draw(XMMATRIX& world);


};

// Handles Instancing and drawing effectively
class WMeshManager
{
public:
	// Mesh Data
	vector<WMesh*> Meshes;
	

	void Init();

	// Draw Methods
	void Draw(WMesh);
	

	// Add Instance Method
	void AddInstance(int);
	void AddInstance(WMesh*);
};


//--------Graphics 
class Graphics
{
private:
	// function prototypes
	void InitPipeline();
	void InitShaders(string[]);
	void SetShader(Shader );
	
	vector<ID3D11DeviceContext*> Devcons;
	vector<ID3D11Device*> Devices;

	ID3D11InputLayout * INPUT_LAYOUT;
	
	


public:
	map<HWND,ID3D11Device*> devices;
	
	Graphics(ID3D11DeviceContext*);
	virtual ~Graphics(void);
	void Init();
	void RenderToTexture();
	
	// Destroy Functions
	 void Destroy();
	
	// Variables
};












#endif // GRAPHICS_H