#pragma once
#include "GamePlayCharacter.h"

// ���� : ĳ���� ��ǿ� ���õ� Ŭ����
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

