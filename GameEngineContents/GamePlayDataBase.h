#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <string>
#include <vector>
#include "GamePlayEnum.h"

#define FighterAnimationInter 0.08f

// 설명 :
class GamePlayItem_DESC;
enum class GamePlayItemType;
enum class InventoryBag
{
	  None
	, Inventory_QuickSlot
	, Inventory_ItemInventory_Equipment
	, Inventory_ItemInventory_Equipment_Wear
	, Inventory_ItemInventory_Stuff
	, Inventory_ItemInventory_Consumable
	, Inventory_Avata
	, Inventory_Avata_Wear
	, Inventory_Pet
};
class CharacterAbilityStat
{
	friend class CharacterStatManager;
	friend class GamePlayCharacter;
public:
	CharacterAbilityStat()
		: Level(0)
		, MaxEXP(1000)
		, EXP(0)
		, MoveSpeed(2.0f)
		, AttSpeed(1.f)
		, CastSpeed(1.f)
		, MAXHP(1000)
		, MAXMP(1000)
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
		, Hit_Recovery(1.f)
		, JumpPower(600.f)

	{

	}

private:
	unsigned int Level;
	unsigned int MaxEXP;
	int EXP;

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
	float Hit_Recovery;


	float JumpPower;
};
struct InventoryData
{
	GamePlayItem_DESC* Item_DESC;
	unsigned int Stack;
};

class GamePlayDataBase
{
	friend class GamePlayCharacter;
public:
	// constrcuter destructer
	GamePlayDataBase(CharacterFormerClass _Class, const std::string& _Name);
	~GamePlayDataBase();

	// delete Function
	GamePlayDataBase(const GamePlayDataBase& _Other) = delete;
	GamePlayDataBase(GamePlayDataBase&& _Other) noexcept = delete;
	GamePlayDataBase& operator=(const GamePlayDataBase& _Other) = delete;
	GamePlayDataBase& operator=(GamePlayDataBase&& _Other) noexcept = delete;
	inline CharacterFormerClass GetFormerClass() const
	{
		return Enum_FormerClass;
	}
	AllCharacterClass GetCharacterClass() const
	{
		switch (Enum_FormerClass)
		{
		case CharacterFormerClass::Striker:
			return AllCharacterClass::Fighter_F;
			break;
		case CharacterFormerClass::Lucher:
		case CharacterFormerClass::CharacterClass_Max:
		case CharacterFormerClass::None:
		default:
			MsgBoxAssert("아직 만들어지지 않은 직업입니다")
			break;
		}
		return AllCharacterClass::None;
	}
	inline  std::vector<InventoryData*>& GetInventoryData(InventoryBag _BagType)
	{
		return DataBase_InventoryData[_BagType];
	}
	inline TownMap GetCurrentMap() const
	{
		return CurrentMap;
	}
	inline void  SetCurrentMap(TownMap _Town)
	{
		CurrentMap = _Town;
	}


	static void SetCurrentCharacterData(GamePlayDataBase* _Data)
	{
		CurrentCharacterData = _Data;
	}
	inline static GamePlayDataBase* GetCurrentCharacterData()
	{
		return CurrentCharacterData;
	}



public:
	inline CharacterAbilityStat* GetAbilityStat()
	{
		return &Class_CharacterAbilityStat;
	}

	void CreateItem(GamePlayItemCode _Code, int _Stack);
	bool PushInventoryToItem(InventoryData* _Data);
protected:

private:
	CharacterFormerClass Enum_FormerClass;
	std::string NickName;

	CharacterAbilityStat Class_CharacterAbilityStat;
	std::map<InventoryBag, std::vector<InventoryData*>> DataBase_InventoryData;
	

	TownMap CurrentMap;








	// Static
public:

	static void SetAnimationForFrameAnimationDESC(AllCharacterClass _Class);
	static void DestroyFrameAnimationDESC();

	inline static std::map<std::string, FrameAnimation_DESC*>& GetClassAnimation_DESC(AllCharacterClass _Class)
	{
		return CharacterAnimation_DESCs[_Class];
	}

private:
	std::list<InventoryData*> All_ItemData;

	static GamePlayDataBase* CurrentCharacterData;
	static std::map<AllCharacterClass, std::map<std::string, FrameAnimation_DESC*>> CharacterAnimation_DESCs;
	static void CreateFighter_F_Animation();


};

