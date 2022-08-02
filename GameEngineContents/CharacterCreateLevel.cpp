#include "PreCompile.h"
#include <GameEngineCore/GameEngineFolderTexture.h>
#include <GameEngineCore/GameEngineTexture.h>
#include "CharacterCreateLevel.h"
#include "TitleCreateCharacterBackGround.h"
#include "MouseCursorComponent.h"
#include "TitleCreateCharacter_ThumbnailManager.h"
#include "TitleCreateCharacter_ClassIllustGIF.h"
#include "TitleCreateCharacterButtonUI.h"

CharacterCreateLevel::CharacterCreateLevel() 
	: Actor_BackGround(nullptr)
	, Enum_CurrentClass(CharacterClass::None)
	, Actor_ThumbnailManager(nullptr)
	, Actor_ClassIllustGIF(nullptr)
	, Actor_ButtonManager(nullptr)
{
}

CharacterCreateLevel::~CharacterCreateLevel() 
{
}

void CharacterCreateLevel::Start()
{
	CreateActor<MouseCursorComponent>();
	Actor_BackGround = CreateActor<TitleCreateCharacterBackGround>();
	Actor_ThumbnailManager = CreateActor<TitleCreateCharacter_ThumbnailManager>();
	Actor_ClassIllustGIF = CreateActor<TitleCreateCharacter_ClassIllustGIF>();
	Actor_ButtonManager = CreateActor<TitleCreateCharacterButtonUI>();
	Actor_ClassIllustGIF->GetTransform().SetLocalScale({ MonitorX, MonitorY });

	FirstSetting();
	{
		
		ChangeCurrentClass(AllCharacterClass::Fighter_F);
	}// 순회해서 제일 가까운 클래스를 초기로 지정
	
}

void CharacterCreateLevel::FirstSetting()
{
	Actor_ClassIllustGIF->CreateClassIllustGIF("Fighter_F", "CharacterCreate_Fighter_F_GIF");
	Actor_ClassIllustGIF->CreateClassIllustGIF("Gunner_M", "CharacterCreate_Gunner_M_GIF");
}

void CharacterCreateLevel::Update(float _DeltaTime)
{

}


void CharacterCreateLevel::ChangeCurrentClass(AllCharacterClass _Class)
{
	GameEngineTexture* BackGroundTexture = nullptr;
	std::string ClassIllustGIF = "";

	switch (_Class)
	{
	case AllCharacterClass::Fighter_F:
		BackGroundTexture = GameEngineTexture::Find("CharacterCreate_Background_Fighter_F.png");
		ClassIllustGIF = "Fighter_F";
		break;
	case AllCharacterClass::Gunner_M:
		BackGroundTexture = GameEngineTexture::Find("CharacterCreate_Background_Gunner_M.png");
		ClassIllustGIF = "Gunner_M";
		break;
	case AllCharacterClass::None:
	case AllCharacterClass::Swordman_M:
	case AllCharacterClass::Swordman_F:
	case AllCharacterClass::Fighter_M:
	case AllCharacterClass::Gunner_F:
	case AllCharacterClass::Mage_M:
	case AllCharacterClass::Mage_F:
	case AllCharacterClass::Priest_M:
	case AllCharacterClass::Priest_F:
	case AllCharacterClass::Thief:
	case AllCharacterClass::Knight:
	case AllCharacterClass::Demoniclancer:
	case AllCharacterClass::Gunblader:
	case AllCharacterClass::Darknight:
	case AllCharacterClass::Creator:
	case AllCharacterClass::AllCharacterClass_Max:
		//MsgBoxAssert("배경화면이 없는 클래스입니다")
	default:
		break;
	}

	if (BackGroundTexture == nullptr || ClassIllustGIF == "")
	{
		return;
	}
	Actor_ThumbnailManager->SetSelectCharacter(_Class);
	Actor_BackGround->SetChangeClass(BackGroundTexture);
	Actor_ClassIllustGIF->SetClassIllustGIF(ClassIllustGIF);
}

