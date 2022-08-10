#include "PreCompile.h"
#include <GameEngineCore/GameEngineFolderTexture.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GEngine.h>
#include "CharacterCreateLevel.h"
#include "TitleCreateCharacterBackGround.h"
#include "MouseCursorComponent.h"
#include "TitleCreateCharacter_ThumbnailManager.h"
#include "TitleCreateCharacter_ClassIllustGIF.h"
#include "TitleCreateCharacterButtonUI.h"
#include "GamePlayCharacter.h"
#include "ButtonComponent.h"
#include "SelectCharacterLevel.h"
#include "GamePlayDataBase.h"

AllCharacterClass CharacterCreateLevel::Enum_CurrentClass = AllCharacterClass::None;

CharacterCreateLevel::CharacterCreateLevel() 
	: Actor_BackGround(nullptr)
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


	// Debug
	CharacterCreateLevel::Enum_CurrentClass = AllCharacterClass::Fighter_F;
	CharacterCreateLevel::CreateCharacter();
	// Debug

	
}

void CharacterCreateLevel::FirstSetting()
{
	Actor_ClassIllustGIF->CreateClassIllustGIF("Fighter_F", "CharacterCreate_Fighter_F_GIF");
	Actor_ClassIllustGIF->CreateClassIllustGIF("Gunner_M", "CharacterCreate_Gunner_M_GIF");
}

void CharacterCreateLevel::Update(float _DeltaTime)
{
	if (Actor_ButtonManager->GetCreateCharacterButton()->UpdateButtonPush())
	{
		CreateCharacter();
	}
}

void CharacterCreateLevel::CreateCharacter()
{
	GamePlayDataBase* CharacterData = nullptr;
	switch (CharacterCreateLevel::Enum_CurrentClass)
	{
	case AllCharacterClass::Fighter_F:
		CharacterData = GamePlayCharacter::CreateCharacterBase(CharacterFormerClass::Striker);
		break;
	case AllCharacterClass::Gunner_M:
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
	case AllCharacterClass::None:
	case AllCharacterClass::AllCharacterClass_Max:
		MsgBoxAssert("존재하지 않는 클래스들입니다")
	default:
		break;
	}
	SelectCharacterLevel::PushCharacterData(CharacterData);
	GEngine::ChangeLevel("SelectCharacter");
}

void CharacterCreateLevel::OnEvent()
{
	ChangeCurrentClass(AllCharacterClass::Fighter_F);
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
	CharacterCreateLevel::Enum_CurrentClass = _Class;
	Actor_ThumbnailManager->SetSelectCharacter(_Class);
	Actor_BackGround->SetChangeClass(BackGroundTexture);
	Actor_ClassIllustGIF->SetClassIllustGIF(ClassIllustGIF);
}
