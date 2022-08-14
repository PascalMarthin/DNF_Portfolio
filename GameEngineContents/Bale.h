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

	// ---------FSM-------------
	void CreateFSMForBale();	

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

