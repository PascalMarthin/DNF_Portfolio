#pragma once
#include <GameEngineCore/GameEngineTransformComponent.h>
#include "GamePlaySkill.h"
// Ό³Έν :
class CharacterSkillManager : public GameEngineTransformComponent
{
	friend class CharacterStatManager;
public:
	static CharacterSkillManager* GetInst()
	{
		return Inst;
	}
	// constrcuter destructer
	CharacterSkillManager();
	~CharacterSkillManager();

	// delete Function
	CharacterSkillManager(const CharacterSkillManager& _Other) = delete;
	CharacterSkillManager(CharacterSkillManager&& _Other) noexcept = delete;
	CharacterSkillManager& operator=(const CharacterSkillManager& _Other) = delete;
	CharacterSkillManager& operator=(CharacterSkillManager&& _Other) noexcept = delete;

	GamePlaySkill* PossibleSkillReturn(char _Char);

	inline void InsertBuff(AllSkillEnum _Skill, float _BuffTime )
	{
		Staic_BuffTime[_Skill] = _BuffTime;
	}

	inline void InsertBuffStat(AllSkillEnum _Skill, StatClass _Class, int _Index)
	{
		if (Staic_BuffTime[_Skill] > 0)
		{
			Static_StatBuff[_Skill][_Class] = _Index;
		}
	}

protected:

	void Start() override;

	void Update(float _DeltaTime) override;

	void End() override {}

	void LevelStartEvent() override;
	void LevelEndEvent() override;
	//void OnEvent();
	//void OffEvent();

private:

	std::map<char, GamePlaySkill*> map_SkillSlot;
	std::map<AllSkillEnum, GamePlaySkill*> List_AllSkill;

	static std::map<AllSkillEnum, float> Staic_CoolTime;
	static std::map<AllSkillEnum, float> Staic_BuffTime;
	static std::map<AllSkillEnum, std::map<StatClass, int>> Static_StatBuff;


	static CharacterSkillManager* Inst;
	//std::function<void()> Input_SkillSlot_01;
	//std::function<void()> Input_SkillSlot_02;
	//std::function<void()> Input_SkillSlot_03;
	//std::function<void()> Input_SkillSlot_04;
	//std::function<void()> Input_SkillSlot_05;
	//std::function<void()> Input_SkillSlot_06;
	//std::function<void()> Input_SkillSlot_07;
	//std::function<void()> Input_SkillSlot_08;
	//std::function<void()> Input_SkillSlot_09;
	//std::function<void()> Input_SkillSlot_10;
	//std::function<void()> Input_SkillSlot_11;
	//std::function<void()> Input_SkillSlot_12;
	//std::function<void()> Input_SkillSlot_13;
	//std::function<void()> Input_SkillSlot_14;
};

