#pragma once
#include "GamePlayMonster.h"

// 설명 :
class BaleTentacle;
class Bale : public GamePlayMonster
{
public:
	// constrcuter destructer
	Bale();
	~Bale();

	// delete Function
	Bale(const Bale& _Other) = delete;
	Bale(Bale&& _Other) noexcept = delete;
	Bale& operator=(const Bale& _Other) = delete;
	Bale& operator=(Bale&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent();
	void OffEvent() override;
	void LevelStartEvent() override;

	unsigned int SetHPFromHit(unsigned int _Damage) override;
	unsigned int SetHPFromHit(unsigned int _Damage, const std::vector<float>& _AddDamage)override;
private:
	// ---------Dir-------------
	void CheckDir();


	// ---------Collision-------
	std::map<std::string, GameEngineCollision*> AllCollision;


	// ---------Barrier------------------

	//GameEngineActor* Dummy;
	bool Barrier_On;
	GameEngineEffectRenderer* Texure_Barrier;
	GameEngineEffectRenderer* Texure_Barrier_Effect_Front;
	GameEngineEffectRenderer* Texure_Barrier_Effect_FrontDodge;
	GameEngineEffectRenderer* Texure_Barrier_Effect_Back;
	GameEngineEffectRenderer* Texure_Barrier_Effect_BackDodge;

	float Barrier_CoolTime;
	int Barrier_HP;

	//----------배경----------
	GameEngineEffectRenderer* Texture_BlackBack;
	
	//----------Hit----------
	GamePlayObject* Hit_Player;
	CollisionReturn GetPlayer(GameEngineCollision* _This, GameEngineCollision* _Other);
	// ---------FSM-------------

	float4 BeforePos;
	void SetFSManager() override;

	void Bale_BackToNone(const FrameAnimation_DESC& _DESC);

	void FSM_Move_Stand_Start(const StateInfo& _Info);
	void FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Stand_End(const StateInfo& _Info);

	float StayStandDelay;

	void FSM_Hit_Stand_Start(const StateInfo& _Info);
	void FSM_Hit_Stand_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Stand_End(const StateInfo& _Info);


	void FSM_Hit_Aerial_Start(const StateInfo& _Info);
	void FSM_Hit_Aerial_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Aerial_End(const StateInfo& _Info);

	void Ani_StandUp(const FrameAnimation_DESC&);


	void FSM_Hit_Aerial_DoingDown_Start(const StateInfo& _Info);
	void FSM_Hit_Aerial_DoingDown_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Aerial_DoingDown_End(const StateInfo& _Info);

	void LandingEnd() override;

	void FSM_Hit_Down_Start(const StateInfo& _Info);
	void FSM_Hit_Down_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Hit_Down_End(const StateInfo& _Info);


	void FSM_Move_Walk_Start(const StateInfo& _Info);
	void FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Walk_End(const StateInfo& _Info);

	float MoveDelay;
	//float4 TrackerPos;
	GameEngineCollision* Collision_PlayerLessPos;
	
	void FSM_Att_Sting_Start(const StateInfo& _Info);
	void FSM_Att_Sting_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Sting_End(const StateInfo& _Info);

	std::vector<GameEngineEffectRenderer*>  Texture_StingEffect_Slash;
	std::vector<GameEngineEffectRenderer*>  Texture_StingEffect_Puple;
	std::vector<GameEngineEffectRenderer*>  Texture_StingSmokeEffect;

	GameEngineCollision* Collision_StingHit;


	GameEngineActor* Actor_TrackingObject;



	

	void Sting_End(const FrameAnimation_DESC& _DESC);


	void Sting_Update(const FrameAnimation_DESC& _DESC);


	void FSM_Att_Stamping_Start(const StateInfo& _Info);
	void FSM_Att_Stamping_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Stamping_End(const StateInfo& _Info);

	GameEngineEffectRenderer* Texture_StampingEffect;
	GameEngineEffectRenderer* Texture_StampingEffect_Floor;
	GameEngineEffectRenderer* Texture_SmokeEffect;

	GameEngineCollision* Collision_StampingHit;

	float StampingEnd;

	void Bale_Stamping(const FrameAnimation_DESC& _DESC);
	
	// ----------------대쉬----------------


	void FSM_Att_Dash_Start(const StateInfo& _Info);
	void FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Dash_End(const StateInfo& _Info);
	bool DashUpdate;

	bool PlayerDashHit;
	GameEngineCollision* Collision_DashHit;

	GameEngineCollision* Collision_ect;



	void Bale_DashStart(const FrameAnimation_DESC& _DESC);
	void Bale_DashUpdate(const FrameAnimation_DESC& _DESC, float _Time);
	void Bale_DashFrame(const FrameAnimation_DESC& _DESC);
	float DashColorDelay;
	float VisionDelay;

	// ----------------텔레포트----------------


	void FSM_Move_Teleport_Start(const StateInfo& _Info);
	void FSM_Move_Teleport_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Teleport_End(const StateInfo& _Info);


	void Bale_TeleportStart(const FrameAnimation_DESC& _DESC);

	// ----------------스킬--------------------

	// ----------------추적--------------------
	void FSM_Skill_Tracking_Start(const StateInfo& _Info);
	void FSM_Skill_Tracking_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Skill_Tracking_End(const StateInfo& _Info);

	void Bale_TrackReadyEnd(const FrameAnimation_DESC& _DESC);
	void Bale_TrackFrmae(const FrameAnimation_DESC& _DESC);
	void Bale_TrackUpdate(const FrameAnimation_DESC& _DESC, float _Time);


	void Bale_TrackCatchUpdate(const FrameAnimation_DESC& _DESC, float _Time);
	void Bale_TrackCatchFrame(const FrameAnimation_DESC& _DESC);

	// ----------------촉수소환------------------
	void FSM_Skill_BringTentacle_Start(const StateInfo& _Info);
	void FSM_Skill_BringTentacle_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Skill_BringTentacle_End(const StateInfo& _Info);

	void Bale_TentacleReadyEnd(const FrameAnimation_DESC& _DESC);
	void Bale_TentacleFrame(const FrameAnimation_DESC& _DESC);


	int BringTentacleIndex;
	BaleTentacle* Actor_Tentacle;

	GameEngineCollision* Coliision_TentacleHit;
	//void FSM_Att_TrackingPlayer_Start(const StateInfo& _Info);
	//void FSM_Att_TrackingPlayer_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Att_TrackingPlayer_End(const StateInfo& _Info);
	

	//void FSM_Move_Walk_Start(const StateInfo& _Info);
	//void FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Move_Walk_End(const StateInfo& _Info);
	//void FSM_Move_Sting_Start(const StateInfo& _Info);
	//void FSM_Move_Sting_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Move_Sting_End(const StateInfo& _Info);
	//void FSM_Move_Dash_Start(const StateInfo& _Info);
	//void FSM_Move_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Move_Dash_End(const StateInfo& _Info);
	//void FSM_Move_Walk_Start(const StateInfo& _Info);
	//void FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info);
	//void FSM_Move_Walk_End(const StateInfo& _Info);

	GameEngineSoundPlayer Sound_BaleVoice;
	inline void SetVoice(const std::string& _Name)
	{
		Sound_BaleVoice.Stop();
		Sound_BaleVoice = GameEngineSound::SoundPlayControl(_Name);
		Sound_BaleVoice.Volume(0.8f);
	}


};

