#pragma once
#include "CharacterFighter.h"

// Ό³Έν :
class CharacterStryker : public CharacterFighter
{
public:
	// constrcuter destructer
	CharacterStryker();
	~CharacterStryker();

	// delete Function
	CharacterStryker(const CharacterStryker& _Other) = delete;
	CharacterStryker(CharacterStryker&& _Other) noexcept = delete;
	CharacterStryker& operator=(const CharacterStryker& _Other) = delete;
	CharacterStryker& operator=(CharacterStryker&& _Other) noexcept = delete;

protected:
	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

};

