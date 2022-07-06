#pragma once
#include <GameEngineCore/GameEngineComponent.h>

// Ό³Έν :
class CharacterSkillKeyManager : public GameEngineComponent
{
public:
	// constrcuter destructer
	CharacterSkillKeyManager();
	~CharacterSkillKeyManager();

	// delete Function
	CharacterSkillKeyManager(const CharacterSkillKeyManager& _Other) = delete;
	CharacterSkillKeyManager(CharacterSkillKeyManager&& _Other) noexcept = delete;
	CharacterSkillKeyManager& operator=(const CharacterSkillKeyManager& _Other) = delete;
	CharacterSkillKeyManager& operator=(CharacterSkillKeyManager&& _Other) noexcept = delete;

protected:

	void Update(float _DeltaTime) override;

	void OnEvent() override {}

	void OffEvent() override {}

	void Start() override;

	void End() override;

private:

};

