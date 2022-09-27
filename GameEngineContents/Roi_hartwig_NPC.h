#pragma once
#include "GamePlayObjectNPC.h"

// Ό³Έν :
class Roi_hartwig_NPC : public GamePlayObjectNPC
{
public:
	// constrcuter destructer
	Roi_hartwig_NPC();
	~Roi_hartwig_NPC();

	// delete Function
	Roi_hartwig_NPC(const Roi_hartwig_NPC& _Other) = delete;
	Roi_hartwig_NPC(Roi_hartwig_NPC&& _Other) noexcept = delete;
	Roi_hartwig_NPC& operator=(const Roi_hartwig_NPC& _Other) = delete;
	Roi_hartwig_NPC& operator=(Roi_hartwig_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

};
