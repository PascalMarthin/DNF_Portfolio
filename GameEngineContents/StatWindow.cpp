#include "PreCompile.h"
#include "StatWindow.h"
#include <GameEngineCore/GameEngineFontRenderer.h>
#include "GamePlayDataBase.h"

StatWindow::StatWindow() 
	: Texture_Profile(nullptr)
{
}

StatWindow::~StatWindow() 
{
}

void StatWindow::Start()
{
	Texture_Profile = CreateComponent<GameEngineUIRenderer>();
	Texture_Profile->SetTexture("Window_Stat.png");
	Texture_Profile->ScaleToTexture();
	//(Texture_Profile->)

	{
		GameEngineFontRenderer* Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetText("500/5000", "±¼¸²");
		Font->SetColor({ 74.f / 255.f,  162.f / 255.f, 86.f / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::MAXHP] = Font;

		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetText("1000/100", "±¼¸²");
		Font->SetColor({ 74.f / 255.f,  162.f  / 255.f,  86.f  / 255.f, 1.0 });
		Font->SetSize(11.f);
		Font->SetLeftAndRightSort(LeftAndRightSort::RIGHT);
		Font->SetTopAndBotSort(TopAndBotSort::VCENTER);

		Font->ChangeCamera(CAMERAORDER::UICAMERA);
		Font_Renderer[StatClass::Physical_Armor] = Font;
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
}

void StatWindow::SetFontPos()
{
	float4 StatWindowPos = {GameEngineWindow::GetScale().hx() + GetTransform().GetLocalPosition().x, GameEngineWindow::GetScale().hy() - GetTransform().GetLocalPosition().y};
	Font_Renderer[StatClass::MAXHP]->SetScreenPostion({ StatWindowPos.x - 6.f, StatWindowPos.y - 1.f });
	Font_Renderer[StatClass::Physical_Armor]->SetScreenPostion({ StatWindowPos.x - 6.f, StatWindowPos.y + 17.f });
}
void StatWindow::OffEvent()
{

}




void StatWindow::LevelStartEvent()
{
	On();
}
void StatWindow::LevelEndEvent()
{
	Off();
}