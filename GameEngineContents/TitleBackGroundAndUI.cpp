#include "PreCompile.h"
#include "TitleBackGroundAndUI.h"
#include "TitleCharacterSlot.h"
#include "TitleButtonUI.h"
#include <GameEngineBase/GameEngineInput.h>

TitleBackGroundAndUI::TitleBackGroundAndUI() 
	: BackGround(nullptr)
	, GuideLine(nullptr)
	, Actor_ButtonUI(nullptr)
{
}

TitleBackGroundAndUI::~TitleBackGroundAndUI() 
{
}

void TitleBackGroundAndUI::Start()
{
	float4 WinddowScale = GameEngineWindow::GetInst()->GetScale();
	{
		BackGround = CreateComponent<GameEngineTextureRenderer>();
		BackGround->SetTexture("CharacterSelect_BackGround.png");
		BackGround->GetTransform().SetLocalScale(WinddowScale);
		BackGround->GetTransform().SetLocalPosition({ 0, 0, 100 });
	}
	{
		GuideLine = CreateComponent<GameEngineTextureRenderer>();
		GuideLine->SetTexture("CharacterSelect_GuideLine.png");
		GuideLine->GetTransform().SetLocalScale({ WinddowScale.x , 580 });
		GuideLine->GetTransform().SetLocalPosition({ 0, -325, 98 });
	}
	{
		Actor_ButtonUI = GetLevel()->CreateActor<TitleButtonUI>();
	}


}

void TitleBackGroundAndUI::Update(float _DeltaTime)
{
}