#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class TitleCreateCharacterButtonUI;
class TitleCreateCharacter_ClassIllustGIF;
class TitleCreateCharacter_ThumbnailManager;
class TitleCreateCharacterBackGround;
class CharacterCreateLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	CharacterCreateLevel();
	~CharacterCreateLevel();

	// delete Function
	CharacterCreateLevel(const CharacterCreateLevel& _Other) = delete;
	CharacterCreateLevel(CharacterCreateLevel&& _Other) noexcept = delete;
	CharacterCreateLevel& operator=(const CharacterCreateLevel& _Other) = delete;
	CharacterCreateLevel& operator=(CharacterCreateLevel&& _Other) noexcept = delete;


	void ChangeCurrentClass(AllCharacterClass _Class);


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}
private:
	TitleCreateCharacterBackGround* Actor_BackGround;
	TitleCreateCharacter_ThumbnailManager* Actor_ThumbnailManager;
	TitleCreateCharacter_ClassIllustGIF* Actor_ClassIllustGIF;
	TitleCreateCharacterButtonUI* Actor_ButtonManager;

	CharacterClass Enum_CurrentClass;
	void FirstSetting();
};

