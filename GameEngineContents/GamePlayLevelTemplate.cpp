#include "PreCompile.h"
#include "GamePlayLevelTemplate.h"

GamePlayLevelTemplate::GamePlayLevelTemplate()
	: Camera_UIFont(nullptr)
	, Camera_OutLine(nullptr)
	, Camera_MainAvata(nullptr)
{
}

GamePlayLevelTemplate::~GamePlayLevelTemplate()
{
}

void GamePlayLevelTemplate::Start()
{
	Camera_OutLine = CreateActor<GameEngineCameraActor>();
	Camera_OutLine->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -100.0f });
	Camera_OutLine->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
	Camera_OutLine->GetCameraComponent()->SetCameraOrder(CAMERAORDER::Object_OutLine);

	Camera_MainAvata = CreateActor<GameEngineCameraActor>();
	Camera_MainAvata->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -100.0f });
	Camera_MainAvata->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
	Camera_MainAvata->GetCameraComponent()->SetCameraOrder(CAMERAORDER::Object);

	Camera_UIFont = CreateActor<GameEngineCameraActor>();
	Camera_UIFont->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -100.0f });
	Camera_UIFont->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
	Camera_UIFont->GetCameraComponent()->SetCameraOrder(CAMERAORDER::UIFont);
}
