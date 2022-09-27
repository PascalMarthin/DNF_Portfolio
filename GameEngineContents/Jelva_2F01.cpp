#include "PreCompile.h"
#include "Jelva_2F01.h"
#include "MoveManager.h"
#include "Jelva2F01_WaveBackGround.h"
#include "Roi_hartwig_NPC.h"

Jelva_2F01::Jelva_2F01() 
	: Texture_Jelva2F01(nullptr)
	, Player_Character(nullptr)
	, Texture_Jelva2F01_Wave(nullptr)
	, NPC_Roi_hartwig(nullptr)
{
}

Jelva_2F01::~Jelva_2F01() 
{
}


void Jelva_2F01::Start()
{
	GamePlayLevelTemplate::Start();
	Texture_Jelva2F01 = CreateActor<Jelva2F01_BackGround>();
	Texture_Jelva2F01_Wave = CreateActor<Jelva2F01_WaveBackGround>();

	float Hight = Texture_Jelva2F01->GetBackGroundTextureScale().y;
	float Width = Texture_Jelva2F01->GetBackGroundTextureScale().x;
	Texture_Jelva2F01->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });
	Texture_Jelva2F01_Wave->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });

	NPC_Roi_hartwig = CreateActor<Roi_hartwig_NPC>();
	NPC_Roi_hartwig->GetTransform().SetLocalPosition({ 400, -520, -520 });

	Player_Character = CreateActor<GamePlayCharacter>();
	//Player_Character->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f, Hight - GameEngineWindow::GetScale().hy() - 200.f + static_cast<float>(ZSortOrder::Character_Avata) - static_cast<float>(ZSortOrder::Character_Fighter_F) });
	GetMainCameraActor()->GetTransform().SetWorldMove(Player_Character->GetTransform().GetLocalPosition());

}

void Jelva_2F01::Update(float _DeltaTime)
{

	float4 Pos = Player_Character->GetMoveManager()->GetMoveCollision()->GetTransform().GetWorldPosition();
	if (!GetMainCameraActor()->IsFreeCameraMode())
	{
		if (Pos.x <= 642.f)
		{
			Pos.x = 642.f;
		}
		else if (Pos.x >= 1000.f)
		{
			Pos.x = 1000.f;
		}

		if ((Pos.y >= -609.f))
		{
			Pos.y = -609.f;
		}
		else if (Pos.y <= -747.f)
		{
			Pos.y = -747.f;
		}
		Pos.y += 100.f;

		GetMainCameraActor()->GetTransform().SetWorldPosition(Pos);
		GetAvataCamera()->GetTransform().SetWorldPosition(Pos);
		GetOutLineCamera()->GetTransform().SetWorldPosition(Pos);
		GetUIFontCamera()->GetTransform().SetWorldPosition(Pos);

	}
	{
		Pos.x = (Pos.x - 800.f) * 0.5f;
		Pos.y = 0.f;
		Pos.z = Texture_Jelva2F01_Wave->GetTransform().GetLocalPosition().z;
		Texture_Jelva2F01_Wave->GetTransform().SetLocalPosition(Pos);
	}

}


void Jelva_2F01::LevelStartEvent()
{
	float Hight = Texture_Jelva2F01->GetBackGroundTextureScale().y;
	if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::Jelva2F)
	{
		Player_Character->GetTransform().SetLocalPosition({ 200.f , -650.f , -650.f });
	}
	else if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::DungeonSelect)
	{
		Player_Character->GetTransform().SetLocalPosition({ 1530.f  , -750.f , -750.f });
	}
	else// Debug
	{
		BGM_Player.Stop();
		BGM_Player = GameEngineSound::SoundPlayControl("jelva.ogg");
		Player_Character->GetTransform().SetLocalPosition({ 1200.f  , -700.f , -700.f });
	}

	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Jelva2F_01);
}