#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "GamePlaySkill.h"

// Ό³Έν :
class Skill_Fighter_F_Ham_Kick : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_Ham_Kick();
	~Skill_Fighter_F_Ham_Kick();

	// delete Function
	Skill_Fighter_F_Ham_Kick(const Skill_Fighter_F_Ham_Kick& _Other) = delete;
	Skill_Fighter_F_Ham_Kick(Skill_Fighter_F_Ham_Kick&& _Other) noexcept = delete;
	Skill_Fighter_F_Ham_Kick& operator=(const Skill_Fighter_F_Ham_Kick& _Other) = delete;
	Skill_Fighter_F_Ham_Kick& operator=(Skill_Fighter_F_Ham_Kick&& _Other) noexcept = delete;

	bool TriggerSkill(GameEngineCollision* _This, GameEngineCollision* _Other) override;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:
	GameEngineCollision* Collision_HamerKick;


};

