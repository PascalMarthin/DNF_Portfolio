#include "PreCompile.h"
#include "Jelva2F_BackGround.h"

Jelva2F_BackGround::Jelva2F_BackGround() 
{
}

Jelva2F_BackGround::~Jelva2F_BackGround() 
{
}

void Jelva2F_BackGround::Start()
{
	//GetTransform().SetLocalScale({ MonitorX , MonitorY });
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->CreateFrameAnimationFolder("Jelva02", FrameAnimation_DESC("Jelva_2F", 0.15f));
	Texture_BackGround->ChangeFrameAnimation("Jelva02");
	Texture_BackGround->ScaleToTexture();
	//float indoex = Texture_BackGround->GetTransform().GetLocalScale().x;
	//Texture_BackGround->GetTransform().SetLocalPosition({ -(Texture_BackGround->GetTransform().GetLocalScale().x * MonitorX) / 2.f,  (Texture_BackGround->GetTransform().GetLocalScale().y * MonitorY) / 2.f });
	Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);


	Texture_MapCollision = GameEngineTexture::Find("Jelva02F_Collision.png");

}
void Jelva2F_BackGround::Update(float _DeltaTime)
{

}