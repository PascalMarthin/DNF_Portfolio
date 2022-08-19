#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "TownLevel.h"
#include "Seria_NPC.h"
#include "SeriaRoomBackground.h"

class GamePlayCharacter;
class SeriaRoom_Level : public GameEngineLevel, public TownLevel
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

	inline GameEngineTexture* GetCollisionMapTexture() override
	{
		return Texture_SeriaRoom->GetCollisionTexture();
	}

protected:

	void Start() override;

	void Update(float _DeltaTime) override;

	void End() override {}

	void LevelStartEvent() override;
	// void OffEvent() {}

private:
	

private:

	SeriaRoomBackground* Texture_SeriaRoom;
	
	Seria_NPC* NPCSeria;
	GamePlayCharacter* Fighter;

};

