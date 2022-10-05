#include "PreCompile.h"
#include "Hartz_von_kruger_NPC.h"

Hartz_von_kruger_NPC::Hartz_von_kruger_NPC() 
{
}

Hartz_von_kruger_NPC::~Hartz_von_kruger_NPC() 
{
}
void Hartz_von_kruger_NPC::Start()
{
	GamePlayObjectNPC::Start();
	Texture_NPCStanding->CreateFrameAnimationFolderPlus("Hartz_von_kruger", FrameAnimation_DESC("Hartz_von_kruger", 0.25f));
	Texture_NPCStanding->ChangeFrameAnimationPlus("Hartz_von_kruger");
	Texture_NPCStanding->ScaleToTexture();
	Texture_NPCStanding->GetOutLine()->ScaleToTexture();
	SetOutLineOff();


	EnumNPC = NPCEnum::Hartz_von_kruger;
	//vector_Option.push_back(InteractOption::Deal);
	vector_Option.push_back(InteractOption::Talking);
	Name = "���� �� ũ���";

	map_InteractionTalk[InteractOption::Talking].push_back("��� ���� ����� ����. ������ å�̳� �а� ������ �ò������� ��...");
	map_InteractionTalk[InteractOption::Talking].push_back("����, �� ����? ���� å�� �д´ٴ� �� �׷��� �ű��ϳ�?");
	map_InteractionTalk[InteractOption::Talking].push_back("... ��... �� ���õ� å���ٴ� â�� �� ������, ���� �鿡�� �����϶�� �ϴ� ���忡�� ���� ���� ���� �� �ݳ�.");
	
	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("hartz_amb_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("hartz_amb_02.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Nomal].push_back("hartz_amb_03.ogg");

	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("hartz_tk_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("hartz_tk_02.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Click].push_back("hartz_tk_03.ogg");

	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("hartz_fw_01.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("hartz_fw_02.ogg");
	map_NPCVoice[InteractOptionNPCVoice::Off].push_back("hartz_fw_03.ogg");


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Hartz.png");

}