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

void GamePlayObject::BeHit(GamePlaySkill* _Skill, GameEngineCollision* _HitCollision , const GamePlayDataBase* _Character, int _Index)
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

	
	// ����� ó��

	switch (_Skill->GetHitPostureType())
	{
	case HitPostureType::Standing:
	case HitPostureType::Air:
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
	case HitPostureType::Hold:
		
		break;

	case HitPostureType::None:
	default:
		MsgBoxAssert("��ų�� �������� �ʾҽ��ϴ�");
		break;
	}



	GamePlayObject* Hit = _Skill->GetActor<GamePlayObject>();
	switch (_Skill->GetHitType())
	{
	case HitType::Hit:
	{
		for (auto* Iter: Hit->map_NomalEffect["KnockLarge"])
		{
			if (Iter->IsUpdate())
			{
				continue;
			}
			else
			{
				HitEffect(Iter, _HitCollision, "KnockLarge");
				break;
			}
		}
		// 3���� ���������� �׳� ����Ʈ ����
	}
		break;
	case HitType::Slash:
	case HitType::None:
	default:
		MsgBoxAssert("Ÿ�� ������ ���߽��ϴ�")
		break;
	}

	//
	// ��ų������ ���� ��ų Ÿ�������� ������ �ڼ��� ��ħ
	// ������� ��ų�� ĳ���� ������ ���̽��� ������� ��
	// 
	// 
	//
}

void GamePlayObject::HitEffect(GameEngineTextureRenderer* _Texture, GameEngineCollision* _HitCollision, const std::string& _AniName)
{
	const float4 Postion = _HitCollision->GetTransform().GetWorldPosition();
	const float4& Scale = _HitCollision->GetTransform().GetLocalScale();

	_Texture->GetTransform().SetWorldPosition({ Postion.x + GameEngineRandom::MainRandom.RandomFloat(-Scale.x * 0.5f, Scale.x * 0.5f),
											    Postion.y + GameEngineRandom::MainRandom.RandomFloat(-Scale.y * 0.5f, Scale.y * 0.5f),
												0 });
	_Texture->On();
	_Texture->ChangeFrameAnimation(_AniName);
	
}

void GamePlayObject::Ani_BindEndOff(const FrameAnimation_DESC& _Desc)
{
	_Desc.CurRenderer->Off();
	_Desc.CurRenderer->ChangeFrameAnimation("None");
}

void GamePlayObject::BeHitEnd()
{
	Manager_StatManager->SetHit_StandEnd();
}
