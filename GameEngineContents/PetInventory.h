#pragma once
#include "ItemBagInventory.h"

// Ό³Έν :
class PetInventory : public ItemBagInventory
{
public:
	// constrcuter destructer
	PetInventory(GamePlayCharacter* _Owner);
	~PetInventory();

	// delete Function
	PetInventory(const PetInventory& _Other) = delete;
	PetInventory(PetInventory&& _Other) noexcept = delete;
	PetInventory& operator=(const PetInventory& _Other) = delete;
	PetInventory& operator=(PetInventory&& _Other) noexcept = delete;

protected:

private:

	bool PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From) override;

};

