#include "PreCompile.h"
#include "GamePlayInventory.h"
#include "GamePlayItem_DESC.h"
#include "GamePlayItem.h"

GamePlayInventory::GamePlayInventory() 
	: Texture_Inventory(nullptr)
	, Collision_WindowInventory(nullptr)
	, Component_MouseCursorComponent(nullptr)
	, DragMode(false)
	, Item_DragData(nullptr)
{
}

GamePlayInventory::~GamePlayInventory() 
{
}

bool GamePlayInventory::IsItemDrag(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Item_DragData = _Other->GetActor<GamePlayItem>();
	DragMode = true;
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

		GamePlayItem* Item = CreateComponent<GamePlayItem>();
		Item->SetDESC(Inventory[i]->Item_DESC);
		Item->SetTransform(Inventory_Blank[i].Texture_Blank);
		//GameEngineDebug::OutPutString(std::to_string(Inventory_Blank[i].Texture_Blank->GetTransform().GetLocalPosition().x) + " / " + std::to_string(Inventory_Blank[i].Texture_Blank->GetTransform().GetLocalPosition().y));
		Inventory_CurrentItem[i] = Item;
	}
	
}