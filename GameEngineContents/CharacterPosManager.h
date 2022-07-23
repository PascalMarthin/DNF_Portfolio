#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineTransform.h>
#include "GamePlayObject.h"

// ���� : �̵� Ŭ����
// ���⼭�� ���̳� ������Ʈ �浹�� ���� �̵��Ұ��ɸ� Ȯ���Ѵ�
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

