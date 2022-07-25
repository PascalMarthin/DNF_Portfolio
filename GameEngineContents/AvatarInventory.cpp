#include "PreCompile.h"
#include "AvatarInventory.h"

AvatarInventory::AvatarInventory()
{
}

AvatarInventory::~AvatarInventory() 
{
}

void AvatarInventory::Start()
{
	ItemBagInventory::Start();
	Inventory_Window = CreateComponent<GameEngineTextureRenderer>();
	Inventory_Window->SetTexture("Window_Avatainventory.png");
	Inventory_Window->ScaleToTexture();
	Off();
}

void AvatarInventory::Update(float _DeltaTime)
{

}


void AvatarInventory::End()
{

}

bool AvatarInventory::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}