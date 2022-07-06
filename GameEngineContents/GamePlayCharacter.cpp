#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "GamePlayCharacter.h"
#include "ItemBagEquipmentWindow.h"
#include "ItemBagQuickslot.h"
#include "AvatarInventory.h"
#include "PetInventory.h"
#include "ItemInventory.h"
#include "ChararcterUIKeyManager.h"
#include "ChararcterSkillKeyManager.h"

GamePlayCharacter::GamePlayCharacter()
	: PlayerEquipment(nullptr)
	, PlayerQuickslot(nullptr)
	, PlayerItemInventory(nullptr)
	, PlayerAvatarInventory(nullptr)
	, PlayerPetInventory(nullptr)
	, PlayerUIKeyManager(CreateComponent<ChararcterUIKeyManager>())
	, PlayerSkillKeyManager(CreateComponent<ChararcterSkillKeyManager>())
	, PlayerCurrentState(0x0)
{

	
}

GamePlayCharacter::~GamePlayCharacter() 
{

	
}

void GamePlayCharacter::Start()
{

	{
		PlayerEquipment = GetLevel()->CreateActor<ItemBagEquipmentWindow>();
		PlayerEquipment->SetOwner(this);

		PlayerQuickslot = GetLevel()->CreateActor<ItemBagQuickslot>();
		PlayerQuickslot->SetOwner(this);

		PlayerItemInventory = GetLevel()->CreateActor<ItemInventory>();
		PlayerItemInventory->SetOwner(this);

		PlayerAvatarInventory = GetLevel()->CreateActor<AvatarInventory>();
		PlayerAvatarInventory->SetOwner(this);

		PlayerPetInventory = GetLevel()->CreateActor<PetInventory>();
		PlayerPetInventory->SetOwner(this);

	}

}

