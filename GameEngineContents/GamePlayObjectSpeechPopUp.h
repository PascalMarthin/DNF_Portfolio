#pragma once
#include <GameEngineCore/GameEngineTransformComponent.h>

// Ό³Έν :
class GamePlayObjectSpeechPopUp : public GameEngineTransformComponent
{
public:
	// constrcuter destructer
	GamePlayObjectSpeechPopUp();
	~GamePlayObjectSpeechPopUp();

	// delete Function
	GamePlayObjectSpeechPopUp(const GamePlayObjectSpeechPopUp& _Other) = delete;
	GamePlayObjectSpeechPopUp(GamePlayObjectSpeechPopUp&& _Other) noexcept = delete;
	GamePlayObjectSpeechPopUp& operator=(const GamePlayObjectSpeechPopUp& _Other) = delete;
	GamePlayObjectSpeechPopUp& operator=(GamePlayObjectSpeechPopUp&& _Other) noexcept = delete;

	void CreatePopup(const std::string& _Speech);
protected:
	void Start() override;
private:
	static GameEngineFolderTexture* TextureR_PopText;
	std::vector<GameEngineUIRenderer*> vector_Texture_PopText;
};

