#include "PreCompile.h"
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineCore/GameEngineComponent.h>
#include "SeriaRoom_Level.h"
#include "SeriaRoomBackground.h"

SeriaRoom_Level::SeriaRoom_Level() 
	: Camera(CreateActor<GameEngineCameraActor>())
	, NPCSeria(CreateActor<Seria_NPC>())
	, Texture_SeriaRoom(CreateActor<SeriaRoomBackground>())
{
	Camera->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
	Camera->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -500.0f });
}

SeriaRoom_Level::~SeriaRoom_Level()
{
	
}


void SeriaRoom_Level::Start()
{

}

void SeriaRoom_Level::Update(float _DeltaTime)
{


}