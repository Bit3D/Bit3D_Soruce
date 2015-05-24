#include"Actor.h"

void Actor::Start()
{
	for(int i=0; i < Classes.size();++i)
	{
		
	}
}


void Actor::Init()
{
	MemSecure(World);
	MemSecure(PosMatrix);
	MemSecure(RotMatrix);
	MemSecure(ScalMatrix);
	
}
void Actor::EditorUpdate()
{


	if(prs != tempPrs)
	{
		
		 	//Update the Transformation
		if(prs.Position != tempPrs.Position)
			{
				PosMatrix = XMMatrixTranslation(prs.Position.x,prs.Position.y,prs.Position.z);
				tempPrs.Position = prs.Position;
		   }

		if(prs.Rotation != tempPrs.Rotation)
		 {
			 //RotMatrix = XMMatrixRotationQuaternion();
		 }

	}
}

