#include "PreCompile.h"
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineBase/GameEngineTransform.h>
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
	GetTransform().SetLocalPosition({ 0, -50.f, 30});

		Seria_Renderer = CreateComponent<GameEngineTextureRenderer>();
		Seria_Renderer->CreateFrameAnimationFolder("Seria_Town_Standing", FrameAnimation_DESC("Seria", 0, 11, 0.25f));

		Seria_Renderer->ChangeFrameAnimation("Seria_Town_Standing");
		Seria_Renderer->ScaleToTexture();
		float4 GetLocal = Seria_Renderer->GetTransform().GetLocalScale();
		GetLocal;

}

void Seria_NPC::Update(float _DeltaTime)
{
	float4 GetLocal = GetTransform().GetLocalPosition();
} 
