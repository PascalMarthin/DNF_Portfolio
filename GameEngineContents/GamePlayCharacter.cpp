#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "GamePlayCharacter.h"
#include "ItemBagEquipmentWindow.h"
#include "ItemBagQuickslot.h"
#include "AvatarInventory.h"
#include "PetInventory.h"
#include "ItemInventory.h"
#include "CharacterUIKeyManager.h"
#include "CharacterSkillKeyManager.h"

GamePlayCharacter::GamePlayCharacter()
	: PlayerEquipment(nullptr)
	, PlayerQuickslot(nullptr)
	, PlayerItemInventory(nullptr)
	, PlayerAvatarInventory(nullptr)
	, PlayerPetInventory(nullptr)
	, PlayerUIKeyManager(CreateComponent<CharacterUIKeyManager>())
	, PlayerSkillKeyManager(CreateComponent<CharacterSkillKeyManager>())
	, PlayerCurrentState(0x0)

	, Avata_Belt(nullptr)
	, Avata_Skin(nullptr)
	, Avata_Cap(nullptr)
	, Avata_Coat(nullptr)
	, Avata_Face(nullptr)
	, Avata_Hair(nullptr)
	, Avata_Neck(nullptr)
	, Avata_Pants(nullptr)
	, Avata_Shoes(nullptr)

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


	Avata_Belt = CreateComponent<GameEngineTextureRenderer>();
	Avata_Skin = CreateComponent<GameEngineTextureRenderer>();
	Avata_Cap = CreateComponent<GameEngineTextureRenderer>();
	Avata_Coat = CreateComponent<GameEngineTextureRenderer>();
	Avata_Face = CreateComponent<GameEngineTextureRenderer>();
	Avata_Hair = CreateComponent<GameEngineTextureRenderer>();
	Avata_Neck = CreateComponent<GameEngineTextureRenderer>();
	Avata_Pants = CreateComponent<GameEngineTextureRenderer>();
	Avata_Shoes = CreateComponent<GameEngineTextureRenderer>();

	SettingCharactorAnimation(Avata_Belt);
	SettingCharactorAnimation(Avata_Skin);
	SettingCharactorAnimation(Avata_Cap);
	SettingCharactorAnimation(Avata_Coat);
	SettingCharactorAnimation(Avata_Face);
	SettingCharactorAnimation(Avata_Hair);
	SettingCharactorAnimation(Avata_Neck);
	SettingCharactorAnimation(Avata_Pants);
	SettingCharactorAnimation(Avata_Shoes);

}


