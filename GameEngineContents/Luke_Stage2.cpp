#include "PreCompile.h"
#include "Luke_Stage2.h"
#include "GamePlayCharacter.h"
#include "Luke_Stage2_BackGround.h"
#include "MoveManager.h"
#include "AvataManager.h"
#include "Bale.h"
#include "GamePlayResultWindow.h"

Luke_Stage2::Luke_Stage2() 
{
}

Luke_Stage2::~Luke_Stage2() 
{
}



void Luke_Stage2::Start()
{
	GamePlayLevelTemplate::Start();
	Texture_Luke_Stage2 = CreateActor<Luke_Stage2_BackGround>();
	Player_Character = CreateActor<GamePlayCharacter>();

	Debug_Bale = CreateActor<Bale>();


	vector_AllMonster.push_back(Debug_Bale);

	for (auto& Actor : GetGroup(0))
	{
		Actor->GetTransform().SetLocalScale({ MonitorX, MonitorY, 1.f });
	}
}

void Luke_Stage2::Update(float _DeltaTime)
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


	if (!Debug_Bale->IsUpdate() && Window_Result == nullptr)
	{
		Window_Result = CreateActor<GamePlayResultWindow>();
	}
}

void Luke_Stage2::LevelStartEvent()
{
	float Hight = Texture_Luke_Stage2->GetBackGroundTextureScale().y;
	if (Dungeon_Luke::GetStage() == Luke_Stage::Stage_1)
	{

		Player_Character->GetTransform().SetLocalPosition({ 200.f, -650.f, -650.f });

	}
	else
	{

		Player_Character->GetMoveManager()->SetObjectPos({});

		Player_Character->GetTransform().SetLocalPosition({ 500.f, -500.f, -500.f });
	}

	Debug_Bale->GetTransform().SetLocalPosition({ 1000.f, -600.f, -600.f });
	Debug_Bale->SetLeftDir();
	Dungeon_Luke::SetStage(Luke_Stage::Stage_1);

}