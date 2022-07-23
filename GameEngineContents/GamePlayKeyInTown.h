#pragma once
#include "GamePlayKeyManager.h"

// Ό³Έν :
class GamePlayKeyInTown : public GamePlayKeyManager
{
public:
	// constrcuter destructer
	GamePlayKeyInTown();
	~GamePlayKeyInTown();

	// delete Function
	GamePlayKeyInTown(const GamePlayKeyInTown& _Other) = delete;
	GamePlayKeyInTown(GamePlayKeyInTown&& _Other) noexcept = delete;
	GamePlayKeyInTown& operator=(const GamePlayKeyInTown& _Other) = delete;
	GamePlayKeyInTown& operator=(GamePlayKeyInTown&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
protected:
	void CheckKeyByMove(float _DeltaTime, float _MoveSpeed) override;
	void CheckKeyBySkill(float _DeltaTime, float _MoveSpeed) override;
	//void CheckKeyByInterface(float _DeltaTime, float _MoveSpeed) override;

private:

};

