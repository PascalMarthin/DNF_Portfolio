#pragma once
#include "GamePlayItem.h"

// Ό³Έν :
class Item_Avata : public GamePlayItem
{
public:
	friend class AvataInventory;
	// constrcuter destructer
	Item_Avata();
	~Item_Avata();

	// delete Function
	Item_Avata(const Item_Avata& _Other) = delete;
	Item_Avata(Item_Avata&& _Other) noexcept = delete;
	Item_Avata& operator=(const Item_Avata& _Other) = delete;
	Item_Avata& operator=(Item_Avata&& _Other) noexcept = delete;

	static AllAvataClass FindAvataClass(GamePlayItemCode _Code);
protected:
	void Start() override;
private:
	AllAvataClass Enum_AvataClass;
	void AfterSetDesc() override;
};

