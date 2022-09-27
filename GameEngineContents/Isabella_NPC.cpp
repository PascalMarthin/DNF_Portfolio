#include "PreCompile.h"
#include "Isabella_NPC.h"

Isabella_NPC::Isabella_NPC() 
{
}

Isabella_NPC::~Isabella_NPC() 
{
}

void Isabella_NPC::Start()
{
	GamePlayObjectNPC::Start();
	Texture_NPCStanding->CreateFrameAnimationFolderPlus("Isabella", FrameAnimation_DESC("Isabella", 0.25f));
	Texture_NPCStanding->ChangeFrameAnimationPlus("Isabella");
	Texture_NPCStanding->ScaleToTexture();
	Texture_NPCStanding->GetOutLine()->ScaleToTexture();
	SetOutLineOff();


	EnumNPC = NPCEnum::Isabella;
	//vector_Option.push_back(InteractOption::Deal);
	vector_Option.push_back(InteractOption::Talking);
	Name = "황녀 이자벨라";

	map_InteractionTalk[InteractOption::Talking].push_back("벨란트 공이 초대했던 만찬 파티는 정말 최악이었어요 그 후줄근한 커튼보다는 차라리 이곳 젤바의 천막이 더 화려할 거예요.");


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Isabella.png");

}