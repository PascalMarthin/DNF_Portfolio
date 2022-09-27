#pragma once
#include <GameEngineBase/GameEngineDebug.h>
#include "AvataManager.h"

// 설명 : Town에 해당되는 레벨의 템플릿
class GameEngineSoundPlayer;
class TownLevel
{
public:
	// constrcuter destructer
	TownLevel();
	~TownLevel();

	// delete Function
	TownLevel(const TownLevel& _Other) = delete;
	TownLevel(TownLevel&& _Other) noexcept = delete;
	TownLevel& operator=(const TownLevel& _Other) = delete;
	TownLevel& operator=(TownLevel&& _Other) noexcept = delete;

	virtual GameEngineTexture* GetCollisionMapTexture() { MsgBoxAssert("반드시 필요한 오버라이드입니다") return nullptr; };



private:

};

