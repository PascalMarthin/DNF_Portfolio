#include "PreCompile.h"
#include "Luke_Stage1_BackGround.h"

Luke_Stage1_BackGround::Luke_Stage1_BackGround() 
{
}

Luke_Stage1_BackGround::~Luke_Stage1_BackGround() 
{
}

void Luke_Stage1_BackGround::Start()
{
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->SetTexture("Luke_Raid_Stage1.png");
	Texture_BackGround->ScaleToTexture();
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);

	Texture_MapCollision = GameEngineTexture::Find("Luke_Raid_Stage1_Collision.png");
}

void Luke_Stage1_BackGround::Update(float _DeltaTime)
{

}

