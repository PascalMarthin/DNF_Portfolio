#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "TitleCreateCharacterButtonUI.h"
#include "ButtonComponent.h"

TitleCreateCharacterButtonUI::TitleCreateCharacterButtonUI() 
	: Actor_CreateCharacterButton(nullptr)
	, Texture_BackButton(nullptr)
	, Collision_BackButton(nullptr)
{
}

TitleCreateCharacterButtonUI::~TitleCreateCharacterButtonUI() 
{
}

void TitleCreateCharacterButtonUI::Start()
{
	{
		Actor_CreateCharacterButton = GetLevel()->CreateActor<ButtonComponent>();
		Actor_CreateCharacterButton->SetOption(ButtonSize::LongLong);
		Actor_CreateCharacterButton->GetTransform().SetLocalPosition({-300, -100});
	}

	{
		//Texture_BackButton = CreateComponent<GameEngineTextureRenderer>();
		//Collision_BackButton = CreateComponent<GameEngineCollision>();
		//Texture_BackButton->SetTexture("Ninepatch_BlueButton_LongLong_Off.png");
		//Texture_BackButton->ScaleToTexture();
		//Collision_BackButton->GetTransform().SetLocalScale(Texture_BackButton->GetTransform().GetLocalScale());
	}



}
void TitleCreateCharacterButtonUI::Update(float _DeltaTime)
{
	Actor_CreateCharacterButton->UpdateButtonPush();
}