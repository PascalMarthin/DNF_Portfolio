#pragma once
#include "GamePlayCharacter.h"


// 설명 :
class BattleLevel
{
public:
	// constrcuter destructer
	BattleLevel();
	~BattleLevel();

	// delete Function
	BattleLevel(const BattleLevel& _Other) = delete;
	BattleLevel(BattleLevel&& _Other) noexcept = delete;
	BattleLevel& operator=(const BattleLevel& _Other) = delete;
	BattleLevel& operator=(BattleLevel&& _Other) noexcept = delete;


	virtual GameEngineTexture* GetCollisionMapTexture() { MsgBoxAssert("반드시 필요한 오버라이드입니다") return nullptr; };

protected:
	GamePlayCharacter* Player_Character;


	// UI
private:

};

