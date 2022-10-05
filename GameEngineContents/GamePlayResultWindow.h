#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// Ό³Έν :
class GamePlayResultWindow : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayResultWindow();
	~GamePlayResultWindow();

	// delete Function
	GamePlayResultWindow(const GamePlayResultWindow& _Other) = delete;
	GamePlayResultWindow(GamePlayResultWindow&& _Other) noexcept = delete;
	GamePlayResultWindow& operator=(const GamePlayResultWindow& _Other) = delete;
	GamePlayResultWindow& operator=(GamePlayResultWindow&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _Time) override;

private:
	GameEngineUIRenderer* Texteure_Result;

	GameEngineUIRenderer* Texteure_Rank;

	GameEngineUIRenderer* Texteure_RankScore;
	GameEngineUIRenderer* Texteure_ComboResult;
	GameEngineUIRenderer* Texteure_RankWindow;
	GameEngineUIRenderer* Texteure_RankSSS;
	GameEngineUIRenderer* Texteure_RankSmall;

	float StartDelay;
};

