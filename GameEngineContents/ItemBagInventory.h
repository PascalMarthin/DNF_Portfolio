#pragma once
#include "GamePlayItemBag.h"

// ���� :
class ItemBagInventory : public GamePlayItemBag
{
public:
	// constrcuter destructer
	~ItemBagInventory();

	// delete Function
	ItemBagInventory(const ItemBagInventory& _Other) = delete;
	ItemBagInventory(ItemBagInventory&& _Other) noexcept = delete;
	ItemBagInventory& operator=(const ItemBagInventory& _Other) = delete;
	ItemBagInventory& operator=(ItemBagInventory&& _Other) noexcept = delete;

protected:
	ItemBagInventory();

private:

};

