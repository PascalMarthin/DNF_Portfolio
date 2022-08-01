#include "PreCompile.h"
#include "CharacterCreateLevel.h"
#include "TitleCreateCharacterBackGround.h"
#include "MouseCursorComponent.h"
#include "TitleCreateCharacter_ThumbnailManager.h"

CharacterCreateLevel::CharacterCreateLevel() 
	: Actor_BackGround(nullptr)
	, Enum_CurrentClass(CharacterClass::None)
	, Actor_Thumbnail(nullptr)
{
}

CharacterCreateLevel::~CharacterCreateLevel() 
{
}

void CharacterCreateLevel::Start()
{
	CreateActor<MouseCursorComponent>();
	Actor_BackGround = CreateActor<TitleCreateCharacterBackGround>();
	Actor_Thumbnail = CreateActor<TitleCreateCharacter_ThumbnailManager>();
	{
		int Class = static_cast<int>(CharacterClass::None);
		++Class;
		Enum_CurrentClass = static_cast<CharacterClass>(Class);
		ChangeCurrentClass(Enum_CurrentClass);
	}// 순회해서 제일 가까운 클래스를 초기로 지정
	
}

void CharacterCreateLevel::Update(float _DeltaTime)
{

}


void CharacterCreateLevel::ChangeCurrentClass(CharacterClass _Class)
{
	Actor_BackGround->ChangeClass(_Class);
}