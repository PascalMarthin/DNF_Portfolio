#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlaySkill.h"
// ���� :
class Skill_Fighter_F_DashHit : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_DashHit();
	~Skill_Fighter_F_DashHit();

	// delete Function
	Skill_Fighter_F_DashHit(const Skill_Fighter_F_DashHit& _Other) = delete;
	Skill_Fighter_F_DashHit(Skill_Fighter_F_DashHit&& _Other) noexcept = delete;
	Skill_Fighter_F_DashHit& operator=(const Skill_Fighter_F_DashHit& _Other) = delete;
	Skill_Fighter_F_DashHit& operator=(Skill_Fighter_F_DashHit&& _Other) noexcept = delete;


	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;
	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;


private:
	float MoveDistance;
	bool DelayPunch;
};
