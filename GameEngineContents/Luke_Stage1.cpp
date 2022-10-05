#include "PreCompile.h"
#include "Luke_Stage1.h"
#include "GamePlayCharacter.h"
#include "Luke_Stage1_BackGround.h"
#include "MoveManager.h"
#include "AvataManager.h"
#include "Bale.h"
#include "Light_archer.h"
#include "Light_Knight.h"

Luke_Stage1::Luke_Stage1() 
	: Texture_Luke_Stage1(nullptr)

{
}

Luke_Stage1::~Luke_Stage1() 
{
}

void Luke_Stage1::Start()
{
	GamePlayLevelTemplate::Start();
	Texture_Luke_Stage1 = CreateActor<Luke_Stage1_BackGround>();
	Player_Character = CreateActor<GamePlayCharacter>();

	for (size_t i = 0; i < 2; i++)
	{
		Light_archer* Archer = CreateActor<Light_archer>();
		vector_AllMonster.push_back(Archer);
	}

	for (size_t i = 0; i < 3; i++)
	{
		Light_Knight* Archer = CreateActor<Light_Knight>();
		vector_AllMonster.push_back(Archer);
	}



	for (auto& Actor :GetGroup(0))
	{
		Actor->GetTransform().SetLocalScale({ MonitorX, MonitorY, 1.f });
	}

	
}

void Luke_Stage1::Update(float _DeltaTime)
{
	if (!GetMainCameraActor()->IsFreeCameraMode() && Player_Character->GetHoldCam() == false)
	{
		float4 Pos = Player_Character->GetMoveManager()->GetMoveCollision()->GetTransform().GetWorldPosition();
		if (Pos.x <= 705.f * MonitorX)
		{
			Pos.x = 705.f * MonitorX;
		}
		else if (Pos.x >= 1350.f * MonitorX)
		{
			Pos.x = 1350.f * MonitorX;
		}

		if ((Pos.y <= -700.f * MonitorY))
		{
			Pos.y = -700.f * MonitorY;
		}
		else if (Pos.y >= -460.f * MonitorY)
		{
			Pos.y = -460.f * MonitorY;
		}
		Pos.y += 80.f;

		GetMainCameraActor()->GetTransform().SetWorldPosition(Pos);
		GetUIFontCamera()->GetTransform().SetWorldPosition(Pos);
	}

}

void Luke_Stage1::LevelStartEvent()
{
	float Hight = Texture_Luke_Stage1->GetBackGroundTextureScale().y;
	if (Dungeon_Luke::GetStage() == Luke_Stage::Stage_2)
	{

	}
	else
	{
		SetPlayer("luke_phase2.ogg");
		Player_Character->GetMoveManager()->SetObjectPos({});
		
		Player_Character->GetTransform().SetLocalPosition({500.f, -500.f, -500.f });
	}

	for (size_t i = 0; i < 2; i++)
	{
		vector_AllMonster[i]->GetTransform().SetLocalPosition({ 1000, -500.f -100.f * i, -500.f -100.f * i });
	}

	for (size_t i = 2; i < 5; i++)
	{
		vector_AllMonster[i]->GetTransform().SetLocalPosition({ 700, -450.f - 100.f * i, -450.f - 100.f * i });
	}


	//Debug_Bale->GetTransform().SetLocalPosition({ 1000.f, -600.f, -600.f });
	//Debug_Bale->SetLeftDir();
	Dungeon_Luke::SetStage(Luke_Stage::Stage_1);

}