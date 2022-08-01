#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "GamePlayEnum.h"

// Ό³Έν :
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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}
private:
	TitleCreateCharacterBackGround* Actor_BackGround;
	TitleCreateCharacter_ThumbnailManager* Actor_Thumbnail;

	CharacterClass Enum_CurrentClass;
	void ChangeCurrentClass(CharacterClass _Class);
};

