#include "PreCompile.h"
#include "MoveManager.h"
#include "Jelva_2F.h"
#include "Merill_pioneer_NPC.h"
#include "Hunter_pon_NPC.h"
#include "Ajelia_NPC.h"

Jelva_2F::Jelva_2F() 
	: Texture_Jelva2F(nullptr)
	, Player_Character(nullptr)
	, NPC_Merill_pioneer(nullptr)
{
}

Jelva_2F::~Jelva_2F() 
{
}

void Jelva_2F::Start()
{
	GamePlayLevelTemplate::Start();
	Texture_Jelva2F = CreateActor<Jelva2F_BackGround>();

	float Hight = Texture_Jelva2F->GetBackGroundTextureScale().y;
	float Width = Texture_Jelva2F->GetBackGroundTextureScale().x;
	Texture_Jelva2F->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });

	NPC_Merill_pioneer = CreateActor<Merill_pioneer_NPC>();
	NPC_Merill_pioneer->GetTransform().SetLocalPosition({800, -400, -400});

	
	NPC_Hunter_pon = CreateActor<Hunter_pon_NPC>();
	NPC_Hunter_pon->GetTransform().SetLocalPosition({ 1200, -430, -430 });

	NPC_Ajelia = CreateActor<Ajelia_NPC>();
	NPC_Ajelia->GetTransform().SetLocalPosition({ 2130, -480, -480 });
	

	
	Player_Character = CreateActor<GamePlayCharacter>();


	Player_Character->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f, Hight - GameEngineWindow::GetScale().hy() - 200.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	GetMainCameraActor()->GetTransform().SetWorldMove(Player_Character->GetTransform().GetLocalPosition());



}

void Jelva_2F::Update(float _DeltaTime)
{

	if (!GetMainCameraActor()->IsFreeCameraMode())
	{
		float4 Pos = Player_Character->GetMoveManager()->GetMoveCollision()->GetTransform().GetWorldPosition();
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


void Jelva_2F::LevelStartEvent()
{
	float Hight = Texture_Jelva2F->GetBackGroundTextureScale().y;
	if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva1F)
	{
		Player_Character->GetTransform().SetLocalPosition({ 1200.f , -680.f , -680.f });
	}
	else if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva2F_01)
	{
		Player_Character->GetTransform().SetLocalPosition({ 2216.f  , -600.f , -600.f });
	}
	else// Debug
	{
		SetPlayer("jelva.ogg");
		Player_Character->GetTransform().SetLocalPosition({ 1500.f  , -500.f , -500.f });
	}

	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Jelva2F);
}