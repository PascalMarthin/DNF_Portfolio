#include "PreCompile.h"
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineCameraActor.h>
#include "SeriaRoom_Level.h"

SeriaRoom_Level::SeriaRoom_Level() 
	: Texture_SeriaRoom(nullptr)
{
}

SeriaRoom_Level::~SeriaRoom_Level()
{
	
}


void SeriaRoom_Level::Start()
{

	TextureLoad();

}

void SeriaRoom_Level::TextureLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToExitsChildDirectory("Resource");
	Dir.Move("Texture");
	Dir.Move("Map");
	Dir.Move("Seria_Room");

	Texture_SeriaRoom = GameEngineFolderTexture::Load(Dir.GetFullPath());



}

void SeriaRoom_Level::Update(float _DeltaTime)
{


}