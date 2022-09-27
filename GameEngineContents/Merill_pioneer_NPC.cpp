#include "PreCompile.h"
#include "Merill_pioneer_NPC.h"

Merill_pioneer_NPC::Merill_pioneer_NPC() 
{
}

Merill_pioneer_NPC::~Merill_pioneer_NPC() 
{
}

void Merill_pioneer_NPC::Start()
{
	GamePlayObjectNPC::Start();
	Texture_NPCStanding->CreateFrameAnimationFolderPlus("merill_pioneer", FrameAnimation_DESC("merill_pioneer", 0.25f));
	Texture_NPCStanding->ChangeFrameAnimationPlus("merill_pioneer");
	Texture_NPCStanding->ScaleToTexture();
	Texture_NPCStanding->GetOutLine()->ScaleToTexture();
	SetOutLineOff();

	Texture_NPCStanding_Smoke = CreateComponent<GameEnginePlusTextureRenderer>();
	Texture_NPCStanding_Smoke->CreateFrameAnimationFolderPlus("merill_pioneer_smoke", FrameAnimation_DESC("merill_pioneer_smoke", 0.25f));
	Texture_NPCStanding_Smoke->ChangeFrameAnimationPlus("merill_pioneer_smoke");
	Texture_NPCStanding_Smoke->ScaleToTexture();
	Texture_NPCStanding_Smoke->GetOutLine()->Off();



	EnumNPC = NPCEnum::Merill_pioneer;
	//vector_Option.push_back(InteractOption::Deal);
	vector_Option.push_back(InteractOption::Talking);
	Name = "메릴 오드뤼즈";

	map_InteractionTalk[InteractOption::Talking].push_back("자네는 모험에 이유가 있다고 생각하나 ?");
	map_InteractionTalk[InteractOption::Talking].push_back("아직 가보지 못한 미지의 땅, 경험하지 못한 신비로운 이기, 쓰러트리지 못한 절대 강자, 설명되지 않는 강력한 몬스터!");
	map_InteractionTalk[InteractOption::Talking].push_back("이 모든 것들을 찾아서 경험하고 극복하는 것, 이것이 바로 우리의 목적이자 존재의 이유가 아닐까 ?");
	map_InteractionTalk[InteractOption::Talking].push_back("그러니 자네도 복잡한 생각일랑 접어두고 모험가 본연의 모습으로 돌아가 세상을 즐기게나.");
	map_InteractionTalk[InteractOption::Talking].push_back("그렇게 한다면 자네도 이 나이가 먹어서도 청춘 이라 불릴 수 있을 거야.");
		
		

	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Merill.png");

}