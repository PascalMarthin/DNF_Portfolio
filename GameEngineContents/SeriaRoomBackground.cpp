#include "PreCompile.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"
#include "SeriaRoomBackground.h"


SeriaRoomBackground::SeriaRoomBackground() 
	: SeriaRoomBackGround_Texture(nullptr)
{
}

SeriaRoomBackground::~SeriaRoomBackground() 
{
}

void SeriaRoomBackground::Start()
{
	SeriaRoomBackGround_Texture = CreateComponent<GameEngineTextureRenderer>();
	SeriaRoomBackGround_Texture->GetTransform().SetLocalPosition({ 0, 0, ZSortOrder::BackGround });
	SeriaRoomBackGround_Texture->CreateFrameAnimationFolder("Seria_BackGround", FrameAnimation_DESC("Seria_Room", 0.15f));
	SeriaRoomBackGround_Texture->ChangeFrameAnimation("Seria_BackGround");
	SeriaRoomBackGround_Texture->GetTransform().SetLocalScale({ 1280, 720 });
}

void SeriaRoomBackground::Update(float _DeltaTime)
{

}
