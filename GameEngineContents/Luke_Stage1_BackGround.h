#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "BackGroundParent.h"
// Ό³Έν :
class Luke_Stage1_BackGround : public BackGroundParent
{
public:
	// constrcuter destructer
	Luke_Stage1_BackGround();
	~Luke_Stage1_BackGround();

	// delete Function
	Luke_Stage1_BackGround(const Luke_Stage1_BackGround& _Other) = delete;
	Luke_Stage1_BackGround(Luke_Stage1_BackGround&& _Other) noexcept = delete;
	Luke_Stage1_BackGround& operator=(const Luke_Stage1_BackGround& _Other) = delete;
	Luke_Stage1_BackGround& operator=(Luke_Stage1_BackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void End() override {}
	// void OnEvent() override
	// void OffEvent() override

private:
	GameEngineTextureRenderer* Texture_Black;

	GameEngineCollision* Collision_Jelva1F_Door;
	GameEngineCollision* Collision_Jelva2F_01_Door;
};

