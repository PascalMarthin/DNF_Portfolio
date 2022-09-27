#include "PreCompile.h"
#include "Ajelia_NPC.h"

Ajelia_NPC::Ajelia_NPC() 
{
}

Ajelia_NPC::~Ajelia_NPC() 
{
}

void Ajelia_NPC::Start()
{
	GamePlayObjectNPC::Start();
	Texture_NPCStanding->CreateFrameAnimationFolderPlus("ajelia", FrameAnimation_DESC("ajelia", 0.25f));
	Texture_NPCStanding->ChangeFrameAnimationPlus("ajelia");
	Texture_NPCStanding->ScaleToTexture();
	Texture_NPCStanding->GetOutLine()->ScaleToTexture();
	SetOutLineOff();


	EnumNPC = NPCEnum::Ajelia;
	//vector_Option.push_back(InteractOption::Deal);
	vector_Option.push_back(InteractOption::Talking);
	Name = "아젤리아 로트";

	map_InteractionTalk[InteractOption::Talking].push_back("저 기괴한 성을 보세요.정말 부자연스럽지 않나요?");
	map_InteractionTalk[InteractOption::Talking].push_back("사도와 관련된 모든 것이 부자연스러워요. 있어 서는 안 될 일들이 사도 때문에 벌어지고 있어요.");
	map_InteractionTalk[InteractOption::Talking].push_back("하지만 무턱대고 공격해서는 안 됩니다.이미 아라드의 운명이 그들과 깊게 연결되어 있기 때문이죠.");
	map_InteractionTalk[InteractOption::Talking].push_back("엉킨 실타래를 풀듯이 조심스럽게 다가가야 해요.돌이킬 수 없는 일이 다시 벌어져서는 안 됩니다.");
	
		


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Ajelia.png");

}