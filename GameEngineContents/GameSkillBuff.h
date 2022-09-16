#pragma once
#include "GamePlaySkill.h"

// Ό³Έν :
class GameSkillBuff : public GamePlaySkill
{
	friend class CharacterSkillManager;
public:
	// constrcuter destructer
	GameSkillBuff();
	~GameSkillBuff();

	// delete Function
	GameSkillBuff(const GameSkillBuff& _Other) = delete;
	GameSkillBuff(GameSkillBuff&& _Other) noexcept = delete;
	GameSkillBuff& operator=(const GameSkillBuff& _Other) = delete;
	GameSkillBuff& operator=(GameSkillBuff&& _Other) noexcept = delete;

	//bool BuffCurrentTime(float _Time);
	virtual bool BuffUpdate(CharacterStatManager* _Stat) { return false; }

	virtual void BuffEnd() {}

	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override { return false; };
protected:
	//void LevelStartEvent() override;
	//void LevelEndEvent() override;
	
};

