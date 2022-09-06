#pragma once
#include "GamePlayObject.h"
#include <GameEngineCore/GameEngineCollision.h> 

// Ό³Έν :
enum class MonsterClass
{
	None,
	Nomal,
	Named,
	Boss
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

private: 
	unsigned int MAXHP;
	unsigned int HP;

	float Def;

};
class GameEngineStateManager;
class GamePlayMonster : public GamePlayObject
{
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


protected:
	MonsterAbilityStat MonsterAbilityStat;
	void CreateMonsterStat(unsigned int _MAXHP, float Def);

	void Jump_GoingDown() override;
	float GoingDownTime;

	void Start() override;
	void LevelStartEvent() override;
	//--------------------Collision---------------
	GameEngineCollision* Collision_HitBody_Top;
	GameEngineCollision* Collision_HitBody_Mid;
	GameEngineCollision* Collision_HitBody_Bottom;


	//---------------------Texture-----------------
	GameEngineTextureRenderer* Texture_Monster;


	unsigned int SetHPFromHit(unsigned int _Damage) override;


	inline void SetMonsterClass(MonsterClass _Class)
	{
		Monster_Class = _Class;
	}
private:
	

	MonsterClass Monster_Class;
};

