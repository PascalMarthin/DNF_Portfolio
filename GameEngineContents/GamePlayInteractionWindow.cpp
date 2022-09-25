#include "PreCompile.h"
#include "GamePlayInteractionWindow.h"
#include "GamePlayObjectNPC.h"
#include <GameEngineCore/GameEngineFontRenderer.h>
#include "GamePlayLevelTemplate.h"
#include "GamePlayNPCInteraction.h"

GamePlayInteractionWindow::GamePlayInteractionWindow() 
	: Font_Name(nullptr)
	, CurrentOptionIndex(0)
	, CurrentOption(InteractOption::None)
{
}

GamePlayInteractionWindow::~GamePlayInteractionWindow() 
{
}


void GamePlayInteractionWindow::SetInteractUIOn(GamePlayObjectNPC* _NPC)
{

	if (Font_Name != nullptr)
	{

		SetInteractUIOff(); // ¹º°¡ ÀÌ»óÇÏ´Ù
	}
	const float4& CamPos = GetLevel()->GetMainCamera()->GetTransform().GetWorldPosition();
	GetTransform().SetLocalPosition({ _NPC->GetTransform().GetWorldPosition().x - CamPos.x + 20.f, _NPC->GetTransform().GetWorldPosition().y - CamPos.y });

	const std::vector<InteractOption>& Options = _NPC->GetInteractOption();

	
	Font_Name = CreateComponent<GameEngineFontRenderer>("Font_Name");
	Font_Name->ChangeCamera(CAMERAORDER::UICAMERA);
	Font_Name->GetTransform().SetLocalPosition({0, 1,-10.006f });
	Font_Name->SetText(_NPC->Name, "±¼¸²");
	Font_Name->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
	Font_Name->SetRenderingOrder(10000);
	Font_Name->SetSize(11);
	Font_Name->SetPositionMode(FontPositionMode::WORLD);
	Font_Name->SetTopAndBotSort(TopAndBotSort::VCENTER);
	Font_Name->SetLeftAndRightSort(LeftAndRightSort::CENTER);


	GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>("InteractOption");
	Renderer->SetTexture("NPCInteraction_Name.png");
	Renderer->ScaleToTexture();
	map_Texture_InteractUI[InteractOption::None] = (Renderer);


	vector_AllCurrentOption.push_back(InteractOption::None);
	CurrentOptionIndex = 0;
	CurrentOption = vector_AllCurrentOption[CurrentOptionIndex];
	float Hight = -21.f;
	for (InteractOption Iter : Options)
	{
		Renderer = CreateComponent<GameEngineUIRenderer>("InteractOption");
		SetTextureInteractOption(Iter, Renderer);

		Renderer->GetTransform().SetLocalPosition({ 0, Hight, 0 });
		Renderer->ScaleToTexture();
		Hight += -21.f;
		map_Texture_InteractUI[Iter] = Renderer;
		vector_AllCurrentOption.push_back(Iter);
	}
	On();
}



void GamePlayInteractionWindow::SetInteractUIOff()
{

	for (auto& Iter : map_Texture_InteractUI)
	{
		Iter.second->Death();
	}
	map_Texture_InteractUI.clear();
	if (Font_Name != nullptr)
	{
		Font_Name->Death();
		Font_Name = nullptr;
	}
	vector_AllCurrentOption.clear();
	CurrentOptionIndex = 0;
	Off();
}

void GamePlayInteractionWindow::SetTextureInteractOption(InteractOption _Option, GameEngineUIRenderer* _Renderer)
{
	switch (_Option)
	{
	case InteractOption::Quest:
		_Renderer->SetTexture("NPCInteraction_Quest_Nomal.png");
		break;
	case InteractOption::Deal:
		_Renderer->SetTexture("NPCInteraction_Deal_Nomal.png");
		break;
	case InteractOption::Talking:
		_Renderer->SetTexture("NPCInteraction_Talking_Nomal.png");
		break;
	default:
		break;
	}
}

InteractOption GamePlayInteractionWindow::CheckInput()
{
	if (GameEngineInput::GetInst()->IsDown("UP_Arrow"))
	{
		--CurrentOptionIndex;
	}
	else if (GameEngineInput::GetInst()->IsDown("Down_Arrow"))
	{
		++CurrentOptionIndex;
	}
	else if (GameEngineInput::GetInst()->IsUp("Enter"))
	{
		//GamePlayNPCInteraction::GetInst()->
		if (CurrentOption == InteractOption::None)
		{
			return CurrentOption;
		}
		else
		{
			SetInteractUIOff();
			return CurrentOption;
		}
	}
	else
	{
		return InteractOption::None;
	}



	if (CurrentOptionIndex < 1)
	{
		CurrentOptionIndex = static_cast<int>(vector_AllCurrentOption.size()) - 1;
	}
	else if(CurrentOptionIndex >= vector_AllCurrentOption.size())
	{
		CurrentOptionIndex = 1;
	}


	for (auto& InteractUI : map_Texture_InteractUI)
	{
		if (InteractUI.first == InteractOption::None)
		{
			continue;
		}

		SetTextureInteractOption(InteractUI.first, InteractUI.second);
	}

	CurrentOption = vector_AllCurrentOption[CurrentOptionIndex];

	switch (CurrentOption)
	{
	case InteractOption::None:
	{
		int a = 0;
	}
		break;
	case InteractOption::Quest:
	{
		map_Texture_InteractUI[CurrentOption]->SetTexture("NPCInteraction_Quest_Active.png");
	}
		break;
	case InteractOption::Deal:
	{
		map_Texture_InteractUI[CurrentOption]->SetTexture("NPCInteraction_Deal_Active.png");
	}
		break;
	case InteractOption::Talking:
	{
		map_Texture_InteractUI[CurrentOption]->SetTexture("NPCInteraction_Talking_Active.png");
	}
		break;
	default:
		break;
	}

	return InteractOption::None;


}