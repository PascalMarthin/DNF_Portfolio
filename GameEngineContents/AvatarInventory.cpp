#include "PreCompile.h"
#include "AvatarInventory.h"

AvatarInventory::AvatarInventory(GamePlayCharacter* _Owner)
	: ItemBagInventory(_Owner)
{
}

AvatarInventory::~AvatarInventory() 
{
}

bool AvatarInventory::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}