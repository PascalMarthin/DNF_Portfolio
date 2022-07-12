#pragma once
#include "GamePlayCharacter.h"

// 설명 : 캐릭터 모션에 관련된 클래스
class CharacterFighter : public GamePlayCharacter
{
public:
	// constrcuter destructer
	CharacterFighter();
	~CharacterFighter();

	// delete Function
	CharacterFighter(const CharacterFighter& _Other) = delete;
	CharacterFighter(CharacterFighter&& _Other) noexcept = delete;
	CharacterFighter& operator=(const CharacterFighter& _Other) = delete;
	CharacterFighter& operator=(CharacterFighter&& _Other) noexcept = delete;

protected:

private:

};

