#pragma once
#include "GamePlayObjectNPC.h"

// Ό³Έν :
class Hartz_von_kruger_NPC : public GamePlayObjectNPC
{
public:
	// constrcuter destructer
	Hartz_von_kruger_NPC();
	~Hartz_von_kruger_NPC();

	// delete Function
	Hartz_von_kruger_NPC(const Hartz_von_kruger_NPC& _Other) = delete;
	Hartz_von_kruger_NPC(Hartz_von_kruger_NPC&& _Other) noexcept = delete;
	Hartz_von_kruger_NPC& operator=(const Hartz_von_kruger_NPC& _Other) = delete;
	Hartz_von_kruger_NPC& operator=(Hartz_von_kruger_NPC&& _Other) noexcept = delete;

protected:
	void Start() override;
private:

};

