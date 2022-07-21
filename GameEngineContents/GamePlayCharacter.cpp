#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayCharacter.h"
#include "GamePlayKeyManager.h"
#include "ItemBagEquipmentWindow.h"
#include "ItemBagQuickslot.h"
#include "AvatarInventory.h"
#include "PetInventory.h"
#include "ItemInventory.h"

int GamePlayCharacter::CharactorIndex = 0;
GamePlayCharacter::GamePlayCharacter()
	: PlayerEquipment(nullptr)
	, PlayerQuickslot(nullptr)
	, PlayerItemInventory(nullptr)
	, PlayerAvatarInventory(nullptr)
	, PlayerPetInventory(nullptr)
	, KeyManager(nullptr)

	, Avata_Belt(nullptr)
	, Avata_Skin(nullptr)
	, Avata_Cap(nullptr)
	, Avata_Coat(nullptr)
	, Avata_Face(nullptr)
	, Avata_Hair_a(nullptr)
	, Avata_Hair_b(nullptr)
	, Avata_Neck(nullptr)
	, Avata_Pants(nullptr)
	, Avata_Shoes(nullptr)

{
	++GamePlayCharacter::CharactorIndex;
}

GamePlayCharacter::~GamePlayCharacter() 
{
	--GamePlayCharacter::CharactorIndex;
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


	AllAvatas.push_back(Avata_Skin = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Belt = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Cap = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Coat = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Face = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Pants = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Shoes = CreateComponent<GameEnginePlusTextureRenderer>());

	for (auto& Avata :AllAvatas)
	{
		Avata->GetTransform().SetLocalScale({ 500, 500 });
	}
	Avata_Skin->GetTransform().SetLocalPosition({ 0, 0, 100 });

	CurrentAvataCode[Avata_Belt] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Cap] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Coat] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Face] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Hair_a] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Hair_b] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Neck] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Pants] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Shoes] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Skin] = GamePlayItemCode::Empty;


	KeyManager = CreateComponent<GamePlayKeyManager>();
	

}

void GamePlayCharacter::ChangeAvataAnimation(const std::string& _AnimationName)
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->ChangeFrameAnimationPlus(_AnimationName);
	}
}
