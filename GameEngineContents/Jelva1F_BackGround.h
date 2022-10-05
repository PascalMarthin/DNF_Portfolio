#pragma once
#include <GameEngineCore/GameEngineCollision.h>
#include "BackGroundParent.h"

// Ό³Έν :
class Jelva1F_BackGround : public BackGroundParent
{
public:
	// constrcuter destructer
	Jelva1F_BackGround();
	~Jelva1F_BackGround();

	// delete Function
	Jelva1F_BackGround(const Jelva1F_BackGround& _Other) = delete;
	Jelva1F_BackGround(Jelva1F_BackGround&& _Other) noexcept = delete;
	Jelva1F_BackGround& operator=(const Jelva1F_BackGround& _Other) = delete;
	Jelva1F_BackGround& operator=(Jelva1F_BackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void End() override {}
	// void OnEvent() override
	// void OffEvent() override

private:
	GameEngineCollision* Collision_SeriaRoom_Door;
	GameEngineCollision* Collision_Jelva2F_Door;

	GameEngineCollision* Collision_SeriaRoom_Gate;
	GameEngineTextureRenderer* Texture_SeriaGate;

};

