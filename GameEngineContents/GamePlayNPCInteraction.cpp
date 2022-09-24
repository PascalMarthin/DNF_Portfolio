#include "PreCompile.h"
#include "GamePlayNPCInteraction.h"
#include "GameEngineUIFontRenderer.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayInteractionWindow.h"
#include "GamePlayNPCInteractionTalk.h"

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

	On();
}


void GamePlayNPCInteraction::Update(float _DeltaTime)
{


}


InteractionMenuDo GamePlayNPCInteraction::CheckInput()
{
	switch (CurrentActiveInteract)
	{
	case InteractOption::None:
		switch (Actor_InteractWindow->CheckInput())
		{
		case InteractionMenuDo::None:
			return InteractionMenuDo::None;
			break;
		case InteractionMenuDo::Exit:
			return InteractionMenuDo::Exit;
			break;		
		case InteractionMenuDo::Talking:
			SetNPCInteraction(InteractOption::Talking);
			break;
		default:
			break;
		}
		break;
	case InteractOption::Quest:

		break;
	case InteractOption::Deal:
		break;
	case InteractOption::Talking:
		if (Actor_Talk->CheckInput() == InteractionMenuDo::Exit)
		{
			return InteractionMenuDo::Exit;

		}
		break;
	default:
		break;
	}
	return InteractionMenuDo::None;
}


void GamePlayNPCInteraction::SetNPCInteractionMenu(GamePlayObjectNPC* _NPC)
{
	NPC_Interaction = _NPC;
	Actor_InteractWindow->SetInteractUIOn(NPC_Interaction);
	CurrentActiveInteract = InteractOption::None;

}
void GamePlayNPCInteraction::NPCInteractionEnd()
{
	CurrentActiveInteract = InteractOption::None;
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

		break;
	case InteractOption::Talking:
		Actor_Talk->SetNPCInteraction_Talk(NPC_Interaction->GetStringPtr(InteractOption::Talking), NPC_Interaction);
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
}



void GamePlayNPCInteraction::LevelStartEvent()
{
	GamePlayNPCInteraction::Inst = this;
}
void GamePlayNPCInteraction::LevelEndEvent()
{
	GamePlayNPCInteraction::Inst = nullptr;
}