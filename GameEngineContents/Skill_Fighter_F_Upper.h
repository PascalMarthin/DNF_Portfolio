#pragma once
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlaySkill.h"

// Ό³Έν :
class Skill_Fighter_F_Upper : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_Upper();
	~Skill_Fighter_F_Upper();

	// delete Function
	Skill_Fighter_F_Upper(const Skill_Fighter_F_Upper& _Other) = delete;
	Skill_Fighter_F_Upper(Skill_Fighter_F_Upper&& _Other) noexcept = delete;
	Skill_Fighter_F_Upper& operator=(const Skill_Fighter_F_Upper& _Other) = delete;
	Skill_Fighter_F_Upper& operator=(Skill_Fighter_F_Upper&& _Other) noexcept = delete;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:

};

