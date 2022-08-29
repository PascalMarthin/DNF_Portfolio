#pragma once
#include "GamePlaySkill.h"

// Ό³Έν :
class Skill_Fighter_F_LightingDance : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_LightingDance();
	~Skill_Fighter_F_LightingDance();

	// delete Function
	Skill_Fighter_F_LightingDance(const Skill_Fighter_F_LightingDance& _Other) = delete;
	Skill_Fighter_F_LightingDance(Skill_Fighter_F_LightingDance&& _Other) noexcept = delete;
	Skill_Fighter_F_LightingDance& operator=(const Skill_Fighter_F_LightingDance& _Other) = delete;
	Skill_Fighter_F_LightingDance& operator=(Skill_Fighter_F_LightingDance&& _Other) noexcept = delete;

	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;
	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;

	bool GetTarget(GameEngineCollision* _This, GameEngineCollision* _Other);
	void CheckEffectFrame(const FrameAnimation_DESC& _Desc);
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:
	float4 TargetPos;
	bool FirstHit_Animation;
	bool IsHitFloor;
	bool DanceFrameEnd;
	int DanceStuck;
	GameEngineCollision* Collision_CheckHitPos;

	GameEngineTextureRenderer* Texture_Kick;
	GameEngineTextureRenderer* Texture_Illusion_1;
	GameEngineTextureRenderer* Texture_Illusion_2;
	GameEngineTextureRenderer* Texture_Flash;

	void LightingAnimition(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime);
	
};

