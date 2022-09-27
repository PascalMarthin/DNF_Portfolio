#pragma once
#include "GamePlayObjectNPC.h"

// Ό³Έν :
class Isabella_NPC : public GamePlayObjectNPC
{
public:
	// constrcuter destructer
	Isabella_NPC();
	~Isabella_NPC();

	// delete Function
	Isabella_NPC(const Isabella_NPC& _Other) = delete;
	Isabella_NPC(Isabella_NPC&& _Other) noexcept = delete;
	Isabella_NPC& operator=(const Isabella_NPC& _Other) = delete;
	Isabella_NPC& operator=(Isabella_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

};

