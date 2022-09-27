#pragma once
#include "GamePlayObjectNPC.h"

// Ό³Έν :
class Merill_pioneer_NPC : public GamePlayObjectNPC
{
public:
	// constrcuter destructer
	Merill_pioneer_NPC();
	~Merill_pioneer_NPC();

	// delete Function
	Merill_pioneer_NPC(const Merill_pioneer_NPC& _Other) = delete;
	Merill_pioneer_NPC(Merill_pioneer_NPC&& _Other) noexcept = delete;
	Merill_pioneer_NPC& operator=(const Merill_pioneer_NPC& _Other) = delete;
	Merill_pioneer_NPC& operator=(Merill_pioneer_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;
private:
	GameEnginePlusTextureRenderer* Texture_NPCStanding_Smoke;
};
