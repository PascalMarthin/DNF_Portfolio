#include "PreCompile.h"
#include "Roi_hartwig_NPC.h"

Roi_hartwig_NPC::Roi_hartwig_NPC() 
{
}

Roi_hartwig_NPC::~Roi_hartwig_NPC() 
{
}

void Roi_hartwig_NPC::Start()
{
	GamePlayObjectNPC::Start();
	Texture_NPCStanding->CreateFrameAnimationFolderPlus("roi_hartwig", FrameAnimation_DESC("roi_hartwig", 0.25f));
	Texture_NPCStanding->ChangeFrameAnimationPlus("roi_hartwig");
	Texture_NPCStanding->ScaleToTexture();
	Texture_NPCStanding->GetOutLine()->ScaleToTexture();
	SetOutLineOff();


	EnumNPC = NPCEnum::Roi_hartwig;
	//vector_Option.push_back(InteractOption::Deal);
	vector_Option.push_back(InteractOption::Talking);
	Name = "���� �� ������";

	map_InteractionTalk[InteractOption::Talking].push_back("���� ��������� ���� ���鿡 �� �ð��� �ƴ϶� ���̾�. ������ ���̵� ��Ʈ�� �Ű� ����� �ϰŵ�.");
	map_InteractionTalk[InteractOption::Talking].push_back("�����ڶ�� ������ ��Ȯ�� ��Ȱ ���ϰ� ����� ���̵��� ��ġ�� �ʴ� �Ĳ����� �ʿ�����. �ʵ� �� �� �Ƶ�.");
	map_InteractionTalk[InteractOption::Talking].push_back("���� ���谡���� �׷� �� ����ϱ�� ������� ?");

	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("roi_amb_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("roi_amb_02.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("roi_amb_03.ogg");

	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("roi_tk_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("roi_tk_02.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("roi_tk_03.ogg");

	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("roi_fw_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("roi_fw_02.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("roi_fw_03.ogg");


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Roi.png");

}