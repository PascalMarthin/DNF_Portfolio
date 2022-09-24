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
	if (nullptr == FontTarget)
	{
		FontTarget = GameEngineRenderTarget::Create("FontTarget");
		FontTarget->CreateRenderTargetTexture(GameEngineWindow::GetScale(), float4::ZERO);
	}

	PushRendererToUICamera();
}