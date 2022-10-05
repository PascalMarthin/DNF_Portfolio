#pragma once
#include "GamePlaySkill.h"
#define Skill_Rising_High 180.f

// Ό³Έν :
class Skill_Fighter_F_Rising : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_Rising();
	~Skill_Fighter_F_Rising();

	// delete Function
	Skill_Fighter_F_Rising(const Skill_Fighter_F_Rising& _Other) = delete;
	Skill_Fighter_F_Rising(Skill_Fighter_F_Rising&& _Other) noexcept = delete;
	Skill_Fighter_F_Rising& operator=(const Skill_Fighter_F_Rising& _Other) = delete;
	Skill_Fighter_F_Rising& operator=(Skill_Fighter_F_Rising&& _Other) noexcept = delete;

	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
	void EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:
	float JumpTime;
	float AttDealy;
	int HitCount;
	float4 LandPos;
	std::vector<GameEngineEffectRenderer*> Texture_Wind;
	//GameEngineTextureRenderer* Texture_Wind_0;
	//GameEngineTextureRenderer* Texture_Wind_2;
	//GameEngineTextureRenderer* Texture_Wind_5;

	std::vector<GameEngineEffectRenderer*> Texture_Rising_spin;
	std::vector<GameEngineEffectRenderer*> Texture_RisingEffect;

	//GameEngineTextureRenderer* Texture_EffectAir_1;
	//GameEngineTextureRenderer* Texture_EffectAir_2;

	static GameEngineFolderTexture* FolderTexture_Rising_spin;
	static GameEngineFolderTexture* FolderTexture_Tigerstrike_00;
	//static GameEngineFolderTexture* FolderTexture_EffectAir_2;
	//GameEngineTextureRenderer* 
	bool DelayPunch;
};

