#pragma once
#include "GamePlayItemBag.h"

// Ό³Έν :
class ItemBagEquipmentWindow : public GamePlayItemBag
{
public:
	// constrcuter destructer
	ItemBagEquipmentWindow(GamePlayCharacter* _Owner);
	~ItemBagEquipmentWindow();

	// delete Function
	ItemBagEquipmentWindow(const ItemBagEquipmentWindow& _Other) = delete;
	ItemBagEquipmentWindow(ItemBagEquipmentWindow&& _Other) noexcept = delete;
	ItemBagEquipmentWindow& operator=(const ItemBagEquipmentWindow& _Other) = delete;
	ItemBagEquipmentWindow& operator=(ItemBagEquipmentWindow&& _Other) noexcept = delete;


protected:

private:

	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;


};

