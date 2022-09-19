#include "PreCompile.h"
#include <GameEngineCore/GEngine.h>
#include "Jelva2F01_BackGround.h"
#include "DummyActor.h"
#include "GamePlayEnum.h"
#include "DungeonSelect.h"

Jelva2F01_BackGround::Jelva2F01_BackGround() 
	: Collision_Jelva2F_Door(nullptr)
	, Collision_LukeRaid_Door(nullptr)
{
}

Jelva2F01_BackGround::~Jelva2F01_BackGround() 
{
}


void Jelva2F01_BackGround::Start()
{
		
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->CreateFrameAnimationFolder("Jelva0201", FrameAnimation_DESC("Jelva_2F_1", 0.15f));
	Texture_BackGround->ChangeFrameAnimation("Jelva0201");
	Texture_BackGround->ScaleToTexture();
	//float indoex = Texture_BackGround->GetTransform().GetLocalScale().x;
	//Texture_BackGround->GetTransform().SetLocalPosition({ -(Texture_BackGround->GetTransform().GetLocalScale().x * MonitorX) / 2.f,  (Texture_BackGround->GetTransform().GetLocalScale().y * MonitorY) / 2.f });
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);


	Texture_MapCollision = GameEngineTexture::Find("Jelva02F01_Collision.png");

	float Hight = GetBackGroundTextureScale().y;

	Collision_Jelva2F_Door = GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>();
	Collision_Jelva2F_Door->GetTransform().SetLocalScale({ 80.f, 300.f , 300.f });
	Collision_Jelva2F_Door->GetTransform().SetWorldPosition({ 40.f, -750.f, Hight - 750.f });
	Collision_Jelva2F_Door->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_Jelva2F_Door->SetDebugSetting(CollisionType::CT_AABB, float4::WHITE);

	Collision_LukeRaid_Door = GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>();
	Collision_LukeRaid_Door->GetTransform().SetLocalScale({ 80.f, 300.f , 300.f });
	Collision_LukeRaid_Door->GetTransform().SetWorldPosition({ 1620.f, -760, Hight - 760 });
	Collision_LukeRaid_Door->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_LukeRaid_Door->SetDebugSetting(CollisionType::CT_AABB, float4::WHITE);

	SetBackGroundZOrder();


}
void Jelva2F01_BackGround::Update(float _DeltaTime)
{
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

	if (Collision_LukeRaid_Door->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player_Floor, CollisionType::CT_AABB,
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
		DungeonSelect::SetWorldDungeon(WorldDungeon::Luke);
		GEngine::ChangeLevel("DungeonSelect");
	}
}