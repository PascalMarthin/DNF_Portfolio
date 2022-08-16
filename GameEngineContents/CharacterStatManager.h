#pragma once
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineStateManager.h>
#include "GamePlayEnum.h"
#include "GamePlayDataBase.h"


// 설명 : 상태를 체크하고 업데이트마다 정리하는 클래스
class CharacterAbilityStat;
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
	inline bool IsBeAir() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_BeAir;
	}
	

	void SetWalk();
	void SetWalkEnd();
	void SetDash();
	void SetDashEnd();
	void SetStand();
	void SetDoBaseAtt();
	void SetDoBaseAttEnd();
	void SetJump();
	void SetJumpEnd();
	void SetHit(const float4& _HitTime, float _Damge);
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
		return CurrentAbilityStat->MoveSpeed;
	}



protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	void OnEvent() override;
	void OffEvent();


private:
	// -----------PlayerSetting----------
	void SettingFirstTime();
	void SetCharacter_Fighter_F();
	// ----------------------------------
	unsigned int PlayerCurrentState;

private:
	GameEngineStateManager FSMManager;
	CharacterAbilityStat* CurrentAbilityStat;

private:
	float Time_CurrentEngage;
	float4 Time_BeHit;
};

