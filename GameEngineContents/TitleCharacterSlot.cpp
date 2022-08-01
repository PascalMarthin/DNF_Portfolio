#include "PreCompile.h"
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "TitleCharacterSlot.h"
#include "SelectCharacterLevel.h"
#include "GamePlayEnum.h"

TitleCharacterSlot::TitleCharacterSlot() 
	: Texture_SlotBorder(nullptr)
	, Texture_MagicCircle(nullptr)
	, Collision_SlotBorder(nullptr)

{
}

TitleCharacterSlot::~TitleCharacterSlot() 
{
}

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
		Collision_SlotBorder->ChangeOrder(CollisionOrder::UI_ect);
	}

}

void TitleCharacterSlot::Update(float _DeltaTime)
{
	if (Collision_SlotBorder->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_ect, CollisionType::CT_AABB2D,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Collision_MouseCursor")
			{
				return true;
			}
			return false;
		}))
	{
		Texture_SlotBorder->On();
	}
	else
	{
		Texture_SlotBorder->Off();
	}
	
}
