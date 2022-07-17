#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "CharacterFighter.h"
#include "CharacterUIKeyManager.h"
#include <GameEngineCore/GameEngineFolderTexture.h>

GameEngineTextureRenderer* CharacterFighter::FighterRenderer = nullptr;

CharacterFighter::CharacterFighter() 
{
}

CharacterFighter::~CharacterFighter() 
{
}


void CharacterFighter::Start()
{
	if (CharacterFighter::FighterRenderer == nullptr)
	{
		CharacterFighter::FighterRenderer = CreateComponent<GameEngineTextureRenderer>();
	}
	Seria_Renderer 
	SettingCharactorAnimation();


}

void CharacterFighter::SettingCharactorAnimation()
{
	GameEngineFolderTexture* asd = nullptr;
	asd->
	Seria_Renderer->CreateFrameAnimationFolder("Seria_Town_Standing", FrameAnimation_DESC("Seria", 0, 11, 0.25f));

	Seria_Renderer->ChangeFrameAnimation("Seria_Town_Standing");
	Seria_Renderer->GetTransform().SetLocalScale({ 120, 240 });
}

void CharacterFighter::Update(float _DeltaTime)
{

}
