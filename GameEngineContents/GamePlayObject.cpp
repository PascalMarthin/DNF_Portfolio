#include "PreCompile.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "GamePlayObjectNPC.h"
#include "MoveManager.h"
#include "GamePlaySkill.h"
#include "GamePlayMonster.h"
#include "GameEngineDamageRenderer.h"
#include "GamePlayComboSystem.h"

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
		MsgBoxAssert("오브젝트 타입이 설정되지 않았습니다")
	}
}

void GamePlayObject::BeHit(GamePlaySkill* _Skill, GameEngineCollision* _HitCollision , GamePlayObject* _HitObject, int _Index, unsigned int _Damage)
{
	if (Enum_UnitType == UnitType::None)
	{
		MsgBoxAssert("설정하지 않았습니다")
	}

	if (Manager_StatManager->IsInvincibility())
	{
		switch (Enum_ObjectType)
		{
		case ObjectType::Character:
			GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::GhostFrame);
			GamePlayComboSystem::GetInst()->PlusScore(10000);
			return;
			break;
		case ObjectType::Monster:
			return;
			break;
		default:
			break;
		}
	}

	float4 Power = _Skill->Class_Power[_Skill->int_ComboStuck].float4_HitPhysicsPower;
	Power.x *= static_cast<float>(_Index);

	//
	// x > 0 y > 0 w > 0
	// x > 0 y = 0 w > 0
	// x = 0 y > 0 w = 0
	// 


	
	// 대미지 처리
	SetDamage(5000000);	

	// 점수
	if (Enum_ObjectType == ObjectType::Monster)
	{
		float MultipleIndex = 1.f;
		{
			if (GetTransform().GetLocalScale().x > 0)
			{
				if (_HitObject->GetTransform().GetWorldPosition().x < GetTransform().GetWorldPosition().x)
				{
					MultipleIndex *= 1.5f;
					GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::BackAttack);
				}
			}
			else
			{
				if (_HitObject->GetTransform().GetWorldPosition().x > GetTransform().GetWorldPosition().x)
				{
					MultipleIndex *= 1.5f;
					GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::BackAttack);
				}
			}
		}// 백어택

		{
			if (Manager_StatManager->IsAerial())
			{
				MultipleIndex *= 1.2f;
				GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::Aerial);
			}
		}// 공중에 뜸

		{
			if (Manager_StatManager->IsDoSkill())
			{
				MultipleIndex *= 1.8f;
				GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::Counter);
			}
		}// 카운터

		GamePlayComboSystem::GetInst()->PlusScore(1235);
	}



	switch (_Skill->Class_Power[_Skill->int_ComboStuck].Enum_HitPostureType)
	{
	case HitPostureType::Standing:
	{
		Manager_StatManager->SetHit_Stand();
		Manager_MoveManager->SetHit(Power);
	}
	break;
	case HitPostureType::Aerial:
	{
		Manager_StatManager->SetHit_BlowUp();
		//if (Power.x != 0 && Power.y != 0 && Power.w == 0)
		//{
		//
		//}
		//else if (Power.x != 0 && Power.w != 0)
		//{
	
		//}
		//else
		//{
		//	MsgBoxAssert("예외발생_ 확인후 추가")
		//}

		Manager_MoveManager->SetHit(Power);
	}
		break;
	case HitPostureType::Hold:
	{
		if (Manager_StatManager->IsDoSkill())
		{
			GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::CounterHold); // 카운터 홀드
		}

		Manager_StatManager->SetHold();
		Manager_MoveManager->SetHold(Power.w);
	}
		break;

	case HitPostureType::None:
	default:
		MsgBoxAssert("스킬이 설정되지 않았습니다");
		break;
	}



	GamePlayObject* Hit = _Skill->GetActor<GamePlayObject>();
	switch (_Skill->Class_Power[_Skill->int_ComboStuck].Enum_HitType)
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
		// 3개다 쓰고있으면 그냥 이펙트 생략
	}
		break;
	case HitType::Slash:
	case HitType::None:
	default:
		//MsgBoxAssert("타입 설정을 안했습니다")
		break;
	}

	//
	// 스킬안으로 들어가서 스킬 타입을보고 본인의 자세를 고침
	// 대미지는 스킬과 캐릭터 데이터 베이스를 기반으로 함
	// 
	// 



}

void GamePlayObject::SetDamage(unsigned int _Damage)
{
	GameEngineDamageRenderer* Font = GetLevel()->CreateActor<GameEngineDamageRenderer>();
	Font->GetTransform().SetLocalPosition({ GetTransform().GetLocalPosition().x ,GetTransform().GetLocalPosition().y, -10.f});
	Font->SetDamage(SetHPFromHit(_Damage));

	
	// 대미지 - 방어력 

}

void GamePlayObject::BeHitHold()
{

}

void GamePlayObject::HitEffect(GameEngineTextureRenderer* _Texture, GameEngineCollision* _HitCollision, const std::string& _AniName)
{
	_Texture->SetParent(_HitCollision->GetActor());
	const float4 Postion = _HitCollision->GetTransform().GetWorldPosition();
	const float4& Scale = _HitCollision->GetTransform().GetLocalScale();

	_Texture->GetTransform().SetWorldPosition({ Postion.x + GameEngineRandom::MainRandom.RandomFloat(-Scale.x * 0.5f, Scale.x * 0.5f),
											    Postion.y + GameEngineRandom::MainRandom.RandomFloat(-Scale.y * 0.5f, Scale.y * 0.5f),
												Postion.y - 50.f });
	_Texture->On();
	_Texture->ChangeFrameAnimation(_AniName);
	
}

void GamePlayObject::Ani_BindEndOff(const FrameAnimation_DESC& _Desc)
{
	_Desc.Renderer->Off();
	_Desc.Renderer->ChangeFrameAnimation("None");
}

void GamePlayObject::BeHitEnd()
{
	Manager_StatManager->SetHit_StandEnd();
}
