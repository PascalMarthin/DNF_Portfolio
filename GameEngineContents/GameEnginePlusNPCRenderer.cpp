#include "PreCompile.h"
#include "GameEnginePlusNPCRenderer.h"

GameEnginePlusNPCRenderer::GameEnginePlusNPCRenderer() 
{
}

GameEnginePlusNPCRenderer::~GameEnginePlusNPCRenderer() 
{
}

void GameEnginePlusNPCRenderer::Start()
{
	GameEngineTextureRenderer::Start();
	ChangeCamera(CAMERAORDER::Object);

}


void GameEnginePlusNPCRenderer::Update(float _Delta)
{
	GameEngineTextureRenderer::Update(_Delta);

}