#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// ���� :
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

	inline float4& GetPosToInGame()
	{
		return ObjectPos;
	}

protected:
	void Start() override;
	// GameEngineTextureRenderer* Object_Body;
	// ������Ʈ ������


	// ���� �� ��ġ 
private:
	
	float4 ObjectPos;

};

