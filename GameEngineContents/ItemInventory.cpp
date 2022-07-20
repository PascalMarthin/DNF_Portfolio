#include "PreCompile.h"
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
	ItemList.resize(48);
	for (size_t i = 0; i < 48; i++)
	{
	}
}

void ItemInventory::Update(float _DeltaTime)
{

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
