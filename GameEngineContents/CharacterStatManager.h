#pragma once
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineStateManager.h>
#include "GamePlayEnum.h"
#include "GamePlayDataBase.h"
#include "StatWindow.h"


// 설명 : 상태를 체크하고 업데이트마다 정리하는 클래스

enum class HPMPEnum;
class HealHPAni;
class CharacterAbilityStat;
class MonsterAbilityStat;
class GameSkillBuff;
class CharacterSkillManager;
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
	static CharacterStatManager* GetInst()
	{
		return CharacterStatManager::Inst;
	}

	inline void StatWindowOn()
	{
		Window_Stat->On();
	}
	inline void StatWindowOff()
	{
		Window_Stat->Off();
	}
	inline bool StatWindowIsUpdate()
	{
		return Window_Stat->IsUpdate();
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
		return (PlayerCurrentState & CharacterStat::Player_Character_Superarmor) | PlayerCurrentState & CharacterStat::Player_Character_Build;
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
	inline bool IsDoSkill() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_DoSkill;
	}
	inline bool IsBuild() const
	{
		return PlayerCurrentState & CharacterStat::Player_Character_Build;
	}
	
	inline const std::vector<float>& GetAddDamage() const
	{
		return vector_AddDamage;
	}




	bool HealHP(int _Heal, HPMPEnum _Enum);

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
	void SetDoSkill();
	void SetDoSkillEnd();
	void SetCasting();
	void SetCastingEnd();
	void SetInvincibility();
	void SetInvincibilityEnd();
	void SetSuperarmor();
	void SetSuperarmorEnd();
	void SetDead();
	void SetLive();
	void SetBuild();
	void SetBuildEnd();

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

	bool LevelUp();

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
	CharacterSkillManager* Manager_SkillManager;

	StatWindow* Window_Stat;




	static CharacterStatManager* Inst;


	MonsterAbilityStat* CurrentMonsterAbilityStat;
private:
	std::vector<GameEngineTextureRenderer*> Texture_LevelUp;
	std::vector<float> vector_AddDamage;

	float LevelUpTime;


	float Time_CurrentEngage;
};

