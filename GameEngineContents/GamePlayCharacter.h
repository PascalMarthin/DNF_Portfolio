#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "CharacterStatManager.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :

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

	

	inline CharacterStatManager* GetStatManager() const
	{
		return Manager_StatManager;
	}
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
	CharacterStatManager* Manager_StatManager;
	AvataManager* Manager_AvataManager;

	void Create_Fighter_F_Default_FSManager();
	void SetRightDir();
	void SetLeftDir();

private:
	static GamePlayDataBase* CurrentCharacterData;
	static std::list<GamePlayDataBase*> AllCharacterData;

public:
	static GamePlayDataBase* CreateCharacterBase(CharacterFormerClass _Class, const std::string& _NickName = "Debug");


	void SetFSManager();

	void FSM_Move_Walk_Start(const StateInfo& _Info);
	void FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Walk_End(const StateInfo& _Info);


	void FSM_Move_Dash_Start(const StateInfo& _Info);
	void FSM_Move_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Dash_End(const StateInfo& _Info);

	void FSM_Move_Stand_Start(const StateInfo& _Info);
	void FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Stand_End(const StateInfo& _Info);

	// 점프
	void FSM_Move_Jump_Start(const StateInfo& _Info);
	bool StartJump;
	bool JumpGoingDown;
	void FSM_Move_Jump_Update(float _DeltaTime, const StateInfo& _Info);
	bool EndJump;
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

	// 대쉬 공격
	void FSM_Att_Dash_Start(const StateInfo& _Info);
	void FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Dash_End(const StateInfo& _Info);

};

