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
			Actor_AllThumbnails.push_back(ThumbnailPtr);
		}
	}
	{
		Actor_AllThumbnails[0]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Swordman_M_Off.png");
		Actor_AllThumbnails[1]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Swordman_F_Off.png");
		Actor_AllThumbnails[2]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Fighter_M_Off.png");
		Actor_AllThumbnails[3]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Fighter_F_On.png");
		Actor_AllThumbnails[4]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunner_M_On.png");
		Actor_AllThumbnails[5]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunner_F_Off.png");
		Actor_AllThumbnails[6]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Mage_M_Off.png");
		Actor_AllThumbnails[7]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Mage_F_Off.png");
		Actor_AllThumbnails[8]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Priest_M_Off.png");
		Actor_AllThumbnails[9]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Priest_F_Off.png");
		Actor_AllThumbnails[10]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Thief_Off.png");
		Actor_AllThumbnails[11]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Knight_Off.png");
		Actor_AllThumbnails[12]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Demoniclancer_Off.png");
		Actor_AllThumbnails[13]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Gunblader_Off.png");
		Actor_AllThumbnails[14]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Darknight_Off.png");
		Actor_AllThumbnails[15]->Texture_Thumbnails->SetTexture("CharacterCreate_Thumbnail_Creator_Off.png");
	}
}
void TitleCreateCharacter_ThumbnailManager::Update(float _DeltaTime)
{

}
