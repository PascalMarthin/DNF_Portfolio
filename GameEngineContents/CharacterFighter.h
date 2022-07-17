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

	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	void SettingCharactorAnimation();

private:
	static GameEngineTextureRenderer* FighterRenderer;


};

