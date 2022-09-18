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
enum class MonsterCategory
{
	None,
	Human,
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

private: 
	unsigned int MAXHP;
	unsigned int HP;

	float MAXHPLine;

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


protected:
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


	//---------------------Texture-----------------
	GameEngineTextureRenderer* Texture_Monster;


	unsigned int SetHPFromHit(unsigned int _Damage) override;


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


private:
	std::string String_MonsterName;
	
	MonsterClass Monster_Class;
	std::vector<MonsterCategory> All_MonsterCategory;
};

