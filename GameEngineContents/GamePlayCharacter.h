#pragma once
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// ���� :
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
	// ItemBag ����
	ItemBagEquipmentWindow* PlayerEquipment;
	ItemBagQuickslot* PlayerQuickslot;
	ItemInventory* PlayerItemInventory;
	AvatarInventory* PlayerAvatarInventory;
	PetInventory* PlayerPetInventory;

	CharacterUIKeyManager* const PlayerUIKeyManager;
	CharacterSkillKeyManager* const PlayerSkillKeyManager;

private:


protected:
	virtual void SettingCharactorAnimation(GameEngineTextureRenderer* _TextureRenderer) = 0;
	// �ƹ�Ÿ
	GameEngineTextureRenderer* Avata_Belt;
	GameEngineTextureRenderer* Avata_Skin;
	GameEngineTextureRenderer* Avata_Cap;
	GameEngineTextureRenderer* Avata_Coat;
	GameEngineTextureRenderer* Avata_Face;
	GameEngineTextureRenderer* Avata_Hair;
	GameEngineTextureRenderer* Avata_Neck;
	GameEngineTextureRenderer* Avata_Pants;
	GameEngineTextureRenderer* Avata_Shoes;
};

