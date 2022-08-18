#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "CharacterStatManager.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :
class Skill_Fighter_F_BaseHit;
class Skill_Fighter_F_Ham_Kick;
enum class Collision_AllSkill
{
	BasePunch1,
	BasePunch3,
	Hammer_Kick,
	Jump_Kick,
	Att_Dash,
};
class PlayerInterface;
class AvataManager;
class InterfaceHUD;
class GamePlayDataBase;
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

	


	inline PlayerInterface* GetInterface() const
	{
		return PlayerUserInterface;
	}
	inline CharacterFormerClass GetPlayerClass() const
	{
		return PlayerFormerClass;
	}
	inline static GamePlayDataBase* GetCurrentCharacterData()
	{
		return 	CurrentCharacterData;
	}



	static void SetPlayerCharacter();

protected:
	void Start() override;
	void OnEvent() override;
	void OffEvent() override;

protected:
	PlayerInterface* PlayerUserInterface;

private:
	CharacterFormerClass PlayerFormerClass;

protected:

	// 아바타


protected:
	AvataManager* Manager_AvataManager;

	void Create_Fighter_F_Default_FSManager();
	// ---------------Collision------------------
	std::map<Collision_AllSkill , std::vector<GameEngineCollision*> > Collision_HitCollision;
	void On_EnumCollision(Collision_AllSkill _Collsion);
	void Off_EnumCollision(Collision_AllSkill _Collsion);


private:
	// ----------GameCharacterData---------------
	static GamePlayDataBase* CurrentCharacterData;
	static std::list<GamePlayDataBase*> AllCharacterData;

public:
	static GamePlayDataBase* CreateCharacterBase(CharacterFormerClass _Class, const std::string& _NickName = "Debug");
	//-------------------------------------------

	void SetFSManager() override;
	//void SetCollisionManager();

	//------FSM--------------
	void FSM_Move_Walk_Start(const StateInfo& _Info);
	void FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Walk_End(const StateInfo& _Info);

	float MoveIndex;


	void FSM_Move_Dash_Start(const StateInfo& _Info);
	void FSM_Move_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Dash_End(const StateInfo& _Info);

	void FSM_Move_Stand_Start(const StateInfo& _Info);
	void FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Stand_End(const StateInfo& _Info);

	// 점프
	void FSM_Move_Jump_Start(const StateInfo& _Info);
	bool StartJump;
	void FSM_Move_Jump_Update(float _DeltaTime, const StateInfo& _Info);
	bool EndJump;
	void Jump_GoingDown() override;
	void LandingEnd() override;
	void FSM_Move_Jump_End(const StateInfo& _Info);
	// 점프 킥
	float JumpKick_DelayTime;
	bool BaseJumpKick;


	// 기본공격
	void FSM_Att_BasePunch1_Start(const StateInfo& _Info);
	void FSM_Att_BasePunch1_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_BasePunch1_End(const StateInfo& _Info);
	float Att_BaseAtt_Delay;

	void FSM_Att_BasePunch2_Start(const StateInfo& _Info);
	void FSM_Att_BasePunch2_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_BasePunch2_End(const StateInfo& _Info);

	void FSM_Att_BasePunch3_Start(const StateInfo& _Info);
	void FSM_Att_BasePunch3_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_BasePunch3_End(const StateInfo& _Info);
	bool DelayPunch;

	void FSM_Att_BaseKick_Start(const StateInfo& _Info);
	void FSM_Att_BaseKick_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_BaseKick_End(const StateInfo& _Info);

	Skill_Fighter_F_BaseHit* Class_Skill_Fighter_F_BaseHit;
	void FSM_Move_Helper();
	// 해머 킥
	void FSM_Att_HamKick_Start(const StateInfo& _Info);
	void FSM_Att_HamKick_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_HamKick_End(const StateInfo& _Info);

	Skill_Fighter_F_Ham_Kick* Class_Skill_Fighter_F_HamKick;
	// 대쉬 공격
	void FSM_Att_Dash_Start(const StateInfo& _Info);
	void FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Dash_End(const StateInfo& _Info);

};

