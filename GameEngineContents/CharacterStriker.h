#pragma once
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterFighter.h"

// Ό³Έν :
class CharacterStriker : public CharacterFighter
{
public:
	// constrcuter destructer
	CharacterStriker();
	~CharacterStriker();

	// delete Function
	CharacterStriker(const CharacterStriker& _Other) = delete;
	CharacterStriker(CharacterStriker&& _Other) noexcept = delete;
	CharacterStriker& operator=(const CharacterStriker& _Other) = delete;
	CharacterStriker& operator=(CharacterStriker&& _Other) noexcept = delete;

protected:
	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;


	void Set_Default_FSMManager() override;
private:

};

