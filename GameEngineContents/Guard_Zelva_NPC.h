#pragma once
#include "GamePlayObjectNPC.h"

// Ό³Έν :
class Guard_Zelva_NPC : public GamePlayObjectNPC
{
public:
	// constrcuter destructer
	Guard_Zelva_NPC();
	~Guard_Zelva_NPC();

	// delete Function
	Guard_Zelva_NPC(const Guard_Zelva_NPC& _Other) = delete;
	Guard_Zelva_NPC(Guard_Zelva_NPC&& _Other) noexcept = delete;
	Guard_Zelva_NPC& operator=(const Guard_Zelva_NPC& _Other) = delete;
	Guard_Zelva_NPC& operator=(Guard_Zelva_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

