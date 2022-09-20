#include "PreCompile.h"
#include "GameEngineUIFontRenderer.h"

GameEngineUIFontRenderer::GameEngineUIFontRenderer() 
{
}

GameEngineUIFontRenderer::~GameEngineUIFontRenderer() 
{
}

void GameEngineUIFontRenderer::Start()
{
	GameEngineTextureRenderer::Start();
	ChangeCamera(CAMERAORDER::UIFont);
}