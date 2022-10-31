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

enum class StatClass
{
	  Level
	, MaxEXP
	, EXP
	, MoveSpeed
	, AttSpeed
	, CastSpeed
	, MAXHP
	, MAXMP
	, HP
	, MP
	, Physical_Armor
	, Magcial_Armor
	, STR
	, INT
	, Health
	, SPI
	, Physical_Damage
	, Magcial_Damage
	, Independent_Damage
	, Physical_Critical
	, Magcial_Critical
	, Accuracy
	, Evasion
	, Hit_Stun
	, Hit_Recovery
	, JumpPower
};
class CharacterAbilityStat
{
	friend class CharacterStatManager;
	friend class GamePlayCharacter;
	friend class StatWindow;
public:
	CharacterAbilityStat()
		: Level(5)
		, MaxEXP(1000)
		, EXP(0)
		, MoveSpeed(2.0f)
		, AttSpeed(1.f)
		, CastSpeed(1.f)
		, MAXHP(1000)
		, MAXMP(1000)
		, HP(1000)
		, MP(300)
		, Physical_Armor(10)
		, Magcial_Armor(10)
		, STR(10)
		, INT(10)
		, Health(10)
		, SPI(10)
		, Physical_Damage(1)
		, Magcial_Damage(1)
		, Independent_Damage(1)
		, Physical_Critical(35.f)
		, Magcial_Critical(0)
		, Accuracy(0.f)
		, Evasion(0.f)
		, Hit_Stun(0)
		, Hit_Recovery(1.f)
		, JumpPower(600.f)
		, Coin(100)
	{
		HP = MAXHP;
		MP = MAXMP;
	}

	inline void SetRefreshbyLevel()
	{
		MaxEXP = static_cast<unsigned long long>(Level) * 1000;
		

		MAXHP = Level * 820;
		MAXMP = Level * 300;



		STR = Level * 31;
		INT = Level * 31;
		Health = Level * 30;
		SPI = Level * 30;
		Physical_Damage = Level * 112;
		Magcial_Damage = Level * 112;
		Independent_Damage = Level * 87;
		Physical_Armor = Level * 7;
		Magcial_Armor = Level * 7;
	}

	inline unsigned int GetLevel() const
	{
		return Level;
	}


	inline int GetHP() const
	{
		return HP;
	}

	inline unsigned int GetMAXHP() const
	{
		return MAXHP;
	}

	inline int GetMP() const
	{
		return MP;
	}

	inline unsigned int GetMAXMP() const
	{
		return MAXMP;
	}

	inline float GetPhysical_Critical() const
	{
		return Physical_Critical;
	}

	inline unsigned int GetSTR() const
	{
		return STR;
	}

	inline unsigned int GetPhysical_Damage() const
	{
		return Physical_Damage;
	}

private:


	unsigned int Level;
	unsigned __int64 MaxEXP;
	unsigned __int64 EXP;

	unsigned int MAXHP;
	int HP;
	unsigned int MAXMP;
	int MP;

	unsigned int Physical_Armor; //              방어력
	unsigned int Magcial_Armor; //               마법 방어력
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

	int Coin;
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

	inline unsigned int GetGold() const
	{
		return Gold;
	}

	inline unsigned int SetGold(unsigned int _int)
	{
		if (Gold < _int)
		{
			return Gold = 0;
		}
		else
		{
			return Gold -= _int;
		}
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
	

	unsigned int Gold;

	TownMap CurrentMap;

	//---------------Skill---------------
	
	//std::map<std::string, >



	// ----------------------------------






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

