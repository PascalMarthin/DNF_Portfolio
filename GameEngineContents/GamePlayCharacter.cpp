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
#include "GamePlayObjectNPC.h"
#include "GamePlayNPCInteraction.h"
#include "GamePlayObjectSpeechPopUp.h"
#include "ItemInventory_Equipment.h"

GamePlayDataBase* GamePlayCharacter::CurrentCharacterData = nullptr;
std::list<GamePlayDataBase*> GamePlayCharacter::AllCharacterData;
GamePlayCharacter* GamePlayCharacter::Inst = nullptr;
GameEngineSoundPlayer GamePlayCharacter::Fighter_Voice;

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
	, Collision_NPCCanInteraction(nullptr)
	, Collision_NPCVoice(nullptr)
	, NPC_Interaction(nullptr)
	, Collision_Body(nullptr)
	, Class_EquipmentInventory(nullptr)
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
	Class_EquipmentInventory = GetLevel()->CreateActor<ItemInventory_Equipment>();
	
	

	Component_MouseCursorComponent = GetLevel()->CreateActor<MouseCursorComponent>(ActorOrder::Mouse);



	Collision_Body = CreateComponent<GameEngineCollision>("Hit_Collision");
	Collision_Body->GetTransform().SetLocalScale({ 48, 110, 20 });
	Collision_Body->ChangeOrder(CollisionOrder::Player);
	Collision_Body->SetDebugSetting(CollisionType::CT_SPHERE, { 0, 0, 1, 0.7f });


	Collision_NPCCanInteraction = CreateComponent<GameEngineCollision>("NPCInteraction");
	Collision_NPCCanInteraction->GetTransform().SetLocalScale({150, 100, 100});
	Collision_NPCCanInteraction->ChangeOrder(CollisionOrder::Player_NPCinteraction);

	Collision_NPCVoice = CreateComponent<GameEngineCollision>("NPCVoice");


	Collision_NearMiss = CreateComponent<GameEngineCollision>("Player_NearMiss");
	Collision_NPCCanInteraction->GetTransform().SetLocalScale({ 200, 100, 200 });
	Collision_NPCCanInteraction->ChangeOrder(CollisionOrder::Player_NearMiss);

	//Collision_HitBody_Top = CreateComponent<GameEngineCollision>("Hit_Collision");
	//Collision_HitBody_Top->ChangeOrder(CollisionOrder::Player);
	//Collision_HitBody_Top->GetTransform().SetLocalPosition({ 0, -80 });
	//Collision_HitBody_Top->GetTransform().SetLocalScale({ 48, 110 });
	//Collision_HitBody_Top->SetDebugSetting(CollisionType::CT_AABB2D, {0, 0, 255, 100});
	//Collision_HitBody_Top->Off();

//	GamePlayObjectSpeechPopUp* Text = CreateComponent<GamePlayObjectSpeechPopUp>();

//	Text->CreatePopup("찢어주마!");

	Enum_UnitType = UnitType::Unit;
}

void GamePlayCharacter::Update(float _Delta)
{
	CheckInventoryKey();

	if (Manager_StatManager->GetFSMManager().GetCurStateStateName() != "Interaction")
	{
		if (Collision_NPCCanInteraction->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::NPC_Interaction, CollisionType::CT_SPHERE,
			std::bind(&GamePlayCharacter::NPCInteraction, this, std::placeholders::_1, std::placeholders::_2)))
		{
			if (GameEngineInput::GetInst()->IsUp("Enter"))
			{
				Manager_StatManager->GetFSMManager().ChangeState("Interaction");
			}
		}
		else if (NPC_Interaction != nullptr)
		{
			NPC_Interaction->SetOutLineOff();
			NPC_Interaction = nullptr;
		}
	}

	if (GameEngineInput::GetInst()->IsDown("Debug7"))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}

}

//CollisionReturn GamePlayCharacter::NearMissFunc(GameEngineCollision* _This, GameEngineCollision* _Other)
//{
//	NearList.find(_Other) == 
//	NearList[]
//
//}

CollisionReturn GamePlayCharacter::NPCInteraction(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (NPC_Interaction == _Other->GetActor<GamePlayObjectNPC>())
	{
		return CollisionReturn::Break;
	}
	else if (NPC_Interaction != nullptr)
	{
		NPC_Interaction->SetOutLineOff();
	}


	NPC_Interaction = _Other->GetActor<GamePlayObjectNPC>();
	if (GameEngineRandom::MainRandom.RandomInt(0, 3) == 0)
	{
		GamePlayObjectNPC::SetVoice(NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Nomal][GameEngineRandom::MainRandom.RandomInt(0, NPC_Interaction->map_NPCVoice[InteractOptionNPCVoice::Nomal].size() - 1)]);
	}
	
	NPC_Interaction->SetOutLine();
	return CollisionReturn::Break;

}

void GamePlayCharacter::CheckInventoryKey()
{
	if (GameEngineInput::GetInst()->IsDown("Inventory"))
	{
		if (Class_ItemInventory->IsUpdate())
		{
			Class_ItemInventory->Off();
		}
		else
		{
			Class_EquipmentInventory->Off();
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
			Class_EquipmentInventory->Off();
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



	NewCharacter->CreateItem(GamePlayItemCode::s_HPPotion, 1);
	NewCharacter->CreateItem(GamePlayItemCode::m_HPPotion, 1);
	NewCharacter->CreateItem(GamePlayItemCode::L_HPPotion, 1);
	NewCharacter->CreateItem(GamePlayItemCode::s_MPPotion, 1);
	NewCharacter->CreateItem(GamePlayItemCode::m_MPPotion, 1);
	NewCharacter->CreateItem(GamePlayItemCode::L_MPPotion, 1);


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


	GamePlayCharacter::Inst = this;
	Fighter_Voice.Stop();
	//GetTransform().SetLocalMove({0 , 0 , GetTransform().GetLocalPosition().y });
	//Class_ItemInventory->GetTransform().SetLocalPosition({ GetTransform().GetLocalPosition().x, GetTransform().GetLocalPosition().y, 0 });
}

void GamePlayCharacter::LevelEndEvent()
{
	JumpGoingDown = false;
	HoldCam = false;
	GamePlayCharacter::Inst = nullptr;

	Fighter_Voice.Stop();
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
void GamePlayCharacter::SetVoice(const std::string& _Name)
{
	Fighter_Voice.Stop();
	Fighter_Voice = GameEngineSound::SoundPlayControl(_Name);
	Fighter_Voice.Volume(0.8f);
}

unsigned int GamePlayCharacter::SetHPFromHit(unsigned int _Damage)
{
	//if (CurrentCharacterData->GetAbilityStat()->HP < static_cast<int>(_Damage))
	//{
	//	Manager_StatManager->SetDead();
	//	CurrentCharacterData->GetAbilityStat()->HP = 0;
	//}
	//else
	{
		CurrentCharacterData->GetAbilityStat()->HP -= _Damage;
	}

	return _Damage;
}