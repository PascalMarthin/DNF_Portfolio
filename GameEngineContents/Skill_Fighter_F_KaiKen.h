#pragma once
#include "GameSkillBuff.h"
// Ό³Έν :
class Skill_Fighter_F_KaiKen : public GameSkillBuff
{
public:
	// constrcuter destructer
	Skill_Fighter_F_KaiKen();
	~Skill_Fighter_F_KaiKen();

	// delete Function
	Skill_Fighter_F_KaiKen(const Skill_Fighter_F_KaiKen& _Other) = delete;
	Skill_Fighter_F_KaiKen(Skill_Fighter_F_KaiKen&& _Other) noexcept = delete;
	Skill_Fighter_F_KaiKen& operator=(const Skill_Fighter_F_KaiKen& _Other) = delete;
	Skill_Fighter_F_KaiKen& operator=(Skill_Fighter_F_KaiKen&& _Other) noexcept = delete;

	//bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
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
};

