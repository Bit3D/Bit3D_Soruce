// Gaurds
#ifndef ACTOR_H
#define ACTOR_H

#include"../Includes.h"
#include"../Graphics/Graphics.h"



class Actor
{
  
private:
	PRS tempPrs;
public :
	PRS prs; // Postion Rotation and scale


	// For Animation 

	// For Rendering
	WMesh * Mesh;
	
	XMMATRIX World; // Final World Matrix 

	XMMATRIX PosMatrix; // Position Matrix
	XMMATRIX RotMatrix; // Rotation matrix
	XMMATRIX ScalMatrix; // Scale matrix

	// For Scripts and meshes
	vector<void*> Classes;

	bool Static;

	void Update(float); // Update during gmaeplay
	void Start();
	void EditorUpdate(); // Upate during editor
	void Init();




};

#endif