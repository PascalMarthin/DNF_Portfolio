#include "PreCompile.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayEnum.h"

GameEngineSoundPlayer GamePlayObjectNPC::NPC_Voice;

GamePlayObjectNPC::GamePlayObjectNPC() 
	: Texture_NPCStanding(nullptr)

{
}

GamePlayObjectNPC::~GamePlayObjectNPC() 
{
}

void GamePlayObjectNPC::Start()
{
	GetTransform().SetLocalScale({MonitorX, MonitorY, 1.f });
	

	Collision_CharacterSpot = CreateComponent<GameEngineCollision>();
	Collision_CharacterSpot->ChangeOrder(CollisionOrder::NPC_Interaction);
	Collision_CharacterSpot->GetTransform().SetLocalScale({150, 100, 100});

	Texture_NPCStanding = CreateComponent<GameEnginePlusTextureRenderer>();
	Texture_NPCStanding->SetPivot(PIVOTMODE::CENTER);
	Texture_NPCStanding->GetOutLine()->GetPixelData().PlusColor = { 174.f / 255.f, 245.f / 255.f, 92.f / 255.f, 1 };
	Texture_NPCStanding->GetOutLine()->GetPixelData().Slice = { 0, 0, 0, 0 };
	Texture_NPCStanding->GetOutLine()->SetPivot(PIVOTMODE::CENTER);
	Texture_NPCStanding->GetAtlasDatas().PivotPos = float4::ZERO;
	const float4& Pos = Texture_NPCStanding->GetTransform().GetLocalPosition();

	const float4& Pos1 = Texture_NPCStanding->GetOutLine()->GetTransform().GetLocalPosition();
	Texture_NPCStanding->GetOutLine()->GetTransform().SetLocalMove({ 0,0, 0.001f});
	//Texture_NPCStanding->GetOutLine()->GetPixelData().Slice = { 5, 5 };


	int a = 0;


	SetOutLineOff();

}


void GamePlayObjectNPC::Update(float _DeltaTime)
{

}

void GamePlayObjectNPC::SetVoice(const std::string& _Name)
{

	NPC_Voice.Stop();
	NPC_Voice = GameEngineSound::SoundPlayControl(_Name);
	NPC_Voice.Volume(0.8f);
}