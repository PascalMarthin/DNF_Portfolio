#include "PreCompile.h"
#include "ItemBagQuickslot.h"

ItemBagQuickslot::ItemBagQuickslot(GamePlayCharacter* _Owner)
	: GamePlayItemBag(_Owner)
{

}

ItemBagQuickslot::~ItemBagQuickslot() 
{
}

bool ItemBagQuickslot::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}