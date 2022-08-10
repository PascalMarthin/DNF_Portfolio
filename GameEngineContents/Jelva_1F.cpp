#include "PreCompile.h"
#include "Jelva_1F.h"
#include "Jelva1F_BackGround.h"

Jelva_1F::Jelva_1F() 
	: Texture_Jelva1F(nullptr)
	, Player_Fighter(nullptr)
{
}

Jelva_1F::~Jelva_1F() 
{
}

void Jelva_1F::Start()
{
	Texture_Jelva1F = CreateActor<Jelva1F_BackGround>();

	float Hight = Texture_Jelva1F->GetBackGroundTextureScale().y;
	float Width = Texture_Jelva1F->GetBackGroundTextureScale().x;
	Texture_Jelva1F->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });


	Player_Fighter = CreateActor<GamePlayCharacter>();
	Player_Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f, Hight - GameEngineWindow::GetScale().hy() - 200.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	GetMainCameraActor()->GetTransform().SetWorldMove(Player_Fighter->GetTransform().GetLocalPosition());

}

void Jelva_1F::Update(float _DeltaTime)
{
	GetMainCameraActor()->GetTransform().SetWorldPosition(Player_Fighter->GetTransform().GetLocalPosition());
}
