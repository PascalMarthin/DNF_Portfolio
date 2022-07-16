#include "PreCompile.h"
#include <GameEngineCore/GameEngineComponent.h>
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
	{
		Seria_Renderer = CreateComponent<GameEngineTextureRenderer>();
		//Seria_Renderer->GetTransform().SetLocalScale({ 100, 100, 100 });
		Seria_Renderer->SetTexture("Boss_Left.bmp");

	}
}

void Seria_NPC::Update(float _DeltaTime)
{

}
