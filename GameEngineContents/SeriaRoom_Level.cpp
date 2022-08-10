#include "PreCompile.h"
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineCore/GameEngineComponent.h>
#include "SeriaRoom_Level.h"
#include "SeriaRoomBackground.h"
#include "GamePlayCharacter.h"

SeriaRoom_Level::SeriaRoom_Level() 
	: NPCSeria(nullptr)
	, Texture_SeriaRoom(nullptr)
	, Fighter(nullptr)
{
}

SeriaRoom_Level::~SeriaRoom_Level()
{
	
}


void SeriaRoom_Level::Start()
{
	Texture_SeriaRoom = CreateActor<SeriaRoomBackground>();
	Texture_SeriaRoom->GetTransform().SetLocalScale({MonitorX, MonitorY});
	float Hight = Texture_SeriaRoom->GetBackGroundTextureScale().y;
	Texture_SeriaRoom->GetTransform().SetLocalPosition({ 0, 0, Hight + ZSortOrder::BackGround });



	NPCSeria = CreateActor<Seria_NPC>();
	Fighter = CreateActor<GamePlayCharacter>();
	NPCSeria->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() , Hight / 2 - ZSortOrder::NPC_Object});
	Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy(), Hight / 2 - ZSortOrder::Character_Fighter_F });
	GetMainCameraActor()->GetTransform().SetWorldPosition(Fighter->GetTransform().GetWorldPosition());



}

void SeriaRoom_Level::Update(float _DeltaTime)
{


}