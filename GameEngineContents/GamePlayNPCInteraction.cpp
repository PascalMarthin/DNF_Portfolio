#include "PreCompile.h"
#include "GamePlayNPCInteraction.h"
#include "GameEngineUIFontRenderer.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayInteractionWindow.h"
#include "GamePlayNPCInteractionTalk.h"
#include "GamePlayInteractionShop.h"

GamePlayNPCInteraction* GamePlayNPCInteraction::Inst = nullptr;

GamePlayNPCInteraction::GamePlayNPCInteraction() 
	:  Actor_InteractWindow(nullptr)
	, NPC_Interaction(nullptr)
	, Actor_Talk(nullptr)
	, CurrentActiveInteract(InteractOption::None)
{
}

GamePlayNPCInteraction::~GamePlayNPCInteraction() 
{
}

void GamePlayNPCInteraction::Start()
{

	Actor_Talk = GetLevel()->CreateActor<GamePlayNPCInteractionTalk>();
	Actor_InteractWindow = GetLevel()->CreateActor<GamePlayInteractionWindow>();
	Actor_Shop = GetLevel()->CreateActor<GamePlayInteractionShop>();

	
	On();
}


void GamePlayNPCInteraction::Update(float _DeltaTime)
{


}


InteractOption GamePlayNPCInteraction::CheckInput()
{
	switch (CurrentActiveInteract)
	{
	case InteractOption::None:
		SetNPCInteraction(Actor_InteractWindow->CheckInput());
		break;
	case InteractOption::Quest:

		break;
	case InteractOption::Deal:

		break;
	case InteractOption::Talking:
		if (Actor_Talk->CheckInput() == InteractOption::Exit)
		{
			GamePlayObjectNPC::SetVoice(NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Off][GameEngineRandom::MainRandom.RandomInt(0, NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Off].size() - 1)]);
			return InteractOption::Exit;
		}
		break;
	default:
		break;
	}
	return InteractOption::None;
}


void GamePlayNPCInteraction::SetNPCInteractionMenu(GamePlayObjectNPC* _NPC)
{
	NPC_Interaction = _NPC;
	Actor_InteractWindow->SetInteractUIOn(NPC_Interaction);

	GamePlayObjectNPC::SetVoice(NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Click][GameEngineRandom::MainRandom.RandomInt(0, NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Click].size() - 1)]);

	


	CurrentActiveInteract = InteractOption::None;

}
void GamePlayNPCInteraction::NPCInteractionEnd()
{
	CurrentActiveInteract = InteractOption::None;
	Actor_Shop->Off();
	Actor_Talk->Off();
}

void GamePlayNPCInteraction::SetNPCInteraction(InteractOption _Option)
{
	switch (_Option)
	{
	case InteractOption::None:
		break;
	case InteractOption::Quest:
		//SetNPCInteraction_Talk(NPC_Interaction->GetStringPtr(InteractOption::Quest));
		break;
	case InteractOption::Deal:
		Actor_Shop->SetShopData(NPC_Interaction);
		Actor_Shop->On();
		break;
	case InteractOption::Talking:
		Actor_Talk->SetNPCInteraction_Talk(NPC_Interaction->GetStringPtr(InteractOption::Talking), NPC_Interaction);
		Actor_Talk->On();
		//Actor_Talk->On();
		break;
	default:
		break;
	}
	CurrentActiveInteract = _Option;
}

void GamePlayNPCInteraction::EndInteraction()
{
	Actor_InteractWindow->SetInteractUIOff();
	Actor_InteractWindow->Off();
	Actor_Talk->Off();
	Actor_Shop->Off();
}



void GamePlayNPCInteraction::LevelStartEvent()
{
	GamePlayNPCInteraction::Inst = this;
}
void GamePlayNPCInteraction::LevelEndEvent()
{
	GamePlayNPCInteraction::Inst = nullptr;
}