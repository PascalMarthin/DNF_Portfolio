#pragma once
#include "GamePlayInventory.h"

// Ό³Έν :
class ItemInventory_Consumable : public GamePlayInventory
{
	friend class ItemInventory_Equipment;
public:
	// constrcuter destructer
	ItemInventory_Consumable();
	~ItemInventory_Consumable();

	// delete Function
	ItemInventory_Consumable(const ItemInventory_Consumable& _Other) = delete;
	ItemInventory_Consumable(ItemInventory_Consumable&& _Other) noexcept = delete;
	ItemInventory_Consumable& operator=(const ItemInventory_Consumable& _Other) = delete;
	ItemInventory_Consumable& operator=(ItemInventory_Consumable&& _Other) noexcept = delete;

	static inline ItemInventory_Consumable* GetInst()
	{
		return Inst;
	}
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent() override;
	void Update(float _Time) override;
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

	GameEngineCollision* Collision_InventoryTapOff;
	static ItemInventory_Consumable* Inst;
};

