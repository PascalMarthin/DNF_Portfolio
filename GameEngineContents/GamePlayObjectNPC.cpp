#include "PreCompile.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayEnum.h"

GamePlayObjectNPC::GamePlayObjectNPC() 
	: Texture_NPCStanding(nullptr)
{
}

GamePlayObjectNPC::~GamePlayObjectNPC() 
{
}

void GamePlayObjectNPC::Start()
{
	GetTransform().SetLocalScale({MonitorX, MonitorY });
	

	Collision_CharacterSpot = CreateComponent<GameEngineCollision>();
	Collision_CharacterSpot->ChangeOrder(CollisionOrder::NPC_Interaction);
	Collision_CharacterSpot->GetTransform().SetLocalScale({150, 100, 100});

	Texture_NPCStanding = CreateComponent<GameEnginePlusTextureRenderer>();
	Texture_NPCStanding->SetPivot(PIVOTMODE::CENTER);
	Texture_NPCStanding->ChangeCamera(CAMERAORDER::Object);
	Texture_NPCStanding->GetOutLine()->GetPixelData().PlusColor = { 174.f / 255.f, 245.f / 255.f, 92.f / 255.f, 1 };
	Texture_NPCStanding->GetOutLine()->GetPixelData().Slice = { 0, 0, 0, 0 };
	Texture_NPCStanding->GetAtlasDatas().PivotPos = float4::ZERO;
	//Texture_NPCStanding->GetOutLine()->GetPixelData().Slice = { 5, 5 };



}


void GamePlayObjectNPC::Update(float _DeltaTime)
{

}