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
			ThumbnailPtr->SetParent(this);
			ThumbnailPtr->GetTransform().SetLocalScale({ MonitorX, MonitorY });
			ThumbnailPtr->GetTransform().SetLocalPosition({ -WindowScale.hx() + 197.f + ((74.f) * MonitorX * x), WindowScale.hy() - 88.f - (74.f * MonitorY * y)});
			Actor_AllThumbnails.push_back(ThumbnailPtr);
		}
	}
	Actor_AllThumbnails[0]->SetCharacterThumbnail(AllCharacterClass::Swordman_M);
	Actor_AllThumbnails[1]->SetCharacterThumbnail(AllCharacterClass::Swordman_F);
	Actor_AllThumbnails[2]->SetCharacterThumbnail(AllCharacterClass::Fighter_M);
	Actor_AllThumbnails[3]->SetCharacterThumbnail(AllCharacterClass::Fighter_F);
	Actor_AllThumbnails[4]->SetCharacterThumbnail(AllCharacterClass::Gunner_M);
	Actor_AllThumbnails[5]->SetCharacterThumbnail(AllCharacterClass::Gunner_F);
	Actor_AllThumbnails[6]->SetCharacterThumbnail(AllCharacterClass::Mage_M);
	Actor_AllThumbnails[7]->SetCharacterThumbnail(AllCharacterClass::Mage_F);
	Actor_AllThumbnails[8]->SetCharacterThumbnail(AllCharacterClass::Priest_M);
	Actor_AllThumbnails[9]->SetCharacterThumbnail(AllCharacterClass::Priest_F);
	Actor_AllThumbnails[10]->SetCharacterThumbnail(AllCharacterClass::Thief);
	Actor_AllThumbnails[11]->SetCharacterThumbnail(AllCharacterClass::Knight);
	Actor_AllThumbnails[12]->SetCharacterThumbnail(AllCharacterClass::Demoniclancer);
	Actor_AllThumbnails[13]->SetCharacterThumbnail(AllCharacterClass::Gunblader);
	Actor_AllThumbnails[14]->SetCharacterThumbnail(AllCharacterClass::Darknight);
	Actor_AllThumbnails[15]->SetCharacterThumbnail(AllCharacterClass::Creator);

}
void TitleCreateCharacter_ThumbnailManager::Update(float _DeltaTime)
{

}

void TitleCreateCharacter_ThumbnailManager::SetSelectCharacter(AllCharacterClass _Class)
{
	for (auto& Actor : Actor_AllThumbnails)
	{
		if (Actor->GetAllCharacterClass() == _Class)
		{
			Actor->SetCursorSelectOn();
		}
		else
		{
			Actor->SetCursorSelectOff();
		}
	}

}