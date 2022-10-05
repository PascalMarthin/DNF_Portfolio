#pragma once
#include "GamePlaySkill.h"

// Ό³Έν :
class Skill_Fighter_F_LowKick : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_LowKick();
	~Skill_Fighter_F_LowKick();

	// delete Function
	Skill_Fighter_F_LowKick(const Skill_Fighter_F_LowKick& _Other) = delete;
	Skill_Fighter_F_LowKick(Skill_Fighter_F_LowKick&& _Other) noexcept = delete;
	Skill_Fighter_F_LowKick& operator=(const Skill_Fighter_F_LowKick& _Other) = delete;
	Skill_Fighter_F_LowKick& operator=(Skill_Fighter_F_LowKick&& _Other) noexcept = delete;

	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;
	void EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)override;
	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;
private:
	GameEngineEffectRenderer* Texture_LowKick;
	GameEngineEffectRenderer* Texture_LowKick_WaveEffect09;
	GameEngineEffectRenderer* Texture_LowKick_WaveEffect06;
	bool IsReady;
};

