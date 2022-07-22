#pragma once
#include <GameEngineCore/GameEngineComponent.h>
#include "GamePlayEnum.h"

// 설명 :
class CharacterAbilityStat
{
	friend class CharacterStatManager;
public:
	CharacterAbilityStat()
		: MoveSpeed(1.f)
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
class CharacterStatManager : public GameEngineComponent
{
public:
	// constrcuter destructer
	CharacterStatManager();
	~CharacterStatManager();

	// delete Function
	CharacterStatManager(const CharacterStatManager& _Other) = delete;
	CharacterStatManager(CharacterStatManager&& _Other) noexcept = delete;
	CharacterStatManager& operator=(const CharacterStatManager& _Other) = delete;
	CharacterStatManager& operator=(CharacterStatManager&& _Other) noexcept = delete;

	CharacterAbilityStat& GetAbilityStat()
	{
		return PlayerStat;
	}

public:
	inline bool IsLive() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_ALive;
	}
	inline bool IsAction() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Action;
	}
	inline bool IsMove() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Move;
	}
	inline bool IsInAir() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_InAir;
	}
	inline bool IsInvincibility() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Invincibility;
	}


	inline bool IsCanAction() const
	{
		return CanAction;
	}
	inline bool IsCanMove() const
	{
		return CanMove;
	}


	inline void SetMove()
	{
		PlayerCurrentState |= CharacterStat::Player_Character_Move;
		PlayerCurrentState &= ~CharacterStat::Player_Character_Action;
	}
	inline void SetAction()
	{
		PlayerCurrentState |= CharacterStat::Player_Character_Action;
		PlayerCurrentState &= ~CharacterStat::Player_Character_Move;
	}
	inline void SetStanding()
	{
		PlayerCurrentState &= ~(CharacterStat::Player_Character_Move | CharacterStat::Player_Character_Move);
		CanAction = true;
		CanMove = true;
	}

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	void SettingStand();


	CharacterAbilityStat PlayerStat;
	unsigned int PlayerCurrentState;

	bool CanAction;
	bool CanMove;


};

