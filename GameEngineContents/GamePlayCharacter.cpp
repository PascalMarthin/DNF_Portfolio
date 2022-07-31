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
	, Avata_Shoes_a(nullptr)
	, Avata_Shoes_b(nullptr)

	, Input_SkillSlot_01(nullptr)
	, Input_SkillSlot_02(nullptr)
	, Input_SkillSlot_03(nullptr)
	, Input_SkillSlot_04(nullptr)
	, Input_SkillSlot_05(nullptr)
	, Input_SkillSlot_06(nullptr)
	, Input_SkillSlot_07(nullptr)
	, Input_SkillSlot_08(nullptr)
	, Input_SkillSlot_09(nullptr)
	, Input_SkillSlot_10(nullptr)
	, Input_SkillSlot_11(nullptr)
	, Input_SkillSlot_12(nullptr)
	, Input_SkillSlot_13(nullptr)
	, Input_SkillSlot_14(nullptr)


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
	AllAvatas.push_back(Avata_Shoes_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Shoes_b = CreateComponent<GameEnginePlusTextureRenderer>());

	for (auto& Avata :AllAvatas)
	{
		Avata->GetTransform().SetLocalScale({ 500, 500 });
	}

	PlayerUserInterface = GetLevel()->CreateActor<PlayerInterface>();

	Avata_Belt->GetTransform().SetLocalPosition({ 0, 0, 4 });
	Avata_Cap->GetTransform().SetLocalPosition({ 0, 0,  3 });
	Avata_Coat->GetTransform().SetLocalPosition({ 0, 0, 5 });
	Avata_Face->GetTransform().SetLocalPosition({ 0, 0, 4 });
	Avata_Hair_a->GetTransform().SetLocalPosition({ 0, 0, 3 });
	Avata_Hair_b->GetTransform().SetLocalPosition({ 0, 0, 3 });
	Avata_Neck->GetTransform().SetLocalPosition({ 0, 0, 7 });
	Avata_Pants->GetTransform().SetLocalPosition({ 0, 0, 8 });
	Avata_Shoes_a->GetTransform().SetLocalPosition({ 0, 0, 7 });
	Avata_Skin->GetTransform().SetLocalPosition({ 0, 0, 10 });


	CurrentAvataCode[Avata_Belt] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Cap] =   GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Coat] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Face] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Hair_a] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Hair_b] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Neck] =  GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Pants] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Shoes_a] = GamePlayItemCode::Empty;
	CurrentAvataCode[Avata_Skin] =  GamePlayItemCode::Empty;



}

void GamePlayCharacter::ChangeAvataAnimation(const std::string& _AnimationName) const
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->ChangeFrameAnimationPlus(_AnimationName);
	}
}

void GamePlayCharacter::ChangeFrame_Manual(int _Frame) const
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->SetFrame_Manual(_Frame);
	}
}

void GamePlayCharacter::SetAllAvataManualControl()
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->SetManualControl();
	}
}
void GamePlayCharacter::SetAllAvataAutoControl()
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->SetAutoControl();
	}
}

void GamePlayCharacter::SetRightDir()
{
	GetTransform().PixLocalPositiveX();
	StatManager->SetRightSide();
}
void GamePlayCharacter::SetLeftDir()
{
	GetTransform().PixLocalNegativeX();
	StatManager->SetLeftSide();
}