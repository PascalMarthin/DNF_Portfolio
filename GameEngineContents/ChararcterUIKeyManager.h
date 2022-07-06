#pragma once
#include <GameEngineCore/GameEngineComponent.h>

// Ό³Έν :
class ChararcterUIKeyManager : public GameEngineComponent
{
public:
	// constrcuter destructer
	ChararcterUIKeyManager();
	~ChararcterUIKeyManager();

	// delete Function
	ChararcterUIKeyManager(const ChararcterUIKeyManager& _Other) = delete;
	ChararcterUIKeyManager(ChararcterUIKeyManager&& _Other) noexcept = delete;
	ChararcterUIKeyManager& operator=(const ChararcterUIKeyManager& _Other) = delete;
	ChararcterUIKeyManager& operator=(ChararcterUIKeyManager&& _Other) noexcept = delete;

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

};

