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
	, JumpPower(600.f)
	, JumpHigh(0.f)
	, CurrentGravitIndex(-1.f)
	, JumpTime(0.f)
	, Collision_Move(nullptr)
	, Texture_CollisionMap(nullptr)
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


	Collision_Move = ParentCharacter->GetLevel()->CreateActor<DummyActor>()->CreateComponent<GameEngineCollision>("Character_Map_Collision");
	Collision_Move->GetTransform().SetLocalScale({50 , 20 , 30});
	Collision_Move->ChangeOrder(CollisionOrder::Player_Floor);
	Collision_Move->SetDebugSetting(CollisionType::CT_AABB2D, {0, 1, 0, 0.5f});
	Collision_Move->GetTransform().SetLocalPosition({ 0, -56 });
}




// -------------Update------------------
void MoveManager::Update(float _DeltaTime)
{
	if (ManagerStat != nullptr )
	{
		if (ManagerStat->IsJump())
		{
			JumpTime += _DeltaTime;
			if (JumpHigh > -650)
			{
				JumpHigh = (-(ParentCharacter->GetCharacterWeight()  * JumpTime * Gravitational_Constant) * JumpTime + JumpPower);
			}
		
		}
		// Y = x(ax);
		// y = 속력
		// x = 점프 시간
		// 
	}
	GameEngineDebug::OutPutString(std::to_string(Collision_Move->GetTransform().GetLocalPosition().x) + " " + std::to_string(Collision_Move->GetTransform().GetLocalPosition().y));
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

	//float4 IndexL = { Pos.x - Scale.hx(), -Pos.y};
	//float4 IndexR = { Pos.x + Scale.hx(), -Pos.y };
	//float4 IndexU = { Pos.x , -(Pos.y + Scale.hx()) };
	//float4 IndexD = { Pos.x , -(Pos.y - Scale.hx()) };

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
	Collision_Move->GetTransform().SetLocalMove(Move);

	//
	return Move;
}

void MoveManager::SetCharacterJump(const float4& _Move)
{
	ParentCharacter->GetTransform().SetWorldMove(_Move);
}

void MoveManager::SetCharacterLocation(const float4& _Pos)
{
	ParentCharacter->GetTransform().SetLocalPosition(_Pos);
}

void MoveManager::SetJump()
{
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;
	LandingPostion = ParentCharacter->GetTransform().GetLocalPosition();
	GameEngineDebug::OutPutString(std::to_string(LandingPostion.y));
}

void MoveManager::OnEvent()
{
	JumpHigh = 0.f;
	CurrentGravitIndex = -1.f;
	JumpTime = 0.f;

	GamePlayCharacter* Character = dynamic_cast<GamePlayCharacter*>(ParentCharacter);

	if (Character->GetObjectType() == ObjectType::Character)
	{
		ManagerStat = Character->GetStatManager();
	}
	TownLevel* Level = dynamic_cast<TownLevel*>(Character->GetLevel());
	if (Level != nullptr)
	{
		Texture_CollisionMap = Level->GetCollisionMapTexture();
	}
	else
	{
		BattleLevel* BatLevel = dynamic_cast<BattleLevel*>(Character->GetLevel());
		if (BatLevel != nullptr)
		{
			Texture_CollisionMap = BatLevel->GetCollisionMapTexture();
		}
	}




	Collision_Move->GetTransform().SetLocalPosition({ ParentCharacter->GetTransform().GetLocalPosition().x, 
		ParentCharacter->GetTransform().GetLocalPosition().y - 56,
		ParentCharacter->GetTransform().GetLocalPosition().z });

}

void MoveManager::OffEvent()
{
	Texture_CollisionMap = nullptr;
}