#include "PreCompile.h"
#include "Light_archer.h"
#include "MoveManager.h"
#include "GamePlayCharacter.h"

Light_archer::Light_archer() 
	: MoveDelay(0)
{
}

Light_archer::~Light_archer() 
{
}

void Light_archer::Start()
{
	GamePlayMonster::Start();

	Enum_UnitType = UnitType::Unit;

	CreateMonsterStat(3000000, 50, 10.45f); //1,115,180,000

	SetMonsterClass(MonsterClass::Nomal);


	Texture_Monster = CreateComponent<GameEngineTextureRenderer>();
	Texture_Monster->CreateFrameAnimationFolder("Monster_Standing", FrameAnimation_DESC("light_archer_Body", 0, 3, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Monster_Walk", FrameAnimation_DESC("light_archer_Body", 0, 3, 0.15f));

	Texture_Monster->CreateFrameAnimationFolder("Monster_Down", FrameAnimation_DESC("light_archer_Body", 38, 38, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Monster_GoingDown", FrameAnimation_DESC("light_archer_Body", 35, 36, 0.125f, false));
	Texture_Monster->CreateFrameAnimationFolder("Monster_Hit1", FrameAnimation_DESC("light_archer_Body", 34, 34, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Monster_Hit2", FrameAnimation_DESC("light_archer_Body", 35, 35, 0.15f, false));
	Texture_Monster->ChangeFrameAnimation("Monster_Walk");
	Texture_Monster->ScaleToTexture();

	Texture_Monster->GetTransform().SetLocalPosition({ 0, 30, 0 });

	Collision_HitBody = CreateComponent<GameEngineCollision>();
	Collision_HitBody->GetTransform().SetLocalScale({ 80, 150, 50 });
	Collision_HitBody->ChangeOrder(CollisionOrder::Monster);


	Collision_TargetPos = CreateComponent<GameEngineCollision>();
	Collision_TargetPos->GetTransform().SetLocalScale({ 200, 200, 200 });


	SetFSManager();
}
void Light_archer::SetFSManager()
{
	Manager_StatManager->GetFSMManager().CreateStateMember
	("None", [=](float _DeltaTime, const StateInfo& _Info)
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		});

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Stand", std::bind(&Light_archer::FSM_Move_Stand_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Light_archer::FSM_Move_Stand_Start, this, std::placeholders::_1)
		, std::bind(&Light_archer::FSM_Move_Stand_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Stand", std::bind(&Light_archer::FSM_Hit_Stand_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Light_archer::FSM_Hit_Stand_Start, this, std::placeholders::_1)
		, std::bind(&Light_archer::FSM_Hit_Stand_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Aerial", std::bind(&Light_archer::FSM_Hit_Aerial_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Light_archer::FSM_Hit_Aerial_Start, this, std::placeholders::_1)
		, std::bind(&Light_archer::FSM_Hit_Aerial_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Aerial_GoingDown", std::bind(&Light_archer::FSM_Hit_Aerial_DoingDown_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Light_archer::FSM_Hit_Aerial_DoingDown_Start, this, std::placeholders::_1)
		, std::bind(&Light_archer::FSM_Hit_Aerial_DoingDown_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Down", std::bind(&Light_archer::FSM_Hit_Down_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Light_archer::FSM_Hit_Down_Start, this, std::placeholders::_1)
		, std::bind(&Light_archer::FSM_Hit_Down_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Walk", std::bind(&Light_archer::FSM_Move_Walk_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Light_archer::FSM_Move_Walk_Start, this, std::placeholders::_1)
		, std::bind(&Light_archer::FSM_Move_Walk_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().ChangeState("None");

}

void Light_archer::CheckDir()
{
	if (GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition().x >= GetTransform().GetWorldPosition().x)
	{
		GetTransform().PixLocalPositiveX();
	}
	else
	{
		GetTransform().PixLocalNegativeX();
	}
}

void Light_archer::Update(float _DeltaTime)
{
	GamePlayMonster::Update(_DeltaTime);


	if (Manager_StatManager->GetFSMManager().GetCurStateStateName() == "Move_Stand" || Manager_StatManager->GetFSMManager().GetCurStateStateName() == "Move_Walk")
	{
		CheckDir();

		std::vector<std::string> CanSkill;

		for (auto& CollTime : All_CollTime)
		{
			if (CollTime.second > 0)
			{
				continue;
			}
			else
			{
				CanSkill.push_back(CollTime.first);
			}
		}
		//
		//std::list<std::string>::iterator StartIter = CanSkill.begin();
		//std::list<std::string>::iterator EndIter = CanSkill.end();


		for (auto& Collision : CanSkill)
		{
			//if (!AllCollision[Collision]->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
			//{
			//	Collision = "None";
			//	continue;
			//}
		}

		int RandomIndex = GameEngineRandom::MainRandom.RandomInt(-100, static_cast<int>(CanSkill.size()) - 1);


		if (RandomIndex >= 0)
		{
			if (CanSkill[RandomIndex] != "None")
			{
				Manager_StatManager->GetFSMManager().ChangeState(CanSkill[RandomIndex]);
			}
		}
	}



	
}


void Light_archer::Bale_BackToNone(const FrameAnimation_DESC& _DESC)
{
	Manager_StatManager->GetFSMManager().ChangeState("None");
}


void Light_archer::FSM_Move_Stand_Start(const StateInfo& _Info)
{
	
	Texture_Monster->ChangeFrameAnimation("Monster_Standing");
	

	StayStandDelay = 1.5f;
}
void Light_archer::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{

	StayStandDelay -= _DeltaTime;
	if (StayStandDelay <= 0)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Walk");
		return;
	}

	//if (!Collision_TargetPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
	//{
	//	Manager_StatManager->GetFSMManager().ChangeState("Move_Walk"); // 중단점 용
	//	return;
	//}

	//}
}
void Light_archer::FSM_Move_Stand_End(const StateInfo& _Info)
{

}

void Light_archer::FSM_Hit_Stand_Start(const StateInfo& _Info)
{
	if (_Info.PrevState == "Hit_Stand" && GameEngineRandom::MainRandom.RandomInt(0, 1) == 1)
	{
		Texture_Monster->ChangeFrameAnimation("Monster_Hit2");
	}
	else
	{
		Texture_Monster->ChangeFrameAnimation("Monster_Hit1");
	}


}
void Light_archer::FSM_Hit_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (!Manager_StatManager->IsBeHit())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void Light_archer::FSM_Hit_Stand_End(const StateInfo& _Info)
{
	Manager_StatManager->SetHit_StandEnd();
}

void Light_archer::FSM_Hit_Aerial_Start(const StateInfo& _Info)
{
	Manager_MoveManager->SetAerial();
	Manager_StatManager->SetAerial();
	Texture_Monster->ChangeFrameAnimation("Monster_Hit1");
	JumpGoingDown = false;
}
void Light_archer::FSM_Hit_Aerial_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (JumpGoingDown == true)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Hit_Aerial_GoingDown");
	}
}
void Light_archer::FSM_Hit_Aerial_End(const StateInfo& _Info)
{
	JumpGoingDown = false;
	Manager_StatManager->SetAerialEnd();
}

void Light_archer::FSM_Hit_Aerial_DoingDown_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetAerial();
	Texture_Monster->ChangeFrameAnimation("Monster_GoingDown");
	GoingDownTime = 0.f;
}
void Light_archer::FSM_Hit_Aerial_DoingDown_Update(float _DeltaTime, const StateInfo& _Info)
{
	GoingDownTime += _DeltaTime;

	if (!Manager_StatManager->IsAerial())
	{
		Manager_StatManager->SetDown();
	}

}
void Light_archer::FSM_Hit_Aerial_DoingDown_End(const StateInfo& _Info)
{
	Manager_StatManager->SetAerialEnd();
	//Collision_HitBody_Top->On();
	GoingDownTime = 0.f;
}


//void Light_archer::Ani_StandUp(const FrameAnimation_DESC&)
//{
//	Texture_Monster->ChangeFrameAnimation("Bale_Standing");
//}


void Light_archer::LandingEnd()
{
	Manager_StatManager->SetAerialEnd();
}



void Light_archer::FSM_Hit_Down_Start(const StateInfo& _Info)
{
	Texture_Monster->ChangeFrameAnimation("Monster_Down");
	DownWait = 0.6f;
}
void Light_archer::FSM_Hit_Down_Update(float _DeltaTime, const StateInfo& _Info)
{
	DownWait -= _DeltaTime;
	if (DownWait <= 0.f)
	{
		Manager_StatManager->SetDownEnd();
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void Light_archer::FSM_Hit_Down_End(const StateInfo& _Info)
{
	DownWait = 0.f;
}


void Light_archer::FSM_Move_Walk_Start(const StateInfo& _Info)
{

	Texture_Monster->ChangeFrameAnimation("Monster_Walk", true);
	Collision_TargetPos->SetParent(GamePlayCharacter::GetInst());
	Collision_TargetPos->GetTransform().SetLocalPosition(float4::ZERO);
	MoveDelay = 0;
}
void Light_archer::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
{

	MoveDelay -= _DeltaTime;
	bool IsArrive = false;
	if (MoveDelay <= 0 || (IsArrive = Collision_TargetPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE)))
	{
		if (IsArrive == true)
		{
			if (Collision_TargetPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
			{
				Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
			}
		}

		float4 Pos = float4::ZERO;
		Pos.x += GameEngineRandom::MainRandom.RandomFloat(-2.f, 2.f) * 25.f;
		Pos.y += GameEngineRandom::MainRandom.RandomFloat(-2.f, 2.f) * 20.f ;

		if (Pos.x >= 0)
		{
			Pos.x += 190.f;
		}
		else
		{
			Pos.x -= 190.f;
		}

		Collision_TargetPos->GetTransform().SetLocalPosition(Pos);
		MoveDelay = 2.f;
	}

	const float4& Collision = Collision_TargetPos->GetTransform().GetWorldPosition();
	const float4& Monster = GetTransform().GetWorldPosition();

	float4 Dir = 0;
	if (Collision.x - Monster.x > 0)
	{
		Dir.x = 180.f;
	}
	else
	{
		Dir.x = -180.f;
	}

	if (Collision.z - Monster.z > 0)
	{
		Dir.z = 180.f;
	}
	else
	{
		Dir.z = -180.f;

	}



	//Manager_MoveManager->SetCharacterMoveCheck({ Dir.x * _DeltaTime, Dir.z * _DeltaTime }, Collision);
	//if (Collision_TargetPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))
	//{
	//	if (Collision_TargetPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
	//	{
	//		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	//	}
	//}

	//const float4& Collision = Collision_TargetPos->GetTransform().GetWorldPosition();
	//const float4& Monster = GetTransform().GetWorldPosition();

	//float4 Dir = 0;
	//if (Collision.x - Monster.x > 0)
	//{
	//	Dir.x = 100.f;
	//}
	//else
	//{
	//	Dir.x = -100.f;
	//}

	//if (Collision.z - Monster.z > 0)
	//{
	//	Dir.z = 100.f;
	//}
	//else
	//{
	//	Dir.z = -100.f;
	//}

	Manager_MoveManager->SetCharacterMoveCheck({ Dir.x * _DeltaTime, Dir.z * _DeltaTime }, Collision);

}
void Light_archer::FSM_Move_Walk_End(const StateInfo& _Info)
{

}


void Light_archer::LevelStartEvent()
{

}