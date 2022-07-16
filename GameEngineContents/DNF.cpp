#include "PreCompile.h"
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineFolderTexture.h>


#include "DNF.h"
#include "DebugLevel.h"

//#pragma comment(lib, "GameEngineBase.lib")

DNF::DNF()
	//: GameEngineCore()
{
}

DNF::~DNF()
{
}

void DNF::Start()
{
	// GameEngineDebug::ConsoleOpen();

	AllResourceLoad();

	CreateLevel<DebugLevel>("Debug");
	//CreateLevel<PlayLevel>("Play");
	ChangeLevel("Debug");

}


void DNF::AllResourceLoad()
{
	BaseSoundLoad();
	BaseTextureLoad();
	BaseFolderTextureLoad();
}

void DNF::BaseSoundLoad()
{

}

void DNF::BaseTextureLoad()
{

}

void DNF::BaseFolderTextureLoad()
{

}

void DNF::Update(float _DeltaTime)
{


}

void DNF::End()
{
	int a = 0;
}