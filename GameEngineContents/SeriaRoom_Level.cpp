#include "PreCompile.h"
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineCore/GameEngineComponent.h>
#include "SeriaRoom_Level.h"
#include "SeriaRoomBackground.h"
#include "CharacterStryker.h"

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
	CharacterStryker* Fighter = CreateActor<CharacterStryker>();


}

void SeriaRoom_Level::Update(float _DeltaTime)
{


}