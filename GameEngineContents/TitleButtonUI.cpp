#include "PreCompile.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GEngine.h>
#include "TitleButtonUI.h"
#include "GamePlayEnum.h"

TitleButtonUI::TitleButtonUI() 
	: Texture_Button_GameStart(nullptr)
	, Texture_Button_CreateCharacter(nullptr)
	, Collision_Button_GameStart(nullptr)
	, Collision_Button_CreateCharacter(nullptr)
{
}

TitleButtonUI::~TitleButtonUI() 
{
}

void TitleButtonUI::Start()
{
	Texture_Button_GameStart = CreateComponent<GameEngineTextureRenderer>();
	Texture_Button_CreateCharacter = CreateComponent<GameEngineTextureRenderer>();
	Texture_Button_GameStart->GetTransform().SetLocalScale({203, 55});
	Texture_Button_CreateCharacter->GetTransform().SetLocalScale({ 71, 28 });
	Texture_Button_CreateCharacter->GetTransform().SetLocalPosition({ -230, 0 });


	Collision_Button_GameStart = CreateComponent<GameEngineCollision>();
	Collision_Button_CreateCharacter = CreateComponent<GameEngineCollision>();
	Collision_Button_GameStart->GetTransform().SetLocalScale(Texture_Button_GameStart->GetTransform().GetLocalScale());
	Collision_Button_GameStart->GetTransform().SetLocalPosition(Texture_Button_GameStart->GetTransform().GetLocalPosition());
	Collision_Button_GameStart->ChangeOrder(CollisionOrder::UI_ect);
	Collision_Button_CreateCharacter->GetTransform().SetLocalScale(Texture_Button_CreateCharacter->GetTransform().GetLocalScale());
	Collision_Button_CreateCharacter->GetTransform().SetLocalPosition(Texture_Button_CreateCharacter->GetTransform().GetLocalPosition());
	Collision_Button_CreateCharacter->ChangeOrder(CollisionOrder::UI_ect);

}

void TitleButtonUI::Update(float _DeltaTime)
{

	if (Check_Collision_Button_GameStart())
	{
		return;
	}
	if (Check_Collision_Button_CreateCharacter())
	{
		GEngine::ChangeLevel("CharacterCreate");
		return;
	}

}

bool TitleButtonUI::Check_Collision_Button_GameStart()
{
	//if (Collision_Button_GameStart->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI, CollisionType::CT_AABB2D,
//	[](GameEngineCollision* _This, GameEngineCollision* _Other)
//	{
//		if (_Other->GetNameConstRef() == "Collision_MouseCursor")
//		{
//			return true;
//		}
//		return false;
//	}))
//{
//	Texture_SlotBorder->On();
//}
	return false;
}
bool TitleButtonUI::Check_Collision_Button_CreateCharacter()
{
	if (Collision_Button_CreateCharacter->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_ect, CollisionType::CT_AABB2D,
	[](GameEngineCollision* _This, GameEngineCollision* _Other)
	{
		if (_Other->GetNameConstRef() == "Collision_MouseCursor")
		{
			return true;
		}
		return false;
	}))
	{
		// 소리 키고
		// 텍스쳐 바꾸고
		if (GameEngineInput::GetInst()->IsUp("LMouseCLK"))
		{
			return true;
		}

	}
	return false;
}