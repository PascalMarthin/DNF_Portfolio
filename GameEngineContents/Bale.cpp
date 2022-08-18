#include "PreCompile.h"
#include "Bale.h"
#include "GamePlayEnum.h"
#include "CharacterStatManager.h"
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
	Texture_Monster->CreateFrameAnimationFolder("Bale_HitDown", FrameAnimation_DESC("Bale", 26, 29, 0.07f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Down", FrameAnimation_DESC("Bale", 29, 29, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Sit", FrameAnimation_DESC("Bale", 30, 30, 0.05f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Stamping", FrameAnimation_DESC("Bale", 31, 35, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Grap", FrameAnimation_DESC("Bale", 36, 37, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hold", FrameAnimation_DESC("Bale", 38, 38, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Press", FrameAnimation_DESC("Bale", 39, 44, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_RunReady", FrameAnimation_DESC("Bale", 45, 46, 0.2f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Running", FrameAnimation_DESC("Bale", 47, 48, 0.1f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_RunEnd", FrameAnimation_DESC("Bale", 49, 49, 0.1f, false));


	Texture_Monster->GetTransform().SetLocalPosition({ 72, 12, 1 }); // Áß¾Ó ±âÁØ
	Texture_Monster->GetTransform().SetLocalScale({454, 340, 100});
	Texture_Monster->ChangeFrameAnimation("Bale_Standing");


	Collision_HitBody = CreateComponent<GameEngineCollision>();
	//Collision_HitBody->GetTransform().SetLocalPosition({0, 0, -1});
	Collision_HitBody->GetTransform().SetLocalScale({ 80, 150, 50 });
	Collision_HitBody->ChangeOrder(CollisionOrder::Monster);
	Collision_HitBody->SetDebugSetting(CollisionType::CT_AABB, {0, 0 , 0, 0});
	//Collision_HitBody->Off();
}

void Bale::Update(float _DeltaTime)
{
	//GameEngineDebug::OutPutString(std::to_string(Collision_HitBody->GetTransform().GetLocalScale().z));
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
	Texture_Monster->ChangeFrameAnimation("Bale_Standing");
}
void Bale::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{

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

}
void Bale::FSM_Hit_Stand_End(const StateInfo& _Info)
{

}

void Bale::FSM_Hit_Aerial_Start(const StateInfo& _Info)
{
	Texture_Monster->ChangeFrameAnimation("Bale_Hit1");
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

}

void Bale::FSM_Hit_Aerial_DoingDown_Start(const StateInfo& _Info)
{
	Texture_Monster->ChangeFrameAnimation("Bale_HitDown");
	GoingDownTime = 0.f;
}
void Bale::FSM_Hit_Aerial_DoingDown_Update(float _DeltaTime, const StateInfo& _Info)
{
	GoingDownTime += _DeltaTime;


	if (!Manager_StatManager->IsAerial())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Hit_Down");
	}
	
}
void Bale::FSM_Hit_Aerial_DoingDown_End(const StateInfo& _Info)
{
	//Texture_Monster->GetTransform().SetLocalPosition({ 0, 0, 0 });
	Texture_Monster->GetTransform().SetLocalRotation({ 0 , 0, 0, 0 });
	//Texture_Monster->GetTransform().SetLocalPosition({ 72, 12, 1 });
	GoingDownTime = 0.f;
}


void Bale::LandingEnd()
{
	Manager_StatManager->SetAerialEnd();
}

void Bale::FSM_Hit_Down_Start(const StateInfo& _Info)
{
	Texture_Monster->ChangeFrameAnimation("Bale_Down");
	DownWait = 0.6f;
}
void Bale::FSM_Hit_Down_Update(float _DeltaTime, const StateInfo& _Info)
{
	DownWait -= _DeltaTime;
	if (DownWait <= 0.f)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void Bale::FSM_Hit_Down_End(const StateInfo& _Info)
{
	DownWait = 0.f;
}