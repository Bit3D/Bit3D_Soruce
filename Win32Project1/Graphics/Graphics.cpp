#include "Graphics.h"


Graphics::Graphics(ID3D11DeviceContext* devCon)
{
	
}


Graphics::~Graphics(void)
{
}

void Graphics::InitPipeline()
{
	D3D11_INPUT_ELEMENT_DESC inputDesc[8];

	SecureZeroMemory(&inputDesc,sizeof(inputDesc));

	inputDesc[0].SemanticName = "POSITION";
	inputDesc[0].SemanticIndex = 0;
	inputDesc[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	inputDesc[0].InstanceDataStepRate = D3D11_INPUT_PER_VERTEX_DATA;
	inputDesc[0].AlignedByteOffset = 0;

	inputDesc[1].SemanticName = "NORMAL";
	inputDesc[1].SemanticIndex = 0;
	inputDesc[1].InstanceDataStepRate = D3D11_INPUT_PER_VERTEX_DATA;
	inputDesc[1].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	inputDesc[1].AlignedByteOffset = 12;

	inputDesc[2].SemanticName = "COLOR";
	inputDesc[2].SemanticIndex = 0;
	inputDesc[2].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	inputDesc[2].InstanceDataStepRate = D3D10_INPUT_PER_VERTEX_DATA;
	inputDesc[2].AlignedByteOffset = 24;

	inputDesc[3].SemanticName = "TANGENT";
	inputDesc[3].SemanticIndex = 0;
	inputDesc[3].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	inputDesc[3].InstanceDataStepRate = D3D10_INPUT_PER_VERTEX_DATA;
	inputDesc[3].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;

	// instancing
	
	inputDesc[4].SemanticName = "WORLD";
	inputDesc[4].SemanticIndex =0 ;
	inputDesc[4].InputSlot = 1;
	inputDesc[4].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	inputDesc[4].InstanceDataStepRate = 1;
	inputDesc[4].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputDesc[4].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;

	inputDesc[5].SemanticName = "WORLD";
	inputDesc[5].SemanticIndex =1 ;
	inputDesc[5].InputSlot = 1;
	inputDesc[5].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	inputDesc[5].InstanceDataStepRate = 1;
	inputDesc[5].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputDesc[5].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
			  
	inputDesc[6].SemanticName = "WORLD";
	inputDesc[6].SemanticIndex =2 ;
	inputDesc[6].InputSlot = 1;
	inputDesc[6].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	inputDesc[6].InstanceDataStepRate = 1;
	inputDesc[6].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputDesc[6].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;

	inputDesc[7].SemanticName = "WORLD";
	inputDesc[7].SemanticIndex =3 ;
	inputDesc[7].InputSlot = 1;
	inputDesc[7].InputSlotClass = D3D11_INPUT_PER_INSTANCE_DATA;
	inputDesc[7].InstanceDataStepRate = 1;
	inputDesc[7].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	inputDesc[7].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;







}



void Graphics::SetShader(Shader shader)
{



}

#pragma region Meshes
void WMesh::Destroy()
{
  
	RELEASE(VertexBuffer);
	RELEASE(IndexBuffer);
	RELEASE(InstanceBuffer);
	RELEASE(InputLayout);



	vertices.empty();
	Instances.empty();

	Destroy(Material.shader);
	Destroy(Material);
	
	
}

void WMesh::Destroy(WMaterial& mat)
{
	mat.Colors.empty();
	mat.Textures.empty();

}
void WMesh::Destroy(Shader& shader)
{

	RELEASE(shader.ComputeShader);
	RELEASE(shader.PixelShader);
	RELEASE(shader.DomainShader);
	RELEASE(shader.GeometryShader);
	RELEASE(shader.HullShader);
	RELEASE(shader.VertexShader);
	

}
#pragma endregion