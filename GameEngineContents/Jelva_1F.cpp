#include "PreCompile.h"
#include "Jelva_1F.h"
#include "Jelva1F_BackGround.h"
#include "MoveManager.h"

Jelva_1F::Jelva_1F() 
	: Texture_Jelva1F(nullptr)
	, Player_Character(nullptr)
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


	Player_Character = CreateActor<GamePlayCharacter>();

}

void Jelva_1F::Update(float _DeltaTime)
{
	if (!GetMainCameraActor()->IsFreeCameraMode())
	{
		float4 Pos = Player_Character->GetMoveManager()->GetMoveCollision()->GetTransform().GetWorldPosition();
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
		Player_Character->GetTransform().SetLocalPosition({ 1460.f , -490.f , Hight });
	}
	else if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva2F)
	{
		Player_Character->GetTransform().SetLocalPosition({ 2050.f , -440.f , Hight });
	}
	else // Debug
	{
		Player_Character->GetTransform().SetLocalPosition({ 1780.f , -600.f , Hight });
	}

	GetMainCameraActor()->GetTransform().SetWorldPosition(Player_Character->GetMoveManager()->GetMoveCollision()->GetTransform().GetLocalPosition());
	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Jelva1F);
}