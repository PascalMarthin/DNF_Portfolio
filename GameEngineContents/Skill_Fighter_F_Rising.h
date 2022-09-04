//#pragma once
//#include "GamePlaySkill.h"
//
//// Ό³Έν :
//class Skill_Fighter_F_Rising : public GamePlaySkill
//{
//public:
//	// constrcuter destructer
//	Skill_Fighter_F_Rising();
//	~Skill_Fighter_F_Rising();
//
//	// delete Function
//	Skill_Fighter_F_Rising(const Skill_Fighter_F_Rising& _Other) = delete;
//	Skill_Fighter_F_Rising(Skill_Fighter_F_Rising&& _Other) noexcept = delete;
//	Skill_Fighter_F_Rising& operator=(const Skill_Fighter_F_Rising& _Other) = delete;
//	Skill_Fighter_F_Rising& operator=(Skill_Fighter_F_Rising&& _Other) noexcept = delete;
//
//	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
//	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;
//
//	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
//protected:
//	void Start() override;
//	void Update(float _DeltaTime) override;
//
//	// void End() override {}
//	//void OnEvent() override;
//	//void OffEvent() override;
//
//private:
//	GameEngineTextureRenderer* Texture_Wind_0;
//	GameEngineTextureRenderer* Texture_Wind_2;
//	GameEngineTextureRenderer* Texture_Wind_5;
//	//GameEngineTextureRenderer* 
//	bool DelayPunch;
//};
//
