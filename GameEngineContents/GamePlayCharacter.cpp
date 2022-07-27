#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "PlayerInterface.h"
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayCharacter.h"

#include "InterfaceHUD.h"

int GamePlayCharacter::CharacterIndex = 0;
GamePlayCharacter::GamePlayCharacter()
	: StatManager(nullptr)
	, PlayerUserInterface(nullptr)

	, Avata_Belt(nullptr)
	, Avata_Skin(nullptr)
	, Avata_Cap(nullptr)
	, Avata_Coat(nullptr)
	, Avata_Face(nullptr)
	, Avata_Hair_a(nullptr)
	, Avata_Hair_b(nullptr)
	, Avata_Neck(nullptr)
	, Avata_Pants(nullptr)
	, Avata_Shoes(nullptr)

{
	++GamePlayCharacter::CharacterIndex;
}

GamePlayCharacter::~GamePlayCharacter() 
{
	--GamePlayCharacter::CharacterIndex;
}

void GamePlayCharacter::Start()
{
	GamePlayObject::Start();
	StatManager = CreateComponent<CharacterStatManager>();

	AllAvatas.push_back(Avata_Skin = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Belt = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Cap = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Coat = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Face = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Pants = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Shoes = CreateComponent<GameEnginePlusTextureRenderer>());

	for (auto& Avata :AllAvatas)
	{
		Avata->GetTransform().SetLocalScale({ 500, 500 });
	}

	PlayerUserInterface = GetLevel()->CreateActor<PlayerInterface>();

	//Avata_Belt->GetTransform().SetLocalPosition({ 0, 0, 4 });
	//Avata_Cap->GetTransform().SetLocalPosition({ 0, 0,  2 });
	//Avata_Coat->GetTransform().SetLocalPosition({ 0, 0, 3 });
	//Avata_Face->GetTransform().SetLocalPosition({ 0, 0, 4 });
	//Avata_Hair_a->GetTransform().SetLocalPosition({ 0, 0, 5 });
	//Avata_Hair_b->GetTransform().SetLocalPosition({ 0, 0, 6 });
	//Avata_Neck->GetTransform().SetLocalPosition({ 0, 0, 7 });
	//Avata_Pants->GetTransform().SetLocalPosition({ 0, 0, 8 });
	//Avata_Shoes->GetTransform().SetLocalPosition({ 0, 0, 9 });
	//Avata_Skin->GetTransform().SetLocalPosition({ 0, 0, 10 });


	CurrentAvataCode[Avata_Belt] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Cap] =   GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Coat] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Face] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Hair_a] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Hair_b] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Neck] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Pants] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Shoes] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Skin] =  GamePlayItemCode::Empty;



}

void GamePlayCharacter::ChangeAvataAnimation(const std::string& _AnimationName) const
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->ChangeFrameAnimationPlus(_AnimationName);
	}
}
