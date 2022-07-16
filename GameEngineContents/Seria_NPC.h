#pragma once

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

class Seria_NPC : public GameEngineActor
{
public:
	// constrcuter destructer
	Seria_NPC();
	~Seria_NPC();

	// delete Function
	Seria_NPC(const Seria_NPC& _Other) = delete;
	Seria_NPC(Seria_NPC&& _Other) noexcept = delete;
	Seria_NPC& operator=(const Seria_NPC& _Other) = delete;
	Seria_NPC& operator=(Seria_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	GameEngineTextureRenderer* Seria_Renderer;

};

