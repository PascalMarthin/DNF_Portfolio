#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "CharacterStatManager.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :
class Skill_Fighter_F_BaseHit;
class Skill_Fighter_F_DashHit;
class MouseCursorComponent;
class GamePlayObjectNPC;
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
class CharacterSkillManager;
class ItemInventory_Consumable;
class AvataInventory;
class ItemInventory_Equipment;
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

	
	inline AvataManager* GetAvataManager() const
	{
		return Manager_AvataManager;
	}
	inline CharacterSkillManager* GetSkillManager() const
	{
		return Manager_SkillManager;
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
	inline void SetCamHoldOn()
	{
		HoldCam = true;
	}
	inline void SetCamHoldOff()
	{
		HoldCam = false;
	}

	inline bool GetHoldCam() const
	{
		return HoldCam;
	}

	static void SetPlayerCharacter();

protected:
	void Start() override;
	void Update(float _Delta) override;
	void LevelStartEvent() override;
	void LevelEndEvent() override;

protected:
	PlayerInterface* PlayerUserInterface;

private:
	CharacterFormerClass PlayerFormerClass;

protected:

	// 아바타


protected:

	AvataManager* Manager_AvataManager;
	CharacterSkillManager* Manager_SkillManager;

	void Create_Fighter_F_Default_FSManager();
	// ---------------Collision------------------
	std::map<Collision_AllSkill , std::vector<GameEngineCollision*> > Collision_HitCollision;

	GameEngineCollision* Collision_NPCCanInteraction;
	GameEngineCollision* Collision_NPCVoice;
	//void On_EnumCollision(Collision_AllSkill _Collsion);
	//void Off_EnumCollision(Collision_AllSkill _Collsion);


private:

	void CheckInventoryKey();
	CollisionReturn NPCInteraction(GameEngineCollision* _This, GameEngineCollision* _Other);
	GamePlayObjectNPC* NPC_Interaction;

	// ------------Cam--------------------

	bool HoldCam;


	// ----------GameCharacterData---------------
	static GamePlayDataBase* CurrentCharacterData;
	static std::list<GamePlayDataBase*> AllCharacterData;


	static GamePlayCharacter* Inst;

public:
	static GamePlayDataBase* CreateCharacterBase(CharacterFormerClass _Class, const std::string& _NickName = "Debug");

	static GamePlayCharacter* GetInst()
	{
		return Inst;
	}

	//---------------------------------------
	void SetFSManager() override;

	GameEngineCollision* Collision_Body;
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

	//// 기본공격
	void FSM_Att_BaseHit_Start(const StateInfo& _Info);
	void FSM_Att_BaseHit_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_BaseHit_End(const StateInfo& _Info);


	// 스킬공격
	void FSM_Att_Skill_Start(const StateInfo& _Info);
	void FSM_Att_Skill_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Skill_End(const StateInfo& _Info);

	// 상호작용중
	void FSM_Interaction_Start(const StateInfo& _Info);
	void FSM_Interaction_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Interaction_End(const StateInfo& _Info);
	

	// 피격중
	void FSM_Hit_Aerial_Start(const StateInfo& _Info);
	void FSM_Hit_Aerial_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Aerial_End(const StateInfo& _Info);


	void FSM_Hit_Aerial_GoingDown_Start(const StateInfo& _Info);
	void FSM_Hit_Aerial_GoingDown_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Aerial_GoingDown_End(const StateInfo& _Info);

	void FSM_Hit_Down_Start(const StateInfo& _Info);
	void FSM_Hit_Down_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Down_End(const StateInfo& _Info);

	void FSM_Hit_Stand_Start(const StateInfo& _Info);
	void FSM_Hit_Stand_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Stand_End(const StateInfo& _Info);
	
	



	
	//float Att_BaseAtt_Delay;

	//void FSM_Att_BasePunch2_Start(const StateInfo& _Info);
	//void FSM_Att_BasePunch2_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Att_BasePunch2_End(const StateInfo& _Info);

	//void FSM_Att_BasePunch3_Start(const StateInfo& _Info);
	//void FSM_Att_BasePunch3_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Att_BasePunch3_End(const StateInfo& _Info);
	//bool DelayPunch;

	//void FSM_Att_BaseKick_Start(const StateInfo& _Info);
	//void FSM_Att_BaseKick_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Att_BaseKick_End(const StateInfo& _Info);

	//void FSM_Move_Helper();
	//// 해머 킥
	//void FSM_Att_HamKick_Start(const StateInfo& _Info);
	//void FSM_Att_HamKick_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Att_HamKick_End(const StateInfo& _Info);


	//// 대쉬 공격
	//void FSM_Att_Dash_Start(const StateInfo& _Info);
	//void FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Att_Dash_End(const StateInfo& _Info);



	// ------------------Skill------------------
	//std::map<std::string, GamePlaySkill*> map_AllSkill;
	//void SkillCollisionActive(const std::string& _Name, int _Frame);


	GamePlaySkill* Skill_CurrentSkill;
	Skill_Fighter_F_BaseHit* Skill_BaseHit;
	Skill_Fighter_F_DashHit* Skill_BaseDashAtt;
	std::function<bool(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)> Function_BaseAtt;
	std::function<bool(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)> Function_CurrentSkill;

private:
	// -----------------Inventory------------------------------
	ItemInventory_Consumable* Class_ItemInventory;
	AvataInventory* Class_AvataInventory;
	ItemInventory_Equipment* Class_EquipmentInventory;
	//------------------Mouse---------------------------------
	inline MouseCursorComponent* GetMouseCursor()
	{
		return Component_MouseCursorComponent;
	}

	private:
	MouseCursorComponent* Component_MouseCursorComponent;
};

