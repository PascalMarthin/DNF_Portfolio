#pragma once
#include "GamePlayInventory.h"

// 설명 :
 
// 설명 :
class ItemInventory_Equipment : public GamePlayInventory
{
public:
	// constrcuter destructer
	ItemInventory_Equipment();
	~ItemInventory_Equipment();

	// delete Function
	ItemInventory_Equipment(const ItemInventory_Equipment& _Other) = delete;
	ItemInventory_Equipment(ItemInventory_Equipment&& _Other) noexcept = delete;
	ItemInventory_Equipment& operator=(const ItemInventory_Equipment& _Other) = delete;
	ItemInventory_Equipment& operator=(ItemInventory_Equipment&& _Other) noexcept = delete;

protected:

	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent() override;
	//void OffEvent() override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;

	void Mouse_RClick(GamePlayItem* _Item) override;
private:
	std::map<AllEquipmentClass, GameEngineCollision*> All_WearEquipment_Type;
	std::map<GameEngineCollision*, GamePlayItem*> All_WearEquipment_Texture;

	inline void MoveInventory(unsigned int _Pos, InventoryData* _Item) override
	{
		MoveItem(_Pos, _Item, InventoryBag::Inventory_ItemInventory_Consumable);
	}
};

