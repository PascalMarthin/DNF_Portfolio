#include "PreCompile.h"
#include "TitleCreateCharacterThumbnail.h"
#include "GamePlayEnum.h"

TitleCreateCharacterThumbnail::TitleCreateCharacterThumbnail() 
	: Texture_Thumbnails(nullptr)
	, Texture_CursorLocate(nullptr)
	, Texture_CursorSelect(nullptr)
	, Collision_Thumbnails(nullptr)
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

	Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Empty.png");
	Texture_Thumbnails->ScaleToTexture();
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
	if (Collision_Thumbnails->IsCollision(CollisionType::CT_AABB2D, CollisionOrder::UI_ect, CollisionType::CT_AABB2D,
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
			// 선택한 직업을 레벨로 넘겨줘야한다
			Texture_CursorSelect->On();
		}
	}
	else
	{
		Texture_CursorLocate->Off();
	}
}