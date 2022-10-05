#pragma once
#include "GamePlaySkill.h"

// Ό³Έν :
enum class StrongLowKickPoint
{
	StartEvent,
	StartEffectEnd,
	Kick,
	Hit,
	NoHItDelay,
	EndSkill,
	CameraZoomOn,
	CameraZoomOff,
};
class Skill_Fighter_F_StrongLowKick : public GamePlaySkill
{
public:
	// constrcuter destructer
	Skill_Fighter_F_StrongLowKick();
	~Skill_Fighter_F_StrongLowKick();

	// delete Function
	Skill_Fighter_F_StrongLowKick(const Skill_Fighter_F_StrongLowKick& _Other) = delete;
	Skill_Fighter_F_StrongLowKick(Skill_Fighter_F_StrongLowKick&& _Other) noexcept = delete;
	Skill_Fighter_F_StrongLowKick& operator=(const Skill_Fighter_F_StrongLowKick& _Other) = delete;
	Skill_Fighter_F_StrongLowKick& operator=(Skill_Fighter_F_StrongLowKick&& _Other) noexcept = delete;

	bool TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other) override;
	bool ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime) override;

	void StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
	void EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata) override;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent() override;
	//void OffEvent() override;

private:
	std::vector<GameEngineTextureRenderer*> Texture_Start;
	void StrongestLowKick_startEnd(const FrameAnimation_DESC& _DESC);
	std::map<StrongLowKickPoint, bool> map_AllBool;
	float Start_Delay;

	GameEngineTextureRenderer* Texture_Spin;
	GameEngineTextureRenderer* Texture_Spin_dust;

	std::vector<GameEngineTextureRenderer*> vector_Texture_Leg;
	std::vector<GameEngineTextureRenderer*> vector_Texture_Wind;

	GameEngineSoundPlayer Sound_Wind;

	GameEngineTextureRenderer* Texture_AttLowKick;

	void AttLowKickEnd(const FrameAnimation_DESC& _DESC);

	std::vector<GameEngineUIRenderer*> vector_finish;
	GameEngineTextureRenderer* Texture_universe;
	GameEngineTextureRenderer* Texture_typeC;

	GameEngineTextureRenderer* Texture_BackGround;

	GameEngineUIRenderer* Texture_1stFace;

	float EndDelay;
	float CameraZoomDelay;

	void AttSkillEnd(const FrameAnimation_DESC& _DESC);
};

