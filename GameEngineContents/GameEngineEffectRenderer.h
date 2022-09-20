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

protected:
	void Start() override;
private:

};

