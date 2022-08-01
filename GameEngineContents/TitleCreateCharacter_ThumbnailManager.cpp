#include "PreCompile.h"
#include "GamePlayEnum.h"
#include "TitleCreateCharacter_ThumbnailManager.h"
#include "TitleCreateCharacterThumbnail.h"

TitleCreateCharacter_ThumbnailManager::TitleCreateCharacter_ThumbnailManager() 
{
}

TitleCreateCharacter_ThumbnailManager::~TitleCreateCharacter_ThumbnailManager() 
{
}

void TitleCreateCharacter_ThumbnailManager::Start()
{
	float4 WindowScale = GameEngineWindow::GetScale();
	for (size_t y = 0; y < 4; y++)
	{
		for (size_t x = 0; x < 4; x++)
		{
			TitleCreateCharacterThumbnail* ThumbnailPtr = GetLevel()->CreateActor<TitleCreateCharacterThumbnail>();
			ThumbnailPtr->GetTransform().SetLocalScale({ MonitorX, MonitorY });
			ThumbnailPtr->GetTransform().SetLocalPosition({ -WindowScale.hx() + 197.f + ((74.f) * MonitorX * x), WindowScale.hy() - 88.f - (74.f * MonitorY * y)});
			Actor_AllThumbnails[static_cast<AllCharacterClass>((y * 4) + x + 1)] = ThumbnailPtr;
		}
	}
	{
		Actor_AllThumbnails[AllCharacterClass::Swordman_M]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Swordman_M_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Swordman_F]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Swordman_F_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Fighter_M]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Fighter_M_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Fighter_F]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Fighter_F_On.png");
		Actor_AllThumbnails[AllCharacterClass::Gunner_M]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunner_M_On.png");
		Actor_AllThumbnails[AllCharacterClass::Gunner_F]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunner_F_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Mage_M]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Mage_M_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Mage_F]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Mage_F_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Priest_M]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Priest_M_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Priest_F]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Priest_F_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Thief]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Thief_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Knight]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Knight_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Demoniclancer]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Demoniclancer_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Gunblader]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunblader_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Darknight]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Darknight_Off.png");
		Actor_AllThumbnails[AllCharacterClass::Creator]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Creator_Off.png");
	}
}
void TitleCreateCharacter_ThumbnailManager::Update(float _DeltaTime)
{

}
