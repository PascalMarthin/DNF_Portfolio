#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// Ό³Έν :
class DungeonSelect_BackGround : public GameEngineActor
{
	friend class DungeonSelect;
public:
	// constrcuter destructer
	DungeonSelect_BackGround();
	~DungeonSelect_BackGround();

	// delete Function
	DungeonSelect_BackGround(const DungeonSelect_BackGround& _Other) = delete;
	DungeonSelect_BackGround(DungeonSelect_BackGround&& _Other) noexcept = delete;
	DungeonSelect_BackGround& operator=(const DungeonSelect_BackGround& _Other) = delete;
	DungeonSelect_BackGround& operator=(DungeonSelect_BackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	// void End() override {}

	void LevelStartEvent() override;
	// void OffEvent() {}
private:
	GameEngineTextureRenderer* Texture_Background;
};

