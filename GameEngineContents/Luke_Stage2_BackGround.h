#pragma once
#include "BackGroundParent.h"

// Ό³Έν :
class Luke_Stage2_BackGround : public BackGroundParent
{
public:
	// constrcuter destructer
	Luke_Stage2_BackGround();
	~Luke_Stage2_BackGround();

	// delete Function
	Luke_Stage2_BackGround(const Luke_Stage2_BackGround& _Other) = delete;
	Luke_Stage2_BackGround(Luke_Stage2_BackGround&& _Other) noexcept = delete;
	Luke_Stage2_BackGround& operator=(const Luke_Stage2_BackGround& _Other) = delete;
	Luke_Stage2_BackGround& operator=(Luke_Stage2_BackGround&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void End() override {}
	// void OnEvent() override
	// void OffEvent() override
	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:

	GameEngineTextureRenderer* Texture_Stage2_Door;
	GameEngineTextureRenderer* Texture_Stage2_Door_Close;

	GameEngineCollision* Collision_Stage2_Door;
};
