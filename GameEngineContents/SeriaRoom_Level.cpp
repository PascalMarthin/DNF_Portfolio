#include "PreCompile.h"
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineCore/GameEngineComponent.h>
#include "SeriaRoom_Level.h"
#include "SeriaRoomBackground.h"
#include "GamePlayCharacter.h"

SeriaRoom_Level::SeriaRoom_Level() 
	: NPCSeria(CreateActor<Seria_NPC>())
	, Texture_SeriaRoom(CreateActor<SeriaRoomBackground>())
{
}

SeriaRoom_Level::~SeriaRoom_Level()
{
	
}


void SeriaRoom_Level::Start()
{
	GamePlayCharacter* Fighter = CreateActor<GamePlayCharacter>();
	//GamePlayCharacter::SetCurrentPlayer(Fighter);
}

void SeriaRoom_Level::Update(float _DeltaTime)
{


}