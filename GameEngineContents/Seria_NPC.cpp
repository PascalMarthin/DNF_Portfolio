#include "PreCompile.h"
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineBase/GameEngineTransform.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineTransformComponent.h>
#include "Seria_NPC.h"

Seria_NPC::Seria_NPC() 
	: Seria_Renderer(nullptr)
{
}

Seria_NPC::~Seria_NPC() 
{
}

void Seria_NPC::Start()
{
	GamePlayObjectNPC::Start();
	{
		Seria_Renderer = CreateComponent<GameEngineTextureRenderer>();
		Seria_Renderer->CreateFrameAnimationFolder("Seria_Town_Standing", FrameAnimation_DESC("Seria", 0, 11, 0.25f));

		Seria_Renderer->ChangeFrameAnimation("Seria_Town_Standing");
		Seria_Renderer->ScaleToTexture();
	//	Seria_Renderer->SetPivot(PIVOTMODE::LEFTTOP);
	}
}

void Seria_NPC::Update(float _DeltaTime)
{

} 
