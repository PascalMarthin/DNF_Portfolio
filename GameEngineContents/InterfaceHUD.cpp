#include "PreCompile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineCore/GameEngineComponent.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "GamePlayEnum.h"
#include "InterfaceHUD.h"
#include "CharacterStatManager.h"

InterfaceHUD::InterfaceHUD() 
	: HUDBase(nullptr)
	, HPBar(nullptr)
	, MPBar(nullptr)
	, HPBar_Hit(nullptr)
	, EXPBar(nullptr)
	, SkillPage(nullptr)
	, HUDBasePivot({0, 0, ZSortOrder::HUD_Base })
	, HPBarPivot({ -146 , -5 , -10 })
	, MPBarPivot({  146 , -6 , 8 })
	, SkillInterfacePivot({-88 , -24  })
	, EXPBarPivot({0, -33  })
	, CurrentHP(0)
	, CurrentBeHindHP(0)
	, HPBar_Behind(nullptr)
	, HPBar_Outline(nullptr)
	, CurrentHitHP(0)
	, MPBar_Outline(nullptr)
	, MPBar_Behind(nullptr)
	, MPBar_Hit(nullptr)
	, CurrentMP(0)
	, CurrentBeHindMP(0)
	, CurrentHitMP(0)
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
		HPBar_Behind   = CreateComponent<GameEngineUIRenderer>();
		HPBar_Hit      = CreateComponent<GameEngineUIRenderer>();
		HPBar		   = CreateComponent<GameEngineUIRenderer>();
		MPBar          = CreateComponent<GameEngineUIRenderer>();
		MPBar_Behind   = CreateComponent<GameEngineUIRenderer>();
		MPBar_Hit	   = CreateComponent<GameEngineUIRenderer>();
		HPBar_Outline  = CreateComponent<GameEngineUIRenderer>();
		MPBar_Outline  = CreateComponent<GameEngineUIRenderer>();
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


				Skillicon = CreateComponent<GameEngineUIRenderer>();
				Skillicon->SetTexture("HUD_SkillIcon.png");
				Skillicon->ScaleToTexture();
				Skillicon->GetTransform().SetLocalPosition(SkillInterfacePivot);
				Skillicon->GetTransform().SetLocalMove({ 32.f * j , 32.f * i });
				SkillInterIcon.push_back(Skillicon);


				// 컴포넌트화 예정
			}
		}

		{
			SkillInterIcon[7]->SetTexture("SkillHUD_Shoulder.png");
			SkillInterIcon[8]->SetTexture("SkillHUD_RN.png");
			SkillInterIcon[9]->SetTexture("SkillHUD_LD.png");
			SkillInterIcon[10]->SetTexture("SkillHUD_Strongest.png");
			SkillInterIcon[11]->SetTexture("SkillHUD_Am.png");
			SkillInterIcon[12]->SetTexture("SkillHUD_Kaiken.png");
			SkillInterIcon[0]->SetTexture("SkillHUD_1punch.png");
			SkillInterIcon[1]->SetTexture("SkillHUD_Upper.png");
			SkillInterIcon[2]->SetTexture("SkillHUD_Lowkick.png");
			SkillInterIcon[3]->SetTexture("SkillHUD_Carsh.png");
			SkillInterIcon[4]->SetTexture("SkillHUD_Kick.png");
			SkillInterIcon[5]->SetTexture("SkillHUD_Boong.png");

			for (size_t i = 0; i < SkillInterIcon.size(); i++)
			{
				SkillInterIcon[i]->ScaleToTexture();
			}
		}

		HUDBase->SetTexture("HUD_HUDBase.png");
		HUDBase->ScaleToTexture();
		HUDBase->GetTransform().SetLocalPosition(HUDBasePivot);


		HPBar_Outline->SetTexture("HUD_HPOutline.png");
		HPBar_Outline->ScaleToTexture();
		HPBar_Outline->GetTransform().SetLocalPosition(HPBarPivot);

		MPBar_Outline->SetTexture("HUD_MPOutline.png");
		MPBar_Outline->ScaleToTexture();
		MPBar_Outline->GetTransform().SetLocalPosition(MPBarPivot);

		HPBar->SetTexture("HUD_HPBar.png");
		HPBar->ScaleToTexture();
		HPBar->GetTransform().SetLocalPosition(HPBarPivot);
	
		
		HPBar_Behind->SetTexture("HUD_HPBar.png");
		HPBar_Behind->ScaleToTexture();
		HPBar_Behind->GetTransform().SetLocalPosition(HPBarPivot);
		HPBar_Behind->GetTransform().SetLocalMove({ 0,0, 0.002f });
		HPBar_Behind->GetPixelData().PlusColor = {-0.2f, -0.2f, -0.2f, 0};

		HPBar_Hit->SetTexture("HUD_HPBarHit.png");
		HPBar_Hit->ScaleToTexture();
		HPBar_Hit->GetTransform().SetLocalPosition(HPBarPivot);
		HPBar_Hit->GetTransform().SetLocalMove({ 0,0, 0.002f });	


		MPBar->SetTexture("HUD_MPBar.png");
		MPBar->ScaleToTexture();
		MPBar->GetTransform().SetLocalPosition(MPBarPivot);

		
		MPBar_Behind->SetTexture("HUD_MPBar.png");
		MPBar_Behind->ScaleToTexture();
		MPBar_Behind->GetTransform().SetLocalPosition(MPBarPivot);
		MPBar_Behind->GetTransform().SetLocalMove({ 0,0, 0.002f });
		MPBar_Behind->GetPixelData().PlusColor = { -0.2f, -0.2f, -0.2f, 0 };


		MPBar_Hit->SetTexture("HUD_HPBarHit.png");
		MPBar_Hit->ScaleToTexture();
		MPBar_Hit->GetTransform().SetLocalPosition(MPBarPivot);
		MPBar_Hit->GetTransform().SetLocalMove({ 0,0, 0.002f });
		

		EXPBar->SetTexture("HUD_ExpBar.png");
		EXPBar->ScaleToTexture();
		EXPBar->GetTransform().SetLocalPosition(EXPBarPivot);

	/*	SkillInterface->SetTexture("HUD_SkillInterface.png");
		SkillInterface->ScaleToTexture(); 
		SkillInterface->GetTransform().SetLocalPosition(SkillInterfacePivot);*/

		//HPBar_Hit->Off();
	}


}

void InterfaceHUD::Update(float _DeltaTime)
{

	if (CurrentHP == 0 && !CharacterStatManager::GetInst()->IsDeath())
	{
		CurrentHP = CharacterStatManager::GetInst()->GetAbilityStat()->GetHP();
		CurrentHitHP = CurrentHP;
		CurrentBeHindHP = CurrentHP;

		CurrentMP = CharacterStatManager::GetInst()->GetAbilityStat()->GetMP();
		CurrentHitMP = CurrentMP;
		CurrentBeHindMP = CurrentMP;

	}

	HPUpdate(_DeltaTime);
	MPUpdate(_DeltaTime);
}

void InterfaceHUD::HPUpdate(float _Time)
{
	int HP = CharacterStatManager::GetInst()->GetAbilityStat()->GetHP();
	int MAXHP = CharacterStatManager::GetInst()->GetAbilityStat()->GetMAXHP();
	if (CurrentHP < HP) // 체력 회복
	{
		CurrentHP += MAXHP / 500;
		CurrentBeHindHP = CurrentHP;
		CurrentHitHP = CurrentHP;
		if (CurrentHP > HP)
		{
			CurrentHP = HP;
		}

	}

	if (CurrentBeHindHP > HP) // 피격
	{
		if (CurrentHP > HP)
		{
			CurrentHitHP = CurrentHP;
			CurrentBeHindHP = CurrentHP;
			HPBar_Hit->GetPixelData().MulColor.a = 1.f;
			CurrentHP = HP;
		}

		if (HPBar_Hit->GetPixelData().MulColor.a > 0)
		{
			HPBar_Hit->GetPixelData().MulColor.a -= _Time * 5.f;
			if (HPBar_Hit->GetPixelData().MulColor.a < 0)
			{
				HPBar_Hit->GetPixelData().MulColor.a = 0;
				CurrentHitHP = CurrentHP;
			}
		}
		else
		{
			CurrentBeHindHP -= MAXHP / 1000;
		}
	}

	HPBar->GetPixelData().Slice.y = 1.f - (static_cast<float>(CurrentHP) / static_cast<float>(MAXHP));
	HPBar_Hit->GetPixelData().Slice.y = 1.f - (static_cast<float>(CurrentHitHP) / static_cast<float>(MAXHP));
	HPBar_Behind->GetPixelData().Slice.y = 1.f - (static_cast<float>(CurrentBeHindHP) / static_cast<float>(MAXHP));

}
void InterfaceHUD::MPUpdate(float _Time)
{


	int MP = CharacterStatManager::GetInst()->GetAbilityStat()->GetMP();
	int MAXMP = CharacterStatManager::GetInst()->GetAbilityStat()->GetMAXMP();
	if (CurrentMP < MP) // 체력 회복
	{
		CurrentMP += 3;
		CurrentBeHindMP = CurrentMP;
		CurrentHitMP = CurrentMP;
		if (CurrentMP > MP)
		{
			CurrentMP = MP;
		}

	}

	if (CurrentBeHindMP > MP) // 피격
	{
		if (CurrentMP > MP)
		{
			CurrentHitMP = CurrentMP;
			CurrentBeHindMP = CurrentMP;
			MPBar_Hit->GetPixelData().MulColor.a = 1.f;
			CurrentMP = MP;
		}

		if (MPBar_Hit->GetPixelData().MulColor.a > 0)
		{
			MPBar_Hit->GetPixelData().MulColor.a -= _Time * 5.f;
			if (MPBar_Hit->GetPixelData().MulColor.a < 0)
			{
				MPBar_Hit->GetPixelData().MulColor.a = 0;
				CurrentHitMP = CurrentMP;
			}
		}
		else
		{
			CurrentBeHindMP -= 2;
		}
	}

	MPBar->GetPixelData().Slice.y = 1.f - (static_cast<float>(CurrentMP) / static_cast<float>(MAXMP));
	MPBar_Hit->GetPixelData().Slice.y = 1.f - (static_cast<float>(CurrentHitMP) / static_cast<float>(MAXMP));
	MPBar_Behind->GetPixelData().Slice.y = 1.f - (static_cast<float>(CurrentBeHindMP) / static_cast<float>(MAXMP));
}

void InterfaceHUD::LevelStartEvent()
{
	if (CharacterStatManager::GetInst() != nullptr)
	{
		CurrentHP = CharacterStatManager::GetInst()->GetAbilityStat()->GetHP();
	}

	HPBar_Hit->GetPixelData().MulColor.a = 0;
	MPBar_Hit->GetPixelData().MulColor.a = 0;
}

void InterfaceHUD::LevelEndEvent()
{
	CurrentHP = 0;
	CurrentBeHindHP = 0;
	CurrentHitHP = 0;
}