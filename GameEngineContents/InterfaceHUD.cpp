#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlayEnum.h"
#include "InterfaceHUD.h"

InterfaceHUD::InterfaceHUD() 
	: HUDBase(nullptr)
	, HPBar(nullptr)
	, MPBar(nullptr)
	, HPBar_Hit(nullptr)
	, EXPBar(nullptr)
	, SkillPage(nullptr)
	, HUDBasePivot({0, 0, ZSortOrder::HUD_Base })
	, HPBarPivot({ -146 , -6 , 8 })
	, MPBarPivot({  146 , -6 , 8 })
	, SkillInterfacePivot({-88 , -24  })
	, EXPBarPivot({0, -33  })

{
}

InterfaceHUD::~InterfaceHUD() 
{
}

void InterfaceHUD::Start()
{
	GetTransform().SetLocalScale({ MonitorX , MonitorY });
	{
		GetTransform().SetLocalPosition({ 0, (-720 + (84 * MonitorY )) / 2 });
		HUDBase        = CreateComponent<GameEngineUIRenderer>();
		HPBar		   = CreateComponent<GameEngineUIRenderer>();
		MPBar          = CreateComponent<GameEngineUIRenderer>();
		HPBar_Hit      = CreateComponent<GameEngineUIRenderer>();
		EXPBar		   = CreateComponent<GameEngineUIRenderer>();

		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < 7; j++)
			{
				GameEngineUIRenderer* Skillicon = CreateComponent<GameEngineUIRenderer>();
				Skillicon->SetTexture("HUD_SkillIcon.png");
				Skillicon->ScaleToTexture();
				Skillicon->GetTransform().SetLocalPosition(SkillInterfacePivot);
				Skillicon->GetTransform().SetLocalMove({ 32.f * j , 32.f * i  });
				SkillInterface.push_back(Skillicon);
				// 컴포넌트화 예정
			}
		}

		HUDBase->SetTexture("HUD_HUDBase.png");
		HUDBase->ScaleToTexture();
		HUDBase->GetTransform().SetLocalPosition(HUDBasePivot);

		HPBar->SetTexture("HUD_HPBar.png");
		HPBar->ScaleToTexture();
		HPBar->GetTransform().SetLocalPosition(HPBarPivot);

		HPBar_Hit->SetTexture("HUD_HPBarHit.png");
		HPBar_Hit->ScaleToTexture();
		HPBar_Hit->GetTransform().SetLocalPosition(HPBarPivot);

		MPBar->SetTexture("HUD_MPBar.png");
		MPBar->ScaleToTexture();
		MPBar->GetTransform().SetLocalPosition(MPBarPivot);

		EXPBar->SetTexture("HUD_ExpBar.png");
		EXPBar->ScaleToTexture();
		EXPBar->GetTransform().SetLocalPosition(EXPBarPivot);

	/*	SkillInterface->SetTexture("HUD_SkillInterface.png");
		SkillInterface->ScaleToTexture(); 
		SkillInterface->GetTransform().SetLocalPosition(SkillInterfacePivot);*/

		HPBar_Hit->Off();
	}


}

void InterfaceHUD::Update(float _DeltaTime)
{

}