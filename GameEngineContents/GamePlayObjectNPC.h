#pragma once
#include "GamePlayObject.h"

// ���� :
class GamePlayObjectNPC : public GamePlayObject
{
public:
	// constrcuter destructer
	GamePlayObjectNPC();
	~GamePlayObjectNPC();

	// delete Function
	GamePlayObjectNPC(const GamePlayObjectNPC& _Other) = delete;
	GamePlayObjectNPC(GamePlayObjectNPC&& _Other) noexcept = delete;
	GamePlayObjectNPC& operator=(const GamePlayObjectNPC& _Other) = delete;
	GamePlayObjectNPC& operator=(GamePlayObjectNPC&& _Other) noexcept = delete;

protected:

private:

};

