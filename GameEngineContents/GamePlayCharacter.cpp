#include "PreCompile.h"
#include "GamePlayCharacter.h"
#include "ItemBagEquipmentWindow.h"
#include "ItemBagQuickslot.h"
#include "AvatarInventory.h"
#include "PetInventory.h"
#include "ItemInventory.h"

GamePlayCharacter::GamePlayCharacter()
	: PlayerEquipment(new ItemBagEquipmentWindow(this))
	, PlayerQuickslot(new ItemBagQuickslot(this))
	, PlayerItemInventory(new ItemInventory(this))
	, PlayerAvatarInventory(new AvatarInventory(this))
	, PlayerPetInventory(new PetInventory(this))
{

	
}

GamePlayCharacter::~GamePlayCharacter() 
{
	if (PlayerEquipment != nullptr)
	{
		delete PlayerEquipment;
	}
	if (PlayerQuickslot != nullptr)
	{
		delete PlayerQuickslot;
	}
	if (PlayerItemInventory != nullptr)
	{
		delete PlayerItemInventory;
	}
	if (PlayerAvatarInventory != nullptr)
	{
		delete PlayerAvatarInventory;
	}
	if (PlayerPetInventory != nullptr)
	{
		delete PlayerPetInventory;
	}
	
}

