#include "PreCompile.h"
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineBase/GameEngineTransform.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineTransformComponent.h>
#include "Seria_NPC.h"

Seria_NPC::Seria_NPC() 
{
}

Seria_NPC::~Seria_NPC() 
{
}

void Seria_NPC::Start()
{
	GamePlayObjectNPC::Start();
	{

		Texture_NPCStanding->CreateFrameAnimationFolderPlus("Seria_Town_Standing", FrameAnimation_DESC("Seria", 0, 11,  0.25f));
		Texture_NPCStanding->ChangeFrameAnimationPlus("Seria_Town_Standing");
		Texture_NPCStanding->ScaleToTexture();
		Texture_NPCStanding->GetOutLine()->ScaleToTexture();
		SetOutLineOff();

		//Texture_NPCStanding->SetPivot(PIVOTMODE::LEFTTOP);


		//Texture_NPCOutLine->CreateFrameAnimationFolder("Seria_Town_Standing", FrameAnimation_DESC("Seria", 0.25f));
		//Texture_NPCOutLine->ChangeFrameAnimation("Seria_Town_Standing");
		//Texture_NPCOutLine->ScaleToTexture();

		map_SellItemList[GamePlayItemCode::Tropica_Coat] = 50000;
		map_SellItemList[GamePlayItemCode::Tropica_Belt] = 50000;
		map_SellItemList[GamePlayItemCode::Tropica_Pants] = 50000;
		map_SellItemList[GamePlayItemCode::Tropica_Neck] = 50000;
		map_SellItemList[GamePlayItemCode::Tropica_Shoes] = 50000;
		EnumNPC = NPCEnum::Seria;
		//std::map<InteractOption, std::vector<std::string>> map_InteractionTalk;
		vector_Option.push_back(InteractOption::Deal);
		vector_Option.push_back(InteractOption::Talking);
		Name = "세리아 키르민";

		map_InteractionTalk[InteractOption::Talking].push_back("테스트 1231232 32123 1233123     3213   213213 3213213");
		map_InteractionTalk[InteractOption::Talking].push_back("가나다라 마바사 아자차카마바사하 1234567890 abcdefghijklmnopqrstuvwxyz");

		TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Seria.png");

	}
}

void Seria_NPC::Update(float _DeltaTime)
{
	//GameEngineDebug::OutPutString(std::to_string(Texture_NPCStanding->GetTransform().GetLocalPosition().y));
	//GameEngineDebug::OutPutString(std::to_string(Texture_NPCOutLine->GetTransform().GetLocalPosition().y));
} 
