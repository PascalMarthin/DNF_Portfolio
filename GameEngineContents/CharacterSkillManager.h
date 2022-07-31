#pragma once
#include <GameEngineCore/GameEngineLevel.h>
// Ό³Έν :
class CharacterSkillManager : public GameEngineLevel
{
public:
	// constrcuter destructer
	CharacterSkillManager();
	~CharacterSkillManager();

	// delete Function
	CharacterSkillManager(const CharacterSkillManager& _Other) = delete;
	CharacterSkillManager(CharacterSkillManager&& _Other) noexcept = delete;
	CharacterSkillManager& operator=(const CharacterSkillManager& _Other) = delete;
	CharacterSkillManager& operator=(CharacterSkillManager&& _Other) noexcept = delete;

protected:

	void Start() override;

	void Update(float _DeltaTime) override;

	void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}

private:

};

