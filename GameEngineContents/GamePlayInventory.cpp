#include "PreCompile.h"
#include "GamePlayInventory.h"
#include "GamePlayItem_DESC.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"

GamePlayInventory::GamePlayInventory() 
	: Texture_Inventory(nullptr)
	, Collision_WindowInventory(nullptr)
	, Component_MouseCursorComponent(nullptr)
	, DragMode(false)
	, Item_DragData(nullptr)
	, Item_DragDataIndex(0)
{
}

GamePlayInventory::~GamePlayInventory() 
{
}

void GamePlayInventory::Update(float _DeltaTime)
{

	if (GameEngineInput::GetInst()->IsPress("LMouseCLK"))
	{
		if (Collision_WindowInventory->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_UIMouse, CollisionType::CT_AABB2D,
			[](GameEngineCollision* _This, GameEngineCollision* _Other)
			{
				if (_Other->GetNameConstRef() == "Collision_UICam_MouseCursor")
				{
					return true;
				}
				else
				{
					return false;
				}

			}))
		{
			GetTransform().SetLocalMove(GetLevel()->GetUICamera()->GetMouseWorldDir());
		}
	}

	if (DragMode == false)
	{
		if (GameEngineInput::GetInst()->IsDown("LMouseCLK"))
		{
			if (Component_MouseCursorComponent->GetUICamMouseCursor()->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_InventoryItem, CollisionType::CT_AABB2D,
				std::bind(&GamePlayInventory::IsItemDrag, this, std::placeholders::_1, std::placeholders::_2)))
			{
				DragMode = true;

				for (auto& Item : Inventory_CurrentItem)
				{
					if (Item.second == Item_DragData)
					{
						Item_DragDataIndex = Item.first;
					}
				}
				if (Item_DragDataIndex == -1)
				{
					MsgBoxAssert("예외 발생");
				}
			}

		}
	}
	else
	{
		if (GameEngineInput::GetInst()->IsPress("LMouseCLK"))
		{
			if (Item_DragData != nullptr)
			{
				Item_DragData->SetTransform(Component_MouseCursorComponent->GetUICamMouseCursor());
			}
		}
		else if (GameEngineInput::GetInst()->IsUp("LMouseCLK"))
		{
			Item_DragData->GetCollision()->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_InventoryBlank, CollisionType::CT_AABB2D,
				std::bind(&GamePlayInventory::CheckBlankCollision, this, std::placeholders::_1, std::placeholders::_2));
			Item_DragData->SetTransform(Inventory_Blank[Item_DragDataIndex].Texture_Blank);
			Inventory_CurrentItem[Item_DragDataIndex] = Item_DragData;

			DragMode = false;
			Item_DragData = nullptr;
			Item_DragDataIndex = -1;
		}
	}

	//else if (GameEngineInput::GetInst()->IsPress("MouseCLK"))
	//{

	//}
}

void GamePlayInventory::Mouse_RClick(GamePlayItem* _Item)
{
	MsgBoxAssert("인벤토리 가상함수 설정이 안되어있습니다")
}

bool GamePlayInventory::IsItemDrag(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Item_DragData = _Other->GetActor<GamePlayItem>();

	return true;
}
bool GamePlayInventory::CheckBlankCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	for (auto& Blank : Inventory_Blank)
	{
		if (Blank.second.Collision_Blank == _Other)
		{
			Inventory_CurrentItem[Item_DragDataIndex] = nullptr;
			Item_DragDataIndex = Blank.first;
		}
	}
	return true;
}


void GamePlayInventory::SetLevelStartItem(std::vector<InventoryData*>& Inventory)
{
	for (int i = 0 ; i < Inventory.size();i++)
	{
		//
		if (Inventory[i] == nullptr)
		{
			continue;
		}

		GamePlayItem* Item = CreateComponent<GamePlayItem>("GamePlayItem");
		Item->SetDESC(Inventory[i]->Item_DESC);
		Item->SetTransform(Inventory_Blank[i].Texture_Blank);
		//GameEngineDebug::OutPutString(std::to_string(Inventory_Blank[i].Texture_Blank->GetTransform().GetLocalPosition().x) + " / " + std::to_string(Inventory_Blank[i].Texture_Blank->GetTransform().GetLocalPosition().y));
		Inventory_CurrentItem[i] = Item;
	}
	
}