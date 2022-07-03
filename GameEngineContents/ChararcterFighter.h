#pragma once
#include "GamePlayCharacter.h"

// Ό³Έν :
class ChararcterFighter : public GamePlayCharacter
{
public:
	// constrcuter destructer
	ChararcterFighter();
	~ChararcterFighter();

	// delete Function
	ChararcterFighter(const ChararcterFighter& _Other) = delete;
	ChararcterFighter(ChararcterFighter&& _Other) noexcept = delete;
	ChararcterFighter& operator=(const ChararcterFighter& _Other) = delete;
	ChararcterFighter& operator=(ChararcterFighter&& _Other) noexcept = delete;

protected:
	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

};

