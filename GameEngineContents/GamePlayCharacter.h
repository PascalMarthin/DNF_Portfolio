#pragma once
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :
class ItemBagEquipmentWindow;
class ItemBagInventory;
class ItemBagQuickslot;
class ItemInventory;
class AvatarInventory;
class PetInventory;
class CharacterSkillKeyManager;
class CharacterUIKeyManager;
class GamePlayCharacter : public GamePlayObject
{
public:
	// constrcuter destructer
	GamePlayCharacter();
	~GamePlayCharacter();

	// delete Function
	GamePlayCharacter(const GamePlayCharacter& _Other) = delete;
	GamePlayCharacter(GamePlayCharacter&& _Other) noexcept = delete;
	GamePlayCharacter& operator=(const GamePlayCharacter& _Other) = delete;
	GamePlayCharacter& operator=(GamePlayCharacter&& _Other) noexcept = delete;

	
	inline ItemBagEquipmentWindow* GetEquipment() const
	{
		return PlayerEquipment;
	}
	inline ItemBagQuickslot* GetQuickslot() const
	{
		return PlayerQuickslot;
	}

	inline ItemInventory* GetItemInventory() const
	{
		return PlayerItemInventory;
	}
	inline AvatarInventory* GetAvatarInventory() const
	{
		return PlayerAvatarInventory;
	}
	inline PetInventory* GetPetInventory() const
	{
		return PlayerPetInventory;
	}

protected:
	void Start() override;



protected:
	unsigned int PlayerCurrentState;
	
private:
	// ItemBag 관련
	ItemBagEquipmentWindow* PlayerEquipment;
	ItemBagQuickslot* PlayerQuickslot;
	ItemInventory* PlayerItemInventory;
	AvatarInventory* PlayerAvatarInventory;
	PetInventory* PlayerPetInventory;

	CharacterUIKeyManager* const PlayerUIKeyManager;
	CharacterSkillKeyManager* const PlayerSkillKeyManager;

private:
	//std::map<std::string, std::vector<>>
	// 모션관련
};

