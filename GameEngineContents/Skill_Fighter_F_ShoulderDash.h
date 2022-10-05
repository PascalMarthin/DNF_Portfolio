#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlaySkill.h"

// Ό³Έν :
class Skill_Fighter_F_ShoulderDash : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_ShoulderDash();
	~Skill_Fighter_F_ShoulderDash();

	// delete Function
	Skill_Fighter_F_ShoulderDash(const Skill_Fighter_F_ShoulderDash& _Other) = delete;
	Skill_Fighter_F_ShoulderDash(Skill_Fighter_F_ShoulderDash&& _Other) noexcept = delete;
	Skill_Fighter_F_ShoulderDash& operator=(const Skill_Fighter_F_ShoulderDash& _Other) = delete;
	Skill_Fighter_F_ShoulderDash& operator=(Skill_Fighter_F_ShoulderDash&& _Other) noexcept = delete;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;
	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
	void EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;


private:
	GameEngineTextureRenderer* Texture_Effect;
	static bool FirstTime;

	float MoveDistance;
	bool DelayPunch;
};
