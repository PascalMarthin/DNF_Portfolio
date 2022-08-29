#pragma once
#include "GamePlayCharacter.h"


// ���� :
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


	virtual GameEngineTexture* GetCollisionMapTexture() { MsgBoxAssert("�ݵ�� �ʿ��� �������̵��Դϴ�") return nullptr; };

protected:
	GamePlayCharacter* Player_Character;


	// UI
private:

};

