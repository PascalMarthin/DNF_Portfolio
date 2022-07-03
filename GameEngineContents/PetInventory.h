#pragma once
#include "ItemBagInventory.h"

// Ό³Έν :
class PetInventory : public ItemBagInventory
{
public:
	// constrcuter destructer
	PetInventory();
	~PetInventory();

	// delete Function
	PetInventory(const PetInventory& _Other) = delete;
	PetInventory(PetInventory&& _Other) noexcept = delete;
	PetInventory& operator=(const PetInventory& _Other) = delete;
	PetInventory& operator=(PetInventory&& _Other) noexcept = delete;

protected:
	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;

};

