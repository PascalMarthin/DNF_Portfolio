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
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("Object");
		Dir.Move("NPC");
		Dir.Move("Seria");

		GameEngineFolderTexture::Load(Dir.GetFullPath());
	}
	{
		Seria_Renderer = CreateComponent<GameEngineTextureRenderer>();
		Seria_Renderer->CreateFrameAnimationFolder("Seria_Town_Standing", FrameAnimation_DESC("Seria", 0, 11, 0.25f));

		Seria_Renderer->ChangeFrameAnimation("Seria_Town_Standing");
		Seria_Renderer->GetTransform().SetLocalScale({ 120, 240 });

	}
}

void Seria_NPC::Update(float _DeltaTime)
{

}
