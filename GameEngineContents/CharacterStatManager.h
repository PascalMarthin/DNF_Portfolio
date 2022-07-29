#pragma once
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineStateManager.h>
#include "GamePlayEnum.h"



// 설명 :
class CharacterAbilityStat
{
	friend class CharacterStatManager;
public:
	CharacterAbilityStat()
		: MoveSpeed(2.0f)
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
// 설명 : 상태를 체크하고 업데이트마다 정리하는 클래스
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

	GameEngineStateManager& GetFSMManager()
	{
		return FSMManager;
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
	inline bool IsDash() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Dash;
	}
	inline bool IsJump() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Jump;
	}
	inline bool IsInvincibility() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Invincibility;
	}

	void SetMove();
	void SetDash();
	void SetStand();
	void SetJump(const float4& _StartJumpPos);
	inline void SetEngage()
	{
		CurrentEngageTime = 5.f;
	}
	inline float GetEngage() const
	{
		return CurrentEngageTime;
	}



	inline bool IsCanAction() const
	{
		return CanAction;
	}
	inline bool IsCanMove() const
	{
		return CanMove;
	}


	float GetMoveSpeed() const;


public:
	// Jump
	float JumpTime;
	float JumpPower;
	float JumpHigh;
	float CharacterWeight;
	float CurrentGravitIndex;
	float4 LandingPostion;
	//
protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	void OffEvent();


private:
	CharacterAbilityStat PlayerStat;
	unsigned int PlayerCurrentState;

	bool CanAction;
	bool CanMove;


private:
	GameEngineStateManager FSMManager;


private:
	float CurrentEngageTime;
};

