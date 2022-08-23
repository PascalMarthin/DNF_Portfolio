#pragma once
#include "GamePlaySkill.h"
// 설명 :
class Skill_Fighter_F_ClosePunch : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_ClosePunch();
	~Skill_Fighter_F_ClosePunch();

	// delete Function
	Skill_Fighter_F_ClosePunch(const Skill_Fighter_F_ClosePunch& _Other) = delete;
	Skill_Fighter_F_ClosePunch(Skill_Fighter_F_ClosePunch&& _Other) noexcept = delete;
	Skill_Fighter_F_ClosePunch& operator=(const Skill_Fighter_F_ClosePunch& _Other) = delete;
	Skill_Fighter_F_ClosePunch& operator=(Skill_Fighter_F_ClosePunch&& _Other) noexcept = delete;

	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;
	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
protected:
	void Start() override;
	//void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

public:
	void Texture_W_Front_d_Animation_Start(const FrameAnimation_DESC& _Desc);
	void Texture_W_Front_d_Animation_Frame(const FrameAnimation_DESC& _Desc);
	void Texture_W_Middle_d_Animation_Frame(const FrameAnimation_DESC& _Desc);
	void Texture_Punch02_Animation_Frame(const FrameAnimation_DESC& _Desc);

private:
	float Att_ClosePunch_Delay;
	bool Bool_Texture_W_Middle_d_Start;
	bool SomeOneHit; // 사이드 이펙트 사전차단용
	bool Texture_W_Front_; //엔진 추가전

	GameEngineTextureRenderer* Texture_Punch00;
	GameEngineTextureRenderer* Texture_Punch01;
	GameEngineTextureRenderer* Texture_Punch02;
	GameEngineTextureRenderer* Texture_Punch03;
	GameEngineTextureRenderer* Texture_W_1_d;
	GameEngineTextureRenderer* Texture_W_2_d;
	GameEngineTextureRenderer* Texture_W_Front_d;
	GameEngineTextureRenderer* Texture_W_Back_d;
	GameEngineTextureRenderer* Texture_W_Middle_d;

};

