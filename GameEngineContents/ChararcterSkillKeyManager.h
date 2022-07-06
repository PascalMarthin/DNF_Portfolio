#pragma once
#include <GameEngineCore/GameEngineComponent.h>

// Ό³Έν :
class ChararcterSkillKeyManager : public GameEngineComponent
{
public:
	// constrcuter destructer
	ChararcterSkillKeyManager();
	~ChararcterSkillKeyManager();

	// delete Function
	ChararcterSkillKeyManager(const ChararcterSkillKeyManager& _Other) = delete;
	ChararcterSkillKeyManager(ChararcterSkillKeyManager&& _Other) noexcept = delete;
	ChararcterSkillKeyManager& operator=(const ChararcterSkillKeyManager& _Other) = delete;
	ChararcterSkillKeyManager& operator=(ChararcterSkillKeyManager&& _Other) noexcept = delete;

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

};

