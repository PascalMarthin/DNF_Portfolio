#pragma once
#include <GameEngineCore/GameEngineStateManager.h>
#include "CharacterFighter.h"

// ���� :
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


	void Set_Default_FSMManager() override;
private:

};

