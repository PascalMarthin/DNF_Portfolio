#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "PlayLevel.h"


//class GameEngineFolderTexture;
class SeriaRoom_Level : public GameEngineLevel, public PlayLevel
{
public:
	// constrcuter destructer
	SeriaRoom_Level();
	~SeriaRoom_Level();

	// delete Function
	SeriaRoom_Level(const SeriaRoom_Level& _Other) = delete;
	SeriaRoom_Level(SeriaRoom_Level&& _Other) noexcept = delete;
	SeriaRoom_Level& operator=(const SeriaRoom_Level& _Other) = delete;
	SeriaRoom_Level& operator=(SeriaRoom_Level&& _Other) noexcept = delete;

protected:

	void Start() override;

	void Update(float _DeltaTime) override;

	void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}

private:
	void TextureLoad() override;
	

private:
	GameEngineFolderTexture* Texture_SeriaRoom;

};

