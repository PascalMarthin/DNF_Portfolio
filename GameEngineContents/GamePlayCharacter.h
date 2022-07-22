#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :

class CharacterAbilityStat
{
public:
	CharacterAbilityStat()
		: MoveSpeed(1.f)
		, AttSpeed(1.f)
		, CastSpeed(1.f)
		, MAXHP(1000)
		, HP(0)
		, MP(0)
		, Physical_Armor(0.f)
		, Magcial_Armor(0.f)
		, STR(0)
		, INT(0)
		, Health(0)
		, SPI(0)
		, Physical_Damage(0)
		, Magcial_Damage(0)
		, Independent_Damage(0)
		, Physical_Critical(0.f)
		, Magcial_Critical(0.f)
		, Accuracy(0.f)
		, Evasion(0.f)
		, Hit_Stun(0)
		, Hit_Recovery(0)
		, PlayerCurrentState(0)

	{

	}

private:
	unsigned int MAXHP;
	int HP;
	unsigned int MAXMP;
	int MP;

	float Physical_Armor; //              방어력
	float Magcial_Armor; //               마법 방어력
	unsigned int STR; // Strength         힘
	unsigned int INT; // Intelligence     지능

	unsigned int Health;   //             체력
	unsigned int SPI;      // Spirit      정신력
	unsigned int Physical_Damage;
	unsigned int Magcial_Damage;

	unsigned int Independent_Damage;
	float Physical_Critical;
	float Magcial_Critical;

	float MoveSpeed;
	float AttSpeed;
	float CastSpeed;

	float Accuracy;
	float Evasion;
	unsigned int Hit_Stun;
	unsigned int Hit_Recovery;

	unsigned int PlayerCurrentState;

};

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
	static int CharacterIndex;
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
	
private:
	// ItemBag 관련
	ItemBagEquipmentWindow* PlayerEquipment;
	ItemBagQuickslot* PlayerQuickslot;
	ItemInventory* PlayerItemInventory;
	AvatarInventory* PlayerAvatarInventory;
	PetInventory* PlayerPetInventory;

private:
	GamePlayKeyManager* KeyInTown;
	GamePlayKeyManager* KeyInDungeon;

protected:
	//virtual void SettingCharacterAnimation(GameEngineTextureRenderer* _TextureRenderer, const std::string& _AvataClass, unsigned int _AvataCode = -1) = 0;

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
	CharacterAbilityStat& GetAbilityStat()
	{
		return PlayerStat;
	}

private:
	CharacterAbilityStat PlayerStat;
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
