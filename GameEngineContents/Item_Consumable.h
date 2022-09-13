#pragma once
#include "GamePlayItem.h"

// Ό³Έν :
class CharacterStatManager;
class Item_Consumable : public GamePlayItem
{
public:
	friend class ItemInventory_Consumable;
	// constrcuter destructer
	Item_Consumable();
	~Item_Consumable();

	// delete Function
	Item_Consumable(const Item_Consumable& _Other) = delete;
	Item_Consumable(Item_Consumable&& _Other) noexcept = delete;
	Item_Consumable& operator=(const Item_Consumable& _Other) = delete;
	Item_Consumable& operator=(Item_Consumable&& _Other) noexcept = delete;


	//void Item_Effect(CharacterStatManager* _Manager);
protected:
	void Start() override;


	void AfterSetDesc() override;
private:
	std::function<void(CharacterStatManager*)> Item_Effect;


	void Function_Level1Up(CharacterStatManager* _Manager);
	//void 

};


