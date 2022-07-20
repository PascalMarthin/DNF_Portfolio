#include "PreCompile.h"
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineFolderTexture.h>


#include "DNF.h"
#include "DebugLevel.h"
#include "SeriaRoom_Level.h"
#include "CharacterFighter.h"

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
	CharacterFighter::SetAnimationForFrameAnimationDESC();


	{
		CreateLevel<DebugLevel>("Debug");
	}
	// 디버그용 레벨


	{
		CreateLevel<SeriaRoom_Level>("SeriaRoom");
	}
	// TownLevel

	ChangeLevel("SeriaRoom");

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
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

		for (GameEngineDirectory& DirIter : AllTextureDir)
		{

			GameEngineFolderTexture::Load(DirIter.GetFullPath());
		}

	}
	//{
	//	GameEngineDirectory Dir;
	//	Dir.MoveParentToExitsChildDirectory("Resource");
	//	Dir.Move("Resource");
	//	Dir.Move("Texture");
	//	Dir.Move("Object");
	//	Dir.Move("Charactor");
	//	Dir.Move("Fighter_F");
	//	Dir.Move("Skin");
	//	Dir.Move("ft_body0011");

	//	GameEngineFolderTexture::Load(Dir.GetFullPath());
	//}
}

void DNF::Update(float _DeltaTime)
{


}

void DNF::End()
{
	CharacterFighter::DestroyFrameAnimationDESC();
}