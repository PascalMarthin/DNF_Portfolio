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
	Name = "���� ��";

	map_InteractionTalk[InteractOption::Talking].push_back("�����... �Ʊ� �޸� ���� ���͵帮�ٰ� ���� ���� ������ ���ϱ�.");
	map_InteractionTalk[InteractOption::Talking].push_back("��, �װ� ������ �ʿ��ϴٸ� ������ �ű�ô�����.");
	map_InteractionTalk[InteractOption::Talking].push_back("�����ڰ� �� ���ſ� �� ��ôµ� ��� ������ ���� �� �ְھ�� ? ���͵帮�ٰ� �Ǽ��� �߳׿�.");
	map_InteractionTalk[InteractOption::Talking].push_back("������... ������ ��������...");

	


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Hunter_pon.png");

}
