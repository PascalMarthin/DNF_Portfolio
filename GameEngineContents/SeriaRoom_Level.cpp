#include "PreCompile.h"
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineCore/GameEngineComponent.h>
#include "SeriaRoom_Level.h"
#include "SeriaRoomBackground.h"
#include "GamePlayCharacter.h"
#include "AvataManager.h"

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
	GamePlayLevelTemplate::Start();
	Texture_SeriaRoom = CreateActor<SeriaRoomBackground>();
	//Texture_SeriaRoom->GetTransform().SetLocalScale({MonitorX, MonitorY});
	float Hight = Texture_SeriaRoom->GetBackGroundTextureScale().y;
	float Width = Texture_SeriaRoom->GetBackGroundTextureScale().x;
	Texture_SeriaRoom->GetTransform().SetLocalPosition({ 0, 0, Hight + static_cast<float>(ZSortOrder::BackGround) });



	NPCSeria = CreateActor<Seria_NPC>();
	Fighter = CreateActor<GamePlayCharacter>();
	NPCSeria->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy(), -GameEngineWindow::GetScale().hy() });
	GetMainCameraActor()->GetTransform().SetWorldMove({ Width / 2, -Hight / 2 });


}

void SeriaRoom_Level::Update(float _DeltaTime)
{
	//GameEngineDebug::OutPutString(std::to_string(Fighter->GetTransform().GetLocalPosition().z));

}

void SeriaRoom_Level::LevelStartEvent()
{
	float Hight = Texture_SeriaRoom->GetBackGroundTextureScale().y;
	if (GamePlayDataBase::GetCurrentCharacterData()->GetCurrentMap() == TownMap::None)
	{
		BGM_Player = GameEngineSound::SoundPlayControl("seria_gate.ogg");
		Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 100.f, -GameEngineWindow::GetScale().hy() - 100.f });
	}
	else
	{
		BGM_Player.Stop();
		BGM_Player = GameEngineSound::SoundPlayControl("seria_gate.ogg");
		Fighter->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() - 200.f, -GameEngineWindow::GetScale().hy() - 200.f });
	}
	GamePlayDataBase::GetCurrentCharacterData()->SetCurrentMap(TownMap::Seria_Room);


}

void SeriaRoom_Level::LevelEndEvent()
{
	BGM_Player.Stop();
}