#include "PreCompile.h"
#include "TitleBackGroundAndUI.h"
#include "TitleCharacterSlot.h"
#include <GameEngineBase/GameEngineInput.h>

std::vector<TitleCharacterSlot*> TitleBackGroundAndUI::CharacterSlot;

TitleBackGroundAndUI::TitleBackGroundAndUI() 
	: BackGround(nullptr)
	, GuideLine(nullptr)
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

	// Debug
	{
		GameEngineInput::GetInst()->CreateKey("CreateCharacterButton", 'c');
	}
	//

	if (TitleBackGroundAndUI::CharacterSlot.empty())
	{


		int Hif = WinddowScale.hix();
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 7; x++)
			{
				TitleCharacterSlot* Slot = GetLevel()->CreateActor<TitleCharacterSlot>();
				Slot->GetTransform().SetLocalPosition({ static_cast<float>(126 - Hif + ((152 + 18) * x)) ,  static_cast<float>(-168 - ((4 + 250) * y))});
				TitleBackGroundAndUI::CharacterSlot.push_back(Slot);
			}
		}

	}
}

void TitleBackGroundAndUI::Update(float _DeltaTime)
{
	// Debug
	if (GameEngineInput::GetInst()->IsDown("CreateCharacterButton"))
	{

	}
	// 
}