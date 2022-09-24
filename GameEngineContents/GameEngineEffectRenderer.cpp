#include "PreCompile.h"
#include "GameEngineEffectRenderer.h"

GameEngineEffectRenderer::GameEngineEffectRenderer() 
	: FollowSclae(true)
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


void GameEngineEffectRenderer::Update(float _Delta)
{
	GameEngineTextureRenderer::Update(_Delta);
	if (!FollowSclae)
	{
		if (GetActor()->GetTransform().GetWorldScale().x >= 0)
		{
			GetTransform().PixLocalPositiveX();
		}
		else
		{
			GetTransform().PixLocalNegativeX();
		}
	}

}