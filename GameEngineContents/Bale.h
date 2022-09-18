#pragma once
#include "GamePlayMonster.h"

// Ό³Έν :
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
	// void OffEvent() override {}
private:
	// ---------Dir-------------
	void CheckDir();


	// ---------Collision-------
	std::map<std::string, GameEngineCollision*> AllCollision;


	// ---------FSM-------------
	void SetFSManager() override;

	void FSM_Move_Stand_Start(const StateInfo& _Info);
	void FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Move_Stand_End(const StateInfo& _Info);

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
	GameEngineCollision* Collision_TargetPos;
	
	void FSM_Att_Sting_Start(const StateInfo& _Info);
	void FSM_Att_Sting_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Sting_End(const StateInfo& _Info);

	void Sting_End(const FrameAnimation_DESC& _DESC);


	void FSM_Att_Stamping_Start(const StateInfo& _Info);
	void FSM_Att_Stamping_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Stamping_End(const StateInfo& _Info);

	void Bale_Stamping(const FrameAnimation_DESC& _DESC);
	

	void FSM_Att_Dash_Start(const StateInfo& _Info);
	void FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Dash_End(const StateInfo& _Info);




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



};

