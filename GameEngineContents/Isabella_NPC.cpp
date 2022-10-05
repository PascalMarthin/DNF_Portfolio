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

	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("isabella_amb_03.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("isabella_amb_05.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("isabella_amb_08.ogg");

	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("isabella_tk_03.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("isabella_tk_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("isabella_tk_05.ogg");

	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("isabella_fw_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("isabella_fw_03.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("isabella_fw_05.ogg");


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Isabella.png");

}