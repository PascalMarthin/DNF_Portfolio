#include "PreCompile.h"
#include "MoveManager.h"
#include "GamePlayObject.h"
#include "TownLevel.h"
#include "GamePlayCharacter.h"
#include "CharacterStatManager.h"
#include "GamePlayEnum.h"
#include "DummyActor.h"
#include "BattleLevel.h"

const float Gravitational_Constant = 9.8f;

MoveManager::MoveManager() 
	: ParentCharacter(nullptr)
	, JumpHigh(0.f)
	, JumpTime(0.f)
	, Collision_Move(nullptr)
	, Texture_CollisionMap(nullptr)
	, BlowPower(float4::ZERO)
{
}

MoveManager::~MoveManager() 
{
}


// --------------Start-------------
void MoveManager::Start()
{
	ParentCharacter = GetParent<GamePlayObject>();

	if (ParentCharacter == nullptr)
	{
		MsgBoxAssert("생성 순서가 다릅니다")
	}


	Collision_Move = ParentCharacter->CreateComponent<GameEngineCollision>("Character_Map_Collision");
	Collision_Move->GetTransform().SetLocalScale({50 , 20 , 30});
	Collision_Move->ChangeOrder(CollisionOrder::Player_Floor);
	Collision_Move->SetDebugSetting(CollisionType::CT_AABB2D, {0, 1, 0, 0.5f});
//	Collision_Move->GetTransform().SetLocalPosition({ 0, -56 });
	Collision_Move->SetParent(this);
	//GetTransform().SetLocalPosition({ 0, -56, 0});
}




// -------------Update------------------
void MoveManager::Update(float _DeltaTime)
{
	const float4& A = ParentCharacter->GetTransform().GetLocalPosition();
	if (ManagerStat != nullptr )
	{
		if (ManagerStat->IsJump() || ManagerStat->IsAerial())
		{
			JumpTime += _DeltaTime;
			JumpHigh = (-(ParentCharacter->GetCharacterWeight() * JumpTime * Gravitational_Constant) * JumpTime);


			float4 Power = BlowPower;

			Power.x += Power.x == 0 ? 0 : (-(ParentCharacter->GetCharacterWeight() * JumpTime * 0.1f) * JumpTime);;
			Power.y += JumpHigh;

			if (BlowPower.x > 0 && Power.x < 0)
			{
				Power.x = 0.f;
			}
			if (BlowPower.x < 0 && Power.x > 0)
			{
				Power.x = 0.f;
			}

			if (Power.y <= -650.f)
			{
				Power.y = -650.f;
			}

			Power *= _DeltaTime;
			Power.x *= 1.5f;

			GetTransform().SetWorldMove({ 0, -Power.y , 0 }); // 보정

			SetCharacterMove({ Power.x , 0, 0});
			ParentCharacter->GetTransform().SetWorldMove({ 0, Power.y, 0 });
	
			LandingPostion.x += Power.x;
			// Y = x(ax);
			// y = 속력
			// x = 점프 시간
			// 
			const float4& A = ParentCharacter->GetTransform().GetLocalPosition();
			if (LandingPostion.y > ParentCharacter->GetTransform().GetLocalPosition().y)
			{
				if (ManagerStat->IsAerial()) 
				{
					if (JumpHigh <= -450.f) // Bouns
					{
						ParentCharacter->GetTransform().SetLocalPosition(LandingPostion);
						BlowPower = { BlowPower.x * 0.1f ,JumpHigh * -1.f * 0.1f, 0 };
						SetAerial();
					}
					else
					{
						ParentCharacter->GetTransform().SetLocalPosition(LandingPostion);
						ParentCharacter->LandingEnd();
						BlowPower = float4::ZERO;
					}

				}
				else if (ManagerStat->IsJump())
				{
					ParentCharacter->GetTransform().SetLocalPosition(LandingPostion);
					ParentCharacter->LandingEnd();
					BlowPower = float4::ZERO;

				}
			}

			if (Power.y < 0.f)
			{
				ParentCharacter->Jump_GoingDown();
			}


			if (Power.x > 0)
			{
				ParentCharacter->SetLeftDir();
			}
			else if (Power.x < 0)
			{
				ParentCharacter->SetRightDir();
			}

		//GameEngineDebug::OutPutString(std::to_string(GetTransform().GetWorldPosition().x) + " " +std::to_string(GetTransform().GetWorldPosition().y) + " " + std::to_string(GetTransform().GetWorldPosition().z));
		}
		else if (ManagerStat->IsBeHit())
		{

		}
	}
}


float4 MoveManager::SetCharacterMove(const float4& _Move)
{
	if (_Move.x > 0.f)
	{
		ParentCharacter->SetRightDir();
	}
	else if (_Move.x < 0.f)
	{
		ParentCharacter->SetLeftDir();
	}
	// 이동 가능 여부 확인
	const float4& Pos = Collision_Move->GetTransform().GetWorldPosition();
	const float4& Scale = Collision_Move->GetTransform().GetLocalScale();


	float4 Move = _Move;


	// Left 	// Right
	if ((Move.x < 0 && Texture_CollisionMap->GetPixelToFloat4(Pos.ix() - Scale.hix(), -Pos.iy()).CompareInt4D(float4::RED)) ||
		(Move.x > 0 && Texture_CollisionMap->GetPixelToFloat4(Pos.ix() + Scale.hix(), -Pos.iy()).CompareInt4D(float4::RED)))
	{
		Move.x = 0;
	}

	//float4 Index = { Pos.x - Scale.hx(), -(Pos.y )};
	//float4 Index1 = { Pos.x, -(Pos.y + Scale.hx()) };
	// UP	  // Down
	if ((Move.y > 0 && Texture_CollisionMap->GetPixelToFloat4(Pos.ix() , -(Pos.iy() + Scale.hix())).CompareInt4D(float4::RED)) ||
		(Move.y < 0 && Texture_CollisionMap->GetPixelToFloat4(Pos.ix() , -(Pos.iy() - Scale.hix())).CompareInt4D(float4::RED)))
	{
		Move.y = 0;
	}
	Move.y *= 0.73f;
	Move.z = Move.y;
	ParentCharacter->GetTransform().SetLocalMove(Move);
	//Collision_Move->GetTransform().SetLocalMove(Move);

	//
	return Move;
}

//void MoveManager::SetCharacterMove_Inertia(const float4& _Move)
//{
//	Move_Inertia = _Move;
//}


void MoveManager::SetCharacterLocation(const float4& _Pos)
{
	ParentCharacter->GetTransform().SetLocalPosition(_Pos);
}

void MoveManager::SetAerial()
{
	JumpHigh = 0.f;
	JumpTime = 0.f;
	LandingPostion = ParentCharacter->GetTransform().GetWorldPosition();
	//GameEngineDebug::OutPutString(std::to_string(LandingPostion.y));

}
void MoveManager::SetJump(float _Power)
{
	JumpHigh = 0.f;
	JumpTime = 0.f;
	LandingPostion = ParentCharacter->GetTransform().GetWorldPosition();
	BlowPower.y = _Power;
}
//void MoveManager::SetBeAir()
//{
//	JumpTime = 0.f;
//}

void MoveManager::SetHit(const float4& _HitPower)
{
	BlowPower = _HitPower;
	if (_HitPower.y != 0 )
	{
		SetAerial();
	}
}

void MoveManager::LevelStartEvent()
{
	JumpHigh = 0.f;
	JumpTime = 0.f;
	ManagerStat = GetActor<GamePlayObject>()->GetStatManager();


	TownLevel* Level = dynamic_cast<TownLevel*>(GetActor()->GetLevel());
	if (Level != nullptr)
	{
		Texture_CollisionMap = Level->GetCollisionMapTexture();
	}
	else
	{
		BattleLevel* BatLevel = dynamic_cast<BattleLevel*>(GetActor()->GetLevel());
		if (BatLevel != nullptr)
		{
			Texture_CollisionMap = BatLevel->GetCollisionMapTexture();
		}
	}

	//switch (GetActor<GamePlayObject>()->GetObjectType())
	//{
	//case ObjectType::Character:
	//{
	//	Collision_Move->GetTransform().SetLocalPosition({ ParentCharacter->GetTransform().GetLocalPosition().x,
	//ParentCharacter->GetTransform().GetLocalPosition().y - 56,
	//ParentCharacter->GetTransform().GetLocalPosition().z });
	//}
	//	break;
	//case ObjectType::Monster:
	//	Collision_Move->Off();
	//	break;
	//case ObjectType::NPC:
	//	break;
	//case ObjectType::None:
	//	break;
	//case ObjectType::Custom:
	//	break;
	//default:
	//	break;
	//}


}

void MoveManager::LevelEndEvent()
{
	Texture_CollisionMap = nullptr;
	BlowPower = float4::ZERO;
}