#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "BackGroundParent.h"
// ���� :
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
	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:

	GameEngineTextureRenderer* Texture_Stage2_Door;
	GameEngineTextureRenderer* Texture_Stage2_Door_Close;

	GameEngineCollision* Collision_Stage2_Door;

	GameEngineUIRenderer* FadeInOut;
	bool MoveMap;
	bool IntotheMap;
};

