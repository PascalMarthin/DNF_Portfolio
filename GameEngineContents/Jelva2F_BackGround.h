#pragma once
#include "BackGroundParent.h"

// ���� :
class Jelva2F_BackGround : public BackGroundParent
{
public:
	// constrcuter destructer
	Jelva2F_BackGround();
	~Jelva2F_BackGround();

	// delete Function
	Jelva2F_BackGround(const Jelva2F_BackGround& _Other) = delete;
	Jelva2F_BackGround(Jelva2F_BackGround&& _Other) noexcept = delete;
	Jelva2F_BackGround& operator=(const Jelva2F_BackGround& _Other) = delete;
	Jelva2F_BackGround& operator=(Jelva2F_BackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void End() override {}
	// void OnEvent() override
	// void OffEvent() override

private:

	GameEngineCollision* Collision_Jelva1F_Door;
	GameEngineCollision* Collision_Jelva2F_01_Door;

};

