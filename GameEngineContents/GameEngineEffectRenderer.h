#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
// Ό³Έν :
class GameEngineEffectRenderer : public GameEngineTextureRenderer
{
public:
	// constrcuter destructer
	GameEngineEffectRenderer();
	~GameEngineEffectRenderer();

	// delete Function
	GameEngineEffectRenderer(const GameEngineEffectRenderer& _Other) = delete;
	GameEngineEffectRenderer(GameEngineEffectRenderer&& _Other) noexcept = delete;
	GameEngineEffectRenderer& operator=(const GameEngineEffectRenderer& _Other) = delete;
	GameEngineEffectRenderer& operator=(GameEngineEffectRenderer&& _Other) noexcept = delete;

	inline void SetFollowScaleOn()
	{
		FollowSclae = true;
	}
	inline void SetFollowScaleOff()
	{
		FollowSclae = false;
	}
protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	bool FollowSclae;
};

