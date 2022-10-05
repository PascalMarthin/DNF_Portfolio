#pragma once
#include "GamePlaySkill.h"

// Ό³Έν :
class Skill_Fighter_F_BaseHit : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_BaseHit();
	~Skill_Fighter_F_BaseHit();

	// delete Function
	Skill_Fighter_F_BaseHit(const Skill_Fighter_F_BaseHit& _Other) = delete;
	Skill_Fighter_F_BaseHit(Skill_Fighter_F_BaseHit&& _Other) noexcept = delete;
	Skill_Fighter_F_BaseHit& operator=(const Skill_Fighter_F_BaseHit& _Other) = delete;
	Skill_Fighter_F_BaseHit& operator=(Skill_Fighter_F_BaseHit&& _Other) noexcept = delete;

	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:
	float MoveDistance;
	float Att_BaseAtt_Delay;
	bool DelayPunch;


	GameEngineSoundPlayer Sound_BaseHit1;
	GameEngineSoundPlayer Sound_BaseHit2;
	GameEngineSoundPlayer Sound_BaseHit3;
	GameEngineSoundPlayer Sound_BaseHit4;
};

