#include "PreCompile.h"
#include "GamePlayInventory.h"
#include "GamePlayItem_DESC.h"

GamePlayInventory::GamePlayInventory() 
	: Texture_Inventory(nullptr)
	, Collision_WindowInventory(nullptr)
{
}

GamePlayInventory::~GamePlayInventory() 
{
}

void GamePlayInventory::SetLevelStartItem(std::vector<InventoryData*>& Inventory)
{
	for (InventoryData* Item : Inventory)
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture(Item->Item_DESC->GetItemIcon());
		Renderer->ScaleToTexture();
		Renderer->SetParent(Inventory_Blank[Item->Location].Texture_Blank);
		Renderer->GetTransform().SetLocalMove({ 0, 0, -1 });

		GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
		Collision->SetParent(Renderer);
	//	Collision->GetTransform().SetLocalScale({0.5f, 0.5f});

		Inventory_CurrentItem[Item->Location].Collision_Blank = Collision;
		Inventory_CurrentItem[Item->Location].Texture_Blank = Renderer;
	//	Inventory_Blank[Item->Location].Texture_Blank->GetTransform().GetLocalPosition();
	}
	
}