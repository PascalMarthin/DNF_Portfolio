#pragma once
#include "GamePlayItem.h"

// ���� :
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
	inline void SetAvataClass(AllAvataClass _Class)
	{
		Enum_AvataClass = _Class;
	}
protected:
	void Start() override;
private:
	AllAvataClass Enum_AvataClass;
};

