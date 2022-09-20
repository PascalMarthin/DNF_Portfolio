#include "PreCompile.h"
#include "Bale.h"
#include "GamePlayEnum.h"
#include "CharacterStatManager.h"
#include "MoveManager.h"
#include "GamePlayCharacter.h"
//#include <GameEngineCore/>

Bale::Bale() 
	: MoveDelay(0)
	//, TrackerPos(float4::ZERO)
	, Collision_TargetPos(nullptr)
	, Collision_ect(nullptr)
	, DashUpdate(false)
	, StayStandDelay(0)
	, BeforePos(float4::ZERO)
{
}

Bale::~Bale() 
{
}

void Bale::Start()
{
	GamePlayMonster::Start();

	Dummy = GetLevel()->CreateActor<DummyActor>();
	Enum_UnitType = UnitType::Unit;
	CreateMonsterStat(1115180000, 50, 301.4f); //1,115,180,000

	SetFSManager();

	Texture_Monster = CreateComponent<GameEngineTextureRenderer>();
	Texture_Monster->CreateFrameAnimationFolder("Bale_Standing", FrameAnimation_DESC("Bale", 0, 5, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Walk", FrameAnimation_DESC("Bale", 6, 13, 0.15f));
	Texture_Monster->ChangeCamera(CAMERAORDER::Object);
	
	{
		Texture_Monster->CreateFrameAnimationFolder("Bale_Sting", FrameAnimation_DESC("Bale", 14, 23, 0.1f, false));
		Texture_Monster->AnimationBindEnd("Bale_Sting", std::bind(&Bale::Sting_End, this, std::placeholders::_1));

	}


	Texture_Monster->CreateFrameAnimationFolder("Bale_Hit1", FrameAnimation_DESC("Bale", 24, 24, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hit2", FrameAnimation_DESC("Bale", 25, 25, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_HitDown", FrameAnimation_DESC("Bale", 26, 30, 0.1f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Down", FrameAnimation_DESC("Bale", 30, 30, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Sit", FrameAnimation_DESC("Bale", 31, 31, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Stand_Up", FrameAnimation_DESC("Bale", 30, 31, 0.08f, false));
	Texture_Monster->AnimationBindEnd("Bale_Stand_Up", std::bind(&Bale::Ani_StandUp, this, std::placeholders::_1));
	{
		Texture_Monster->CreateFrameAnimationFolder("Bale_Stamping", FrameAnimation_DESC("Bale", 32, 36, 0.125f, false));
		Texture_Monster->AnimationBindEnd("Bale_Stamping", std::bind(&Bale::Bale_Stamping, this, std::placeholders::_1));

	}


	Texture_Monster->CreateFrameAnimationFolder("Bale_Grap", FrameAnimation_DESC("Bale", 37, 38, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hold", FrameAnimation_DESC("Bale", 39, 39, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Press", FrameAnimation_DESC("Bale", 40, 44, 0.08f, false));


	{
		Texture_Monster->CreateFrameAnimationFolder("Bale_RunReady", FrameAnimation_DESC("Bale", 45, 46, 0.125f, false));
		Texture_Monster->CreateFrameAnimationFolder("Bale_Running", FrameAnimation_DESC("Bale", 47, 48, 0.1f));
		Texture_Monster->CreateFrameAnimationFolder("Bale_RunEnd", FrameAnimation_DESC("Bale", 49, 50, 0.25f, false));

		Texture_Monster->AnimationBindEnd("Bale_RunReady", std::bind(&Bale::Bale_DashStart, this, std::placeholders::_1));
		Texture_Monster->AnimationBindEnd("Bale_RunEnd", std::bind(&Bale::Bale_BackToNone, this, std::placeholders::_1));

	}

	{
		Texture_Monster->CreateFrameAnimationFolder("Bale_Teleport_Before", FrameAnimation_DESC("Bale", 45, 47, 0.1f, false));
		Texture_Monster->CreateFrameAnimationFolder("Bale_Teleport_After", FrameAnimation_DESC("Bale", 48, 50, 0.1f, false));

		Texture_Monster->AnimationBindEnd("Bale_Teleport_Before", std::bind(&Bale::Bale_TeleportStart, this, std::placeholders::_1));
		Texture_Monster->AnimationBindEnd("Bale_Teleport_After", std::bind(&Bale::Bale_BackToNone, this, std::placeholders::_1));

	}


	Texture_Monster->GetTransform().SetLocalPosition({ 72, 12, 10 }); // 중앙 기준
	Texture_Monster->GetTransform().SetLocalScale({454, 340, 100});
	Texture_Monster->ChangeFrameAnimation("Bale_Standing");

	Collision_HitBody_Mid = CreateComponent<GameEngineCollision>();
	Collision_HitBody_Mid->GetTransform().SetLocalScale({ 80, 50, 50 });
	Collision_HitBody_Mid->GetTransform().SetLocalPosition({ 0, 0, 0 });
	Collision_HitBody_Mid->ChangeOrder(CollisionOrder::Monster);
	Collision_HitBody_Mid->SetDebugSetting(CollisionType::CT_AABB, { 1, 1 , 0, 0.5 });

	Collision_HitBody_Top = CreateComponent<GameEngineCollision>();
	Collision_HitBody_Top->GetTransform().SetLocalScale({ 80, 50, 30 });
	Collision_HitBody_Top->GetTransform().SetLocalPosition({ 0, 50, 0 });
	Collision_HitBody_Top->ChangeOrder(CollisionOrder::Monster);
	Collision_HitBody_Top->SetDebugSetting(CollisionType::CT_AABB, {0, 1 , 1, 0.5});


	Collision_HitBody_Bottom = CreateComponent<GameEngineCollision>();
	Collision_HitBody_Bottom->GetTransform().SetLocalScale({ 80, 50, 30 });
	Collision_HitBody_Bottom->GetTransform().SetLocalPosition({ 0, -50, 0 });
	Collision_HitBody_Bottom->ChangeOrder(CollisionOrder::Monster);
	Collision_HitBody_Bottom->SetDebugSetting(CollisionType::CT_AABB, { 1, 0 , 1, 0.5 });
	//Collision_HitBody_Top->Off();



	Collision_HitBody_Bottom = CreateComponent<GameEngineCollision>();
	Collision_HitBody_Bottom->GetTransform().SetLocalScale({ 80, 50, 30 });
	Collision_HitBody_Bottom->GetTransform().SetLocalPosition({ 0, -50, 0 });
	Collision_HitBody_Bottom->ChangeOrder(CollisionOrder::Monster);
	Collision_HitBody_Bottom->SetDebugSetting(CollisionType::CT_AABB, { 1, 0 , 1, 0.5f });


	{
		GameEngineCollision* Collision = CreateComponent<GameEngineCollision>("BaseHit_Area");
		Collision->GetTransform().SetLocalScale({ 300, 100, 250 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, { 0.5f, 0 , 0.8f, 0.3f });

		AllCollision["Att_Sting"] = Collision;

		Collision = CreateComponent<GameEngineCollision>("Dash_Area");
		Collision->GetTransform().SetLocalScale({ 550, 300, 200 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, { 0, 0.8f , 0.8f, 0.3f });

		AllCollision["Att_Dash"] = Collision;

		Collision = CreateComponent<GameEngineCollision>("Stamping_Area");
		Collision->GetTransform().SetLocalScale({ 200, 150, 100 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, { 0, 0.8f , 0.2f, 0.3f });

		AllCollision["Att_Stamping"] = Collision;



		Collision = CreateComponent<GameEngineCollision>("Teleport_Area");
		Collision->GetTransform().SetLocalScale({ 400, 150, 200 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, { 0.2f, 0.5f , 0.6f, 0.3f });

		AllCollision["Move_Teleport"] = Collision;

	}


	{
		//Collision_ect
	}

	{
		Collision_TargetPos = CreateComponent<GameEngineCollision>("TargetPos");
		Collision_TargetPos->GetTransform().SetLocalScale({ 25, 10, 10 });
		Collision_TargetPos->ChangeOrder(CollisionOrder::Monster_Tarcking);
		Collision_TargetPos->SetDebugSetting(CollisionType::CT_SPHERE, { 0.5f, 0 , 0.8f, 0.3f });
	}



	SetMonsterName("증오의 베일");
	SetCategory(MonsterCategory::Human);
	SetCategory(MonsterCategory::Machine);


	CharacterWeight = 500.f;



	{
		All_CollTime["Att_Sting"] = 0;
		All_CollTime["Att_Dash"] = 0;
		All_CollTime["Att_Stamping"] = 0;
		All_CollTime["Move_Teleport"] = 0;
	}
	SetMonsterClass(MonsterClass::Named);
}

void Bale::Update(float _DeltaTime)
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
			if (!AllCollision[Collision]->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
			{
				Collision = "None";
				continue;
			}
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

	//GameEngineDebug::OutPutString(std::to_string(Collision_HitBody_Top->GetTransform().GetLocalScale().z));
}

void Bale::CheckDir()
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

void Bale::SetFSManager()
{

	Manager_StatManager->GetFSMManager().CreateStateMember
	("None", [=](float _DeltaTime, const StateInfo& _Info)
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		});


	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Stand", std::bind(&Bale::FSM_Move_Stand_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Move_Stand_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Move_Stand_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Stand", std::bind(&Bale::FSM_Hit_Stand_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Hit_Stand_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Hit_Stand_End, this, std::placeholders::_1));
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Aerial", std::bind(&Bale::FSM_Hit_Aerial_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Hit_Aerial_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Hit_Aerial_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Aerial_GoingDown", std::bind(&Bale::FSM_Hit_Aerial_DoingDown_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Hit_Aerial_DoingDown_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Hit_Aerial_DoingDown_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Hit_Down", std::bind(&Bale::FSM_Hit_Down_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Hit_Down_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Hit_Down_End, this, std::placeholders::_1));


	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Walk", std::bind(&Bale::FSM_Move_Walk_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Move_Walk_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Move_Walk_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_Sting", std::bind(&Bale::FSM_Att_Sting_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Att_Sting_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Att_Sting_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_Stamping", std::bind(&Bale::FSM_Att_Stamping_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Att_Stamping_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Att_Stamping_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_Dash", std::bind(&Bale::FSM_Att_Dash_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Att_Dash_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Att_Dash_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Move_Teleport", std::bind(&Bale::FSM_Move_Teleport_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Move_Teleport_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Move_Teleport_End, this, std::placeholders::_1));
	

	
	Manager_StatManager->GetFSMManager().ChangeState("None");
}

void Bale::Bale_BackToNone(const FrameAnimation_DESC& _DESC)
{
	Manager_StatManager->GetFSMManager().ChangeState("None");
}


void Bale::FSM_Move_Stand_Start(const StateInfo& _Info)
{
	if (_Info.PrevState == "Hit_Down")
	{
		Texture_Monster->ChangeFrameAnimation("Bale_Stand_Up");
	}
	else
	{
		Texture_Monster->ChangeFrameAnimation("Bale_Standing");
	}

	if (GameEngineRandom::MainRandom.RandomInt(0, 3) > 2)
	{
		Collision_TargetPos->SetParent(Dummy);
		const float4& Pos = GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition();
		Collision_TargetPos->GetTransform().SetWorldPosition({ Pos.x , Pos.z, Pos.z });
	}
	
	StayStandDelay = 1.5f;
}
void Bale::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	//if (Collision_TargetPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))
	//{

	//}
	//else
	//{
	StayStandDelay -= _DeltaTime;
	if (StayStandDelay <= 0)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Walk");
		return;
	}

	if (!Collision_TargetPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Walk"); // 중단점 용
		return;
	}
		
	//}
}
void Bale::FSM_Move_Stand_End(const StateInfo& _Info)
{

}

void Bale::FSM_Hit_Stand_Start(const StateInfo& _Info)
{
	if (_Info.PrevState == "Hit_Stand" && GameEngineRandom::MainRandom.RandomInt(0, 1) == 1)
	{
		Texture_Monster->ChangeFrameAnimation("Bale_Hit2");
	}
	else
	{
		Texture_Monster->ChangeFrameAnimation("Bale_Hit1");
	}
	
}
void Bale::FSM_Hit_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Manager_StatManager->IsAction())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void Bale::FSM_Hit_Stand_End(const StateInfo& _Info)
{

}

void Bale::FSM_Hit_Aerial_Start(const StateInfo& _Info)
{
	Manager_MoveManager->SetAerial();
	Manager_StatManager->SetAerial();
	Texture_Monster->ChangeFrameAnimation("Bale_Hit1");
	JumpGoingDown = false;
}
void Bale::FSM_Hit_Aerial_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (JumpGoingDown == true)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Hit_Aerial_GoingDown");
	}
}
void Bale::FSM_Hit_Aerial_End(const StateInfo& _Info)
{
	JumpGoingDown = false;
}

void Bale::FSM_Hit_Aerial_DoingDown_Start(const StateInfo& _Info)
{
	Texture_Monster->ChangeFrameAnimation("Bale_HitDown");
	Collision_HitBody_Top->Off();
	GoingDownTime = 0.f;
}
void Bale::FSM_Hit_Aerial_DoingDown_Update(float _DeltaTime, const StateInfo& _Info)
{
	GoingDownTime += _DeltaTime;

	if (!Manager_StatManager->IsAerial())
	{
		Manager_StatManager->SetDown();
	}
	
}
void Bale::FSM_Hit_Aerial_DoingDown_End(const StateInfo& _Info)
{
	Collision_HitBody_Top->On();
	GoingDownTime = 0.f;
}


void Bale::Ani_StandUp(const FrameAnimation_DESC&)
{
	Texture_Monster->ChangeFrameAnimation("Bale_Standing");
}


void Bale::LandingEnd()
{
	Manager_StatManager->SetAerialEnd();
}



void Bale::FSM_Hit_Down_Start(const StateInfo& _Info)
{
	Texture_Monster->ChangeFrameAnimation("Bale_Down");
	Collision_HitBody_Top->Off();
	Collision_HitBody_Mid->Off();
	DownWait = 0.6f;
}
void Bale::FSM_Hit_Down_Update(float _DeltaTime, const StateInfo& _Info)
{
	DownWait -= _DeltaTime;
	if (DownWait <= 0.f)
	{
		Manager_StatManager->SetDownEnd();
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void Bale::FSM_Hit_Down_End(const StateInfo& _Info)
{
	Collision_HitBody_Top->On();
	Collision_HitBody_Mid->On();
	DownWait = 0.f;
}


void Bale::FSM_Move_Walk_Start(const StateInfo& _Info)
{
	MoveDelay = 0;
	Texture_Monster->ChangeFrameAnimation("Bale_Walk", true);
	Collision_TargetPos->SetParent(GamePlayCharacter::GetInst());
	Collision_TargetPos->GetTransform().SetLocalPosition(float4::ZERO);
}
void Bale::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
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
		Pos.x += GameEngineRandom::MainRandom.RandomFloat(-2.f, 2.f) * 25.f ;
		//Pos.y += GameEngineRandom::MainRandom.RandomFloat(-2.f, 2.f) * 15.f ;


		

		if (Pos.x >= 0)
		{
			Pos.x += 200.f;
		}
		else
		{
			Pos.x -= 200.f;
		}

		//if (Pos.y >= 0)
		//{
		//	Pos.y += 25.f;
		//}
		//else
		//{
		//	Pos.y -= 25.f;
		//}


		Collision_TargetPos->GetTransform().SetLocalPosition(Pos);
		MoveDelay = 2.f;
	}


	//if (GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition().z <= GetTransform().GetWorldPosition().z)
	//{
	//	GetTransform().PixLocalPositiveX();
	//}
	//else 
	//{
	//	GetTransform().PixLocalNegativeX();
	//}
	//
	// 마주보기

	
	const float4& Collision = Collision_TargetPos->GetTransform().GetWorldPosition();
	const float4& Monster = GetTransform().GetWorldPosition();

	float4 Dir = 0;
	if (Collision_TargetPos->GetTransform().GetWorldPosition().x - GetTransform().GetWorldPosition().x > 0)
	{
		Dir.x = 180.f;
	}
	else
	{
		Dir.x = -180.f;
	}

	if (Collision_TargetPos->GetTransform().GetWorldPosition().z - GetTransform().GetWorldPosition().z > 0)
	{
		Dir.z = 180.f;
	}
	else
	{
		Dir.z = -180.f;
	}
	
	Manager_MoveManager->SetCharacterMove({ Dir.x * _DeltaTime, Dir.z * _DeltaTime });
	
}
void Bale::FSM_Move_Walk_End(const StateInfo& _Info)
{
	MoveDelay = 0;
}

void Bale::FSM_Att_Sting_Start(const StateInfo& _Info)
{			  
	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_Sting");
}
void Bale::FSM_Att_Sting_Update(float _DeltaTime, const StateInfo& _Info)
{

}
void Bale::FSM_Att_Sting_End(const StateInfo& _Info)
{
	All_CollTime["Att_Sting"] = 2.f;
	Manager_StatManager->SetDoSkillEnd();
}


void Bale::Sting_End(const FrameAnimation_DESC& _DESC)
{
	Manager_StatManager->GetFSMManager().ChangeState("None");
}

void Bale::FSM_Att_Stamping_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_Stamping");
}
void Bale::FSM_Att_Stamping_Update(float _DeltaTime, const StateInfo& _Info)
{

}
void Bale::FSM_Att_Stamping_End(const StateInfo& _Info)
{
	All_CollTime["Att_Stamping"] = 3.f;
	Manager_StatManager->SetDoSkillEnd();
}

void Bale::Bale_Stamping(const FrameAnimation_DESC& _DESC)
{
	Manager_StatManager->GetFSMManager().ChangeState("None");
}


void Bale::FSM_Att_Dash_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_RunReady");

	Collision_ect = CreateComponent<GameEngineCollision>("Dash");
	Collision_ect->SetParent(Dummy);
	Collision_ect->GetTransform().SetLocalScale({ 25, 25, 25 });

	//const float4& Pos = GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition();

	float4 Dir = GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition() - GetTransform().GetWorldPosition();

	if (Dir.x <= 600.f && Dir.x > 0)
	{
		Dir.x = 600.f;
	}
	else if (Dir.x > -600.f && Dir.x < 0)
	{
		Dir.x = -600.f;
	}

	if (Dir.z > 100.f)
	{
		Dir.z = 100.f;
	}
	else if (Dir.z < -100.f)
	{
		Dir.z = -100.f;
	}

	if (Dir.z > 0 && Dir.z < 20.f)
	{
		Dir.z = 20.f;
	}
	else if (Dir.z < 0 && Dir.z > -20.f)
	{
		Dir.z = -20.f;
	}

	Collision_ect->GetTransform().SetWorldPosition({ Dir.x + GetTransform().GetWorldPosition().x, Dir.z + GetTransform().GetWorldPosition().y, Dir.z + GetTransform().GetWorldPosition().z });
	DashUpdate = false;
	MoveDelay = 0;

}


void Bale::Bale_DashStart(const FrameAnimation_DESC& _DESC)
{
	Texture_Monster->ChangeFrameAnimation("Bale_Running");
	DashUpdate = true;
	BeforePos = GetTransform().GetWorldPosition();
	// 마구 베면서 전진
}



void Bale::FSM_Att_Dash_Update(float _DeltaTime, const StateInfo& _Info)
{

	if (DashUpdate == true)
	{
		MoveDelay += _DeltaTime * 1.5f;
		float4 Move = float4::LerpLimit(BeforePos, Collision_ect->GetTransform().GetWorldPosition(), MoveDelay);
		Move -= GetTransform().GetWorldPosition();
		Manager_MoveManager->SetCharacterMove({ Move.x, Move.y });
	}

	if (Collision_ect->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))
	{
		Texture_Monster->ChangeFrameAnimation("Bale_RunEnd");
	}
	//Bale_RunReady
	//	Bale_Running"
	//	Bale_RunEnd",
}

void Bale::FSM_Att_Dash_End(const StateInfo& _Info)
{
	All_CollTime["Att_Dash"] = 10.f;
	DashUpdate = false;
	BeforePos = float4::ZERO;
	{
		Collision_ect->Death();
		Collision_ect = nullptr;
	}

	Manager_StatManager->SetDoSkillEnd();

}


void Bale::FSM_Move_Teleport_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoSkill();
	AllCollision["Move_Teleport"]->SetParent(GamePlayCharacter::GetInst());

	if (AllCollision["Move_Teleport"]->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))
	{
		Manager_StatManager->GetFSMManager().ChangeState("None");
		All_CollTime["Move_Teleport"] = 2.f;
	}
	else
	{
		Texture_Monster->ChangeFrameAnimation("Bale_Teleport_Before"); // 중단점용
	}
}
void Bale::Bale_TeleportStart(const FrameAnimation_DESC& _DESC)
{

	Texture_Monster->ChangeFrameAnimation("Bale_Teleport_After");

	const float4& PlayerPos = GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition();
	float4 Pos = 0;
	Pos.x += GameEngineRandom::MainRandom.RandomFloat(-2.f, 2.f) * 25.f;
	Pos.z += GameEngineRandom::MainRandom.RandomFloat(-2.f, 2.f) * 15.f;

	GetTransform().SetLocalPosition({ GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition().x + Pos.x , PlayerPos.z + Pos.z, PlayerPos.z + Pos.z});

}

void Bale::FSM_Move_Teleport_Update(float _DeltaTime, const StateInfo& _Info)
{

}
void Bale::FSM_Move_Teleport_End(const StateInfo& _Info)
{
	All_CollTime["Move_Teleport"] = 10.f;
	All_CollTime["Att_Dash"] += 5.f;
	Manager_StatManager->SetDoSkillEnd();

}
void Bale::LevelStartEvent()
{
	All_CollTime["Move_Teleport"] = 10.f;
	All_CollTime["Att_Dash"] = 10.f;
}
