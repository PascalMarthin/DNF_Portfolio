#include "PreCompile.h"
#include "ItemInventory_Consumable.h"
#include "GamePlayDataBase.h"
#include "GamePlayItem.h"
#include "MouseCursorComponent.h"
#include "Item_Consumable.h"

ItemInventory_Consumable::ItemInventory_Consumable()

{
}

ItemInventory_Consumable::~ItemInventory_Consumable() 
{
}

void ItemInventory_Consumable::Start()
{
	Texture_Inventory = CreateComponent<GameEngineUIRenderer>("ItemInventory_Consumable");
	Texture_Inventory->SetTexture("Window_Iteminventory.png");
	Texture_Inventory->ScaleToTexture();
	Texture_Inventory->GetTransform().SetLocalPosition({ 0, 0, 10 });
	//Texture_Inventory->GetPixelData().MulColor = { 1, 1, 1, 0.8f };


	{
		Collision_WindowInventory = CreateComponent<GameEngineCollision>();
		Collision_WindowInventory->GetTransform().SetLocalPosition({ 0, 258 , 0});
		Collision_WindowInventory->GetTransform().SetLocalScale({ 258, 23 , 0 });
		Collision_WindowInventory->SetDebugSetting(CollisionType::CT_AABB, float4::BLUE);
		//Collision_WindowInventory->SetParent(Texture_Inventory);
	}
	{
		for (int y = 0; y > -6; y--)
		{
			for (int x = (-3); x < 5; x++)
			{
				GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("Inventory_Blank");
				Renderer->SetTexture("Inventory_Blank.png");
				Renderer->ScaleToTexture();
				Renderer->GetTransform().SetLocalPosition({static_cast<float>(30 * x) - 15,static_cast<float>(30 * y) -12.f , 5});
				GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
				Collision->GetTransform().SetLocalScale(Renderer->GetTransform().GetLocalScale() * 0.125f);
				Collision->GetTransform().SetLocalPosition(Renderer->GetTransform().GetLocalPosition());
				Collision->SetDebugSetting(CollisionType::CT_AABB2D, {0.5f, 0.5f, 0, 0.5f});
				Collision->ChangeOrder(CollisionOrder::UI_InventoryBlank);

				//Renderer->GetPixelData().MulColor = { 1, 1, 1, 0.5f };
				

				Inventory_Blank[x + 3 + y * -8].Collision_Blank = Collision;
				Inventory_Blank[x + 3 + y * -8].Texture_Blank = Renderer;
			}
		}
	}
}

void ItemInventory_Consumable::OnEvent()
{
	
}


void ItemInventory_Consumable::LevelStartEvent()
{
	GamePlayInventory::LevelStartEvent();
	SetLevelStartItem<Item_Consumable>(GamePlayDataBase::GetCurrentCharacterData()->GetInventoryData(InventoryBag::Inventory_ItemInventory_Consumable));
	Off();
}