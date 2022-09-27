#include "PreCompile.h"
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineStatusWindow.h>
#include <GameEngineCore/GameEngineFolderTexture.h>


#include "DNF.h"
#include "DebugLevel.h"
#include "SeriaRoom_Level.h"
#include "SelectCharacterLevel.h"
#include "CharacterCreateLevel.h"
#include "GamePlayDataBase.h"
#include "GameEnginePlusCharacterStatWindow.h"
#include "Jelva_1F.h"
#include "Jelva_2F.h"
#include "Jelva_2F01.h"
#include "DungeonSelect.h"
#include "DungeonLoding.h"
#include "GamePlayItem_DESC.h"
#include <GameEngineCore/GameEngineFont.h>

//#pragma comment(lib, "GameEngineBase.lib")

DNF* DNF::MainCoreEngine = nullptr;

DNF::DNF()
{
}

DNF::~DNF()
{
}

void DNF::Start()
{

	DNF::MainCoreEngine = this;
	// GameEngineDebug::ConsoleOpen();
	//ShowCursor(false);
	AllResourceLoad();


	{
		CreateLevel<DebugLevel>("Debug");
	}
	// 디버그용 레벨
	// TownLevel
	{
		CreateLevel<SeriaRoom_Level>("SeriaRoom");
		CreateLevel<Jelva_1F>("Jelva_1F");
		CreateLevel<Jelva_2F>("Jelva_2F");
		CreateLevel<Jelva_2F01>("Jelva_2F01");

	}
	{
		CreateLevel<DungeonSelect>("DungeonSelect");
		CreateLevel<DungeonLoding>("DungeonLoding");
	}

	{
		CreateLevel<SelectCharacterLevel>("SelectCharacter");
		CreateLevel<CharacterCreateLevel>("CharacterCreate");
	}

	ChangeLevel("SelectCharacter");

	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("EngineStatus", nullptr);
}


void DNF::AllResourceLoad()
{
	BaseSoundLoad();
	BaseTextureLoad();
	BaseFolderTextureLoad();
	BaseShaderLoad();


	BaseKeySetting();
	GamePlayItem_DESC::CreateALLItemData();
}

void DNF::BaseSoundLoad()
{
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Sound");


		std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

		for (GameEngineDirectory& DirIter : AllTextureDir)
		{
			std::vector<GameEngineFile> Sound = DirIter.GetAllFile();

			for (size_t i = 0; i < Sound.size(); i++)
			{
				GameEngineSound::LoadRessource(Sound[i].GetFullPath());
			}
			
		}
	}
}

void DNF::BaseTextureLoad()
{
	GameEngineFont::Load("굴림");
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("UI");
		Dir.Move("Monster_HP");

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
		Dir.Move("Item");
		Dir.Move("Icon");
		Dir.Move("Equipment");
		
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
		Dir.Move("Map");
		Dir.Move("Luke_Raid");

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
		Dir.Move("CharacterCreate");
		Dir.Move("CharacterGoBackMark");

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
		Dir.Move("Map");
		Dir.Move("Collision");

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
		Dir.Move("DungeonSelect");

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
		Dir.Move("DungeonLoading");

		std::vector<GameEngineFile> Texture = Dir.GetAllFile();

		for (size_t i = 0; i < Texture.size(); i++)
		{
			GameEngineTexture::Load(Texture[i].GetFullPath());
		}

		{

			GameEngineDirectory Dir;
			Dir.MoveParentToExitsChildDirectory("Resource");
			Dir.Move("Resource");
			Dir.Move("Texture");
			Dir.Move("UI");
			Dir.Move("Item");
			Dir.Move("Icon");
			Dir.Move("Fighter");
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
			Dir.Move("Item");
			Dir.Move("Icon");
			Dir.Move("Consumption");

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
			Dir.Move("SkillIcon");

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
			Dir.Move("NPC");

			std::vector<GameEngineFile> Texture = Dir.GetAllFile();

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
		Dir.Move("PopUp");
		Dir.Move("NPCInteraction");

		std::vector<GameEngineFile> Texture = Dir.GetAllFile();

		for (size_t i = 0; i < Texture.size(); i++)
		{
			GameEngineTexture::Load(Texture[i].GetFullPath());
		}
	}



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
		Dir.Move("UI");
		Dir.Move("Shop");


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
		Dir.Move("Jelva");

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
		Dir.Move("Seria_Room");

		GameEngineFolderTexture::Load(Dir.GetFullPath());

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
	//	Dir.Move("Monster");
	//	std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

	//	for (GameEngineDirectory& DirIter : AllTextureDir)
	//	{
	//		GameEngineFolderTexture::Load(DirIter.GetFullPath());
	//	}
	//}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExitsChildDirectory("Resource");
		Dir.Move("Resource");
		Dir.Move("Texture");
		Dir.Move("Effect");
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
		Dir.Move("ComboTexture");
		
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
		Dir.Move("Monster");
		//Dir.Move("MonsterCategory");

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
		Dir.Move("LevelUp");

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
		Dir.Move("PopUp");
		Dir.Move("TalkPopUp");

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
	//	Dir.Move("UI");
	//	Dir.Move("Monster_HP");

	//	std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

	//	for (GameEngineDirectory& DirIter : AllTextureDir)
	//	{
	//		GameEngineFolderTexture::Load(DirIter.GetFullPath());
	//	}

	//}


	{
		//GameEngineDirectory Dir;
		//Dir.MoveParentToExitsChildDirectory("Resource");
		//Dir.Move("Resource");
		//Dir.Move("Texture");
		//Dir.Move("Map");
		//Dir.Move("Jelva");
		//std::vector<GameEngineDirectory> AllTextureDir = Dir.GetRecursiveAllDirectory();

		//for (GameEngineDirectory& DirIter : AllTextureDir)
		//{
		//	GameEngineFolderTexture::Load(DirIter.GetFullPath());
		//}
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

void DNF::BaseShaderLoad()
{

	GameEngineRenderingPipeLine* NewPipe = GameEngineRenderingPipeLine::Create("Texture_Avata");
	NewPipe->SetVertexShader("Texture_Avata.hlsl");
	NewPipe->SetPixelShader("Texture_Avata.hlsl");

	NewPipe = GameEngineRenderingPipeLine::Create("Outline");
	NewPipe->SetVertexShader("Outline.hlsl");
	NewPipe->SetPixelShader("Outline.hlsl");

	
	//{
	//	GameEngineDirectory Dir;

	//	Dir.MoveParentToExitsChildDirectory("Shader");
	//	Dir.Move("Shader");

	//	std::vector<GameEngineFile> Shaders = Dir.GetAllFile("hlsl");

	//	for (size_t i = 0; i < Shaders.size(); i++)
	//	{
	//		GameEngineShader::AutoCompile(Shaders[i].GetFullPath());
	//	}

	//}

	//{
	//	GameEngineRenderingPipeLine* NewPipe = GameEngineRenderingPipeLine::Create("Texture_HP");
	//	NewPipe->SetInputAssembler1VertexBuffer("FullRect");
	//	NewPipe->SetInputAssembler2IndexBuffer("FullRect");
	//	NewPipe->SetVertexShader("Texture_HP.hlsl");
	//	NewPipe->SetPixelShader("Texture_HP.hlsl");
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
		GameEngineInput::GetInst()->CreateKey("Key_T", 'T');
		GameEngineInput::GetInst()->CreateKey("Key_Y", 'Y');
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
		GameEngineInput::GetInst()->CreateKey("Avata", 'U');
		GameEngineInput::GetInst()->CreateKey("Skill", 'K');
		GameEngineInput::GetInst()->CreateKey("MyProfile", 'M');
		GameEngineInput::GetInst()->CreateKey("Enter", VK_RETURN);

		
	}
	{
		GameEngineInput::GetInst()->CreateKey("LMouseCLK", MK_LBUTTON);
		GameEngineInput::GetInst()->CreateKey("RMouseCLK", MK_RBUTTON);
	}
	{
		GameEngineInput::GetInst()->CreateKey("Debug0", VK_NUMPAD0);
		GameEngineInput::GetInst()->CreateKey("Debug1", VK_NUMPAD1);
		GameEngineInput::GetInst()->CreateKey("Debug2", VK_NUMPAD2);
		GameEngineInput::GetInst()->CreateKey("Debug3", VK_NUMPAD3);
		GameEngineInput::GetInst()->CreateKey("Debug4", VK_NUMPAD4);
		GameEngineInput::GetInst()->CreateKey("Debug5", VK_NUMPAD5);
	}
}

void DNF::Update(float _DeltaTime)
{


}

void DNF::End()
{
	GamePlayItem_DESC::DestoryALLItemData();
	GamePlayDataBase::DestroyFrameAnimationDESC();
}