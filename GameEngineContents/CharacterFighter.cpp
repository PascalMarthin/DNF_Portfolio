#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "CharacterFighter.h"
#include "CharacterUIKeyManager.h"
#include <GameEngineCore/GameEngineFolderTexture.h>

CharacterFighter::CharacterFighter() 
{
}

CharacterFighter::~CharacterFighter() 
{
}


void CharacterFighter::Start()
{
	GamePlayCharacter::Start();
}




void CharacterFighter::SettingCharactorAnimation(GameEngineTextureRenderer* _TextureRenderer)
{
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());
	_TextureRenderer->CreateFrameAnimationFolder("", FrameAnimation_DESC());

}

void CharacterFighter::Update(float _DeltaTime)
{

}
