#pragma once
#include "GamePlaySkill.h"
// Ό³Έν :
class Skill_Fighter_F_CrashLowKick : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_CrashLowKick();
	~Skill_Fighter_F_CrashLowKick();

	// delete Function
	Skill_Fighter_F_CrashLowKick(const Skill_Fighter_F_CrashLowKick& _Other) = delete;
	Skill_Fighter_F_CrashLowKick(Skill_Fighter_F_CrashLowKick&& _Other) noexcept = delete;
	Skill_Fighter_F_CrashLowKick& operator=(const Skill_Fighter_F_CrashLowKick& _Other) = delete;
	Skill_Fighter_F_CrashLowKick& operator=(Skill_Fighter_F_CrashLowKick&& _Other) noexcept = delete;

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
	GameEngineTextureRenderer* Texture_CrashLowKick;
	GameEngineTextureRenderer* Texture_CrashLowKick_Hit1;
	GameEngineTextureRenderer* Texture_CrashLowKick_Hit3;
	GameEngineTextureRenderer* Texture_CrashLowKick_Bone;
	//GameEngineTextureRenderer* Texture_CrashLowKick_Wave01;
	bool IsReady;
	//
	//GameEngineTextureRenderer* Texture_LowKick_WaveEffect06;

};
