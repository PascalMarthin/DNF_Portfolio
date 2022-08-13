#pragma once
#include "BattleLevel.h"

// Ό³Έν :
enum class Luke_Stage
{
	None,
	Stage_1,
	Stage_2,
	Stage_3,
	Stage_4,
	Stage_Boss
};
class Dungeon_Luke : public BattleLevel
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

protected:
	inline static void SetStage(Luke_Stage _Stage)
	{
		CurrentStage = _Stage;
	}
	inline static Luke_Stage GetStage()
	{
		return CurrentStage;
	}

private:
	static Luke_Stage CurrentStage;

};

