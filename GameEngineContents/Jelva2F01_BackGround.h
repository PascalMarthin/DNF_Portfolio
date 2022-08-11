#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BackGroundParent.h"

// Ό³Έν :
class Jelva2F01_BackGround : public GameEngineActor, public BackGroundParent
{
public:
	// constrcuter destructer
	Jelva2F01_BackGround();
	~Jelva2F01_BackGround();

	// delete Function
	Jelva2F01_BackGround(const Jelva2F01_BackGround& _Other) = delete;
	Jelva2F01_BackGround(Jelva2F01_BackGround&& _Other) noexcept = delete;
	Jelva2F01_BackGround& operator=(const Jelva2F01_BackGround& _Other) = delete;
	Jelva2F01_BackGround& operator=(Jelva2F01_BackGround&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void End() override {}
	// void OnEvent() override
	// void OffEvent() override
private:

	GameEngineCollision* Collision_Jelva2F_Door;
	GameEngineCollision* Collision_LukeRaid_Door;
};