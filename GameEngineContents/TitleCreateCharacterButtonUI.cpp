#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GEngine.h>
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
		Actor_GoBackButton = GetLevel()->CreateActor<ButtonComponent>();
		std::vector<GameEngineTexture*> Texture;
		Texture.push_back(GameEngineTexture::Find("CharacterCreate_Ninepatch_GoBack_Off.png"));
		Texture.push_back(GameEngineTexture::Find("CharacterCreate_Ninepatch_GoBack_On.png"));
		Texture.push_back(GameEngineTexture::Find("CharacterCreate_Ninepatch_GoBack_Push.png"));
		Actor_GoBackButton->SetOption(Texture);
		Actor_GoBackButton->GetTransform().SetLocalPosition({ 600, 320 });
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
	if (Actor_GoBackButton->UpdateButtonPush())
	{
		GEngine::ChangeLevel("SelectCharacter");
		return;
	}
}