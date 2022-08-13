#include "PreCompile.h"
#include <GameEngineCore/GEngine.h>
#include "DungeonSelect.h"
#include "GamePlayDataBase.h"
#include "DungeonSelect_Slot.h"
#include "DungeonSelect_BackGround.h"
#include "DummyActor.h"
#include "MouseCursorComponent.h"

WorldDungeon DungeonSelect::CurrentWorldDungeon = WorldDungeon::None;
DungeonSelect::DungeonSelect() 
	: Actor_BackGround(nullptr)

{
}

DungeonSelect::~DungeonSelect() 
{
}

// -----------------Start---------------
void DungeonSelect::Start()
{
	Actor_BackGround = CreateActor<DungeonSelect_BackGround>();
	Actor_BackGround->GetTransform().SetLocalPosition({ 0 , 0 ,ZSortOrder::BackGround });
	CreateActor<MouseCursorComponent>();


	for (size_t i = 0; i < 5; i++)
	{
		DungeonSelect_Slot* Renderer = CreateActor<DungeonSelect_Slot>();
		Renderer->GetTransform().SetLocalScale({ MonitorX,  MonitorY });
		Data_SlotActor.push_back(Renderer);
		DummyActor* Dummy = CreateActor<DummyActor>();
		GameEngineTextureRenderer* Point = Dummy->CreateComponent<GameEngineTextureRenderer>();
		Point->SetTexture("Dungeon_Point.png");
		Point->ScaleToTexture();
		Point->Off();
		Dummy->GetTransform().SetLocalScale({  MonitorX,  MonitorY });
		Texture_DungeonPoint.push_back(Point);
	}

}

// -----------------Update---------------
void DungeonSelect::Update(float _DeltaTime)
{
	if (GameEngineInput::GetInst()->IsDown("ESC"))
	{
		switch (CurrentWorldDungeon)
		{
		case WorldDungeon::Luke:
			GEngine::ChangeLevel("Jelva_2F01");
			break;
		case WorldDungeon::None:
		default:
			MsgBoxAssert("아직 설정 되지 않은 월드던전입니다")
				break;
		}
	}
}


void DungeonSelect::OnEvent()
{
	switch (CurrentWorldDungeon)
	{
	case WorldDungeon::Luke:
		SetLukeDungeon();
		break;
	case WorldDungeon::None:
	default:
		MsgBoxAssert("아직 설정 되지 않은 월드던전입니다")
		break;
	}
}

void DungeonSelect::SetLukeDungeon()
{
	
	Actor_BackGround->Texture_Background->SetTexture("Dungeon_Luke_BackGround.png");
	Actor_BackGround->Texture_Background->GetTransform().SetLocalScale({ 1280, 720});
	{
		Data_SlotActor[0]->GetTransform().SetLocalPosition({ -225, 45 });
		Data_SlotActor[0]->Texture_BubblePoint->SetTexture("Dungeon_BubblePoint.png");
		Data_SlotActor[0]->Texture_BubblePoint->GetTransform().SetLocalPosition({ -60, 14, 0.06f });
		Data_SlotActor[0]->Texture_DungeonSelect_Slot->SetTexture("Dungeon_Luke_DungeonSlot.png");
		Data_SlotActor[0]->Texture_DungeonSelect_Slot->GetTransform().SetLocalMove({0, -10.f, 0});
		Data_SlotActor[0]->Texture_DungeonSelect_SlotBorder->SetTexture("Dungeon_Luke_SlotBorder.png");


		Data_SlotActor[0]->On();
		Texture_DungeonPoint[0]->GetTransform().SetLocalPosition({ -325, 90 });
		Texture_DungeonPoint[0]->On();
	}
	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::DungeonSelect);
}

void DungeonSelect::OffEvent()
{
	DungeonSelect::CurrentWorldDungeon = WorldDungeon::None;

}
