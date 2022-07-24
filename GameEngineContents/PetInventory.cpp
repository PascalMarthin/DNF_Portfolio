#include "PreCompile.h"
#include "PetInventory.h"

PetInventory::PetInventory()
{
}

PetInventory::~PetInventory() 
{
}

void PetInventory::Start()
{
	Inventory_Window = CreateComponent<GameEngineTextureRenderer>();
	Inventory_Window->SetTexture("Window_Petinventory.png");
	Inventory_Window->ScaleToTexture();
	Off();
}

void PetInventory::Update(float _DeltaTime)
{

}

void PetInventory::End()
{

}


bool PetInventory::PushItembyDrag(GamePlayItem* _Item, GamePlayItemBag* _From)
{
	return true;
}