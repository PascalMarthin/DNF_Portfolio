#include "PreCompile.h"
#include "Jelva_1F.h"
#include "Jelva1F_BackGround.h"
#include "MoveManager.h"

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

}

void Jelva_1F::Update(float _DeltaTime)
{
	if (!GetMainCameraActor()->IsFreeCameraMode())
	{
		float4 Pos = Player_Fighter->GetMoveManager()->GetMoveCollision()->GetTransform().GetLocalPosition();
		if (Pos.x <= 720.f )
		{
			Pos.x = 720.f;
		}
		else if (Pos.x >= 2658.f)
		{
			Pos.x = 2658.f;
		}

		if ((Pos.y <= -625.f ))
		{
			Pos.y = -625.f;
		}
		else if (Pos.y >= -460.f)
		{
			Pos.y = -460.f;
		}
		Pos.y += 100.f;

		GetMainCameraActor()->GetTransform().SetWorldPosition(Pos);
	}
}


void Jelva_1F::OnEvent()
{
	float Hight = Texture_Jelva1F->GetBackGroundTextureScale().y;
	if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Seria_Room)
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 1460.f , -490.f , Hight - 490.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}
	else if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva2F)
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 2050.f , -440.f , Hight - 440.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}
	else // Debug
	{
		Player_Fighter->GetTransform().SetLocalPosition({ 1780.f , -600.f , Hight - 600.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	}

	GetMainCameraActor()->GetTransform().SetWorldPosition(Player_Fighter->GetMoveManager()->GetMoveCollision()->GetTransform().GetLocalPosition());
	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Jelva1F);
}