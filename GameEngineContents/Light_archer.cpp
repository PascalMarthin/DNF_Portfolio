#include "PreCompile.h"
#include "Light_archer.h"
#include "MoveManager.h"
#include "GamePlayCharacter.h"
#include "BattleLevel.h"
#include "GamePlaySkill.h"
#include "GamePlayComboSystem.h"

Light_archer::Light_archer() 
	: MoveDelay(0)
	, Collision_GoPos(nullptr)
	, Collision_PlayerLessPos(nullptr)
	, Collision_PlayerMaxPos(nullptr)
	, Texture_Eff(nullptr)
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

	SetMonsterName("ºûÀÇ ±Ã»ç");
	SetCategory(MonsterCategory::Soul);
	//SetCategory(MonsterCategory::Machine);

	Texture_Monster = CreateComponent<GameEngineTextureRenderer>();
	Texture_Monster->CreateFrameAnimationFolder("Monster_Standing", FrameAnimation_DESC("light_archer_Body", 0, 3, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Monster_Walk", FrameAnimation_DESC("light_archer_Body", 0, 3, 0.15f));

	Texture_Monster->CreateFrameAnimationFolder("Monster_Down", FrameAnimation_DESC("light_archer_Body", 38, 38, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Monster_GoingDown", FrameAnimation_DESC("light_archer_Body", 35, 36, 0.125f, false));
	Texture_Monster->CreateFrameAnimationFolder("Monster_Hit1", FrameAnimation_DESC("light_archer_Body", 34, 34, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Monster_Hit2", FrameAnimation_DESC("light_archer_Body", 35, 35, 0.15f, false));


	Texture_Monster->CreateFrameAnimationFolder("Monster_Att", FrameAnimation_DESC("light_archer_Body", 38, 47, 0.125f, false));
	Texture_Monster->AnimationBindFrame("Monster_Att", std::bind(&Light_archer::Att_ShootFrame, this, std::placeholders::_1));
	Texture_Monster->AnimationBindEnd("Monster_Att", std::bind(&Light_archer::Bale_BackToNone, this, std::placeholders::_1));


	Texture_Eff = CreateComponent<GameEngineTextureRenderer>();
	Texture_Eff->CreateFrameAnimationFolder("Monster_Standing", FrameAnimation_DESC("light_archer_Eff", 0, 3, 0.15f));
	Texture_Eff->CreateFrameAnimationFolder("Monster_Walk", FrameAnimation_DESC("light_archer_Eff", 0, 3, 0.15f));

	Texture_Eff->CreateFrameAnimationFolder("Monster_Down", FrameAnimation_DESC("light_archer_Eff", 38, 38, 0.15f, false));
	Texture_Eff->CreateFrameAnimationFolder("Monster_GoingDown", FrameAnimation_DESC("light_archer_Eff", 35, 36, 0.125f, false));
	Texture_Eff->CreateFrameAnimationFolder("Monster_Hit1", FrameAnimation_DESC("light_archer_Eff", 34, 34, 0.15f, false));
	Texture_Eff->CreateFrameAnimationFolder("Monster_Hit2", FrameAnimation_DESC("light_archer_Eff", 35, 35, 0.15f, false));

	Texture_Eff->CreateFrameAnimationFolder("Monster_Att", FrameAnimation_DESC("light_archer_Eff", 38, 47, 0.125f, false));
	Texture_Eff->AnimationBindFrame("Monster_Att", std::bind(&Light_archer::Att_ShootFrame, this, std::placeholders::_1));
	Texture_Eff->AnimationBindEnd("Monster_Att", std::bind(&Light_archer::Bale_BackToNone, this, std::placeholders::_1));

	Texture_Eff->ChangeFrameAnimation("Monster_Walk");
	Texture_Eff->ScaleToTexture();
	Texture_Eff->GetTransform().SetLocalPosition({ 0, 10, 0 });

	Texture_Monster->ChangeFrameAnimation("Monster_Walk");
	Texture_Monster->ScaleToTexture();

	Texture_Monster->GetTransform().SetLocalPosition({ 0, 10, 0 });

	Collision_HitBody = CreateComponent<GameEngineCollision>();
	Collision_HitBody->GetTransform().SetLocalScale({ 80, 150, 50 });
	Collision_HitBody->ChangeOrder(CollisionOrder::Monster);


	GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale({ 800, 200, 200 });
	Collision->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO);
	Collision->GetTransform().SetLocalPosition({ 200, 0, 0 });
	Collision->ChangeOrder(CollisionOrder::Monster_Att);
	AllCollision["Att_Shoot"] = Collision;
	All_CollTime["Att_Shoot"] = 0;


	Collision_PlayerLessPos = CreateComponent<GameEngineCollision>();
	Collision_PlayerLessPos->GetTransform().SetLocalScale({ 500, 200, 200 });
	Collision_PlayerLessPos->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO);

	Collision_PlayerMaxPos = CreateComponent<GameEngineCollision>();
	Collision_PlayerMaxPos->GetTransform().SetLocalScale({ 900, 400, 400 });
	Collision_PlayerMaxPos->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO);

	Collision_GoPos = CreateComponent<GameEngineCollision>();
	Collision_GoPos->GetTransform().SetLocalScale({ 50, 50, 50 });
	Collision_GoPos->SetDebugSetting(CollisionType::CT_AABB, float4::WHITE);

	Collision_GoPos->SetParent(Actor_Dummy);

	Texture_Thumbnail = GameEngineTexture::Find("light_archer_25.png");

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

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Att_Shoot", std::bind(&Light_archer::FSM_Att_Shoot_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Light_archer::FSM_Att_Shoot_Start, this, std::placeholders::_1)
		, std::bind(&Light_archer::FSM_Att_Shoot_End, this, std::placeholders::_1));


	
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
			if (!AllCollision[Collision]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB))
			{
				Collision = "None";
				continue;
			}
		}

		int RandomIndex = GameEngineRandom::MainRandom.RandomInt(-100, static_cast<int>(CanSkill.size()) - 1);


		if (RandomIndex >= 0)
		{
			if (CanSkill[RandomIndex] != "None" && GamePlayCharacter::GetInst()->GetStatManager()->IsLive())
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
	Texture_Eff->ChangeFrameAnimation("Monster_Standing");
	Texture_Monster->ChangeFrameAnimation("Monster_Standing");
	
	StayStandDelay = 0.5f;
}
void Light_archer::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{

	StayStandDelay -= _DeltaTime;
	if (StayStandDelay <= 0)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Walk");
		return;
	}

	//if (!Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
	//{
	//	Manager_StatManager->GetFSMManager().ChangeState("Move_Walk"); // Áß´ÜÁ¡ ¿ë
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
		Texture_Eff->ChangeFrameAnimation("Monster_Hit2");
	}
	else
	{
		Texture_Monster->ChangeFrameAnimation("Monster_Hit1");
		Texture_Eff->ChangeFrameAnimation("Monster_Hit1");
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
	Texture_Eff->ChangeFrameAnimation("Monster_Hit1");
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
	Texture_Eff->ChangeFrameAnimation("Monster_GoingDown");
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
	Texture_Eff->ChangeFrameAnimation("Monster_Down");
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
	Texture_Eff->ChangeFrameAnimation("Monster_Walk", true);
	const float4& PlayerPos = GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition();

	if (Collision_PlayerMaxPos->IsCollision(CollisionType::CT_AABB,CollisionOrder::Player, CollisionType::CT_AABB))
	{
		float indexX = 0;
		if (PlayerPos.x > GetTransform().GetWorldPosition().x)
		{
			indexX = 1.f;
		}
		else
		{
			indexX = -1.f;
		}
		float indexY = 0;
		if (PlayerPos.y > GetTransform().GetWorldPosition().y)
		{
			indexY = 1.f;
		}
		else
		{
			indexY = -1.f;
		}

		float RandomIndex = GameEngineRandom::MainRandom.RandomFloat(-1.f + PlayerPos.NormalizeReturn().y, 1.f + PlayerPos.NormalizeReturn().y);
		
		if (Collision_PlayerLessPos->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB))
		{
			Collision_GoPos->GetTransform().SetWorldPosition({ PlayerPos.x + (indexX * -300.f * RandomIndex), PlayerPos.y + (indexY * -300.f * RandomIndex),  PlayerPos.y + (indexY * -300.f * RandomIndex) });
		}
		else
		{
			Collision_GoPos->GetTransform().SetWorldPosition({ PlayerPos.x + (indexX * 300.f * RandomIndex), PlayerPos.y + (indexY * 300.f * RandomIndex),  PlayerPos.y + (indexY * 300.f * RandomIndex) });
		}
	}
	else
	{
		Collision_GoPos->GetTransform().SetWorldPosition(PlayerPos);
	}

	//float Len = 0;
	//if (PlayerPos.x >= GetTransform().GetWorldPosition().x)
	//{

	//	Len = 10.f ;
	//}
	//else
	//{
	//	Len = -10.f;
	//}

	//
	//float4 Pos = float4::ZERO;

	//Pos.x = GetTransform().GetWorldPosition().x;
	//Pos.y = GetTransform().GetWorldPosition().y;
	//Pos.Normalize();
	//Pos.x += GameEngineRandom::MainRandom.RandomFloat(-1.f + Len + Pos.x + Pos.y, 1.f + Len + Pos.x + Pos.y) * 15.f;


	//if (PlayerPos.y >= GetTransform().GetWorldPosition().y)
	//{
	//	Len = 10.f;
	//}
	//else
	//{
	//	Len = -10.f;
	//}
	//Pos.y += GameEngineRandom::MainRandom.RandomFloat(-1.f + Len + Pos.y, 1.f + Len + Pos.y) * 10.f;


	//Collision_PlayerLessPos->GetTransform().SetLocalPosition({ Pos.x , Pos.y, Pos.y });
	MoveDelay = 1.0f;
}
void Light_archer::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
{
	MoveDelay -= _DeltaTime;
	if (MoveDelay <= 0 /*|| (Collision_GoPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))*/)
	{
		if (GameEngineRandom::MainRandom.RandomFloat(GetTransform().GetWorldPosition().NormalizeReturn().y, -GetTransform().GetWorldPosition().NormalizeReturn().y) > 0)
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Walk");
		}
		else
		{
			Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
		}
	}

	const float4& Collision = Collision_GoPos->GetTransform().GetWorldPosition();
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
	//if (Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))
	//{
	//	if (Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
	//	{
	//		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	//	}
	//}

	//const float4& Collision = Collision_PlayerLessPos->GetTransform().GetWorldPosition();
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


	if ((Manager_MoveManager->SetCharacterMoveCheck({ Dir.x * _DeltaTime, Dir.z * _DeltaTime }, Collision) * 10.f).CompareInt3D(float4::ZERO))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}

}
void Light_archer::FSM_Move_Walk_End(const StateInfo& _Info)
{

}


void Light_archer::LevelStartEvent()
{

}

void Light_archer::FSM_Att_Shoot_Start(const StateInfo& _Info)
{
	Texture_Monster->ChangeFrameAnimation("Monster_Att", true);
	Texture_Eff->ChangeFrameAnimation("Monster_Att", true);
	Manager_StatManager->SetDoSkill();
	NearMiss = false;
	Actor_SpeechPopUp->CreatePopup("ºûÀÌ¿©...");
}
void Light_archer::FSM_Att_Shoot_Update(float _DeltaTime, const StateInfo& _Info)
{

}
void Light_archer::Att_ShootFrame(const FrameAnimation_DESC& _DESC)
{
	//Texture_Monster->AnimationBindFrame("Monster_Att", std::bind(&Light_archer::Att_ShootFrame, this, std::placeholders::_1));
	// 38, 47
	// 44
	switch (_DESC.CurFrame)
	{
	case 7:
	{
		
		if (Collision_Arrow == nullptr)
		{
			Collision_Arrow = CreateComponent<GameEngineCollision>();
			Collision_Arrow->GetTransform().SetLocalScale({ 50, 50, 200 });
			Collision_Arrow->ChangeOrder(CollisionOrder::Monster_Att);
			Collision_Arrow->SetParent(Actor_Dummy);
		}
		Collision_Arrow->On();
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetTransform().SetWorldPosition({ GetTransform().GetWorldPosition().x + (GetTransform().GetLocalScale().x < 0 ? -50.f : 50.f), GetTransform().GetWorldPosition().y + 80.f, GetTransform().GetWorldPosition().z});
		if (GetTransform().GetLocalScale().x < 0)
		{
			Renderer->GetTransform().PixLocalNegativeX();
		}
		Renderer->CreateFrameAnimationFolder("BaseArrow", FrameAnimation_DESC("BaseArrow", 0.125f, true));
		Renderer->AnimationBindTime("BaseArrow", std::bind(&Light_archer::Att_ArrowUpdate, this, std::placeholders::_1, std::placeholders::_2));
		Renderer->ChangeFrameAnimation("BaseArrow");
		Renderer->ScaleToTexture();
		Renderer->Death(5.f);

	}
		// ½´ÆÃ
		break;

	default:
		break;
	}
}

void Light_archer::Att_ArrowUpdate(const FrameAnimation_DESC& _DESC, float _Time)
{

	if (_DESC.Renderer->GetTransform().GetWorldScale().x < 0)
	{
		_DESC.Renderer->GetTransform().SetLocalMove({ -500 * _Time, 0 });
	}
	else
	{
		_DESC.Renderer->GetTransform().SetLocalMove({ 500 * _Time, 0 });
	}
	Collision_Arrow->GetTransform().SetWorldPosition(_DESC.Renderer->GetTransform().GetWorldPosition());
	if (Collision_Arrow->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB, std::bind(&GamePlayMonster::GetTarget, this, std::placeholders::_1, std::placeholders::_2)))
	{
		NearMiss = false;
		switch (GameEngineRandom::MainRandom.RandomInt(0, 9))
		{
		case 0:
			GameEngineSound::SoundPlayControl("mon_bow_hit_01.ogg").Volume(0.8f);
			break;								 
		case 1:									
			GameEngineSound::SoundPlayControl("mon_bow_hit_02.ogg").Volume(0.8f);
			break;								  
		case 2:									   
			GameEngineSound::SoundPlayControl("mon_bow_hit_03.ogg").Volume(0.8f);
			break;								
		case 3:									 
			GameEngineSound::SoundPlayControl("mon_bow_hit_04.ogg").Volume(0.8f);
			break;								  
		case 4:									 
			GameEngineSound::SoundPlayControl("mon_bow_hit_05.ogg").Volume(0.8f);
			break;								 
		case 5:									 
			GameEngineSound::SoundPlayControl("mon_bow_hit_06.ogg").Volume(0.8f);
			break;								 
		case 6:									
			GameEngineSound::SoundPlayControl("mon_bow_hit_07.ogg").Volume(0.8f);
			break;								 
		case 7:									
			GameEngineSound::SoundPlayControl("mon_bow_hit_08.ogg").Volume(0.8f);
			break;								 
		case 8:									 
			GameEngineSound::SoundPlayControl("mon_bow_hit_09.ogg").Volume(0.8f);
			break;

		default:
			break;
		}


		Player_Target->BeHit({ 20, 0, 0, 50 }, HitPostureType::Standing, nullptr, Player_Target, (GetTransform().GetWorldPosition().x > Player_Target->GetTransform().GetWorldPosition().x ? -1 : 1), 1000);
		_DESC.Renderer->Off();
		_DESC.Renderer->Death();
		Collision_Arrow->Off();
	}
	else if(Collision_Arrow->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player_NearMiss, CollisionType::CT_AABB))
	{
		NearMiss = true;
	}

	if (GetLevel<BattleLevel>()->GetCollisionMapTexture()->GetPixelToFloat4(GetTransform().GetWorldPosition().ix(), -(GetTransform().GetWorldPosition().iy())).CompareInt4D(float4::RED))
	{
		if (NearMiss == true)
		{
			GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::NearMiss);
		}
		_DESC.Renderer->Off();
		_DESC.Renderer->Death();
		Collision_Arrow->Off();
	}
}


void Light_archer::FSM_Att_Shoot_End(const StateInfo& _Info)
{
	Manager_StatManager->SetDoSkillEnd();
	All_CollTime["Att_Shoot"] = 5.f;
}