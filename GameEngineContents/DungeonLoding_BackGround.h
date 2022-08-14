#pragma once
#include "BackGroundParent.h"

// Ό³Έν :
class DungeonLoding_BackGround : public BackGroundParent
{
public:
	// constrcuter destructer
	DungeonLoding_BackGround();
	~DungeonLoding_BackGround();

	// delete Function
	DungeonLoding_BackGround(const DungeonLoding_BackGround& _Other) = delete;
	DungeonLoding_BackGround(DungeonLoding_BackGround&& _Other) noexcept = delete;
	DungeonLoding_BackGround& operator=(const DungeonLoding_BackGround& _Other) = delete;
	DungeonLoding_BackGround& operator=(DungeonLoding_BackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void End() override {}
	// void OnEvent() override
	// void OffEvent() override
private:
	//GameEngineTexture*
};

