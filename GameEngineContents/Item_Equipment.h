#pragma once
#include "GamePlayItem.h"

// Ό³Έν :
enum class StatClass;
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
	static float FindAddDamage(GamePlayItemCode _Code);

	void SetStatClass(GamePlayItemCode _Code);

	inline float GetAddDamage() const
	{
		return AddDamage;
	}
protected:
	void Start() override;
private:
	std::map<StatClass, unsigned int> map_Stat;
	float AddDamage;


	AllEquipmentClass Enum_EquipmentClass;
	void AfterSetDesc() override;
};
