#pragma once
#include "GamePlayMonster.h"
// Ό³Έν :
class Light_Knight : public GamePlayMonster
{
public:
	// constrcuter destructer
	Light_Knight();
	~Light_Knight();

	// delete Function
	Light_Knight(const Light_Knight& _Other) = delete;
	Light_Knight(Light_Knight&& _Other) noexcept = delete;
	Light_Knight& operator=(const Light_Knight& _Other) = delete;
	Light_Knight& operator=(Light_Knight&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent();
	// void OffEvent() override {}
	void LevelStartEvent() override;
private:
	GameEngineTextureRenderer* Texture_Renderer;
	GameEngineTextureRenderer* Texture_Eff;
	GameEngineTextureRenderer* Texture_Eff2;
	GameEngineCollision* Collision_HitBody;
	GameEngineCollision* Collision_PlayerLessPos;
	GameEngineCollision* Collision_PlayerMaxPos;
	GameEngineCollision* Collision_GoPos;



	// ---------Dir-------------
	void CheckDir();


	//

	std::map<std::string, GameEngineCollision*> AllCollision;


	float MoveDelay;

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

	void FSM_Att_Slash_Start(const StateInfo& _Info);
	void FSM_Att_Slash_Update(float _DeltaTime, const StateInfo& _Info);
	void FSM_Att_Slash_End(const StateInfo& _Info);

	GameEngineCollision* Collision_SlashHitPos;
	float4 SlashArrivePos;
	//GameEngineCollision* Collision_ArrivePos;

	void Att_SlashFrame(const FrameAnimation_DESC& _DESC);

	void Att_SlashUpdate(const FrameAnimation_DESC& _DESC, float _Time);
	//GameEngineCollision* Collision_Arrow;

};
