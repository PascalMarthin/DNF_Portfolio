#pragma once
#include <GameEngineCore/GameEngineGUI.h>

// Ό³Έν :
class GameEnginePlusCharacterStatWindow : public GameEngineGUIWindow
{
public:
	// constrcuter destructer
	GameEnginePlusCharacterStatWindow();
	~GameEnginePlusCharacterStatWindow();

	// delete Function
	GameEnginePlusCharacterStatWindow(const GameEnginePlusCharacterStatWindow& _Other) = delete;
	GameEnginePlusCharacterStatWindow(GameEnginePlusCharacterStatWindow&& _Other) noexcept = delete;
	GameEnginePlusCharacterStatWindow& operator=(const GameEnginePlusCharacterStatWindow& _Other) = delete;
	GameEnginePlusCharacterStatWindow& operator=(GameEnginePlusCharacterStatWindow&& _Other) noexcept = delete;

protected:

private:
	void Initialize(class GameEngineLevel* _Level) override;
	void OnGUI(GameEngineLevel* _Level, float _DeltaTime) override;

};
