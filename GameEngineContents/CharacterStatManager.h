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

	void SetWalk();
	void SetWalkEnd();
	void SetDash();
	void SetDashEnd();
	void SetStand();
	void SetDoBaseAtt();
	void SetDoBaseAttEnd();
	void SetJump(const float4& _StartJumpPos);
	void SetJumpEnd();
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


	inline float GetMoveSpeed() const
	{
		return CurrentAbilityStat->MoveSpeed;
	}


	inline void SetRightSide()
	{
		RightSide = true;
	}
	inline void SetLeftSide()
	{
		RightSide = false;
	}
	inline bool GetDirSide()
	{
		return RightSide;
	}


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
	void OnEvent() override;
	void OffEvent();


private:
	unsigned int PlayerCurrentState;
	void SettingFirstTime();
	void SetCharacter_Fighter_F();

	bool CanAction;
	bool CanMove;


private:
	GameEngineStateManager FSMManager;
	CharacterAbilityStat* CurrentAbilityStat;

private:
	float CurrentEngageTime;
	bool RightSide;
};

