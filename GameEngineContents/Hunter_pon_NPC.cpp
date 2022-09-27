#include "PreCompile.h"
#include "Hunter_pon_NPC.h"

Hunter_pon_NPC::Hunter_pon_NPC() 
{
}

Hunter_pon_NPC::~Hunter_pon_NPC() 
{
}
void Hunter_pon_NPC::Start()
{
	GamePlayObjectNPC::Start();
	Texture_NPCStanding->CreateFrameAnimationFolderPlus("hunter_pon", FrameAnimation_DESC("hunter_pon", 0.25f));
	Texture_NPCStanding->ChangeFrameAnimationPlus("hunter_pon");
	Texture_NPCStanding->ScaleToTexture();
	Texture_NPCStanding->GetOutLine()->ScaleToTexture();
	SetOutLineOff();


	EnumNPC = NPCEnum::Hunter_pon;
	vector_Option.push_back(InteractOption::Talking);
	//vector_Option.push_back(InteractOption::Deal);
	Name = "헌터 폰";

	map_InteractionTalk[InteractOption::Talking].push_back("어구구구... 아까 메릴 님을 도와드리다가 발을 세게 찧었지 뭡니까.");
	map_InteractionTalk[InteractOption::Talking].push_back("아, 그게 연구에 필요하다며 광석을 옮기시더라고요.");
	map_InteractionTalk[InteractOption::Talking].push_back("연장자가 저 무거운 걸 드시는데 어떻게 가만히 보고 만 있겠어요 ? 도와드리다가 실수를 했네요.");
	map_InteractionTalk[InteractOption::Talking].push_back("끼이잉... 아직도 아프군요...");

	


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Hunter_pon.png");

}
