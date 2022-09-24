#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>

// Ό³Έν :
class GameEnginePlusNPCRenderer : public GameEngineTextureRenderer
{
public:
	// constrcuter destructer
	GameEnginePlusNPCRenderer();
	~GameEnginePlusNPCRenderer();

	// delete Function
	GameEnginePlusNPCRenderer(const GameEnginePlusNPCRenderer& _Other) = delete;
	GameEnginePlusNPCRenderer(GameEnginePlusNPCRenderer&& _Other) noexcept = delete;
	GameEnginePlusNPCRenderer& operator=(const GameEnginePlusNPCRenderer& _Other) = delete;
	GameEnginePlusNPCRenderer& operator=(GameEnginePlusNPCRenderer&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;
private:



};

