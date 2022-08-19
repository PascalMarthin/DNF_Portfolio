#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlayEnum.h"

// ���� :
class DungeonSelect_BackGround;
class DungeonSelect_Slot;
class DungeonSelect : public GameEngineLevel
{
public:
	// constrcuter destructer
	DungeonSelect();
	~DungeonSelect();

	// delete Function
	DungeonSelect(const DungeonSelect& _Other) = delete;
	DungeonSelect(DungeonSelect&& _Other) noexcept = delete;
	DungeonSelect& operator=(const DungeonSelect& _Other) = delete;
	DungeonSelect& operator=(DungeonSelect&& _Other) noexcept = delete;

	inline static WorldDungeon GetWorldDungeon()
	{
		return DungeonSelect::CurrentWorldDungeon;
	}

	inline static void SetWorldDungeon(WorldDungeon _Dungeon)
	{
		DungeonSelect::CurrentWorldDungeon = _Dungeon;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	void LevelStartEvent() override;
	void LevelEndEvent() override;

private:
	DungeonSelect_BackGround* Actor_BackGround;
	std::vector<DungeonSelect_Slot*> Data_SlotActor;
	std::vector<GameEngineTextureRenderer*> Texture_DungeonPoint;
	// ���� �߰��� vector ���



	void SetLukeDungeon();
	// Static-----------------

	static WorldDungeon CurrentWorldDungeon;

};

