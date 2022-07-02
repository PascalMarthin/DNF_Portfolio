#include "PreCompile.h"
#include "ItemInventory.h"
#include "GamePlayItem.h"

ItemInventory::ItemInventory(GamePlayCharacter* _Owner)
	: ItemBagInventory(_Owner)
{
	ItemList.resize(8 * 6);
}

ItemInventory::~ItemInventory() 
{
}

bool ItemInventory::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}

bool ItemInventory::PushItembyLoot(GamePlayItem* _Item)
{
	std::vector<GamePlayItem*>::iterator StartIter = ItemList.begin();
	std::vector<GamePlayItem*>::iterator EndIter = ItemList.end();


	std::vector<GamePlayItem*>::iterator EmptyIter = ItemList.begin();
	bool Empty = false;


	GamePlayItemCode ItemCode = _Item->GetItemCode();
	GamePlayItemType ItemType = _Item->GetItemType();
	bool StackItem = false;
	switch (ItemType)
	{
	case GamePlayItemType::Stuff:
	case GamePlayItemType::Consumable:
		StackItem = true;
		break;
	case GamePlayItemType::Equipment:
	case GamePlayItemType::Avatar:
	case GamePlayItemType::Pet:
	case GamePlayItemType::Debug:
	case GamePlayItemType::Unknown:
	default:
		StackItem = false;
		break;
	}


	for (; StartIter != EndIter; ++StartIter)
	{
		if ((*StartIter) != nullptr)
		{
			if (StackItem == true && (*StartIter)->GetItemCode() == ItemCode)
			{
				if ((*StartIter)->CombineStackItem(_Item) == 0)
				{
					return true;
				}
			}
		}
		else if (Empty == false)
		{
			if (StackItem == true)
			{
				EmptyIter = StartIter;
				Empty = true;
			}
			else
			{
				(*StartIter) = _Item;
			}

		}
	}


	if (Empty == true)
	{
		(*EmptyIter) = _Item;
		return true;
	}

	return false;

}