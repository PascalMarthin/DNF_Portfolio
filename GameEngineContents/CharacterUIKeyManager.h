#pragma once
#include <GameEngineCore/GameEngineComponent.h>

// Ό³Έν :
class CharacterUIKeyManager : public GameEngineComponent
{
public:
	// constrcuter destructer
	CharacterUIKeyManager();
	~CharacterUIKeyManager();

	// delete Function
	CharacterUIKeyManager(const CharacterUIKeyManager& _Other) = delete;
	CharacterUIKeyManager(CharacterUIKeyManager&& _Other) noexcept = delete;
	CharacterUIKeyManager& operator=(const CharacterUIKeyManager& _Other) = delete;
	CharacterUIKeyManager& operator=(CharacterUIKeyManager&& _Other) noexcept = delete;

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

};

