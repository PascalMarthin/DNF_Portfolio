#pragma once
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineStateManager.h>
#include "GamePlayEnum.h"
#include "GamePlayDataBase.h"


// 설명 : 상태를 체크하고 업데이트마다 정리하는 클래스
class CharacterAbilityStat;
class MonsterAbilityStat;
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


	GameEngineStateManager& GetFSMManager()
	{
		return FSMManager;
	}



public:
	inline CharacterAbilityStat* GetAbilityStat() const
	{
		return CurrentPlayerAbilityStat;
	}

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
	inline bool IsDoBaseAtt() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_BaseAtt;
	}
	inline bool IsSuperarmor() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Superarmor;
	}
	inline bool IsAerial() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Aerial;
	}
	inline bool IsBeHit() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_BeHit;
	}
	inline bool IsHold() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_BeHold;
	}
	inline bool IsDown() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_BeDown;
	}
	

	//  Player_Character_ALive
	//	Player_Character_Action
	//	Player_Character_Move
	//	Player_Character_Dash
	//	Player_Character_Jump
	//	Player_Character_BaseAtt
	//	Player_Character_DoSkill
	//	Player_Character_Casting
	//	Player_Character_Charging
	//	Player_Character_Invincibility
	//	Player_Character_Evasion
	//	Player_Character_Superarmor
	//	Player_Character_BeHit
	//	Player_Character_Aerial
	//	Player_Character_BeDown
	//	Player_Character_BeHold

	void SetWalk();
	void SetWalkEnd();
	void SetDash();
	void SetDashEnd();
	void SetStand();
	void SetDoBaseAtt();
	void SetDoBaseAttEnd();
	void SetJump();
	void SetJumpEnd();
	void SetAerial();
	void SetAerialEnd();
	void SetCanAction();
	void SetCantAction();
	void SetHit_Stand();
	void SetHit_StandEnd();
	void SetHit_BlowUp();
	void SetHold();
	void SetHoldEnd();
	void SetDown();
	void SetDownEnd();

	inline void SetEngage()
	{
		Time_CurrentEngage = 5.f;
	}
	inline float GetEngage() const
	{
		return Time_CurrentEngage;
	}
	inline float GetMoveSpeed() const
	{
		return CurrentPlayerAbilityStat->MoveSpeed;
	}



protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	void LevelStartEvent() override;
	void LevelEndEvent() override;


private:
	// -----------PlayerSetting----------
	void SettingFirstTime();
	void SetCharacter_Fighter_F();
	// ----------------------------------
	unsigned int PlayerCurrentState;

private:
	GameEngineStateManager FSMManager;
	CharacterAbilityStat* CurrentPlayerAbilityStat;
	MonsterAbilityStat* CurrentMonsterAbilityStat;
private:
	float Time_CurrentEngage;
};

