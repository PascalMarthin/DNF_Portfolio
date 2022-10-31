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


		map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("seria_amb_01.ogg");
		map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("seria_amb_02.ogg");
		map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("seria_amb_03.ogg");

		map_NPCVoice[InteractOptionNPCVoice::Click].push_back("seria_tk_01.ogg");
		map_NPCVoice[InteractOptionNPCVoice::Click].push_back("seria_tk_02.ogg");
		map_NPCVoice[InteractOptionNPCVoice::Click].push_back("seria_tk_03.ogg");

		map_NPCVoice[InteractOptionNPCVoice::Off].push_back("seria_fw_01.ogg");
		map_NPCVoice[InteractOptionNPCVoice::Off].push_back("seria_fw_02.ogg");
		map_NPCVoice[InteractOptionNPCVoice::Off].push_back("seria_fw_03.ogg");




		map_SellItemList[GamePlayItemCode::Tropica_Coat] = 50000;
		map_SellItemList[GamePlayItemCode::Tropica_Belt] = 52500;
		map_SellItemList[GamePlayItemCode::Tropica_Pants] = 20000;
		map_SellItemList[GamePlayItemCode::Tropica_Neck] = 40000;
		map_SellItemList[GamePlayItemCode::Tropica_Shoes] = 12500;
		EnumNPC = NPCEnum::Seria;
		//std::map<InteractOption, std::vector<std::string>> map_InteractionTalk;
		vector_Option.push_back(InteractOption::Deal);
		vector_Option.push_back(InteractOption::Talking);
		Name = "세리아 키르민";

		map_InteractionTalk[InteractOption::Talking].push_back("안녕하세요. 세리아 키르민이라고 해요. 곁에서 도와 드리기 위해 여기 있어요.");
		map_InteractionTalk[InteractOption::Talking].push_back("제가 도울 수 있는 일이라면 언제든지 말씀해주세요");

		TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Seria.png");

	}
}

//void Seria_NPC::Update(float _DeltaTime)
//{
//	GameEngineDebug::OutPutString(std::to_string(Texture_NPCStanding->GetTransform().GetLocalPosition().y));
//	GameEngineDebug::OutPutString(std::to_string(Texture_NPCOutLine->GetTransform().GetLocalPosition().y));
//} 
