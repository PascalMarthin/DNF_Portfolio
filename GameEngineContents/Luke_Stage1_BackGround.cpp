#include "PreCompile.h"
#include "Luke_Stage1_BackGround.h"
#include "Luke_Stage1.h"
#include <GameEngineCore/GEngine.h>

Luke_Stage1_BackGround::Luke_Stage1_BackGround()
	: Texture_Stage2_Door(nullptr)
	, Texture_Stage2_Door_Close(nullptr)
{
}

Luke_Stage1_BackGround::~Luke_Stage1_BackGround() 
{
}

void Luke_Stage1_BackGround::Start()
{
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->SetTexture("Luke_Raid_Stage1.png");
	Texture_BackGround->GetTransform().SetLocalPosition({0, 0, static_cast<float>(ZSortOrder::BackGround) });
	
	Texture_BackGround->ScaleToTexture();
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);

	Texture_MapCollision = GameEngineTexture::Find("Luke_Raid_Stage1_Collision.png");

	Texture_Stage2_Door = CreateComponent<GameEngineTextureRenderer>();
	Texture_Stage2_Door->SetTexture("pathGate_Open.png");
	Texture_Stage2_Door->ScaleToTexture();
	Texture_Stage2_Door->GetTransform().SetLocalPosition({ 1870, -600, -600 });

	Texture_Stage2_Door_Close = CreateComponent<GameEngineTextureRenderer>();
	Texture_Stage2_Door_Close->SetTexture("pathGate_Close.png");
	Texture_Stage2_Door_Close->ScaleToTexture();
	Texture_Stage2_Door_Close->GetTransform().SetLocalPosition({ 1870, -600, -600 });

	Collision_Stage2_Door = CreateComponent<GameEngineCollision>();
	Collision_Stage2_Door->GetTransform().SetLocalPosition({ 1870, -600, -600 });
	Collision_Stage2_Door->GetTransform().SetLocalScale({100, 200, 1000});


	FadeInOut = CreateComponent<GameEngineUIRenderer>();
	FadeInOut->GetTransform().SetLocalPosition({ 0,0,-100 });
	FadeInOut->GetTransform().SetLocalScale({ 2000,1000,1 });
	FadeInOut->GetPixelData().MulColor = { 0,0,0,0 };

	//SetBackGroundZOrder();
}

void Luke_Stage1_BackGround::Update(float _DeltaTime)
{
	if (GetLevel<Luke_Stage1>()->IsAllMonsterDie())
	{
		Texture_Stage2_Door_Close->Off();
		if (Collision_Stage2_Door->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB))
		{
			MoveMap = true;
			IntotheMap = false;
			
		}
	}
	else
	{
		Texture_Stage2_Door_Close->On();
	}

	if (MoveMap == true && FadeInOut->GetPixelData().MulColor.a < 1.f)
	{
		FadeInOut->GetPixelData().MulColor.a += _DeltaTime * 5.f;
		if (FadeInOut->GetPixelData().MulColor.a > 1.f)
		{
			FadeInOut->GetPixelData().MulColor.a = 1.f;
			GEngine::ChangeLevel("Luke_Stage2");
		}
	}

	if (IntotheMap == true && FadeInOut->GetPixelData().MulColor.a > 0)
	{
		FadeInOut->GetPixelData().MulColor.a -= _DeltaTime * 5.f;		
		if (FadeInOut->GetPixelData().MulColor.a < 0)
		{
			FadeInOut->GetPixelData().MulColor.a = 0;
			IntotheMap = false;
		}
	}
}

void Luke_Stage1_BackGround::LevelStartEvent()
{
	FadeInOut->GetPixelData().MulColor.a = 1.f;
	IntotheMap = true;
}
void Luke_Stage1_BackGround::LevelEndEvent()
{
	MoveMap = false;
	IntotheMap = false;
}

