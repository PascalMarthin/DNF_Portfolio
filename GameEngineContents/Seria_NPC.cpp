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
	//GetTransform().SetWorldPosition({ 0, -50.f, 30 });
	{
		Seria_Renderer = CreateComponent<GameEngineTextureRenderer>();
		Seria_Renderer->CreateFrameAnimationFolder("Seria_Town_Standing", FrameAnimation_DESC("Seria", 0, 11, 0.25f));

		Seria_Renderer->ChangeFrameAnimation("Seria_Town_Standing");
		Seria_Renderer->ScaleToTexture();
	}

}

void Seria_NPC::Update(float _DeltaTime)
{
	GameEngineDebug::OutPutString(
		std::to_string(Seria_Renderer->GetTransform().GetWorldPosition().x) + "  " +
		std::to_string(Seria_Renderer->GetTransform().GetWorldPosition().y) + "  " +
		std::to_string(Seria_Renderer->GetTransform().GetWorldPosition().x) + "  " +
		std::to_string(Seria_Renderer->GetTransform().GetWorldPosition().y));
} 
