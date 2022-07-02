#include "PreCompile.h"
#include "ItemBagEquipmentWindow.h"

ItemBagEquipmentWindow::ItemBagEquipmentWindow(GamePlayCharacter* _Owner)
	: GamePlayItemBag(_Owner)
{
}

ItemBagEquipmentWindow::~ItemBagEquipmentWindow() 
{
}

bool ItemBagEquipmentWindow::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}

