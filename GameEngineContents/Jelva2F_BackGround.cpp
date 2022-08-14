#include "PreCompile.h"
#include <GameEngineCore/GEngine.h>
#include "Jelva2F_BackGround.h"
#include "DummyActor.h"
#include "GamePlayEnum.h"

Jelva2F_BackGround::Jelva2F_BackGround() 
	: Collision_Jelva1F_Door(nullptr)
	, Collision_Jelva2F_01_Door(nullptr)
{
}

Jelva2F_BackGround::~Jelva2F_BackGround() 
{
}

void Jelva2F_BackGround::Start()
{
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->CreateFrameAnimationFolder("Jelva02", FrameAnimation_DESC("Jelva_2F", 0.15f));
	Texture_BackGround->ChangeFrameAnimation("Jelva02");
	Texture_BackGround->ScaleToTexture();
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);


	Texture_MapCollision = GameEngineTexture::Find("Jelva02F_Collision.png");

	float Hight = GetBackGroundTextureScale().y;

	Collision_Jelva1F_Door = GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>();
	Collision_Jelva1F_Door->GetTransform().SetLocalScale({ 200.f, 80.f , 50.f });
	Collision_Jelva1F_Door->GetTransform().SetWorldPosition({ 1200.f, -780.f, Hight - 780.f });
	Collision_Jelva1F_Door->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_Jelva1F_Door->SetDebugSetting(CollisionType::CT_AABB, float4::WHITE);

	Collision_Jelva2F_01_Door = GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>();
	Collision_Jelva2F_01_Door->GetTransform().SetLocalScale({ 80.f, 300.f , 300.f });
	Collision_Jelva2F_01_Door->GetTransform().SetWorldPosition({ 2378, -700, Hight - 700 });
	Collision_Jelva2F_01_Door->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_Jelva2F_01_Door->SetDebugSetting(CollisionType::CT_AABB, float4::WHITE);

	SetBackGroundZOrder();
}
void Jelva2F_BackGround::Update(float _DeltaTime)
{
	if (Collision_Jelva1F_Door->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player_Floor, CollisionType::CT_AABB,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Character_Map_Collision")
			{
				return true;
			}
			else
			{
				return false;
			}
		}))
	{
		GEngine::ChangeLevel("Jelva_1F");
	}

	if (Collision_Jelva2F_01_Door->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player_Floor, CollisionType::CT_AABB,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Character_Map_Collision")
			{
				return true;
			}
			else
			{
				return false;
			}
		}))
	{
		GEngine::ChangeLevel("Jelva_2F01");
	}
}