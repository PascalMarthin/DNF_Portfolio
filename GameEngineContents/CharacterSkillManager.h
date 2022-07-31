#pragma once
#include <GameEngineCore/GameEngineComponent.h>
// Ό³Έν :
class CharacterSkillManager : public GameEngineComponent
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

	void OnEvent();
	void OffEvent();

private:
	std::function<void()> Input_SkillSlot_01;
	std::function<void()> Input_SkillSlot_02;
	std::function<void()> Input_SkillSlot_03;
	std::function<void()> Input_SkillSlot_04;
	std::function<void()> Input_SkillSlot_05;
	std::function<void()> Input_SkillSlot_06;
	std::function<void()> Input_SkillSlot_07;
	std::function<void()> Input_SkillSlot_08;
	std::function<void()> Input_SkillSlot_09;
	std::function<void()> Input_SkillSlot_10;
	std::function<void()> Input_SkillSlot_11;
	std::function<void()> Input_SkillSlot_12;
	std::function<void()> Input_SkillSlot_13;
	std::function<void()> Input_SkillSlot_14;
};

