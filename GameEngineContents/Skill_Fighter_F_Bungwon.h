
#pragma once
#include "GamePlaySkill.h"


// Ό³Έν :
class Skill_Fighter_F_Bungwon : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_Bungwon();
	~Skill_Fighter_F_Bungwon();

	// delete Function
	Skill_Fighter_F_Bungwon(const Skill_Fighter_F_Bungwon& _Other) = delete;
	Skill_Fighter_F_Bungwon(Skill_Fighter_F_Bungwon&& _Other) noexcept = delete;
	Skill_Fighter_F_Bungwon& operator=(const Skill_Fighter_F_Bungwon& _Other) = delete;
	Skill_Fighter_F_Bungwon& operator=(Skill_Fighter_F_Bungwon&& _Other) noexcept = delete;

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
	GameEngineTextureRenderer* Texture_Dashpunch;
	GameEngineTextureRenderer* Texture_Dashpunchdust;
	GameEngineTextureRenderer* Texture_Dashpunchsub;

	float MoveDistance;
	float Att_Bungwon_Delay;
};