#include "PreCompile.h"
#include "Jelva1F_BackGround.h"
#include "DummyActor.h"
#include <GameEngineCore/GEngine.h>
#include "GamePlayEnum.h"

Jelva1F_BackGround::Jelva1F_BackGround() 
	: Collision_SeriaRoom_Door(nullptr)
	, Collision_Jelva2F_Door(nullptr)
{
}

Jelva1F_BackGround::~Jelva1F_BackGround() 
{
}

void Jelva1F_BackGround::Start()
{
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->CreateFrameAnimationFolder("Jelva01", FrameAnimation_DESC("Jelva_1F", 0.15f));
	Texture_BackGround->ChangeFrameAnimation("Jelva01");
	Texture_BackGround->ScaleToTexture();
	//float indoex = Texture_BackGround->GetTransform().GetLocalScale().x;
	//Texture_BackGround->GetTransform().SetLocalPosition({ -(Texture_BackGround->GetTransform().GetLocalScale().x * MonitorX) / 2.f,  (Texture_BackGround->GetTransform().GetLocalScale().y * MonitorY) / 2.f });
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);


	Texture_MapCollision = GameEngineTexture::Find("Jelva01F_Collision.png");
	
	float Hight = GetBackGroundTextureScale().y;


	Collision_SeriaRoom_Door = GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>();
	Collision_SeriaRoom_Door->GetTransform().SetLocalScale({ 300.f, 80.f , 500.f });
	Collision_SeriaRoom_Door->GetTransform().SetWorldPosition({ 1440.f, -450.f, Hight - 450.f });
	Collision_SeriaRoom_Door->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_SeriaRoom_Door->SetDebugSetting(CollisionType::CT_AABB, float4::GREEN);

	Collision_Jelva2F_Door = GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>();
	Collision_Jelva2F_Door->GetTransform().SetLocalScale({ 200.f, 80.f , 500.f });
	Collision_Jelva2F_Door->GetTransform().SetWorldPosition({ 2050, -375, Hight - 375 });
	Collision_Jelva2F_Door->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_Jelva2F_Door->SetDebugSetting(CollisionType::CT_AABB, float4::GREEN);

	SetBackGroundZOrder();
}
void Jelva1F_BackGround::Update(float _DeltaTime)
{
	if (Collision_SeriaRoom_Door->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player_Floor, CollisionType::CT_AABB,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Character_Map_Collision")
			{
				return CollisionReturn::Break;
			}
			else
			{
				return CollisionReturn::ContinueCheck;
			}
		}))
	{
		GEngine::ChangeLevel("SeriaRoom");
	}

		if (Collision_Jelva2F_Door->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player_Floor, CollisionType::CT_AABB,
			[](GameEngineCollision* _This, GameEngineCollision* _Other)
			{
				if (_Other->GetNameConstRef() == "Character_Map_Collision")
				{
					return CollisionReturn::Break;
				}
				else
				{
					return CollisionReturn::ContinueCheck;
				}
			}))
		{
			GEngine::ChangeLevel("Jelva_2F");
		}
}