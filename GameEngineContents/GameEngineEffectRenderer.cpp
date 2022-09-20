#include "PreCompile.h"
#include "GameEngineEffectRenderer.h"

GameEngineEffectRenderer::GameEngineEffectRenderer() 
{
}

GameEngineEffectRenderer::~GameEngineEffectRenderer() 
{
}

void GameEngineEffectRenderer::Start()
{
	GameEngineTextureRenderer::Start();
	ChangeCamera(CAMERAORDER::Object);
}