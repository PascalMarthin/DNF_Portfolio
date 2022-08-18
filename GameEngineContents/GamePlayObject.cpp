#include "PreCompile.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "GamePlayObjectNPC.h"
#include "MoveManager.h"
#include "GamePlaySkill.h"
#include "GamePlayMonster.h"

GamePlayObject::GamePlayObject() 
	: Dir_RightSide(false)
	, Manager_MoveManager(nullptr)
	, Enum_ObjectType(ObjectType::None)
	, CharacterWeight(0.f)
	, Manager_StatManager(nullptr)
	, Enum_UnitType(UnitType::None)
	, JumpGoingDown(false)
	, DownWait(0.f)
{
	//GetTransform().SetLocalPosition();
}

GamePlayObject::~GamePlayObject() 
{
}

void GamePlayObject::Start()
{
	Manager_MoveManager = CreateComponent<MoveManager>();
	//Manager_CollisionManager = GetLevel()->CreateActor<CollisionManager>();
	//Manager_CollisionManager->SetParent(this);
	CharacterWeight = 170.f;
	if (dynamic_cast<GamePlayCharacter*>(this))
	{
		Enum_ObjectType = ObjectType::Character;
		GetTransform().SetLocalScale({ MonitorX, MonitorY, 1.f });
	}
	else if (dynamic_cast<GamePlayObjectNPC*>(this))
	{
		Enum_ObjectType = ObjectType::NPC;
	}
	else if (dynamic_cast<GamePlayMonster*>(this))
	{
		Enum_ObjectType = ObjectType::Monster;
	}

	if (Enum_ObjectType == ObjectType::None)
	{
		MsgBoxAssert("������Ʈ Ÿ���� �������� �ʾҽ��ϴ�")
	}
}

void GamePlayObject::BeHit(GamePlaySkill* _Skill, const GamePlayDataBase* _Character, int _Index)
{
	if (Enum_UnitType == UnitType::None)
	{
		MsgBoxAssert("�������� �ʾҽ��ϴ�")
	}

	float4 Power = _Skill->GetBlowPower();
	Power.x *= static_cast<float>(_Index);

	//
	// x > 0 y > 0 w > 0
	// x > 0 y = 0 w > 0
	// x = 0 y > 0 w = 0
	// 
	// 
	// 
	//_Skill->GetSkillDamage()
	
	// ����� ó��

	switch (_Skill->GetHitType())
	{
	case HitType::Standing:
	case HitType::Air:
	{

		if (Power.x != 0 && Power.y != 0 && Power.w == 0)
		{
			Manager_StatManager->SetHit_BlowUp();
		}
		else if (Power.x != 0 && Power.y == 0 && Power.w != 0)
		{
			Manager_StatManager->SetHit_Stand();
		}
		else
		{
			MsgBoxAssert("���ܹ߻�_ Ȯ���� �߰�")
		}

		Manager_MoveManager->SetHit(Power);
	}
		break;
	case HitType::Hold:
		
		break;

	case HitType::None:
	default:
		MsgBoxAssert("��ų�� �������� �ʾҽ��ϴ�");
		break;
	}

	//
	// ��ų������ ���� ��ų Ÿ�������� ������ �ڼ��� ��ħ
	// ������� ��ų�� ĳ���� ������ ���̽��� ������� ��
	// 
	// 
	//
}
