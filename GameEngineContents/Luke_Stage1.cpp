#include "PreCompile.h"
#include "Luke_Stage1.h"
#include "GamePlayCharacter.h"
#include "Luke_Stage1_BackGround.h"
#include "MoveManager.h"
#include "Bale.h"

Luke_Stage1::Luke_Stage1() 
	: Texture_Luke_Stage1(nullptr)
	, Debug_Bale(nullptr)
{
}

Luke_Stage1::~Luke_Stage1() 
{
}

void Luke_Stage1::Start()
{
	Texture_Luke_Stage1 = CreateActor<Luke_Stage1_BackGround>();
	Player_Character = CreateActor<GamePlayCharacter>();

	Debug_Bale = CreateActor<Bale>();
}

void Luke_Stage1::Update(float _DeltaTime)
{
	if (!GetMainCameraActor()->IsFreeCameraMode())
	{
		float4 Pos = Player_Character->GetMoveManager()->GetMoveCollision()->GetTransform().GetWorldPosition();
		if (Pos.x <= 705.f)
		{
			Pos.x = 705.f;
		}
		else if (Pos.x >= 1350.f)
		{
			Pos.x = 1350.f;
		}

		if ((Pos.y <= -580.f))
		{
			Pos.y = -580.f;
		}
		else if (Pos.y >= -460.f)
		{
			Pos.y = -460.f;
		}
		Pos.y += 100.f;

		GetMainCameraActor()->GetTransform().SetWorldPosition(Pos);
	}
}

void Luke_Stage1::OnEvent()
{
	float Hight = Texture_Luke_Stage1->GetBackGroundTextureScale().y;
	if (Dungeon_Luke::GetStage() == Luke_Stage::Stage_2)
	{

	}
	else
	{
		Player_Character->GetTransform().SetLocalPosition({500.f, -500.f, Hight });
	}
	Debug_Bale->GetTransform().SetLocalPosition({ 1000.f, -600.f, Hight });
	Debug_Bale->SetLeftDir();
	Dungeon_Luke::SetStage(Luke_Stage::Stage_1);

}