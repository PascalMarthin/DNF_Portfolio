#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// 설명 :
class GamePlayObject : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayObject();
	~GamePlayObject();

	// delete Function
	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

protected:
	GameEngineTextureRenderer* Object_Body;
	// 오브젝트 렌더러

	std::map<std::string, std::pair<int, int>> ObjectMotionIndex;
	// 오브젝트 모션 번호를 저장

private:

};

