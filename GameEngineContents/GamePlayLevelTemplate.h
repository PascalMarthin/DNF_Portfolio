#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class GamePlayComboSystem;
class GamePlayLevelTemplate : public GameEngineLevel
{
public:
	// constrcuter destructer
	GamePlayLevelTemplate();
	~GamePlayLevelTemplate();

	// delete Function
	GamePlayLevelTemplate(const GamePlayLevelTemplate& _Other) = delete;
	GamePlayLevelTemplate(GamePlayLevelTemplate&& _Other) noexcept = delete;
	GamePlayLevelTemplate& operator=(const GamePlayLevelTemplate& _Other) = delete;
	GamePlayLevelTemplate& operator=(GamePlayLevelTemplate&& _Other) noexcept = delete;


	inline GameEngineCameraActor* GetAvataCamera() const
	{
		return Camera_MainAvata;
	}

	inline GameEngineCameraActor* GetOutLineCamera() const
	{
		return Camera_OutLine;
	}

	inline GameEngineCameraActor* GetUIFontCamera() const
	{
		return Camera_UIFont;
	}

	inline GameEngineCameraActor* GetEffectCamera() const
	{
		return Camera_Effect;
	}
	

protected:
	void Start() override;


	GamePlayComboSystem* Actor_SystemCombo;
private:
	GameEngineCameraActor* Camera_MainAvata;
	GameEngineCameraActor* Camera_OutLine;
	GameEngineCameraActor* Camera_UIFont;
	GameEngineCameraActor* Camera_Effect;

};

