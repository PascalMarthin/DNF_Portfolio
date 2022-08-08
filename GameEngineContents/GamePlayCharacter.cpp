#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "PlayerInterface.h"
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayCharacter.h"
#include "GamePlayDataBase.h"
#include "AvataManager.h"
#include "InterfaceHUD.h"

GamePlayDataBase* GamePlayCharacter::CurrentCharacterData = nullptr;
std::list<GamePlayDataBase*> GamePlayCharacter::AllCharacterData;

GamePlayCharacter::GamePlayCharacter()
	: Manager_StatManager(nullptr)
	, Manager_AvataManager(nullptr)
	, PlayerUserInterface(nullptr)
	, PlayerFormerClass(CharacterFormerClass::None)

{
}

GamePlayCharacter::~GamePlayCharacter() 
{
	if (!AllCharacterData.empty())
	{
		for (GamePlayDataBase* Character : AllCharacterData)
		{
			delete Character;
		}
		AllCharacterData.clear();
	}
}

void GamePlayCharacter::Start()
{
	GamePlayObject::Start();
	Manager_StatManager = CreateComponent<CharacterStatManager>();
	Manager_AvataManager = GetLevel()->CreateActor<AvataManager>();
	Manager_AvataManager->SetAvataSetup(ObjectType::Character);

	PlayerUserInterface = GetLevel()->CreateActor<PlayerInterface>();

	//AllAvatas.push_back(Avata_Skin = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Belt = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Cap = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Coat = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Face = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Hair_a = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Hair_b = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Neck = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Pants = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Shoes_a = CreateComponent<GameEnginePlusTextureRenderer>());
	//AllAvatas.push_back(Avata_Shoes_b = CreateComponent<GameEnginePlusTextureRenderer>());

	//for (auto& Avata :AllAvatas)
	//{
	//	Avata->GetTransform().SetLocalScale({ 500, 500 });
	//}


	//Avata_Belt->GetTransform().SetLocalPosition({ 0, 0, 4 });
	//Avata_Cap->GetTransform().SetLocalPosition({ 0, 0,  3 });
	//Avata_Coat->GetTransform().SetLocalPosition({ 0, 0, 5 });
	//Avata_Face->GetTransform().SetLocalPosition({ 0, 0, 4 });
	//Avata_Hair_a->GetTransform().SetLocalPosition({ 0, 0, 3 });
	//Avata_Hair_b->GetTransform().SetLocalPosition({ 0, 0, 3 });
	//Avata_Neck->GetTransform().SetLocalPosition({ 0, 0, 7 });
	//Avata_Pants->GetTransform().SetLocalPosition({ 0, 0, 8 });
	//Avata_Shoes_a->GetTransform().SetLocalPosition({ 0, 0, 7 });
	//Avata_Skin->GetTransform().SetLocalPosition({ 0, 0, 10 });


	//CurrentAvataCode[Avata_Belt] =  GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Cap] =   GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Coat] =  GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Face] =  GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Hair_a] = GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Hair_b] = GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Neck] =  GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Pants] = GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Shoes_a] = GamePlayItemCode::Empty;
	//CurrentAvataCode[Avata_Skin] =  GamePlayItemCode::Empty;
}

GamePlayDataBase* GamePlayCharacter::CreateCharacterBase(CharacterFormerClass _Class, const std::string& _NickName)
{
	GamePlayDataBase* NewCharacter = new GamePlayDataBase(_Class , _NickName);
	AllCharacterData.push_back(NewCharacter);
	return NewCharacter;
}


void GamePlayCharacter::SetPlayerCharacter()
{
	if ((CurrentCharacterData = GamePlayDataBase::GetCurrentCharacterData()) == nullptr)
	{
		MsgBoxAssert("데이터가 지정이 안되어 있습니다")
	}



}

void GamePlayCharacter::SetRightDir()
{
	GetTransform().PixLocalPositiveX();
	Manager_StatManager->SetRightSide();
}
void GamePlayCharacter::SetLeftDir()
{
	GetTransform().PixLocalNegativeX();
	Manager_StatManager->SetLeftSide();
}

void GamePlayCharacter::SetFSManager()
{
	if (PlayerFormerClass == CurrentCharacterData->GetFormerClass())
	{
		return;
	}
	else if (PlayerFormerClass != CharacterFormerClass::None)
	{
		Manager_StatManager->Death();
		Manager_StatManager = CreateComponent<CharacterStatManager>();
	}

	switch (CurrentCharacterData->GetCharacterClass())
	{
	case AllCharacterClass::Fighter_F:
		Create_Fighter_F_Default_FSManager();
		break;
	default:
		MsgBoxAssert("아직 만들어지지 않은 클래스입니다")
			break;
	}

	switch (CurrentCharacterData->GetFormerClass())
	{
	case CharacterFormerClass::Striker:

		break;
	default:
		MsgBoxAssert("아직 만들어지지 않은 클래스입니다")
			break;
	}

}

void GamePlayCharacter::OnEvent()
{
	if (CurrentCharacterData == nullptr)
	{
		MsgBoxAssert("데이터가 지정이 안되어 있습니다")
	}
	SetFSManager();

}

void GamePlayCharacter::OffEvent()
{

}