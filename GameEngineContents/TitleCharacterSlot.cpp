#include "PreCompile.h"
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "TitleCharacterSlot.h"
#include "GameEnginePlusTextureRenderer.h"
#include "SelectCharacterLevel.h"
#include "GamePlayDataBase.h"
#include "GamePlayEnum.h"
#include "AvataManager.h"

TitleCharacterSlot::TitleCharacterSlot() 
	: Texture_SlotBorder(nullptr)
	, Texture_MagicCircle(nullptr)
	, Collision_SlotBorder(nullptr)
	, Manager_Avata(nullptr)
	, Data_Character(nullptr)

{
}

TitleCharacterSlot::~TitleCharacterSlot() 
{
}
// ------------------Start------------------
void TitleCharacterSlot::Start()
{
	Texture_SlotBorder = CreateComponent<GameEngineTextureRenderer>();
	Texture_MagicCircle = CreateComponent<GameEngineTextureRenderer>();

	{
		Texture_SlotBorder->SetTexture("CharacterSelect_SelectBorder.png");
		Texture_SlotBorder->ScaleToTexture();
		Texture_SlotBorder->Off();
	}

	{
		Texture_MagicCircle->SetTexture("CharacterSelect_CaractorCircle.png");
		Texture_MagicCircle->ScaleToTexture();
		Texture_MagicCircle->GetTransform().SetLocalPosition({0 , -70 });
	}

	{
		Collision_SlotBorder = CreateComponent<GameEngineCollision>();
		Collision_SlotBorder->GetTransform().SetLocalScale(Texture_SlotBorder->GetTransform().GetLocalScale());
		Collision_SlotBorder->ChangeOrder(CollisionOrder::UI_MainMouse);
	}


}
void TitleCharacterSlot::CreateAvataData(GamePlayDataBase* _Data)
{
	if (Data_Character != nullptr)
	{
		Manager_Avata->Death();
		Manager_Avata = nullptr;
	}
	Data_Character = _Data;
	{
		Manager_Avata = GetLevel()->CreateActor<AvataManager>();
		Manager_Avata->SetParent(this);
		Manager_Avata->GetTransform().SetLocalPosition({ 0, 62.f });
		Manager_Avata->SetAvataSetup(ObjectType::Character);
		Manager_Avata->ReadCharacterDataBase(Data_Character);
		std::vector<GameEnginePlusTextureRenderer*>& AllAvatas = Manager_Avata->GetAllAvatas();
		switch (Data_Character->GetCharacterClass())
		{
		case AllCharacterClass::Fighter_F:
		{
			for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
			{
				Avata->CreateFrameAnimationFolderPlus("Move_Stand", FrameAnimation_DESC("", 113, 116, 0.15f, true));
				Avata->ChangeFrameAnimationPlus("Move_Stand");
			}
		}
		break;
		default:
			break;
		}
	}
	SetCharacterAvataData();
}

void TitleCharacterSlot::SetCharacterAvataData()
{
	Data_Character;
	if (true)
	{
	

	}
}




// ----------Update--------------
void TitleCharacterSlot::Update(float _DeltaTime)
{
	if (Data_Character == nullptr)
	{
		return;
	}
	if (Collision_SlotBorder->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_MainMouse, CollisionType::CT_AABB2D,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Collision_MainCam_MouseCursor")
			{
				return CollisionReturn::Break;
			}
			return CollisionReturn::ContinueCheck;
		}))
	{
		Texture_SlotBorder->On();
		if (GameEngineInput::GetInst()->IsUp("LMouseCLK") && Data_Character != nullptr)
		{
			SelectCharacterLevel::SetCurrentSelectCharacter(Data_Character);
		}
	}
	else
	{
		if (SelectCharacterLevel::GetCurrentCharacterData() != Data_Character)
		{
			Texture_SlotBorder->Off();
		}
		else
		{
			Texture_SlotBorder->On();
		}
	}



}
