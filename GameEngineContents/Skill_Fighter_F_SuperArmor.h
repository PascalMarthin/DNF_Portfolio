#pragma once
#include "GameSkillBuff.h"

// Ό³Έν :
class Skill_Fighter_F_SuperArmor : public GameSkillBuff
{
public:
	// constrcuter destructer
	Skill_Fighter_F_SuperArmor();
	~Skill_Fighter_F_SuperArmor();

	// delete Function
	Skill_Fighter_F_SuperArmor(const Skill_Fighter_F_SuperArmor& _Other) = delete;
	Skill_Fighter_F_SuperArmor(Skill_Fighter_F_SuperArmor&& _Other) noexcept = delete;
	Skill_Fighter_F_SuperArmor& operator=(const Skill_Fighter_F_SuperArmor& _Other) = delete;
	Skill_Fighter_F_SuperArmor& operator=(Skill_Fighter_F_SuperArmor&& _Other) noexcept = delete;

	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
	bool BuffUpdate(CharacterStatManager* _Stat) override;
	void BuffEnd() override;

protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:
	//GameEngineEffectRenderer* Texture_Upper;
};

