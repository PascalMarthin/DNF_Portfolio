#include "PreCompile.h"
#include "TitleCreateCharacterBackGround.h"
#include "GamePlayEnum.h"

TitleCreateCharacterBackGround::TitleCreateCharacterBackGround() 
	: Texture_BackGround(nullptr)
{
}

TitleCreateCharacterBackGround::~TitleCreateCharacterBackGround() 
{
}

void TitleCreateCharacterBackGround::Start()
{
	Texture_BackGround = CreateComponent<GameEngineTextureRenderer>();
	Texture_BackGround->GetTransform().SetLocalScale(GameEngineWindow::GetScale());
	GetTransform().SetLocalPosition({ 0, 0, ZSortOrder::BackGround });
}

void TitleCreateCharacterBackGround::Update(float _DeltaTime)
{

}

void TitleCreateCharacterBackGround::SetChangeClass(GameEngineTexture* _Texture)
{
	Texture_BackGround->SetTexture(_Texture);
}