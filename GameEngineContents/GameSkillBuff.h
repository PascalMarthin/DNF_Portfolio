#pragma once
#include "GamePlaySkill.h"

// Ό³Έν :
class GameSkillBuff : public GamePlaySkill
{
public:
	// constrcuter destructer
	GameSkillBuff();
	~GameSkillBuff();

	// delete Function
	GameSkillBuff(const GameSkillBuff& _Other) = delete;
	GameSkillBuff(GameSkillBuff&& _Other) noexcept = delete;
	GameSkillBuff& operator=(const GameSkillBuff& _Other) = delete;
	GameSkillBuff& operator=(GameSkillBuff&& _Other) noexcept = delete;

	bool BuffCurrentTime(float _Time);
	virtual bool BuffUpdate(CharacterStatManager* _Stat) {}

	virtual void BuffEnd() {}
protected:
	float BuffTime;
};

