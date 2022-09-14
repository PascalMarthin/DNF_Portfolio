#include "PreCompile.h"
#include "StatWindow.h"
#include <GameEngineCore/GameEngineFontRenderer.h>
#include "GamePlayDataBase.h"
#include "CharacterStatManager.h"
#include "AvataManager.h"
#include "GameEnginePlusTextureRenderer.h"

StatWindow::StatWindow() 
	: Texture_Profile(nullptr)
{
}

StatWindow::~StatWindow() 
{
}

void StatWindow::Start()
{
	//SetOrder(static_cast<int>(ActorOrder::Window));
	Texture_Profile = CreateComponent<GameEngineUIRenderer>();
	Texture_Profile->SetTexture("Window_Stat.png");
	Texture_Profile->ScaleToTexture();
	//(Texture_Profile->)

	{
		GameEngineFontRenderer* Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 74.f / 255.f,  162.f / 255.f, 86.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::MAXHP] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 74.f / 255.f,  162.f  / 255.f,  86.f  / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Physical_Armor] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 74.f / 255.f,  162.f / 255.f,  86.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::MAXMP] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 74.f / 255.f,  162.f / 255.f,  86.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Magcial_Armor] = Font;
	}

	{
		GameEngineFontRenderer* Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 74.f / 255.f,  162.f / 255.f,  86.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::STR] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 79.f / 255.f,  79.f / 255.f,  79.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::INT] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 79.f / 255.f,  79.f / 255.f,  79.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Health] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 79.f / 255.f,  79.f / 255.f,  79.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::SPI] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 74.f / 255.f,  162.f / 255.f,  86.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Physical_Damage] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 74.f / 255.f,  162.f / 255.f,  86.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Physical_Critical] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 79.f / 255.f,  79.f / 255.f,  79.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Magcial_Damage] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 79.f / 255.f,  79.f / 255.f,  79.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Magcial_Critical] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetColor({ 79.f / 255.f,  79.f / 255.f,  79.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Independent_Damage] = Font;
	}
}

//Level
//, MaxEXP
//, EXP
//, MoveSpeed
//, AttSpeed
//, CastSpeed
//, MAXHP
//, MAXMP
//, HP
//, MP
//, Physical_Armor
//, Magcial_Armor
//, STR
//, INT
//, Health
//, SPI
//, Physical_Damage
//, Magcial_Damage
//, Independent_Damage
//, Physical_Critical
//, Magcial_Critical
//, Accuracy
//, Evasion
//, Hit_Stun
//, Hit_Recovery
//, JumpPower


void StatWindow::Update(float _DeltaTime)
{

}	
void StatWindow::OnEvent()
{
	//Font_Renderer[0]->Get
	//->SetScreenPostion
	SetFontPos();
	RefreshStat();
	SetClone();
}

void StatWindow::SetClone()
{

	std::vector<GameEnginePlusTextureRenderer*>& AllRenderer = AvataManager::GetInst()->GetAllAvatas();
	Avata_Clone.resize(AllRenderer.size());
	float ZSort = -20.f;
	for (size_t i = 0 ; i < AllRenderer.size(); i++)
	{
		
		if (Avata_Clone[i] == nullptr)
		{
			Avata_Clone[i] = CreateComponent<GameEngineUIRenderer>();
			Avata_Clone[i]->GetTransform().SetLocalPosition({ 0, 200, ZSort });
			ZSort += 0.01f;
		}

		if (AllRenderer[i]->GetFolderTexture() == nullptr)
		{
			Avata_Clone[i]->Off();
			continue;
		}

		Avata_Clone[i]->SetTexture(AllRenderer[i]->GetFolderTexture()->GetTexture(132));
		Avata_Clone[i]->ScaleToTexture();
		Avata_Clone[i]->On();
	}
	
}

void StatWindow::SetFontPos()
{
	float4 StatWindowPos = {GameEngineWindow::GetScale().hx() + GetTransform().GetLocalPosition().x, GameEngineWindow::GetScale().hy() - GetTransform().GetLocalPosition().y};
	Font_Renderer[StatClass::MAXHP]->SetScreenPostion({ StatWindowPos.x - 4.f, StatWindowPos.y - 1.f });
	Font_Renderer[StatClass::Physical_Armor]->SetScreenPostion({ StatWindowPos.x - 4.f, StatWindowPos.y + 17.f });
	Font_Renderer[StatClass::MAXMP]->SetScreenPostion({ StatWindowPos.x + 128.f, StatWindowPos.y - 1.f });
	Font_Renderer[StatClass::Magcial_Armor]->SetScreenPostion({ StatWindowPos.x + 128.f, StatWindowPos.y + 17.f });
	Font_Renderer[StatClass::STR]->SetScreenPostion({ StatWindowPos.x - 4.f, StatWindowPos.y + 36.f });
	Font_Renderer[StatClass::INT]->SetScreenPostion({ StatWindowPos.x + 128.f, StatWindowPos.y + 36.f });
	Font_Renderer[StatClass::Health]->SetScreenPostion({ StatWindowPos.x - 4.f, StatWindowPos.y + 54.f });
	Font_Renderer[StatClass::SPI]->SetScreenPostion({ StatWindowPos.x + 128.f, StatWindowPos.y + 54.f });

	Font_Renderer[StatClass::Physical_Damage]->SetScreenPostion({ StatWindowPos.x - 4.f, StatWindowPos.y + 72.f });
	Font_Renderer[StatClass::Magcial_Damage]->SetScreenPostion({ StatWindowPos.x + 128.f, StatWindowPos.y + 72.f });
	Font_Renderer[StatClass::Physical_Critical]->SetScreenPostion({ StatWindowPos.x - 2.f, StatWindowPos.y + 90.f });
	Font_Renderer[StatClass::Magcial_Critical]->SetScreenPostion({ StatWindowPos.x + 130.f, StatWindowPos.y + 90.f });
	Font_Renderer[StatClass::Independent_Damage]->SetScreenPostion({ StatWindowPos.x - 4.f, StatWindowPos.y + 108.f });
	
}
void StatWindow::RefreshStat()
{
	CharacterAbilityStat* Stat = CharacterStatManager::GetInst()->GetAbilityStat();
	Font_Renderer[StatClass::MAXHP]->SetText(std::to_string(Stat->HP) +"/"+ std::to_string(Stat->MAXHP), "±¼¸²");
	Font_Renderer[StatClass::MAXMP]->SetText(std::to_string(Stat->MP) + "/" + std::to_string(Stat->MAXMP), "±¼¸²");
	Font_Renderer[StatClass::Physical_Armor]->SetText(std::to_string(Stat->Physical_Armor), "±¼¸²");
	Font_Renderer[StatClass::Magcial_Armor]->SetText(std::to_string(Stat->Magcial_Armor), "±¼¸²");

	Font_Renderer[StatClass::STR]->SetText(std::to_string(Stat->STR), "±¼¸²");
	Font_Renderer[StatClass::INT]->SetText(std::to_string(Stat->INT), "±¼¸²");

	Font_Renderer[StatClass::Health]->SetText(std::to_string(Stat->Health), "±¼¸²");
	Font_Renderer[StatClass::SPI]->SetText(std::to_string(Stat->SPI), "±¼¸²");

	Font_Renderer[StatClass::Physical_Damage]->SetText(std::to_string(Stat->Physical_Damage), "±¼¸²");
	Font_Renderer[StatClass::Magcial_Damage]->SetText(std::to_string(Stat->Magcial_Damage), "±¼¸²");
	{
		int CriticalInt = 0;
		if (Stat->Physical_Critical >= 100.f)
		{
			CriticalInt = 100;
		}
		else
		{
			CriticalInt = static_cast<int>(Stat->Physical_Critical);
		}
		std::string Critical = '+' + std::to_string(CriticalInt);
		Critical += '.' + std::to_string(static_cast<int>(Stat->Physical_Critical * 10.f) % 10) + '%';
		Font_Renderer[StatClass::Physical_Critical]->SetText(Critical, "±¼¸²");


		if (Stat->Magcial_Critical >= 100.f)
		{
			CriticalInt = 100;
		}
		else
		{
			CriticalInt = static_cast<int>(Stat->Magcial_Critical);
		}
		Critical = '+' + std::to_string(CriticalInt);
		Critical += '.' + std::to_string(static_cast<int>(Stat->Magcial_Critical * 10.f) % 10) + '%';
		Font_Renderer[StatClass::Magcial_Critical]->SetText(Critical, "±¼¸²");

	}

	Font_Renderer[StatClass::Independent_Damage]->SetText(std::to_string(Stat->Independent_Damage));
	//Font_Renderer[StatClass::MoveSpeed]
	//Font_Renderer[StatClass::AttSpeed			 ]
	//Font_Renderer[StatClass::CastSpeed		 ]
	// 
	//Font_Renderer[StatClass::Accuracy			 ]
	//Font_Renderer[StatClass::Evasion			 ]
	//Font_Renderer[StatClass::Hit_Stun			 ]
	//Font_Renderer[StatClass::Hit_Recovery		 ]
	//Font_Renderer[StatClass::JumpPower		 ]
}

void StatWindow::OffEvent()
{

}




void StatWindow::LevelStartEvent()
{
	OnEvent();
}
void StatWindow::LevelEndEvent()
{
	Off();
}