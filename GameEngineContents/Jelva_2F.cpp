#include "PreCompile.h"
#include "Jelva_2F.h"

Jelva_2F::Jelva_2F() 
{
}

Jelva_2F::~Jelva_2F() 
{
}

void Jelva_2F::Start()
{
	Texture_Jelva2F = CreateActor<Jelva2F_BackGround>();

	float Hight = Texture_Jelva2F->GetBackGroundTextureScale().y;
	float Width = Texture_Jelva2F->GetBackGroundTextureScale().x;
	Texture_Jelva2F->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });


	Player_Fighter = CreateActor<GamePlayCharacter>();
	Player_Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f, Hight - GameEngineWindow::GetScale().hy() - 200.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	GetMainCameraActor()->GetTransform().SetWorldMove(Player_Fighter->GetTransform().GetLocalPosition());

}

void Jelva_2F::Update(float _DeltaTime)
{
	GetMainCameraActor()->GetTransform().SetWorldPosition(Player_Fighter->GetTransform().GetLocalPosition());
}