#pragma once
#include "GamePlayObject.h"
#include <GameEngineCore/GameEngineCollision.h> 
#include "GamePlayObjectSpeechPopUp.h"

// Ό³Έν :
enum class MonsterClass
{
	None,
	Nomal,
	Named,
	Boss
};
enum class MonsterCategory
{
	None,
	Human,
	Soul,
	Machine,
};

class GamePlayMonsterHPBar;
class MonsterAbilityStat
{
	friend class CharacterStatManager;
	friend class GamePlayMonster;

public:
	inline unsigned int GetMAXHP() const
	{
		return MAXHP;
	}

	inline unsigned int GetHP() const
	{
		return HP;
	}

	inline float GetDef() const
	{
		return Def;
	}

	inline float GetMaxHPLine() const
	{
		return MAXHPLine;
	}

	unsigned int MAXHP;
	int HP;

	float MAXHPLine;

	float Def;

};
class GameEngineStateManager;
class GamePlayMonster : public GamePlayObject
{
	friend class GamePlayMonsterHPBar;
public:
	// constrcuter destructer
	GamePlayMonster();
	~GamePlayMonster();

	// delete Function
	GamePlayMonster(const GamePlayMonster& _Other) = delete;
	GamePlayMonster(GamePlayMonster&& _Other) noexcept = delete;
	GamePlayMonster& operator=(const GamePlayMonster& _Other) = delete;
	GamePlayMonster& operator=(GamePlayMonster&& _Other) noexcept = delete;

	inline GameEngineCollision* GetBodyCollision() const
	{
		return Collision_HitBody_Top;
	}
	inline MonsterAbilityStat* GetMonsterStat()
	{
		return &MonsterAbilityStat;
	}

	inline MonsterClass GetMonsterClass() const
	{
		return Monster_Class;
	}
	inline const std::string& GetMonsterNameRef()
	{
		return String_MonsterName;
	}
	inline const std::vector<MonsterCategory>& GetMonsterCategory()
	{
		return All_MonsterCategory;
	}


	//inline float4 GetScale() override
	//{
	//	//return Texture_Monster->Get
	//}

	CollisionReturn GetTarget(GameEngineCollision* _This, GameEngineCollision* _Other);
protected:
	GameEngineActor* Actor_Dummy;

	MonsterAbilityStat MonsterAbilityStat;
	void CreateMonsterStat(unsigned int _MAXHP, float Def, float _HPLine = -1.f);

	void Jump_GoingDown() override;
	float GoingDownTime;

	void Start() override;
	void Update(float _Delta) override;
	void LevelStartEvent() override;
	//--------------------Collision---------------
	GameEngineCollision* Collision_HitBody_Top;
	GameEngineCollision* Collision_HitBody_Mid;
	GameEngineCollision* Collision_HitBody_Bottom;

	GamePlayObject* Player_Target;



	//---------------------Texture-----------------
	GameEngineTextureRenderer* Texture_Monster;

	// -----Popup---------------
	GamePlayObjectSpeechPopUp* Actor_SpeechPopUp;


	unsigned int SetHPFromHit(unsigned int _Damage) override;
	unsigned int SetHPFromHit(unsigned int _Damage, const std::vector<float>& _AddDamage) override;

	inline void SetMonsterClass(MonsterClass _Class)
	{
		Monster_Class = _Class;
	}

	inline void SetMonsterName(const std::string& _Name)
	{
		String_MonsterName = _Name;
	}
	inline void SetCategory(MonsterCategory _Category)
	{
		All_MonsterCategory.push_back(_Category);
	}


	// --------CoolTime-----------------
	std::map<std::string, float> All_CollTime;

	//void FSM_Dead_Start(const StateInfo& _Info);
	//void FSM_Dead_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Dead_End(const StateInfo& _Info);


	virtual void Dead();

private:
	float DeadDelay;
	std::string String_MonsterName;
	
	MonsterClass Monster_Class;
	std::vector<MonsterCategory> All_MonsterCategory;
};

