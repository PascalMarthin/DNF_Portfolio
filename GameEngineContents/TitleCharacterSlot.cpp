#include "PreCompile.h"
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "TitleCharacterSlot.h"

TitleCharacterSlot::TitleCharacterSlot() 
	: Slot_Border(nullptr)
	, Magic_Circle(nullptr)

{
}

TitleCharacterSlot::~TitleCharacterSlot() 
{
}

void TitleCharacterSlot::Start()
{
	Slot_Border = CreateComponent<GameEngineTextureRenderer>();
	Magic_Circle = CreateComponent<GameEngineTextureRenderer>();

	{
		Slot_Border->SetTexture("CharacterSelect_SelectBorder.png");
		Slot_Border->ScaleToTexture();
		Magic_Circle->GetTransform().SetLocalPosition({ 0 , 0 });
	}

	{
		Magic_Circle->SetTexture("CharacterSelect_CaractorCircle.png");
		Magic_Circle->ScaleToTexture();
		Magic_Circle->GetTransform().SetLocalPosition({0 , -70 });
	}
}

void TitleCharacterSlot::Update(float _DeltaTime)
{

}
