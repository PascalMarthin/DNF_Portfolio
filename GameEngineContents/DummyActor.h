#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DummyActor : public GameEngineActor
{
public:
	// constrcuter destructer
	DummyActor();
	~DummyActor();

	// delete Function
	DummyActor(const DummyActor& _Other) = delete;
	DummyActor(DummyActor&& _Other) noexcept = delete;
	DummyActor& operator=(const DummyActor& _Other) = delete;
	DummyActor& operator=(DummyActor&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update(float _DeltaTime) override {}
	// void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}
private:

};

