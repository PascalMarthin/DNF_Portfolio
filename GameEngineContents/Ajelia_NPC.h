#pragma once
#include "GamePlayObjectNPC.h"

// Ό³Έν :
class Ajelia_NPC : public GamePlayObjectNPC
{
public:
	// constrcuter destructer
	Ajelia_NPC();
	~Ajelia_NPC();

	// delete Function
	Ajelia_NPC(const Ajelia_NPC& _Other) = delete;
	Ajelia_NPC(Ajelia_NPC&& _Other) noexcept = delete;
	Ajelia_NPC& operator=(const Ajelia_NPC& _Other) = delete;
	Ajelia_NPC& operator=(Ajelia_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

};
