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
	//Texture_SeriaRoom->GetTransform().SetLocalScale({MonitorX, MonitorY});
	float Hight = Texture_SeriaRoom->GetBackGroundTextureScale().y;
	float Width = Texture_SeriaRoom->GetBackGroundTextureScale().x;
	Texture_SeriaRoom->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });



	NPCSeria = CreateActor<Seria_NPC>();
	Fighter = CreateActor<GamePlayCharacter>();
	NPCSeria->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f , Hight - GameEngineWindow::GetScale().hy() - 200.f - static_cast<float>(ZSortOrder::NPC_Object) });
	GetMainCameraActor()->GetTransform().SetWorldMove({ Width / 2, -Hight / 2 });



}

void SeriaRoom_Level::Update(float _DeltaTime)
{


}

void SeriaRoom_Level::OnEvent()
{
	float Hight = Texture_SeriaRoom->GetBackGroundTextureScale().y;
	if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::None)
	{
		Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 50.f, Hight });
	}
	else
	{
		Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f, Hight });
	}
	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Seria_Room);
}