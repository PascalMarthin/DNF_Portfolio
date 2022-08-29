#include "PreCompile.h"
#include "TitleCreateCharacterThumbnail.h"
#include "TitleCreateCharacter_ThumbnailManager.h"
#include "CharacterCreateLevel.h"
#include "GamePlayEnum.h"

TitleCreateCharacterThumbnail::TitleCreateCharacterThumbnail() 
	: Texture_Thumbnails(nullptr)
	, Texture_CursorLocate(nullptr)
	, Texture_CursorSelect(nullptr)
	, Collision_Thumbnails(nullptr)
	, Enum_Class(AllCharacterClass::None)
{
}

TitleCreateCharacterThumbnail::~TitleCreateCharacterThumbnail() 
{
}

void TitleCreateCharacterThumbnail::Start()
{
	Texture_Thumbnails = CreateComponent<GameEngineTextureRenderer>();
	Texture_CursorLocate = CreateComponent<GameEngineTextureRenderer>();
	Texture_CursorSelect = CreateComponent<GameEngineTextureRenderer>();
	Collision_Thumbnails = CreateComponent<GameEngineCollision>();

	Texture_Thumbnails->GetTransform().SetLocalScale({74.f, 74.f});
	Texture_CursorSelect->SetTexture("CharacterCreate_Thumbnail_CursorSelect.png");
	Texture_CursorSelect->ScaleToTexture();
	Texture_CursorSelect->Off();
	Texture_CursorLocate->SetTexture("CharacterCreate_Thumbnail_CursorLocate.png");
	Texture_CursorLocate->ScaleToTexture();
	Texture_CursorLocate->Off();
	Collision_Thumbnails->GetTransform().SetLocalScale(Texture_Thumbnails->GetTransform().GetLocalScale());

}
void TitleCreateCharacterThumbnail::Update(float _DeltaTime)
{
	if (Collision_Thumbnails->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_MainMouse, CollisionType::CT_AABB2D,
		[](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			if (_Other->GetNameConstRef() == "Collision_MouseCursor")
			{
				return true;
			}
			return false;
		}))
	{
		Texture_CursorLocate->On();
		if (GameEngineInput::GetInst()->IsUp("LMouseCLK"))
		{
			GetLevel<CharacterCreateLevel>()->ChangeCurrentClass(Enum_Class);
		}
	}
	else
	{
		Texture_CursorLocate->Off();
	}
}

void TitleCreateCharacterThumbnail::SetThumbnailClass()
{

}

void TitleCreateCharacterThumbnail::SetCharacterThumbnail(AllCharacterClass _Class)
{
	Enum_Class = _Class;
	switch (Enum_Class)
	{
	case AllCharacterClass::None:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Empty.png");
		break;
	case AllCharacterClass::Swordman_M:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Swordman_M_Off.png");
		break;
	case AllCharacterClass::Swordman_F:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Swordman_F_Off.png");
		break;
	case AllCharacterClass::Fighter_M:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Fighter_M_Off.png");
		break;
	case AllCharacterClass::Fighter_F:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Fighter_F_On.png");
		break;
	case AllCharacterClass::Gunner_M:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunner_M_On.png");
		break;
	case AllCharacterClass::Gunner_F:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunner_F_Off.png");
		break;
	case AllCharacterClass::Mage_M:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Mage_M_Off.png");
		break;
	case AllCharacterClass::Mage_F:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Mage_F_Off.png");
		break;
	case AllCharacterClass::Priest_M:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Priest_M_Off.png");
		break;
	case AllCharacterClass::Priest_F:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Priest_F_Off.png");
		break;
	case AllCharacterClass::Thief:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Thief_Off.png");
		break;
	case AllCharacterClass::Knight:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Knight_Off.png");
		break;
	case AllCharacterClass::Demoniclancer:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Demoniclancer_Off.png");
		break;
	case AllCharacterClass::Gunblader:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunblader_Off.png");
		break;
	case AllCharacterClass::Darknight:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Darknight_Off.png");
		break;
	case AllCharacterClass::Creator:
		Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Creator_Off.png");
		break;
	case AllCharacterClass::AllCharacterClass_Max:
		break;
	default:
		break;
	}
}