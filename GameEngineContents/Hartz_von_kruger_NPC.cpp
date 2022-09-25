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
	Name = "하츠 폰 크루거";

	map_InteractionTalk[InteractOption::Talking].push_back("어디를 가나 사람이 많군. 조용히 책이나 읽고 싶은데 시끄러워서 원...");
	map_InteractionTalk[InteractOption::Talking].push_back("뭐냐, 그 눈은? 내가 책을 읽는다는 게 그렇게 신기하냐? 뭐... 나 역시도 책보다는 창이 더 좋지만, 부하들에게 공부하라고 하는 입장에서 손을 놓을 수는 없잖냐.");


	TexureR_Face = GameEngineTexture::Find("NPC_Dialog_Face_Hartz.png");

}