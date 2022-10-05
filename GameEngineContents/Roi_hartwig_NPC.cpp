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
	Name = "로이 더 버닝펜";

	map_InteractionTalk[InteractOption::Talking].push_back("잠이 쏟아지지만 아직 수면에 들어갈 시간은 아니라서 말이야. 생각난 아이디어를 노트에 옮겨 적어야 하거든.");
	map_InteractionTalk[InteractOption::Talking].push_back("연구자라면 모름지기 정확한 생활 패턴과 사소한 아이디어라도 놓치지 않는 꼼꼼함이 필요하지. 너도 잘 알 아둬.");
	map_InteractionTalk[InteractOption::Talking].push_back("뭐… 모험가에게 그런 걸 기대하기는 힘드려나 ?");

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