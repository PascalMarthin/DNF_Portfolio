#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :
class GamePlayKeyManager;
class ItemBagEquipmentWindow;
class ItemBagInventory;
class ItemBagQuickslot;
class ItemInventory;
class AvatarInventory;
class PetInventory;
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


	void ChangeAvataAnimation(const std::string& _AnimationName);

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

private:
	GamePlayKeyManager* KeyManager;

protected:
	//virtual void SettingCharactorAnimation(GameEngineTextureRenderer* _TextureRenderer, const std::string& _AvataClass, unsigned int _AvataCode = -1) = 0;

	// 아바타
	GameEnginePlusTextureRenderer* Avata_Belt;
	GameEnginePlusTextureRenderer* Avata_Cap;
	GameEnginePlusTextureRenderer* Avata_Coat;
	GameEnginePlusTextureRenderer* Avata_Face;
	GameEnginePlusTextureRenderer* Avata_Hair_a;
	GameEnginePlusTextureRenderer* Avata_Hair_b;
	GameEnginePlusTextureRenderer* Avata_Neck;
	GameEnginePlusTextureRenderer* Avata_Pants;
	GameEnginePlusTextureRenderer* Avata_Shoes;
	GameEnginePlusTextureRenderer* Avata_Skin;
	std::vector<GameEnginePlusTextureRenderer*> AllAvatas;

	std::map<GameEnginePlusTextureRenderer*, GamePlayItemCode> CurrentAvataCode;



public:
	inline float GetMoveSpeed()
	{
		return MoveSpeed;
	}

	inline float GetAttSpeed()
	{
		return AttSpeed;
	}

	inline float GetCastSpeed()
	{
		return CastSpeed;
	}

private:
	float MoveSpeed;
	float AttSpeed;
	float CastSpeed;

	float MAXHP;
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
