#pragma once
#include "GamePlayItem.h"

// Ό³Έν :
class Item_Consumable : public GamePlayItem
{
public:
	// constrcuter destructer
	Item_Consumable();
	~Item_Consumable();

	// delete Function
	Item_Consumable(const Item_Consumable& _Other) = delete;
	Item_Consumable(Item_Consumable&& _Other) noexcept = delete;
	Item_Consumable& operator=(const Item_Consumable& _Other) = delete;
	Item_Consumable& operator=(Item_Consumable&& _Other) noexcept = delete;


protected:
	void Start() override;

private:

};


