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
#include "ItemInventory.h"
#include "MouseCursorComponent.h"

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

	Component_MouseCursorComponent = GetLevel()->CreateActor<MouseCursorComponent>();
	Manager_AvataManager = GetLevel()->CreateActor<AvataManager>();
	Manager_AvataManager->SetParent(this);
	Manager_AvataManager->SetAvataSetup(ObjectType::Character);
	Manager_StatManager = CreateComponent<CharacterStatManager>();


	PlayerUserInterface = GetLevel()->CreateActor<PlayerInterface>();
	Function_BaseAtt = CreateComponent<Skill_Fighter_F_BaseHit>()->Get_SkillAction();
	
	Class_ItemInventory = GetLevel()->CreateActor<ItemInventory>();


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
			Class_ItemInventory->On();
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
	NewCharacter->GetInventoryData();
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


	GetTransform().SetLocalMove({0 , 0 , GetTransform().GetLocalPosition().y });
	//Class_ItemInventory->GetTransform().SetLocalPosition({ GetTransform().GetLocalPosition().x, GetTransform().GetLocalPosition().y, 0 });
}

void GamePlayCharacter::LevelEndEvent()
{
	JumpGoingDown = false;
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
