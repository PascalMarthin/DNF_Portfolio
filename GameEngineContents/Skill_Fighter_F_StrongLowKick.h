#pragma once
#include "GamePlaySkill.h"

// Ό³Έν :
class Skill_Fighter_F_StrongLowKick : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_StrongLowKick();
	~Skill_Fighter_F_StrongLowKick();

	// delete Function
	Skill_Fighter_F_StrongLowKick(const Skill_Fighter_F_StrongLowKick& _Other) = delete;
	Skill_Fighter_F_StrongLowKick(Skill_Fighter_F_StrongLowKick&& _Other) noexcept = delete;
	Skill_Fighter_F_StrongLowKick& operator=(const Skill_Fighter_F_StrongLowKick& _Other) = delete;
	Skill_Fighter_F_StrongLowKick& operator=(Skill_Fighter_F_StrongLowKick&& _Other) noexcept = delete;

protected:

private:

};

