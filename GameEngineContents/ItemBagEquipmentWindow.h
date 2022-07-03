#pragma once
#include "GamePlayItemBag.h"

// Ό³Έν :
class ItemBagEquipmentWindow : public GamePlayItemBag
{
public:
	// constrcuter destructer
	ItemBagEquipmentWindow();
	~ItemBagEquipmentWindow();

	// delete Function
	ItemBagEquipmentWindow(const ItemBagEquipmentWindow& _Other) = delete;
	ItemBagEquipmentWindow(ItemBagEquipmentWindow&& _Other) noexcept = delete;
	ItemBagEquipmentWindow& operator=(const ItemBagEquipmentWindow& _Other) = delete;
	ItemBagEquipmentWindow& operator=(ItemBagEquipmentWindow&& _Other) noexcept = delete;


protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;


};

