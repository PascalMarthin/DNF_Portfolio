#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BackGroundParent.h"

// Ό³Έν :
class SeriaRoomBackground : public GameEngineActor, public BackGroundParent
{
public:
	// constrcuter destructer
	SeriaRoomBackground();
	~SeriaRoomBackground();

	// delete Function
	SeriaRoomBackground(const SeriaRoomBackground& _Other) = delete;
	SeriaRoomBackground(SeriaRoomBackground&& _Other) noexcept = delete;
	SeriaRoomBackground& operator=(const SeriaRoomBackground& _Other) = delete;
	SeriaRoomBackground& operator=(SeriaRoomBackground&& _Other) noexcept = delete;


protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	GameEngineCollision* Collision_SeriaRoom_OutDoor;
};

