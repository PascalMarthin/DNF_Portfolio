#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "CharacterStatManager.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :
class CharacterAbilityStat
{
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
		, Hit_Recovery(0)

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
	unsigned int Hit_Recovery;

};
class GamePlayItem;
class InventoryData
{
	std::vector<GamePlayItem*> AllItem;
};

class GamePlayDataBase
{
	GamePlayDataBase()
		: Enum_FormerClass(CharacterFormerClass::None)
	{

	}
	CharacterFormerClass Enum_FormerClass;
	std::string NickName;

	CharacterAbilityStat Class_CharacterAbilityStat;
	InventoryData Class_InventoryData;
	// 인벤토리
	// 스킬
};

class PlayerInterface;
class InterfaceHUD;
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

	

	void ChangeAvataAnimation(const std::string& _AnimationName) const;
	void SetAllAvataManualControl();
	void SetAllAvataAutoControl();
	void ChangeFrame_Manual(int _Frame = -1) const;

	inline CharacterStatManager* GetStatManager() const
	{
		return StatManager;
	}
	inline PlayerInterface* GetInterface() const
	{
		return PlayerUserInterface;
	}


	inline AllCharacterClass GetPlayerClass() const
	{
		return PlayerClass;
	}

protected:
	void Start() override;



protected:
	PlayerInterface* PlayerUserInterface;

private:
	AllCharacterClass PlayerClass;

protected:

	// 아바타
	GameEnginePlusTextureRenderer* Avata_Belt;
	GameEnginePlusTextureRenderer* Avata_Cap;
	GameEnginePlusTextureRenderer* Avata_Coat;
	GameEnginePlusTextureRenderer* Avata_Face;
	GameEnginePlusTextureRenderer* Avata_Hair_a;
	GameEnginePlusTextureRenderer* Avata_Hair_b;
	GameEnginePlusTextureRenderer* Avata_Neck;
	GameEnginePlusTextureRenderer* Avata_Pants;
	GameEnginePlusTextureRenderer* Avata_Shoes_a;
	GameEnginePlusTextureRenderer* Avata_Shoes_b;
	GameEnginePlusTextureRenderer* Avata_Skin;
	std::vector<GameEnginePlusTextureRenderer*> AllAvatas;

	std::map<GameEnginePlusTextureRenderer*, GamePlayItemCode> CurrentAvataCode;

protected:
	CharacterStatManager* StatManager;

	virtual void Set_Default_FSMManager() {}
	void SetRightDir();
	void SetLeftDir();

private:
	static std::list<GamePlayDataBase*> AllCharacterData;
public:

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
