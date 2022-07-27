#include "PreCompile.h"
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineBase/GameEngineInput.h>
#include "ItemInventory.h"
#include "GamePlayItem.h"

ItemInventory::ItemInventory()
{

}

ItemInventory::~ItemInventory() 
{
}

void ItemInventory::Start()
{
	ItemBagInventory::Start();
	Inventory_Window = CreateComponent<GameEngineUIRenderer>();
	Inventory_Window->SetTexture("Window_Iteminventory.png");
	Inventory_Window->ScaleToTexture();
	Inventory_Window->GetTransform().SetLocalPosition({ 0, 0, ZSortOrder::Inventory });
	Off();

	ItemBlankRenderer["Equipment"];
	ItemBlankRenderer["Stuff"];
	ItemBlankRenderer["Consumable"];

	for (auto& Inventory : ItemBlankRenderer)
	{
		for (float i = 0.f; i < 6.f; i++)
		{
			for (float j = -3.f; j < 5.f; j++)
			{
				GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
				Renderer->SetTexture("Inventory_Blank.png");
				Renderer->ScaleToTexture();
				Renderer->GetTransform().SetLocalPosition({(-15 +( 30 * j)) * CameraZoomInvers, ( -15 + (-30 * i)) * CameraZoomInvers, ZSortOrder::Inventory_Blank});
				Inventory.second.push_back(Renderer);
				if (Inventory.first != "Equipment")
				{
					Renderer->Off();
				}
			}
		}
	}



}

void ItemInventory::Update(float _DeltaTime)
{
	ItemBagInventory::Update(_DeltaTime);
}


void ItemInventory::End()
{

}


bool ItemInventory::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}
//
//bool ItemInventory::PushItembyLoot(GamePlayItem* _Item)
//{
//	std::vector<GamePlayItem*>::iterator StartIter = ItemList.begin();
//	std::vector<GamePlayItem*>::iterator EndIter = ItemList.end();
//
//
//	std::vector<GamePlayItem*>::iterator EmptyIter = ItemList.begin();
//	bool Empty = false;
//
//
//	GamePlayItemCode ItemCode = _Item->GetItemCode();
//	bool StackItem = false;
//	switch (ItemType)
//	{
//	case GamePlayItemType::Stuff:
//	case GamePlayItemType::Consumable:
//		StackItem = true;
//		break;
//	case GamePlayItemType::Equipment:
//	case GamePlayItemType::Avatar:
//	case GamePlayItemType::Pet:
//	case GamePlayItemType::Debug:
//	case GamePlayItemType::Unknown:
//	default:
//		StackItem = false;
//		break;
//	}
//
//
//	for (; StartIter != EndIter; ++StartIter)
//	{
//		if ((*StartIter) != nullptr)
//		{
//			if (StackItem == true && (*StartIter)->GetItemCode() == ItemCode)
//			{
//				if ((*StartIter)->CombineStackItem(_Item) == 0)
//				{
//					return true;
//				}
//			}
//		}
//		else if (Empty == false)
//		{
//			if (StackItem == true)
//			{
//				EmptyIter = StartIter;
//				Empty = true;
//			}
//			else
//			{
//				(*StartIter) = _Item;
//			}
//
//		}
//	}
//
//	if (Empty == true)
//	{
//		(*EmptyIter) = _Item;
//		return true;
//	}
//
//	return false;
//
//}
