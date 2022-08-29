#include "PreCompile.h"
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ButtonComponent.h"
#include "GamePlayEnum.h"

ButtonComponent::ButtonComponent() 
	: Texture_CreateCharacterButton(nullptr)
	, Collision_CreateCharacterButton(nullptr)
	, Enum_ButtonSize(ButtonSize::None)
	, Enum_ButtonCondition(ButtonCondition::None)
{
}

ButtonComponent::~ButtonComponent() 
{
}

void ButtonComponent::Start()
{
	GetTransform().SetLocalScale({ MonitorX, MonitorY });
	Texture_CreateCharacterButton = CreateComponent<GameEngineTextureRenderer>();
	Collision_CreateCharacterButton = CreateComponent<GameEngineCollision>();
	Collision_CreateCharacterButton->ChangeOrder(CollisionOrder::UI_MainMouse);
}

void ButtonComponent::Update(float _DeltaTime)
{
	// 디버그용
	if (Enum_ButtonCondition == ButtonCondition::None)
	{
		MsgBoxAssert("버튼 엑터를 생성하고 설정하지 않았습니다");
	}
	// 디버그용 
}

void ButtonComponent::SetOption(ButtonSize _Button , const float4& _Size)
{
	if (Enum_ButtonSize != ButtonSize::None )
	{
		MsgBoxAssert("이미 세팅이 완료된 버튼입니다")
	}
	switch (_Button)
	{
	case ButtonSize::Short:
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_Short_Off.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_Short_On.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_Short_Push.png"));
		break;
	case ButtonSize::Long:
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_Long_Off.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_Long_On.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_Long_Push.png"));
		break;
	case ButtonSize::LongLong:
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_LongLong_Off.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_LongLong_On.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_LongLong_Push.png"));
		break;
	case ButtonSize::VeryLongLong:
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_VeryLongLong_Off.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_VeryLongLong_On.png"));
		Texture_AllButton.push_back(GameEngineTexture::Find("Ninepatch_BlueButton_VeryLongLong_Push.png"));
		break;
	default:
		break;
	}

	Texture_CreateCharacterButton->SetTexture(Texture_AllButton[0]);
	if (_Size.CompareInt2D(float4::ZERO))
	{
		Texture_CreateCharacterButton->ScaleToTexture();
	}
	else
	{
		Texture_CreateCharacterButton->GetTransform().SetLocalScale(_Size);

	}
	Collision_CreateCharacterButton->GetTransform().SetLocalScale(Texture_CreateCharacterButton->GetTransform().GetLocalScale());

	Enum_ButtonSize = _Button;
	Enum_ButtonCondition = ButtonCondition::Off;
}

void ButtonComponent::SetOption(const std::vector<GameEngineTexture*>& _VectorTexture, const float4& _Size)
{
	if (Enum_ButtonSize != ButtonSize::None )
	{
		MsgBoxAssert("이미 세팅이 완료된 버튼입니다")
	}

	Texture_AllButton = _VectorTexture;
	Texture_CreateCharacterButton->SetTexture(Texture_AllButton[0]);
	if (_Size.CompareInt2D(float4::ZERO))
	{
		Texture_CreateCharacterButton->ScaleToTexture();
	}
	else
	{
		Texture_CreateCharacterButton->GetTransform().SetLocalScale(_Size);
	}
	Collision_CreateCharacterButton->GetTransform().SetLocalScale(Texture_CreateCharacterButton->GetTransform().GetLocalScale());

	Enum_ButtonSize = ButtonSize::CustomButton;
	Enum_ButtonCondition = ButtonCondition::Off;
}

bool ButtonComponent::UpdateButtonPush()
{
	if (Collision_CreateCharacterButton->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_MainMouse, CollisionType::CT_AABB2D,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Collision_MainCam_MouseCursor")
			{
				return true;
			}
			return false;
		}))
	{
		if (Enum_ButtonCondition == ButtonCondition::Off)
		{
			Texture_CreateCharacterButton->SetTexture(Texture_AllButton[1]);
			Enum_ButtonCondition = ButtonCondition::On;
		}

		if (GameEngineInput::GetInst()->IsDown("LMouseCLK"))
		{
			Texture_CreateCharacterButton->SetTexture(Texture_AllButton[2]);
			Enum_ButtonCondition = ButtonCondition::Push;
		}

		if (GameEngineInput::GetInst()->IsUp("LMouseCLK") && Enum_ButtonCondition == ButtonCondition::Push)
		{
			Texture_CreateCharacterButton->SetTexture(Texture_AllButton[1]);
			Enum_ButtonCondition = ButtonCondition::On;
			return true;
		}
	}
	else
	{
		if (Enum_ButtonCondition == ButtonCondition::On || GameEngineInput::GetInst()->IsUp("LMouseCLK"))
		{
			Texture_CreateCharacterButton->SetTexture(Texture_AllButton[0]);
			Enum_ButtonCondition = ButtonCondition::Off;
		}
	}
	return false;
}
// 업데이트에서 Settexture를 하는 것이 더 깔끔할것같지만 이 업데이트를 실수로 누락했을경우 빠르게 확인이 가능하기때문에 이렇게 ㅁ나듬