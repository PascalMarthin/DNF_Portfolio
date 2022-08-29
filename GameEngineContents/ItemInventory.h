#pragma once
#include "GamePlayInventory.h"

// Ό³Έν :
class ItemInventory : public GamePlayInventory
{
public:
	// constrcuter destructer
	ItemInventory();
	~ItemInventory();

	// delete Function
	ItemInventory(const ItemInventory& _Other) = delete;
	ItemInventory(ItemInventory&& _Other) noexcept = delete;
	ItemInventory& operator=(const ItemInventory& _Other) = delete;
	ItemInventory& operator=(ItemInventory&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() override {}
	// void OffEvent() override {}

	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:

};

