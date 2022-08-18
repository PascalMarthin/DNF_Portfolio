#pragma once
#include "GamePlayObject.h"
#include <GameEngineCore/GameEngineCollision.h> 

// Ό³Έν :
class MonsterAbilityStat
{
	friend class CharacterStatManager;
	friend class GamePlayMonster;

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
		return Collision_HitBody;
	}
	inline MonsterAbilityStat* GetMonsterStat()
	{
		return &MonsterAbilityStat;
	}


protected:
	MonsterAbilityStat MonsterAbilityStat;
	void CreateMonsterStat(unsigned int _MAXHP, float Def);

	void Jump_GoingDown() override;
	float GoingDownTime;

	void Start() override;
	void OnEvent() override;
	//--------------------Collision---------------
	GameEngineCollision* Collision_HitBody;


	//---------------------Texture-----------------
	GameEngineTextureRenderer* Texture_Monster;

private:
	

};

