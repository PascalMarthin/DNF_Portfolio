#include "PreCompile.h"
#include "DungeonSelect_Slot.h"
#include "DungeonSelect.h"
#include <GameEngineCore/GEngine.h>
#include "DungeonLoding.h"

DungeonSelect_Slot::DungeonSelect_Slot() 
	: Texture_DungeonSelect_Slot(nullptr)
	, Texture_DungeonSelect_SlotBorder(nullptr)
	, Texture_DungeonSelect_SelectBorder(nullptr)
	, Texture_BubblePoint(nullptr)
	, Collision_DungeonSelect(nullptr)
{
}

DungeonSelect_Slot::~DungeonSelect_Slot() 
{
}

void DungeonSelect_Slot::Start()
{
	Texture_BubblePoint = CreateComponent<GameEngineTextureRenderer>();
	Texture_DungeonSelect_Slot = CreateComponent<GameEngineTextureRenderer>();
	Texture_DungeonSelect_SelectBorder = CreateComponent<GameEngineTextureRenderer>();
	Texture_DungeonSelect_SlotBorder = CreateComponent<GameEngineTextureRenderer>();

	Texture_DungeonSelect_SelectBorder->SetTexture("Dungeon_SelectBorder.png");
	Texture_DungeonSelect_SelectBorder->ScaleToTexture();

	Texture_BubblePoint->GetTransform().SetLocalScale({171, 96});
	Texture_DungeonSelect_Slot->GetTransform().SetLocalScale({168, 73});
	//Texture_DungeonSelect_SelectBorder->GetTransform().SetLocalScale({ 116,49});
	Texture_DungeonSelect_SlotBorder->GetTransform().SetLocalScale({ 227, 138 });

	Texture_DungeonSelect_Slot->GetTransform().SetLocalPosition({ 0, 0, 0.05f });
	Texture_DungeonSelect_SlotBorder->GetTransform().SetLocalPosition({ 0, 0, 0.03f });
	Texture_DungeonSelect_SelectBorder->GetTransform().SetLocalPosition({ 0, 0, 0.04f });

	Collision_DungeonSelect = CreateComponent<GameEngineCollision>();
	Collision_DungeonSelect->GetTransform().SetLocalScale({ 168, 73 });

	Texture_DungeonSelect_SelectBorder->Off();
	Off();
}
void DungeonSelect_Slot::Update(float _DeltaTime)
{
	if (Collision_DungeonSelect->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_Mouse, CollisionType::CT_AABB2D,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Collision_MouseCursor")
			{
				return true;
			}
			else
			{
				return false;
			}
	
		}))
	{
		Texture_DungeonSelect_SelectBorder->On();
		if (GameEngineInput::GetInst()->IsDown("LMouseCLK"))
		{
			DungeonLoding::SetLocalDungeon(LocalDungeon::Luke_LightOfAltar);
			GEngine::ChangeLevel("DungeonLoding");
		}
	}
	else
	{
		Texture_DungeonSelect_SelectBorder->Off();
	}
}
void DungeonSelect_Slot::OnEvent()
{
}