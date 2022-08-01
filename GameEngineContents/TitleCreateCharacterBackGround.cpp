#include "PreCompile.h"
#include "TitleCreateCharacterBackGround.h"
#include "GamePlayEnum.h"

TitleCreateCharacterBackGround::TitleCreateCharacterBackGround() 
	: Texture_BackGround(nullptr)
	, Enum_CurrentClass(CharacterClass::None)
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

void TitleCreateCharacterBackGround::ChangeClass(CharacterClass _Class)
{
	Enum_CurrentClass = _Class;
	switch (Enum_CurrentClass)
	{
	case CharacterClass::Fighter_F:
		Texture_BackGround->SetTexture("CharacterCreate_Background_Fighter_F.png");
		break;
	case CharacterClass::Gunner_M:
		Texture_BackGround->SetTexture("CharacterCreate_Background_Gunner_M.png");
		break;
	case CharacterClass::None:
	default:
		MsgBoxAssert("아직 클래스가 설정 되지 않았습니다")
		break;
	}
}