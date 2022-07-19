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
	static int CharactorIndex;
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

	//std::string ConverToString(AvataClass _Class);

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

	CharacterUIKeyManager* PlayerUIKeyManager;
	CharacterSkillKeyManager* PlayerSkillKeyManager;

private:


protected:
	//virtual void SettingCharactorAnimation(GameEngineTextureRenderer* _TextureRenderer, const std::string& _AvataClass, unsigned int _AvataCode = -1) = 0;

	// 아바타
	GameEngineTextureRenderer* Avata_Belt;
	GameEngineTextureRenderer* Avata_Cap;
	GameEngineTextureRenderer* Avata_Coat;
	GameEngineTextureRenderer* Avata_Face;
	GameEngineTextureRenderer* Avata_Hair;
	GameEngineTextureRenderer* Avata_Neck;
	GameEngineTextureRenderer* Avata_Pants;
	GameEngineTextureRenderer* Avata_Shoes;
	GameEngineTextureRenderer* Avata_Skin;
};

//enum class AvataClass
//{
//	Belt,
//	Cap,
//	Coat,
//	Face,
//	Hair,
//	Neck,
//	Pants,
//	Shoes,
//	Skin
//};
