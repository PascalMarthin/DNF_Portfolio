#pragma once
#include "GamePlayItem.h"

// Ό³Έν :
class Item_Equipment : public GamePlayItem
{
	friend class ItemInventory_Equipment;
public:
	// constrcuter destructer
	Item_Equipment();
	~Item_Equipment();

	// delete Function
	Item_Equipment(const Item_Equipment& _Other) = delete;
	Item_Equipment(Item_Equipment&& _Other) noexcept = delete;
	Item_Equipment& operator=(const Item_Equipment& _Other) = delete;
	Item_Equipment& operator=(Item_Equipment&& _Other) noexcept = delete;

	static AllEquipmentClass FindAvataClass(GamePlayItemCode _Code);
protected:
	void Start() override;
private:
	AllEquipmentClass Enum_EquipmentClass;
	void AfterSetDesc() override;
};
