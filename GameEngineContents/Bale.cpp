#include "PreCompile.h"
#include "Bale.h"
#include "GamePlayEnum.h"
#include "CharacterStatManager.h"
#include "MoveManager.h"
//#include <GameEngineCore/>

Bale::Bale() 
{
}

Bale::~Bale() 
{
}

void Bale::Start()
{
	GamePlayMonster::Start();
	Enum_UnitType = UnitType::Unit;
	CreateMonsterStat(100000000, 50);

	SetFSManager();

	Texture_Monster = CreateComponent<GameEngineTextureRenderer>();
	Texture_Monster->CreateFrameAnimationFolder("Bale_Standing", FrameAnimation_DESC("Bale", 0, 5, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Walk", FrameAnimation_DESC("Bale", 6, 13, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Sting", FrameAnimation_DESC("Bale", 14, 23, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hit1", FrameAnimation_DESC("Bale", 24, 24, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hit2", FrameAnimation_DESC("Bale", 25, 25, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_HitDown", FrameAnimation_DESC("Bale", 26, 30, 0.1f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Down", FrameAnimation_DESC("Bale", 30, 30, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Sit", FrameAnimation_DESC("Bale", 31, 31, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Stand_Up", FrameAnimation_DESC("Bale", 30, 31, 0.08f, false));
	Texture_Monster->AnimationBindEnd("Bale_Stand_Up", std::bind(&Bale::Ani_StandUp, this, std::placeholders::_1));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Stamping", FrameAnimation_DESC("Bale", 32, 36, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Grap", FrameAnimation_DESC("Bale", 37, 38, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hold", FrameAnimation_DESC("Bale", 39, 39, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Press", FrameAnimation_DESC("Bale", 40, 45, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_RunReady", FrameAnimation_DESC("Bale", 46, 47, 0.2f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Running", FrameAnimation_DESC("Bale", 48, 49, 0.1f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_RunEnd", FrameAnimation_DESC("Bale", 50, 50, 0.1f, false));


	Texture_Monster->GetTransform().SetLocalPosition({ 72, 12, 10 }); // Áß¾Ó ±âÁØ
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

	CharacterWeight = 500.f;
}

void Bale::Update(float _DeltaTime)
{
	//GameEngineDebug::OutPutString(std::to_string(Collision_HitBody_Top->GetTransform().GetLocalScale().z));
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
}
void Bale::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Texture_Monster)
	{

	}
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