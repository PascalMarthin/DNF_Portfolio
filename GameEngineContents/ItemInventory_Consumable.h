#pragma once
#include "GamePlayInventory.h"

// Ό³Έν :
class ItemInventory_Consumable : public GamePlayInventory
{
public:
	// constrcuter destructer
	ItemInventory_Consumable();
	~ItemInventory_Consumable();

	// delete Function
	ItemInventory_Consumable(const ItemInventory_Consumable& _Other) = delete;
	ItemInventory_Consumable(ItemInventory_Consumable&& _Other) noexcept = delete;
	ItemInventory_Consumable& operator=(const ItemInventory_Consumable& _Other) = delete;
	ItemInventory_Consumable& operator=(ItemInventory_Consumable&& _Other) noexcept = delete;

protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent() override;
	//void OffEvent() override;

	void LevelStartEvent() override;
	//void LevelEndEvent() override;
private:


	inline void MoveInventory(unsigned int _Pos, InventoryData* _Item) override
	{
		MoveItem(_Pos, _Item, InventoryBag::Inventory_ItemInventory_Consumable);
	}
};

