#pragma once

#include <GameEngineCore/GameEngineTextureRenderer.h>

#include "GamePlayObjectNPC.h"

class Seria_NPC : public GamePlayObjectNPC
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

