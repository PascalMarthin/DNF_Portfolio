#pragma once
#include "BattleLevel.h"
#include "GamePlayLevelTemplate.h"
#include "GamePlayMonster.h"

// Ό³Έν :
class GamePlayMonsterHPBar;
class GameEngineLevel;
class GamePlayMonster;
enum class Luke_Stage
{
	None,
	Stage_1,
	Stage_2,
	Stage_3,
	Stage_4,
	Stage_Boss
};
class Dungeon_Luke : public GamePlayLevelTemplate, public BattleLevel
{
public:
	// constrcuter destructer
	Dungeon_Luke();
	~Dungeon_Luke();

	// delete Function
	Dungeon_Luke(const Dungeon_Luke& _Other) = delete;
	Dungeon_Luke(Dungeon_Luke&& _Other) noexcept = delete;
	Dungeon_Luke& operator=(const Dungeon_Luke& _Other) = delete;
	Dungeon_Luke& operator=(Dungeon_Luke&& _Other) noexcept = delete;

	inline bool IsAllMonsterDie()
	{
		for (auto& Iter : vector_AllMonster)
		{
			if (Iter->IsUpdate()) 
			{
				return false;
			}
		}
		return true;
	}

	inline std::vector<GamePlayMonster*>& GetAllMonster()
	{
		return vector_AllMonster;
	}

protected:
	inline static void SetStage(Luke_Stage _Stage)
	{
		CurrentStage = _Stage;
	}
	inline static Luke_Stage GetStage()
	{
		return CurrentStage;
	}

	std::vector<GamePlayMonster*> vector_AllMonster;

private:
	static Luke_Stage CurrentStage;

	GamePlayMonsterHPBar* Actor_MonsterHP;


};

