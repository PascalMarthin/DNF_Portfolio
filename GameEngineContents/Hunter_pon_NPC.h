#pragma once
#include "GamePlayObjectNPC.h"
// Ό³Έν :
class Hunter_pon_NPC : public GamePlayObjectNPC
{
public:
	// constrcuter destructer
	Hunter_pon_NPC();
	~Hunter_pon_NPC();

	// delete Function
	Hunter_pon_NPC(const Hunter_pon_NPC& _Other) = delete;
	Hunter_pon_NPC(Hunter_pon_NPC&& _Other) noexcept = delete;
	Hunter_pon_NPC& operator=(const Hunter_pon_NPC& _Other) = delete;
	Hunter_pon_NPC& operator=(Hunter_pon_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

};

