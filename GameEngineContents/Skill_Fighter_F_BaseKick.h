#pragma once
#include "GamePlaySkill.h"
// Ό³Έν :
class Skill_Fighter_F_BaseKick : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_BaseKick();
	~Skill_Fighter_F_BaseKick();

	// delete Function
	Skill_Fighter_F_BaseKick(const Skill_Fighter_F_BaseKick& _Other) = delete;
	Skill_Fighter_F_BaseKick(Skill_Fighter_F_BaseKick&& _Other) noexcept = delete;
	Skill_Fighter_F_BaseKick& operator=(const Skill_Fighter_F_BaseKick& _Other) = delete;
	Skill_Fighter_F_BaseKick& operator=(Skill_Fighter_F_BaseKick&& _Other) noexcept = delete;


	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:
	void CheckCollision() override;

};

