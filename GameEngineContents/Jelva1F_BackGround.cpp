#include "PreCompile.h"
#include "Jelva1F_BackGround.h"
#include "GamePlayEnum.h"

Jelva1F_BackGround::Jelva1F_BackGround() 
	: Collision_Jelva1F_Door(nullptr)
	, Collision_Jelva2F_01_Door(nullptr)
{
}

Jelva1F_BackGround::~Jelva1F_BackGround() 
{
}

void Jelva1F_BackGround::Start()
{
	//GetTransform().SetLocalScale({ MonitorX , MonitorY });
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->CreateFrameAnimationFolder("Jelva01", FrameAnimation_DESC("Jelva_1F", 0.15f));
	Texture_BackGround->ChangeFrameAnimation("Jelva01");
	Texture_BackGround->ScaleToTexture();
	//float indoex = Texture_BackGround->GetTransform().GetLocalScale().x;
	//Texture_BackGround->GetTransform().SetLocalPosition({ -(Texture_BackGround->GetTransform().GetLocalScale().x * MonitorX) / 2.f,  (Texture_BackGround->GetTransform().GetLocalScale().y * MonitorY) / 2.f });
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);


	Texture_MapCollision = GameEngineTexture::Find("Jelva01.png");
	

	Collision_Jelva1F_Door = CreateComponent<GameEngineCollision>();
	Collision_Jelva1F_Door->DetachObject();
	Collision_Jelva1F_Door->GetTransform().SetLocalScale({ 700.f, 100.f , 50.f });
	Collision_Jelva1F_Door->GetTransform().SetWorldPosition({ 640, -720, 0 });
	Collision_Jelva1F_Door->ChangeOrder(CollisionOrder::ChangeMap);
	Collision_Jelva1F_Door->SetDebugSetting(CollisionType::CT_AABB, float4::GREEN);
}
void Jelva1F_BackGround::Update(float _DeltaTime)
{

}