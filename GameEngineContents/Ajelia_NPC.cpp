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
	Name = "�������� ��Ʈ";

	map_InteractionTalk[InteractOption::Talking].push_back("�� �Ⱬ�� ���� ������.���� ���ڿ������� �ʳ���?");
	map_InteractionTalk[InteractOption::Talking].push_back("�絵�� ���õ� ��� ���� ���ڿ���������. �־� ���� �� �� �ϵ��� �絵 ������ �������� �־��.");
	map_InteractionTalk[InteractOption::Talking].push_back("������ ���δ�� �����ؼ��� �� �˴ϴ�.�̹� �ƶ���� ����� �׵�� ��� ����Ǿ� �ֱ� ��������.");
	map_InteractionTalk[InteractOption::Talking].push_back("��Ų ��Ÿ���� Ǯ���� ���ɽ����� �ٰ����� �ؿ�.����ų �� ���� ���� �ٽ� ���������� �� �˴ϴ�.");
	
		


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Ajelia.png");

}