#include "PreCompile.h"
#include "PetInventory.h"

PetInventory::PetInventory(GamePlayCharacter* _Owner)
	: ItemBagInventory(_Owner)
{
}

PetInventory::~PetInventory() 
{
}

bool PetInventory::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}