#include "PreCompile.h"
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineFolderTexture.h>


#include "DNF.h"
#include "DebugLevel.h"
#include "SeriaRoom_Level.h"
#include "CharacterFighter.h"
#include "SelectCharacterLevel.h"
#include "CharacterCreateLevel.h"

//#pragma comment(lib, "GameEngineBase.lib")

DNF::DNF()
{
}

DNF::~DNF()
{
}

void DNF::Start()
{
	// GameEngineDebug::ConsoleOpen();
	//ShowCursor(false);
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

	{
		CreateLevel<SelectCharacterLevel>("SelectCharacter");
		CreateLevel<CharacterCreateLevel>("CharacterCreate");
	}

	ChangeLevel("SelectCharacter");

}


void DNF::AllResourceLoad()
{
	BaseSoundLoad();
	BaseTextureLoad();
	BaseFolderTextureLoad();
	BaseKeySetting();
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
		Dir.Move("Object");
		std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

		for (GameEngineDirectory& DirIter : AllTextureDir)
		{

			GameEngineFolderTexture::Load(DirIter.GetFullPath());
		}
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("Map");
		std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

		for (GameEngineDirectory& DirIter : AllTextureDir)
		{
			GameEngineFolderTexture::Load(DirIter.GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("HUD");

		std::vector<GameEngineFile> Texture = Dir.GetAllFile();

		for (size_t i = 0; i < Texture.size(); i++)
		{
			GameEngineTexture::Load(Texture[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("CharacterSelect");

		std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

		for (GameEngineDirectory& DirIter : AllTextureDir)
		{
			std::vector<GameEngineFile> Texture = DirIter.GetAllFile();
			for (size_t i = 0; i < Texture.size(); i++)
			{
				GameEngineTexture::Load(Texture[i].GetFullPath());
			}
		}
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("Cursor");

		std::vector<GameEngineFile> Texture = Dir.GetAllFile();

		for (size_t i = 0; i < Texture.size(); i++)
		{
			GameEngineTexture::Load(Texture[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("CharacterCreate");
		Dir.Move("CharacterBackGround");
		
		std::vector<GameEngineFile> Texture = Dir.GetAllFile();

		for (size_t i = 0; i < Texture.size(); i++)
		{
			GameEngineTexture::Load(Texture[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("CharacterCreate");
		Dir.Move("CharacterThumbnail");

		std::vector<GameEngineFile> Texture = Dir.GetAllFile();

		for (size_t i = 0; i < Texture.size(); i++)
		{
			GameEngineTexture::Load(Texture[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("NinePatch");

		std::vector<GameEngineFile> Texture = Dir.GetAllFile();

		for (size_t i = 0; i < Texture.size(); i++)
		{
			GameEngineTexture::Load(Texture[i].GetFullPath());
		}
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("CharacterCreate");
		Dir.Move("CharacterillustGIF");
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
	//	Dir.Move("Character");
	//	Dir.Move("Fighter_F");
	//	Dir.Move("Skin");
	//	Dir.Move("ft_body0011");

	//	GameEngineFolderTexture::Load(Dir.GetFullPath());
	//}
}

void DNF::BaseKeySetting()
{
	{
		GameEngineInput::GetInst()->CreateKey("Key_A", 'A');
		GameEngineInput::GetInst()->CreateKey("Key_S", 'S');
		GameEngineInput::GetInst()->CreateKey("Key_D", 'D');
		GameEngineInput::GetInst()->CreateKey("Key_F", 'F');
		GameEngineInput::GetInst()->CreateKey("Key_G", 'G');
		GameEngineInput::GetInst()->CreateKey("Key_H", 'H');
		GameEngineInput::GetInst()->CreateKey("Key_Q", 'Q');
		GameEngineInput::GetInst()->CreateKey("Key_W", 'W');
		GameEngineInput::GetInst()->CreateKey("Key_E", 'E');
		GameEngineInput::GetInst()->CreateKey("Key_R", 'R');
	}
	{
		GameEngineInput::GetInst()->CreateKey("BaseAtt", 'X');
		GameEngineInput::GetInst()->CreateKey("Jump", 'C');
		GameEngineInput::GetInst()->CreateKey("Key_Upper", 'Z');
		GameEngineInput::GetInst()->CreateKey("SpaceBar", VK_SPACE);
		GameEngineInput::GetInst()->CreateKey("UP_Arrow", VK_UP);
		GameEngineInput::GetInst()->CreateKey("Down_Arrow", VK_DOWN);
		GameEngineInput::GetInst()->CreateKey("Left_Arrow", VK_LEFT);
		GameEngineInput::GetInst()->CreateKey("Right_Arrow", VK_RIGHT);
	}
	{
		GameEngineInput::GetInst()->CreateKey("Quick_1", 0x31);
		GameEngineInput::GetInst()->CreateKey("Quick_2", 0x32);
		GameEngineInput::GetInst()->CreateKey("Quick_3", 0x33);
		GameEngineInput::GetInst()->CreateKey("Quick_4", 0x34);
		GameEngineInput::GetInst()->CreateKey("Quick_5", 0x35);
	}
	{
		GameEngineInput::GetInst()->CreateKey("ESC", VK_ESCAPE);
		GameEngineInput::GetInst()->CreateKey("Inventory", 'I');
		GameEngineInput::GetInst()->CreateKey("Skill", 'K');
		GameEngineInput::GetInst()->CreateKey("MyStat", 'P');
	}
	{
		GameEngineInput::GetInst()->CreateKey("LMouseCLK", MK_LBUTTON);
		GameEngineInput::GetInst()->CreateKey("RMouseCLK", MK_RBUTTON);
	}
}

void DNF::Update(float _DeltaTime)
{


}

void DNF::End()
{
	CharacterFighter::DestroyFrameAnimationDESC();
}