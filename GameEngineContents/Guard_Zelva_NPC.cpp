#include "PreCompile.h"
#include "Guard_Zelva_NPC.h"
#include <GameEngineCore/GameEngineCollision.h>
Guard_Zelva_NPC::Guard_Zelva_NPC() 
{
}

Guard_Zelva_NPC::~Guard_Zelva_NPC() 
{
}

void Guard_Zelva_NPC::Start()
{
	GamePlayObjectNPC::Start();
	Texture_NPCStanding->CreateFrameAnimationFolderPlus("npc_guard_zelva1", FrameAnimation_DESC("npc_guard_zelva1", 0.25f));
	Texture_NPCStanding->ChangeFrameAnimationPlus("npc_guard_zelva1");
	Texture_NPCStanding->ScaleToTexture();
	Texture_NPCStanding->GetOutLine()->ScaleToTexture();


	EnumNPC = NPCEnum::Guard_Zelva1;
	Name = "제국 호위병";

	Collision_CharacterSpot->Off();
}