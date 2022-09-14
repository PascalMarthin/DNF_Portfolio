#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "PlayerInterface.h"
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayCharacter.h"
#include "GamePlayDataBase.h"
#include "CollisionManager.h"
#include "GamePlaySkill.h"
#include "AvataManager.h"
#include "InterfaceHUD.h"
#include "Skill_Fighter_F_BaseHit.h"
#include "ItemInventory_Consumable.h"
#include "MouseCursorComponent.h"
#include "GamePlayDataBase.h"
#include "MouseCursorComponent.h"
#include "AvataInventory.h"

GamePlayDataBase* GamePlayCharacter::CurrentCharacterData = nullptr;
std::list<GamePlayDataBase*> GamePlayCharacter::AllCharacterData;

GamePlayCharacter::GamePlayCharacter()
	: Manager_AvataManager(nullptr)
	, PlayerUserInterface(nullptr)
	, PlayerFormerClass(CharacterFormerClass::None)
	, StartJump(false)
	, EndJump(false)
	, MoveIndex(0.f)
	, JumpKick_DelayTime(0.f)
	, BaseJumpKick(false)
	, Skill_CurrentSkill(nullptr)
	, Skill_BaseHit(nullptr)
	, Skill_BaseDashAtt(nullptr)
	, Function_CurrentSkill(nullptr)
	, Function_BaseAtt(nullptr)
	, Class_ItemInventory(nullptr)
	, Component_MouseCursorComponent(nullptr)
	, Manager_SkillManager(nullptr)
	, Class_AvataInventory(nullptr)
	, HoldCam(false)
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

	Manager_AvataManager = GetLevel()->CreateActor<AvataManager>();
	Manager_AvataManager->SetParent(this);
	Manager_AvataManager->SetAvataSetup(ObjectType::Character);
	Manager_StatManager = CreateComponent<CharacterStatManager>();


	PlayerUserInterface = GetLevel()->CreateActor<PlayerInterface>();
	Function_BaseAtt = CreateComponent<Skill_Fighter_F_BaseHit>()->Get_SkillAction();
	
	Class_ItemInventory = GetLevel()->CreateActor<ItemInventory_Consumable>();
	Class_AvataInventory = GetLevel()->CreateActor<AvataInventory>();

	Component_MouseCursorComponent = GetLevel()->CreateActor<MouseCursorComponent>(ActorOrder::Mouse);

	//Collision_HitBody_Top = CreateComponent<GameEngineCollision>("Hit_Collision");
	//Collision_HitBody_Top->ChangeOrder(CollisionOrder::Player);
	//Collision_HitBody_Top->GetTransform().SetLocalPosition({ 0, -80 });
	//Collision_HitBody_Top->GetTransform().SetLocalScale({ 48, 110 });
	//Collision_HitBody_Top->SetDebugSetting(CollisionType::CT_AABB2D, {0, 0, 255, 100});
	//Collision_HitBody_Top->Off();
}

void GamePlayCharacter::Update(float _Delta)
{
	if (GameEngineInput::GetInst()->IsDown("Inventory"))
	{
		if (Class_ItemInventory->IsUpdate())
		{
			Class_ItemInventory->Off();
		}
		else
		{
			Class_AvataInventory->Off();
			Class_ItemInventory->On();
		}
	}

	if (GameEngineInput::GetInst()->IsDown("Avata"))
	{
		if (Class_AvataInventory->IsUpdate())
		{
			Class_AvataInventory->Off();
		}
		else
		{
			Class_ItemInventory->Off();
			Class_AvataInventory->On();
		}
	}

	if (GameEngineInput::GetInst()->IsDown("MyProfile"))
	{
		if (Manager_StatManager->StatWindowIsUpdate())
		{
			Manager_StatManager->StatWindowOff();
		}
		else
		{
			Manager_StatManager->StatWindowOn();
		}
		
	}

	
}

//void GamePlayCharacter::On_EnumCollision(Collision_AllSkill _Collsion)
//{
//	for (GameEngineCollision* Collision : Collision_HitCollision[_Collsion])
//	{
//		Collision->On();
//	}
//}
//
//void GamePlayCharacter::Off_EnumCollision(Collision_AllSkill _Collsion)
//{
//	for (GameEngineCollision* Collision : Collision_HitCollision[_Collsion])
//	{
//		Collision->Off();
//	}
//}

GamePlayDataBase* GamePlayCharacter::CreateCharacterBase(CharacterFormerClass _Class, const std::string& _NickName)
{
	GamePlayDataBase* NewCharacter = new GamePlayDataBase(_Class , _NickName);
	NewCharacter->CreateItem(GamePlayItemCode::Level1Up, 1);

	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Belt_7st_Blue, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Cap_7st_Blue, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Coat_7st_Blue, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Face_7st_Blue, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Hair_7st_Blue, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Neck_7st_Blue, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Pants_7st_Blue, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Shoes_7st_Blue, 1);

	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Belt_9st_Purple, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Cap_9st_Purple, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Coat_9st_Purple, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Face_9st_Purple, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Hair_9st_Purple, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Neck_9st_Purple, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Pants_9st_Purple, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Shoes_9st_Purple, 1);

	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Belt_4st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Cap_4st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Coat_4st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Face_4st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Hair_4st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Neck_4st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Pants_4st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Shoes_4st_White, 1);

	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Belt_14st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Cap_14st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Coat_14st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Face_14st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Hair_14st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Neck_14st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Pants_14st_White, 1);
	NewCharacter->CreateItem(GamePlayItemCode::Fighter_F_Shoes_14st_White, 1);

	//NewCharacter->CreateItem(GamePlayItemCode::Level1Up);
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
		PlayerFormerClass = CurrentCharacterData->GetFormerClass();
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

void GamePlayCharacter::LevelStartEvent()
{
	if (CurrentCharacterData == nullptr)
	{
		MsgBoxAssert("데이터가 지정이 안되어 있습니다")
	}
	SetFSManager();
	MoveIndex = 0.f;


	//GetTransform().SetLocalMove({0 , 0 , GetTransform().GetLocalPosition().y });
	//Class_ItemInventory->GetTransform().SetLocalPosition({ GetTransform().GetLocalPosition().x, GetTransform().GetLocalPosition().y, 0 });
}

void GamePlayCharacter::LevelEndEvent()
{
	JumpGoingDown = false;
	HoldCam = false;
}

//void GamePlayCharacter::SkillCollisionActive(const std::string& _Name, int _Frame)
//{
//	if (Manager_AvataManager->Avata_Skin->GetCurrentFrameStuck() == _Frame)
//	{
//		SetOn(map_AllSkill[_Name]);
//	}
//	else
//	{
//		SetOff(map_AllSkill[_Name]);
//	}
//}
