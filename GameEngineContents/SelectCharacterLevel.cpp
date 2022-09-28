#include "PreCompile.h"
#include <GameEngineCore/GEngine.h>
#include "AvataManager.h"
#include "TitleBackGroundAndUI.h"
#include "TitleCharacterSlot.h"
#include "SelectCharacterLevel.h"
#include "GamePlayDataBase.h"
#include "GamePlayCharacter.h"
#include "CharacterCreateLevel.h"
#include "MouseCursorComponent.h"

GamePlayDataBase* SelectCharacterLevel::CurrentCharacterSlotData = nullptr;
std::vector<TitleCharacterSlot*> SelectCharacterLevel::CharacterSlot;
std::vector<GamePlayDataBase*> SelectCharacterLevel::DataBase_SelectCharacter;

SelectCharacterLevel::SelectCharacterLevel() 
{
}

SelectCharacterLevel::~SelectCharacterLevel() 
{
}

void SelectCharacterLevel::Start()
{

	if (SelectCharacterLevel::DataBase_SelectCharacter.size() < 7)
	{
		DataBase_SelectCharacter.resize(7);
	}
	CreateActor<MouseCursorComponent>();
	CreateActor<TitleBackGroundAndUI>();

	int Hif = GameEngineWindow::GetScale().hix();
	for (int x = 0; x < 7; x++)
	{
		TitleCharacterSlot* Slot = CreateActor<TitleCharacterSlot>();
		Slot->GetTransform().SetLocalPosition({ static_cast<float>(126 - Hif + ((152 + 18) * x)) ,  static_cast<float>(-168) });
		SelectCharacterLevel::CharacterSlot.push_back(Slot);
	}

}

void SelectCharacterLevel::Update(float _DeltaTime)
{

}

void SelectCharacterLevel::PushCharacterData(GamePlayDataBase* _Data)
{
	for (size_t i = 0; i < 7; i++)
	{
		if (SelectCharacterLevel::DataBase_SelectCharacter[i] != nullptr)
		{
			continue;
		}
		else
		{
			SelectCharacterLevel::DataBase_SelectCharacter[i] = _Data;
			CharacterSlot[i]->CreateAvataData(_Data);
			return;
		}
	}
	MsgBoxAssert("캐릭터 생성 갯수 초과")
}

void SelectCharacterLevel::StartPlayLevel()
{
	GamePlayDataBase::SetAnimationForFrameAnimationDESC(CurrentCharacterSlotData->GetCharacterClass());
	GamePlayDataBase::SetCurrentCharacterData(CurrentCharacterSlotData);
	GamePlayCharacter::SetPlayerCharacter();

	GEngine::ChangeLevel("SeriaRoom");
}