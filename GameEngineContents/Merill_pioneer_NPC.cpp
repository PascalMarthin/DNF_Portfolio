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
	Name = "�޸� �������";

	map_InteractionTalk[InteractOption::Talking].push_back("�ڳ״� ���迡 ������ �ִٰ� �����ϳ� ?");
	map_InteractionTalk[InteractOption::Talking].push_back("���� ������ ���� ������ ��, �������� ���� �ź�ο� �̱�, ����Ʈ���� ���� ���� ����, ������� �ʴ� ������ ����!");
	map_InteractionTalk[InteractOption::Talking].push_back("�� ��� �͵��� ã�Ƽ� �����ϰ� �غ��ϴ� ��, �̰��� �ٷ� �츮�� �������� ������ ������ �ƴұ� ?");
	map_InteractionTalk[InteractOption::Talking].push_back("�׷��� �ڳ׵� ������ �����϶� ����ΰ� ���谡 ������ ������� ���ư� ������ ���Գ�.");
	map_InteractionTalk[InteractOption::Talking].push_back("�׷��� �Ѵٸ� �ڳ׵� �� ���̰� �Ծ�� û�� �̶� �Ҹ� �� ���� �ž�.");
		
		

	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Merill.png");

}