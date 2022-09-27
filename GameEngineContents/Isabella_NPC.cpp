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
	Name = "Ȳ�� ���ں���";

	map_InteractionTalk[InteractOption::Talking].push_back("����Ʈ ���� �ʴ��ߴ� ���� ��Ƽ�� ���� �־��̾���� �� ���ٱ��� Ŀư���ٴ� ���� �̰� ������ õ���� �� ȭ���� �ſ���.");


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Isabella.png");

}