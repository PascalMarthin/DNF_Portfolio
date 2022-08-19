#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>

// Ό³Έν :
class DungeonSelect_Slot : public GameEngineActor
{
	friend class DungeonSelect;
public:
	// constrcuter destructer
	DungeonSelect_Slot();
	~DungeonSelect_Slot();

	// delete Function
	DungeonSelect_Slot(const DungeonSelect_Slot& _Other) = delete;
	DungeonSelect_Slot(DungeonSelect_Slot&& _Other) noexcept = delete;
	DungeonSelect_Slot& operator=(const DungeonSelect_Slot& _Other) = delete;
	DungeonSelect_Slot& operator=(DungeonSelect_Slot&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	// void End() override {}

	void LevelStartEvent() override;
	// void OffEvent() {}
private:

	GameEngineTextureRenderer* Texture_DungeonSelect_Slot;
	GameEngineTextureRenderer* Texture_DungeonSelect_SlotBorder;
	GameEngineTextureRenderer* Texture_DungeonSelect_SelectBorder;
	GameEngineTextureRenderer* Texture_BubblePoint;

	GameEngineCollision* Collision_DungeonSelect;
};

