#pragma once
#include <GameEngineCore/GameEngineComponent.h>

// Ό³Έν :
class ChararcterKeyManager : public GameEngineComponent
{
public:
	// constrcuter destructer
	ChararcterKeyManager();
	~ChararcterKeyManager();

	// delete Function
	ChararcterKeyManager(const ChararcterKeyManager& _Other) = delete;
	ChararcterKeyManager(ChararcterKeyManager&& _Other) noexcept = delete;
	ChararcterKeyManager& operator=(const ChararcterKeyManager& _Other) = delete;
	ChararcterKeyManager& operator=(ChararcterKeyManager&& _Other) noexcept = delete;

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

};

