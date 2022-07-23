#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineTransform.h>
#include "GamePlayObject.h"

// 설명 : 이동 클래스
// 여기서는 맵이나 오브젝트 충돌에 의한 이동불가능만 확인한다
class CharacterPosManager
{
public:
	// constrcuter destructer
	CharacterPosManager(GamePlayObject* _Object);
	~CharacterPosManager();

	// delete Function
	CharacterPosManager(const CharacterPosManager& _Other) = delete;
	CharacterPosManager(CharacterPosManager&& _Other) noexcept = delete;
	CharacterPosManager& operator=(const CharacterPosManager& _Other) = delete;
	CharacterPosManager& operator=(CharacterPosManager&& _Other) noexcept = delete;

	void Move_Walk_Up();
	void Move_Walk_Down();
	void Move_Walk_Right();
	void Move_Walk_Left();

protected:

private:
	GamePlayObject* const Player;
	GameEngineTransform& PlayerTransform;
	float4& ObjectInGamePos;
};

