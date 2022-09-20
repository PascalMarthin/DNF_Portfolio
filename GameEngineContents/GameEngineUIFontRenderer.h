#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
// Ό³Έν :
class GameEngineUIFontRenderer : public GameEngineTextureRenderer
{
public:
	// constrcuter destructer
	GameEngineUIFontRenderer();
	~GameEngineUIFontRenderer();

	// delete Function
	GameEngineUIFontRenderer(const GameEngineUIFontRenderer& _Other) = delete;
	GameEngineUIFontRenderer(GameEngineUIFontRenderer&& _Other) noexcept = delete;
	GameEngineUIFontRenderer& operator=(const GameEngineUIFontRenderer& _Other) = delete;
	GameEngineUIFontRenderer& operator=(GameEngineUIFontRenderer&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

};

