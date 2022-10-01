#include "PreCompile.h"
#include "Luke_Stage1_BackGround.h"

Luke_Stage1_BackGround::Luke_Stage1_BackGround()
	: Texture_Stage2_Door(nullptr)
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

	Texture_Stage2_Door = CreateComponent<GameEngineTextureRenderer>();
	Texture_Stage2_Door->SetTexture("pathGate_Close.png");
	Texture_Stage2_Door->ScaleToTexture();
	Texture_Stage2_Door->GetTransform().SetLocalPosition({ 2000, -600, -600 });

	SetBackGroundZOrder();
}

void Luke_Stage1_BackGround::Update(float _DeltaTime)
{

}

void Luke_Stage1_BackGround::LevelStartEvent()
{

}
void Luke_Stage1_BackGround::LevelEndEvent()
{

}

