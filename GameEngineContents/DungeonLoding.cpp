#include "PreCompile.h"
#include <GameEngineCore/GEngine.h>
#include "DNF.h"
#include "DungeonLoding.h"
#include "DungeonLoding_BackGround.h"
#include "Luke_Stage1.h"

LocalDungeon DungeonLoding::CurrentDungeon = LocalDungeon::None;

DungeonLoding::DungeonLoding() 
{
}

DungeonLoding::~DungeonLoding() 
{
}

// -----------Start------------
void DungeonLoding::Start()
{
	Texture_BackGround = CreateActor<DungeonLoding_BackGround>();
}


// -----------Update-----------
void DungeonLoding::Update(float _DeltaTime)
{

}

void DungeonLoding::OnEvent()
{
	switch (DungeonLoding::CurrentDungeon)
	{

	case LocalDungeon::Luke_LightOfAltar:
		{
			DNF::GetInst()->CreateLoadLevel<Luke_Stage1>("Luke_Stage1");


			GEngine::ChangeLevel("Luke_Stage1");
		}
		break;
	case LocalDungeon::None:
	default:
		// Debug
		{
			DungeonLoding::CurrentDungeon = LocalDungeon::Luke_LightOfAltar;
			DungeonLoding::OnEvent();
			return;
		}
		break;
	}
}


void DungeonLoding::OffEvent()
{
	DungeonLoding::CurrentDungeon = LocalDungeon::None;
}