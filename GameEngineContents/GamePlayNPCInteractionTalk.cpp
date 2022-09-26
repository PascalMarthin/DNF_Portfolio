#include "PreCompile.h"
#include "GamePlayNPCInteractionTalk.h"
#include "GamePlayObjectNPC.h"
#include "GamePlayNPCInteraction.h"

GamePlayNPCInteractionTalk::GamePlayNPCInteractionTalk()
	: Texture_MessageBox(nullptr)
	, Texture_NameBox(nullptr)
	, Texture_UI_Enter(nullptr)
	, Texture_NPCFace(nullptr)
	, Font_Name(nullptr)
	, vector_TalkString(nullptr)
	, StartTalkDelay(0)
{
}

GamePlayNPCInteractionTalk::~GamePlayNPCInteractionTalk() 
{
}

void GamePlayNPCInteractionTalk::Start()
{
	GetTransform().SetLocalPosition({ 0, -GameEngineWindow::GetScale().hy(), -10 });

	Texture_MessageBox = CreateComponent<GameEngineUIRenderer>();
	Texture_MessageBox->SetPivot(PIVOTMODE::BOT);
	Texture_MessageBox->GetTransform().SetLocalPosition({ 0 ,0,-10 });
	Texture_MessageBox->SetTexture("NPC_Dialog_UI_TextureBox.png");
	Texture_MessageBox->ScaleToTexture();


	Texture_NameBox = CreateComponent<GameEngineUIRenderer>();
	Texture_NameBox->SetPivot(PIVOTMODE::BOT);
	Texture_NameBox->GetTransform().SetLocalPosition({ -300 ,0 + 6.f , -10.005f });
	Texture_NameBox->SetTexture("NPC_Dialog_UI_NameBox.png");
	Texture_NameBox->ScaleToTexture();

	Texture_UI_Enter = CreateComponent<GameEngineUIRenderer>();
	Texture_UI_Enter->SetPivot(PIVOTMODE::BOT);
	Texture_UI_Enter->GetTransform().SetLocalPosition({ 345 ,0,-11 });
	Texture_UI_Enter->SetTexture("NPC_Dialog_UI_Enter.png");
	Texture_UI_Enter->ScaleToTexture();

	Texture_NPCFace = CreateComponent<GameEngineUIRenderer>();
	Texture_NPCFace->SetPivot(PIVOTMODE::BOT);
	Texture_NPCFace->GetTransform().SetLocalPosition({ -365 ,0,-10.004f });
	Texture_NPCFace->SetTexture("NPC_Dialog_Face_Ajelia.png");
	Texture_NPCFace->ScaleToTexture();

	Font_Name = CreateComponent<GameEngineUIFontRenderer>();
	Font_Name->GetTransform().SetLocalPosition({ -GameEngineWindow::GetScale().hx() + 338 , 23.f, -10.006f });
	//Font_Name->SetText("¾ÆÁ©¸®¾Æ ·ÎÆ®", "±¼¸²");
	Font_Name->SetColor({ 1.0f, 1.0f, 1.0f, 1.f });
	Font_Name->SetRenderingOrder(10000);
	Font_Name->SetSize(14);
	Font_Name->SetPositionMode(FontPositionMode::WORLD);
	Font_Name->SetTopAndBotSort(TopAndBotSort::VCENTER);
	Font_Name->SetLeftAndRightSort(LeftAndRightSort::CENTER);

	Off();
}

InteractOption GamePlayNPCInteractionTalk::CheckInput()
{
	if (StartTalkDelay <= 0)
	{
		if (GameEngineInput::GetInst()->IsDown("Enter"))
		{
			TalkingIndex += 1;
			if (TalkingIndex >= vector_TalkString->size())
			{
				vector_TalkString = nullptr;
				Off();
				return InteractOption::Exit;
			}
			else
			{
				ShowStringBr((*vector_TalkString)[TalkingIndex]);
				return InteractOption::None;
			}
		}
	}
	return InteractOption::None;
}

void GamePlayNPCInteractionTalk::Update(float _DeltaTime)
{
	if (StartTalkDelay > 0)
	{
		StartTalkDelay -= _DeltaTime * 8.f;
		if (StartTalkDelay <= 0)
		{
			Texture_MessageBox->GetPixelData().MulColor.a = 1.f;
			Texture_NameBox->GetPixelData().MulColor.a = 1.f;
			Texture_UI_Enter->GetPixelData().MulColor.a = 1.f;
			Texture_NPCFace->GetPixelData().MulColor.a = 1.f;
			GetTransform().SetLocalPosition({ 0, -GameEngineWindow::GetScale().hy(), -10 });
		}
		else
		{
			Texture_MessageBox->GetPixelData().MulColor.a = 1.f - StartTalkDelay;
			Texture_NameBox->GetPixelData().MulColor.a = 1.f - StartTalkDelay;
			Texture_UI_Enter->GetPixelData().MulColor.a = 1.f - StartTalkDelay;
			Texture_NPCFace->GetPixelData().MulColor.a = 1.f - StartTalkDelay;
			GetTransform().SetLocalPosition(float4::LerpLimit({ -GameEngineWindow::GetScale().hx() + 500.f, -GameEngineWindow::GetScale().hy(), -10 }, { 0, -GameEngineWindow::GetScale().hy(), -10 }, 1.f - StartTalkDelay));
		}
	}
}

void GamePlayNPCInteractionTalk::SetNPCInteraction_Talk(std::vector<std::string>* _vector, GamePlayObjectNPC* _NPC)
{
	Texture_NPCFace->SetTexture(_NPC->GetFaceImage());
	Font_Name->SetText(_NPC->GetName(), "±¼¸²");
	vector_TalkString = _vector;
	GetTransform().SetLocalPosition({ -GameEngineWindow::GetScale().hx() + 500.f, -GameEngineWindow::GetScale().hy(), -10});

	Texture_MessageBox->GetPixelData().MulColor.a = 0;
	Texture_NameBox->GetPixelData().MulColor.a = 0;
	Texture_UI_Enter->GetPixelData().MulColor.a = 0;
	Texture_NPCFace->GetPixelData().MulColor.a = 0;
	//Font_Name->GetPixelData().MulColor.a = 0;
	TalkingIndex = 0;
	ShowStringBr((*vector_TalkString)[TalkingIndex]);


	StartTalkDelay = 1;
	On();
}

void GamePlayNPCInteractionTalk::ShowStringBr(const std::string& _String)
{
	for (auto* Iter : vector_Font_Talk)
	{
		Iter->Death();
	}
	vector_Font_Talk.clear();

	int StartCount = 0;
	int StringAfter = 50;

	//std::string String = _String.substr(0, 20);
	float Hight = 85;
	do 
	{
		GameEngineUIFontRenderer* Renderer = CreateComponent<GameEngineUIFontRenderer>();
		Renderer->GetTransform().SetLocalPosition({ -180 , Hight ,-10.006f });
		Renderer->SetPositionMode(FontPositionMode::WORLD);
		Renderer->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
		Renderer->SetRenderingOrder(10000);
		Renderer->SetSize(18);
		Renderer->SetTopAndBotSort(TopAndBotSort::BOTTOM);
		Renderer->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		if (StartCount > _String.length())
		{
			Renderer->SetText(_String.substr(StartCount - 50, -1), "±¼¸²");
		}
		else
		{
			Renderer->SetText(_String.substr(StartCount, StringAfter), "±¼¸²");
			StartCount += StringAfter;
			
		}
		Hight -= 20.f;
		vector_Font_Talk.push_back(Renderer);
	} while (StartCount < _String.length());


}




void GamePlayNPCInteractionTalk::LevelStartEvent()
{
	TalkingIndex = 0;
}
void GamePlayNPCInteractionTalk::LevelEndEvent() 
{

}