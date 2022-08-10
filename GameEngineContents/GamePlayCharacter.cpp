#include "PreCompile.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "PlayerInterface.h"
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayCharacter.h"
#include "GamePlayDataBase.h"
#include "CollisionManager.h"
#include "AvataManager.h"
#include "InterfaceHUD.h"

GamePlayDataBase* GamePlayCharacter::CurrentCharacterData = nullptr;
std::list<GamePlayDataBase*> GamePlayCharacter::AllCharacterData;

GamePlayCharacter::GamePlayCharacter()
	: Manager_StatManager(nullptr)
	, Manager_AvataManager(nullptr)
	, PlayerUserInterface(nullptr)
	, PlayerFormerClass(CharacterFormerClass::None)
	, StartJump(false)
	, EndJump(false)
	, JumpGoingDown(false)
	, MoveIndex(0.f)
	, JumpKick_DelayTime(0.f)
	, BaseJumpKick(false)
	, Att_BaseAtt_Delay(0.f)
	, DelayPunch(false)
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

	Collision_HitBody = CreateComponent<GameEngineCollision>("Hit_Collision");
	Collision_HitBody->ChangeOrder(CollisionOrder::Player);
	Collision_HitBody->GetTransform().SetLocalPosition({ 0, -80 });
	Collision_HitBody->GetTransform().SetLocalScale({ 48, 110 });
	Collision_HitBody->SetDebugSetting(CollisionType::CT_AABB2D, {0, 0, 255, 100});
	Collision_HitBody->Off();
}

void GamePlayCharacter::On_EnumCollision(Collision_AllSkill _Collsion)
{
	for (GameEngineCollision* Collision : Collision_HitCollision[_Collsion])
	{
		Collision->On();
	}
}

void GamePlayCharacter::Off_EnumCollision(Collision_AllSkill _Collsion)
{
	for (GameEngineCollision* Collision : Collision_HitCollision[_Collsion])
	{
		Collision->Off();
	}
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


	MoveIndex = 0.f;

}

void GamePlayCharacter::OffEvent()
{

}