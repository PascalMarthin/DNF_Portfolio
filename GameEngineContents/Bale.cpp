#include "PreCompile.h"
#include "Bale.h"
#include "GamePlayEnum.h"
//#include <GameEngineCore/>

Bale::Bale() 
{
}

Bale::~Bale() 
{
}

void Bale::Start()
{
	Texture_Monster = CreateComponent<GameEngineTextureRenderer>();
	Texture_Monster->CreateFrameAnimationFolder("Bale_Standing", FrameAnimation_DESC("Bale", 0, 5, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Walk", FrameAnimation_DESC("Bale", 6, 13, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Sting", FrameAnimation_DESC("Bale", 14, 23, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hit1", FrameAnimation_DESC("Bale", 24, 24, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hit2", FrameAnimation_DESC("Bale", 25, 25, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Down", FrameAnimation_DESC("Bale", 26, 26, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Sit", FrameAnimation_DESC("Bale", 27, 27, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Stamping", FrameAnimation_DESC("Bale", 28, 32, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Grap", FrameAnimation_DESC("Bale", 33, 34, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hold", FrameAnimation_DESC("Bale", 34, 34, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Press", FrameAnimation_DESC("Bale", 35, 40, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_RunReady", FrameAnimation_DESC("Bale", 41, 42, 0.2f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Running", FrameAnimation_DESC("Bale", 43, 44, 0.1f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_RunEnd", FrameAnimation_DESC("Bale", 45, 46, 0.1f, false));
	Texture_Monster->GetTransform().SetLocalPosition({ 72, 12, 1 }); // Áß¾Ó ±âÁØ
	Texture_Monster->GetTransform().SetLocalScale({454, 340});
	Texture_Monster->ChangeFrameAnimation("Bale_Standing");

	Collision_HitBody = CreateComponent<GameEngineCollision>();
	//Collision_HitBody->GetTransform().SetLocalPosition({0, 0, -1});
	Collision_HitBody->GetTransform().SetLocalScale({ 80, 150, 30 });
	Collision_HitBody->ChangeOrder(CollisionOrder::Monster);
	Collision_HitBody->SetDebugSetting(CollisionType::CT_AABB, float4::BLACK);

}

void Bale::Update(float _DeltaTime)
{
	GameEngineDebug::OutPutString(std::to_string(GetTransform().GetLocalPosition().z));
}

void Bale::CreateFSMForBale()
{
	//FSMManager.CreateStateMember();
}

