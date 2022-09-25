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


	EnumNPC = NPCEnum::Hartz_von_kruger;
	//vector_Option.push_back(InteractOption::Deal);
	vector_Option.push_back(InteractOption::Talking);
	Name = "���� �� ũ���";

	map_InteractionTalk[InteractOption::Talking].push_back("��� ���� ����� ����. ������ å�̳� �а� ������ �ò������� ��...");
	map_InteractionTalk[InteractOption::Talking].push_back("����, �� ����? ���� å�� �д´ٴ� �� �׷��� �ű��ϳ�? ��... �� ���õ� å���ٴ� â�� �� ������, ���ϵ鿡�� �����϶�� �ϴ� ���忡�� ���� ���� ���� ���ݳ�.");


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Hartz.png");

}