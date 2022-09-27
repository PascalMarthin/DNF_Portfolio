#include "PreCompile.h"
#include "Luke_Stage1_BackGround.h"

Luke_Stage1_BackGround::Luke_Stage1_BackGround()
	: Texture_Black(nullptr)
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

	Texture_Black = CreateComponent<GameEngineTextureRenderer>();
	Texture_Black->SetTexture("BlackBackground.png");
	Texture_Black->GetTransform().SetLocalScale({ 2000, 2000 });
	Texture_Black->GetTransform().SetLocalPosition({ 0, 0, 1000 });
	Texture_Black->SetPivot(PIVOTMODE::LEFTTOP);
	Texture_Black->ChangeCamera(CAMERAORDER::Object);
	Texture_Black->GetPixelData().MulColor = { 0, 0, 0, 0 };

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

