#include "PreCompile.h"
#include "DebugLevel.h"
#include "CharacterFighter.h"
#include <GameEngineCore/GameEngineCameraActor.h>

DebugLevel::DebugLevel() 
{
}

DebugLevel::~DebugLevel() 
{
}

void DebugLevel::Start()
{
	GameEngineCameraActor* actor = CreateActor<GameEngineCameraActor>();
	actor->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
	CreateActor<CharacterFighter>();
}

void DebugLevel::Update(float _DeltaTime)
{


}