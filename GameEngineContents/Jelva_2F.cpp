#include "PreCompile.h"
#include "MoveManager.h"
#include "Jelva_2F.h"

Jelva_2F::Jelva_2F() 
	: Texture_Jelva2F(nullptr)
	, Player_Fighter(nullptr)
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

	if (!GetMainCameraActor()->IsFreeCameraMode())
	{
		float4 Pos = Player_Fighter->GetMoveManager()->GetMoveCollision()->GetTransform().GetLocalPosition();
		if (Pos.x <= 793.f)
		{
			Pos.x = 793.f;
		}
		else if (Pos.x >= 1771.f)
		{
			Pos.x = 1771.f;
		}

		if ((Pos.y <= -621.f))
		{
			Pos.y = -621.f;
		}
		else if (Pos.y >= -460.f)
		{
			Pos.y = -460.f;
		}
		Pos.y += 100.f;

		GetMainCameraActor()->GetTransform().SetWorldPosition(Pos);
	}
}


void Jelva_2F::OnEvent()
{
	float Hight = Texture_Jelva2F->GetBackGroundTextureScale().y;
	if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva1F)
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 1200.f , -680.f , Hight - 680.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}
	else if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva2F_01)
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 2216.f  , -600.f , Hight - 600.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}
	else// Debug
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 1500.f  , -500.f , Hight - 500.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}

	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Jelva2F);
}