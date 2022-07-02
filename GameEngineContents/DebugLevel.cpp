#include "PreCompile.h"
#include "DebugLevel.h"
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
}

void DebugLevel::Update(float _DeltaTime)
{



}