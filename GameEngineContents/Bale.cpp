#include "PreCompile.h"
#include "Bale.h"
#include "GamePlayEnum.h"
#include "CharacterStatManager.h"
#include "MoveManager.h"
#include "GamePlayCharacter.h"
#include "GamePlaySkill.h"
#include "GameEngineEffectRenderer.h"
#include "AvataManager.h"
#include "BaleTentacle.h"
#include "GamePlayMonsterHPBar.h"
//#include <GameEngineCore/>

Bale::Bale()
	: MoveDelay(0)
	//, TrackerPos(float4::ZERO)
	, Collision_PlayerLessPos(nullptr)
	, Collision_ect(nullptr)
	, DashUpdate(false)
	, StayStandDelay(0)
	, BeforePos(float4::ZERO)
	, Barrier_HP(0)
	, Barrier_CoolTime(0)
	, Barrier_On(false)
	, StampingEnd(false)
	, Texure_Barrier(nullptr)
	, Texture_StampingEffect(nullptr)
	, Texture_StampingEffect_Floor(nullptr)
	, Texture_SmokeEffect(nullptr)
	, Collision_StampingHit(nullptr)
	, Texure_Barrier_Effect_Front(nullptr)
	, Texure_Barrier_Effect_FrontDodge(nullptr)
	, Texure_Barrier_Effect_Back(nullptr)
	, Texure_Barrier_Effect_BackDodge(nullptr)
	, Hit_Player(nullptr)
	, Collision_StingHit(nullptr)
	, Texture_BlackBack(nullptr)
	, DashColorDelay(0)
	, Actor_TrackingObject(nullptr)
	, VisionDelay(0)
	, BringTentacleIndex(0)
	, Coliision_TentacleHit(nullptr)
{
}

Bale::~Bale() 
{
}

void Bale::Start()
{
	GamePlayMonster::Start();

	Enum_UnitType = UnitType::Unit;
	CreateMonsterStat(1115180000, 50, 301.4f); //1,115,180,000

	SetFSManager();

	Texture_Monster = CreateComponent<GameEngineTextureRenderer>();
	Texture_Monster->CreateFrameAnimationFolder("Bale_Standing", FrameAnimation_DESC("Bale", 0, 5, 0.15f));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Walk", FrameAnimation_DESC("Bale", 6, 13, 0.15f));
	
	{
		Texture_Monster->CreateFrameAnimationFolder("Bale_Sting", FrameAnimation_DESC("Bale", 14, 23, 0.1f, false));
		Texture_Monster->AnimationBindFrame("Bale_Sting", std::bind(&Bale::Sting_Update, this, std::placeholders::_1));
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
		Texture_Monster->AnimationBindFrame("Bale_Stamping", std::bind(&Bale::Bale_Stamping, this, std::placeholders::_1));

	}


	Texture_Monster->CreateFrameAnimationFolder("Bale_Grap", FrameAnimation_DESC("Bale", 37, 38, 0.08f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Hold", FrameAnimation_DESC("Bale", 39, 39, 0.15f, false));
	Texture_Monster->CreateFrameAnimationFolder("Bale_Press", FrameAnimation_DESC("Bale", 40, 44, 0.08f, false));


	{
		Texture_Monster->CreateFrameAnimationFolder("Bale_RunReady", FrameAnimation_DESC("Bale", 45, 46, 0.125f, false));
		Texture_Monster->CreateFrameAnimationFolder("Bale_Running", FrameAnimation_DESC("Bale", 47, 48, 0.1f));
		Texture_Monster->AnimationBindTime("Bale_Running", std::bind(&Bale::Bale_DashUpdate, this, std::placeholders::_1, std::placeholders::_2));
		Texture_Monster->AnimationBindFrame("Bale_Running", std::bind(&Bale::Bale_DashFrame, this, std::placeholders::_1));

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
	{

		Collision_HitBody_Mid = CreateComponent<GameEngineCollision>();
		Collision_HitBody_Mid->GetTransform().SetLocalScale({ 80, 50, 50 });
		Collision_HitBody_Mid->GetTransform().SetLocalPosition({ 0, 0, 0 });
		Collision_HitBody_Mid->ChangeOrder(CollisionOrder::Monster);
		Collision_HitBody_Mid->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO/*{ 1, 1 , 0, 0.5 }*/);

		Collision_HitBody_Top = CreateComponent<GameEngineCollision>();
		Collision_HitBody_Top->GetTransform().SetLocalScale({ 80, 50, 30 });
		Collision_HitBody_Top->GetTransform().SetLocalPosition({ 0, 50, 0 });
		Collision_HitBody_Top->ChangeOrder(CollisionOrder::Monster);
		Collision_HitBody_Top->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO/*{0, 1 , 1, 0.5}*/);


		Collision_HitBody_Bottom = CreateComponent<GameEngineCollision>();
		Collision_HitBody_Bottom->GetTransform().SetLocalScale({ 80, 50, 30 });
		Collision_HitBody_Bottom->GetTransform().SetLocalPosition({ 0, -50, 0 });
		Collision_HitBody_Bottom->ChangeOrder(CollisionOrder::Monster);
		Collision_HitBody_Bottom->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO/*{ 1, 0 , 1, 0.5 }*/);
		//Collision_HitBody_Top->Off();



		Collision_HitBody_Bottom = CreateComponent<GameEngineCollision>();
		Collision_HitBody_Bottom->GetTransform().SetLocalScale({ 80, 50, 30 });
		Collision_HitBody_Bottom->GetTransform().SetLocalPosition({ 0, -50, 0 });
		Collision_HitBody_Bottom->ChangeOrder(CollisionOrder::Monster);
		Collision_HitBody_Bottom->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO/*{ 1, 0 , 1, 0.5f }*/);
	}


	{
		GameEngineCollision* Collision = CreateComponent<GameEngineCollision>("BaseHit_Area");
		Collision->GetTransform().SetLocalScale({ 300, 300, 300 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, float4::ZERO/*{ 0.5f, 0 , 0.8f, 0.3f }*/);

		AllCollision["Att_Sting"] = Collision;

		Collision = CreateComponent<GameEngineCollision>("Dash_Area");
		Collision->GetTransform().SetLocalScale({ 550, 300, 200 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, float4::ZERO/*{ 0, 0.8f , 0.8f, 0.3f }*/);

		AllCollision["Att_Dash"] = Collision;

		Collision = CreateComponent<GameEngineCollision>("Stamping_Area");
		Collision->GetTransform().SetLocalScale({ 200, 150, 100 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, float4::ZERO/*{ 0, 0.8f , 0.2f, 0.3f }*/);

		AllCollision["Att_Stamping"] = Collision;



		Collision = CreateComponent<GameEngineCollision>("Teleport_Area");
		Collision->GetTransform().SetLocalScale({ 400, 150, 200 });
		Collision->ChangeOrder(CollisionOrder::Monster_Area);
		Collision->SetDebugSetting(CollisionType::CT_SPHERE, float4::ZERO/*{ 0.2f, 0.5f , 0.6f, 0.3f }*/);

		AllCollision["Move_Teleport"] = Collision;

	}


	{
		//Collision_ect
	}

	{
		Collision_PlayerLessPos = CreateComponent<GameEngineCollision>("TargetPos");
		Collision_PlayerLessPos->GetTransform().SetLocalScale({ 25, 10, 10 });
		Collision_PlayerLessPos->ChangeOrder(CollisionOrder::Monster_Tarcking);
		Collision_PlayerLessPos->SetDebugSetting(CollisionType::CT_SPHERE, { 0.5f, 0 , 0.8f, 0.3f });
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
		All_CollTime["Skill_Tracking"] = 0;
		All_CollTime["Skill_Tentacle"] = 0;
	}
	SetMonsterClass(MonsterClass::Named);
	// 배경

	{
		Texture_BlackBack = CreateComponent<GameEngineEffectRenderer>("BlackBack");
		Texture_BlackBack->SetParent(Actor_Dummy);
		Texture_BlackBack->GetTransform().SetLocalScale({ 3500, 1300, 0 });
		Texture_BlackBack->GetTransform().SetWorldPosition({ 0, 0, -0.001f });
		Texture_BlackBack->SetTexture("BlackBackground.png");
		Texture_BlackBack->SetPivot(PIVOTMODE::LEFTTOP);
		Texture_BlackBack->GetPixelData().MulColor.a = 0;


	}

	// 베리어
	{
		Texure_Barrier = CreateComponent<GameEngineEffectRenderer>("Barrier");
		Texure_Barrier->GetTransform().SetLocalPosition({ 0,0, 10.0001f });
		Texure_Barrier->CreateFrameAnimationFolder("Barrier", FrameAnimation_DESC("Bale_back", 0.125f, true));
		Texure_Barrier->ChangeFrameAnimation("Barrier");
		Texure_Barrier->ScaleToTexture();
		Texure_Barrier->Off();


		Texure_Barrier_Effect_Front = CreateComponent<GameEngineEffectRenderer>("Barrier");
		Texure_Barrier_Effect_Front->GetTransform().SetLocalPosition({ 0,0, 0.0001f });
		Texure_Barrier_Effect_Front->CreateFrameAnimationFolder("Barrier", FrameAnimation_DESC("Bale_back_normal", 0.25f, true));
		Texure_Barrier_Effect_Front->ChangeFrameAnimation("Barrier");
		Texure_Barrier_Effect_Front->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texure_Barrier_Effect_Front->ScaleToTexture();
		Texure_Barrier_Effect_Front->Off();

		Texure_Barrier_Effect_FrontDodge = CreateComponent<GameEngineEffectRenderer>("Barrier");
		Texure_Barrier_Effect_FrontDodge->GetTransform().SetLocalPosition({ 0,0, 0.0001f });
		Texure_Barrier_Effect_FrontDodge->CreateFrameAnimationFolder("Barrier", FrameAnimation_DESC("Bale_front_dodge", 0.25f, true));
		Texure_Barrier_Effect_FrontDodge->ChangeFrameAnimation("Barrier");
		Texure_Barrier_Effect_FrontDodge->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texure_Barrier_Effect_FrontDodge->ScaleToTexture();
		Texure_Barrier_Effect_FrontDodge->Off();


		
		Texure_Barrier_Effect_Back = CreateComponent<GameEngineEffectRenderer>("Barrier");
		Texure_Barrier_Effect_Back->GetTransform().SetLocalPosition({ 0,0, 10.0001f });
		Texure_Barrier_Effect_Back->CreateFrameAnimationFolder("Barrier", FrameAnimation_DESC("Bale_front_dodge", 0.25f, true));
		Texure_Barrier_Effect_Back->ChangeFrameAnimation("Barrier");
		Texure_Barrier_Effect_Back->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texure_Barrier_Effect_Back->ScaleToTexture();
		Texure_Barrier_Effect_Back->Off();

		Texure_Barrier_Effect_BackDodge = CreateComponent<GameEngineEffectRenderer>("Barrier");
		Texure_Barrier_Effect_BackDodge->GetTransform().SetLocalPosition({ 0,0, 10.0001f });
		Texure_Barrier_Effect_BackDodge->CreateFrameAnimationFolder("Barrier", FrameAnimation_DESC("Bale_front_dodge", 0.25f, true));
		Texure_Barrier_Effect_BackDodge->ChangeFrameAnimation("Barrier");
		Texure_Barrier_Effect_BackDodge->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texure_Barrier_Effect_BackDodge->ScaleToTexture();
		Texure_Barrier_Effect_BackDodge->Off();

	}

	// 스탬핑
	{
		Texture_StampingEffect = CreateComponent<GameEngineEffectRenderer>("Stamping");
		Texture_StampingEffect->GetTransform().SetLocalPosition({ 52, 85, -10.0001f });
		Texture_StampingEffect->CreateFrameAnimationFolder("Stamping", FrameAnimation_DESC("Bale_StampingEffect", 0, 15, 0.125f, false));
		Texture_StampingEffect->ChangeFrameAnimation("Stamping");
		//Texture_StampingEffect->GetPixelData().MulColor = { 0.2f,0.2f, 0.2f, 1 };
		Texture_StampingEffect->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		//Texture_StampingEffect->GetPixelData().Mul
		Texture_StampingEffect->GetPixelData().PlusColor.a = 1;
		//Texture_StampingEffect->SetParent(Actor_Dummy);
		Texture_StampingEffect->AnimationBindEnd("Stamping", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Texture_StampingEffect->SetScaleRatio(1.2f);
		Texture_StampingEffect->ScaleToTexture();
		Texture_StampingEffect->Off();

		
		Texture_StampingEffect_Floor = CreateComponent<GameEngineEffectRenderer>("Stamping");
		Texture_StampingEffect_Floor->GetTransform().SetLocalPosition({ 52, 85, 10.0002f });
		//Texture_StampingEffect_Floor->GetPixelData().PlusColor = { -0.5f,-0.5f, -0.5f, 0 };
		Texture_StampingEffect_Floor->CreateFrameAnimationFolder("Stamping", FrameAnimation_DESC("Bale_StampingEffect", 16, 29, 0.075f, false));
		Texture_StampingEffect_Floor->ChangeFrameAnimation("Stamping");
		Texture_StampingEffect_Floor->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		//Texture_StampingEffect_Floor->SetParent(Actor_Dummy);
		//Texture_StampingEffect_Floor->GetPixelData().MulColor = { 0.2f, 0.2f, 0.2f, 1.f };
		Texture_StampingEffect_Floor->GetPixelData().PlusColor.a = 1;
		Texture_StampingEffect_Floor->AnimationBindEnd("Stamping", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Texture_StampingEffect_Floor->SetScaleRatio(1.2f);
		Texture_StampingEffect_Floor->ScaleToTexture();
		Texture_StampingEffect_Floor->Off();

		
		Texture_SmokeEffect = CreateComponent<GameEngineEffectRenderer>("Smoke");
		Texture_SmokeEffect->GetTransform().SetLocalPosition({ 165, 60, 10.0000f });
		Texture_SmokeEffect->CreateFrameAnimationFolder("Smoke", FrameAnimation_DESC("Bale_Stampingsmoke", 0.125f, false));
		Texture_SmokeEffect->ChangeFrameAnimation("Smoke");
	
		Texture_SmokeEffect->AnimationBindEnd("Smoke", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Texture_SmokeEffect->ScaleToTexture();
		//Texture_SmokeEffect->SetParent(Actor_Dummy);
		Texture_SmokeEffect->Off();


		Collision_StampingHit = CreateComponent<GameEngineCollision>("Stamping");
		Collision_StampingHit->GetTransform().SetLocalScale({ 250, 200, 180 });
		Collision_StampingHit->GetTransform().SetLocalPosition({ 65, 10, 10.0000f });
		Collision_StampingHit->SetDebugSetting(CollisionType::CT_SPHERE, float4::ZERO);
		Collision_StampingHit->Off();
	}

	// 스팅
	{
		Actor_TrackingObject = GetLevel()->CreateActor<GameEngineActor>();
		GameEngineEffectRenderer* Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		Renderer->GetTransform().SetLocalPosition({ 200, 0, -10.01f });
		Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		Renderer->ChangeFrameAnimation("Sting");
		Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Puple.push_back(Renderer);

		Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		Renderer->GetTransform().SetLocalPosition({ 160, -35, -10.01f });
		Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		Renderer->ChangeFrameAnimation("Sting");
		Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Puple.push_back(Renderer);


		Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		Renderer->GetTransform().SetLocalPosition({ 180, 25, -10.01f });
		Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		Renderer->ChangeFrameAnimation("Sting");
		Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Puple.push_back(Renderer);


		Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		Renderer->GetTransform().SetLocalPosition({ 215, -55, -10.01f });
		Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		Renderer->ChangeFrameAnimation("Sting");
		Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Puple.push_back(Renderer);





		Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
		Renderer->GetTransform().SetLocalPosition({ 280, 32, -10.00f });
		//Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
		Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
			});
		Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
			{	
				if (_DESC.CurFrame > 5)
				{
					_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
					if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
					{
						_DESC.Renderer->GetPixelData().MulColor.a = 0;
					}
				}
			});
		Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ChangeFrameAnimation("Bale_talon_n");
		Renderer->SetScaleRatio(0.8f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Slash.push_back(Renderer);


		Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
		Renderer->GetTransform().SetLocalPosition({ 240, -3,-10.00f });
		//Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
		Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
			});
		Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
			{
				if (_DESC.CurFrame > 5)
				{
					_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
					if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
					{
						_DESC.Renderer->GetPixelData().MulColor.a = 0;
					}
				}
			});
		Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ChangeFrameAnimation("Bale_talon_n");
		Renderer->SetScaleRatio(0.8f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Slash.push_back(Renderer);


		Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
		Renderer->GetTransform().SetLocalPosition({ 260, 57, -10.00f });
		//Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
		Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
			});
		Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
			{
				if (_DESC.CurFrame > 5)
				{
					_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
					if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
					{
						_DESC.Renderer->GetPixelData().MulColor.a = 0;
					}
				}
			});
		Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ChangeFrameAnimation("Bale_talon_n");
		Renderer->SetScaleRatio(0.8f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Slash.push_back(Renderer);

		Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
		Renderer->GetTransform().SetLocalPosition({ 265, -23,-10.00f });
		//Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
		Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
			});
		Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
			{
				if (_DESC.CurFrame > 5)
				{
					_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
					if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
					{
						_DESC.Renderer->GetPixelData().MulColor.a = 0;
					}
				}
			});
		Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ChangeFrameAnimation("Bale_talon_n");
		Renderer->SetScaleRatio(0.8f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Slash.push_back(Renderer);


		//////////////////////////////



		Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		Renderer->GetTransform().SetLocalPosition({ 120, -20, -10.01f });
		Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		Renderer->ChangeFrameAnimation("Sting");
		Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Puple.push_back(Renderer);

		Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		Renderer->GetTransform().SetLocalPosition({ 80, -55, -10.01f });
		Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		Renderer->ChangeFrameAnimation("Sting");
		Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Puple.push_back(Renderer);


		Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		Renderer->GetTransform().SetLocalPosition({ 100, 5, -10.01f });
		Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		Renderer->ChangeFrameAnimation("Sting");
		Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Puple.push_back(Renderer);


		//Renderer = CreateComponent<GameEngineEffectRenderer>("Sting");
		//Renderer->GetTransform().SetLocalPosition({ 105, -75, 0 });
		//Renderer->CreateFrameAnimationFolder("Sting", FrameAnimation_DESC("Bale_Shoot_Effect_All", 0.0625f, false));
		//Renderer->ChangeFrameAnimation("Sting");
		//Renderer->AnimationBindEnd("Sting", [](const FrameAnimation_DESC& _DESC)
		//	{
		//		_DESC.Renderer->Off();
		//	});
		//Renderer->ScaleToTexture();
		//Renderer->Off();
		//Texture_StingEffect_Puple.push_back(Renderer);





		Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
		Renderer->GetTransform().SetLocalPosition({ 200, 12, -10.00f });
		//Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
		Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
			});
		Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
			{
				if (_DESC.CurFrame > 5)
				{
					_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
					if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
					{
						_DESC.Renderer->GetPixelData().MulColor.a = 0;
					}
				}
			});
		Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ChangeFrameAnimation("Bale_talon_n");
		Renderer->SetScaleRatio(0.8f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		Texture_StingEffect_Slash.push_back(Renderer);


		Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
		Renderer->GetTransform().SetLocalPosition({ 160, -23,-10.00f });
		//Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
		Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
			});
		Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
			{
				if (_DESC.CurFrame > 5)
				{
					_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
{
	_DESC.Renderer->GetPixelData().MulColor.a = 0;
}
				}
			});
			Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->Off();
				});
			Renderer->ChangeFrameAnimation("Bale_talon_n");
			Renderer->SetScaleRatio(0.8f);
			Renderer->ScaleToTexture();
			Renderer->Off();
			Texture_StingEffect_Slash.push_back(Renderer);


			//Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
			//Renderer->GetTransform().SetLocalPosition({ 180, 37, 0.01f });
			////Renderer->SetPivot(PIVOTMODE::LEFT);
			//Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
			//Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			//	{
			//		_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
			//	});
			//Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
			//	{
			//		if (_DESC.CurFrame > 5)
			//		{
			//			_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
			//			if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
			//			{
			//				_DESC.Renderer->GetPixelData().MulColor.a = 0;
			//			}
			//		}
			//	});
			//Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
			//	{
			//		_DESC.Renderer->Off();
			//	});
			//Renderer->ChangeFrameAnimation("Bale_talon_n");
			//Renderer->SetScaleRatio(0.8f);
			//Renderer->ScaleToTexture();
			//Renderer->Off();
			//Texture_StingEffect_Slash.push_back(Renderer);

			Renderer = CreateComponent<GameEngineEffectRenderer>("Talon");
			Renderer->GetTransform().SetLocalPosition({ 185, -43, -10.00f });
			//Renderer->SetPivot(PIVOTMODE::LEFT);
			Renderer->CreateFrameAnimationFolder("Bale_talon_n", FrameAnimation_DESC("Bale_talon_n", 0.0625f, false));
			Renderer->AnimationBindStart("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->GetPixelData().MulColor.a = 1.f;
				});
			Renderer->AnimationBindTime("Bale_talon_n", [](const FrameAnimation_DESC& _DESC, float _Delta)
				{
					if (_DESC.CurFrame > 5)
					{
						_DESC.Renderer->GetPixelData().MulColor.a -= _Delta * 5.f;
						if (_DESC.Renderer->GetPixelData().MulColor.a < 0)
						{
							_DESC.Renderer->GetPixelData().MulColor.a = 0;
						}
					}
				});
			Renderer->AnimationBindEnd("Bale_talon_n", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->Off();
				});
			Renderer->ChangeFrameAnimation("Bale_talon_n");
			Renderer->SetScaleRatio(0.8f);
			Renderer->ScaleToTexture();
			Renderer->Off();
			Texture_StingEffect_Slash.push_back(Renderer);


			for (auto& Effect : Texture_StingEffect_Puple)
			{
				Effect->SetParent(Actor_TrackingObject);
			}

			for (auto& Effect : Texture_StingEffect_Slash)
			{
				Effect->SetParent(Actor_TrackingObject);
			}

			Collision_StingHit = CreateComponent<GameEngineCollision>("StingHit");
			Collision_StingHit->GetTransform().SetLocalScale({ 600, 150, 180 });
			Collision_StingHit->GetTransform().SetLocalPosition({ 120, 0 });
			Collision_StingHit->SetDebugSetting(CollisionType::CT_SPHERE, float4::RED);
			Collision_StingHit->Off();

			//Texture_SmokeEffect


			//Texture_StingEffect_Puple;
			//Texture_StingSmokeEffect
	}

	// 대쉬
	{
		Collision_DashHit = CreateComponent<GameEngineCollision>();
		Collision_DashHit->GetTransform().SetLocalScale({ 200, 100, 100 });
		Collision_DashHit->ChangeOrder(CollisionOrder::Monster_Att);
	}
	// 추적
	{

		Texture_Monster->CreateFrameAnimationFolder("Bale_TrackingReady", FrameAnimation_DESC("Bale", 45, 46, 0.5f, false));
		Texture_Monster->AnimationBindEnd("Bale_TrackingReady", std::bind(&Bale::Bale_TrackReadyEnd, this, std::placeholders::_1));
		Texture_Monster->CreateFrameAnimationFolder("Bale_Tracking", FrameAnimation_DESC("Bale", 47, 48, 0.125f));
		Texture_Monster->AnimationBindFrame("Bale_Tracking", std::bind(&Bale::Bale_TrackFrmae, this, std::placeholders::_1));
		Texture_Monster->AnimationBindTime("Bale_Tracking", std::bind(&Bale::Bale_TrackUpdate, this, std::placeholders::_1, std::placeholders::_2));

		std::vector<unsigned int> A = { 37, 38, 38, 38,38 ,38,38,38, 38, 38 ,39, 40, 41, 42, 43, 44, 44, 44, 44 };
		Texture_Monster->CreateFrameAnimationFolder("Bale_TrackCatch", FrameAnimation_DESC("Bale", A, 0.125f, false));
		Texture_Monster->AnimationBindTime("Bale_TrackCatch", std::bind(&Bale::Bale_TrackCatchUpdate, this, std::placeholders::_1, std::placeholders::_2));
		Texture_Monster->AnimationBindFrame("Bale_TrackCatch", std::bind(&Bale::Bale_TrackCatchFrame, this, std::placeholders::_1));
		Texture_Monster->AnimationBindEnd("Bale_TrackCatch", std::bind(&Bale::Bale_BackToNone, this, std::placeholders::_1));


		Texture_Monster->CreateFrameAnimationFolder("Bale_TrackEnd", FrameAnimation_DESC("Bale", 49, 50, 0.25f, false));
		Texture_Monster->AnimationBindEnd("Bale_TrackEnd", std::bind(&Bale::Bale_BackToNone, this, std::placeholders::_1));

		GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 600, 600, 600 });
		Collision->ChangeOrder(CollisionOrder::Monster_Tarcking);

		AllCollision["Skill_Tracking"] = Collision;
	}

	// 촉수
	{
		Texture_Monster->CreateFrameAnimationFolder("Bale_TentacleSet", FrameAnimation_DESC("Bale", 32, 36, 0.1625f, false));

		Texture_Monster->CreateFrameAnimationFolder("Bale_TentacleReady", FrameAnimation_DESC("Bale", 32, 36, 0.1625f, false));
		Texture_Monster->AnimationBindEnd("Bale_TentacleReady", std::bind(&Bale::Bale_TentacleReadyEnd, this, std::placeholders::_1));
		Texture_Monster->AnimationBindFrame("Bale_TentacleReady", std::bind(&Bale::Bale_TentacleFrame, this, std::placeholders::_1));

		//Texture_Monster->CreateFrameAnimationFolder("Bale_Tracking", FrameAnimation_DESC("Bale", 47, 48, 0.125f));
		//Texture_Monster->AnimationBindFrame("Bale_Tracking", std::bind(&Bale::Bale_TrackFrmae, this, std::placeholders::_1));
		//Texture_Monster->AnimationBindTime("Bale_Tracking", std::bind(&Bale::Bale_TrackUpdate, this, std::placeholders::_1, std::placeholders::_2));

		//std::vector<unsigned int> A = { 37, 38, 38, 38,38 ,38,38,38, 38, 38 ,39, 40, 41, 42, 43, 44, 44, 44, 44 };
		//Texture_Monster->CreateFrameAnimationFolder("Bale_TrackCatch", FrameAnimation_DESC("Bale", A, 0.125f, false));
		//Texture_Monster->AnimationBindTime("Bale_TrackCatch", std::bind(&Bale::Bale_TrackCatchUpdate, this, std::placeholders::_1, std::placeholders::_2));
		//Texture_Monster->AnimationBindFrame("Bale_TrackCatch", std::bind(&Bale::Bale_TrackCatchFrame, this, std::placeholders::_1));
		//Texture_Monster->AnimationBindEnd("Bale_TrackCatch", std::bind(&Bale::Bale_BackToNone, this, std::placeholders::_1));

		Coliision_TentacleHit = CreateComponent<GameEngineCollision>();
		Coliision_TentacleHit->GetTransform().SetLocalScale({ 150, 200, 150 });
		Coliision_TentacleHit->ChangeOrder(CollisionOrder::Monster_Att);
		Coliision_TentacleHit->GetTransform().SetLocalPosition({ 65, 10 });

		GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 2000, 2000, 2000 });
		Collision->ChangeOrder(CollisionOrder::Monster_Tarcking);
		Collision->SetDebugSetting(CollisionType::CT_AABB, float4::ZERO);

		AllCollision["Skill_Tentacle"] = Collision;

		BringTentacleIndex = 0; 
	}

	Texture_Thumbnail = GameEngineTexture::Find("Bale_25.png");
}



CollisionReturn Bale::GetPlayer(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	PlayerHit = true;
	Hit_Player = _Other->GetActor<GamePlayObject>();
	if (Hit_Player->GetStatManager()->IsInvincibility())
	{
		return CollisionReturn::ContinueCheck;
	}
	else
	{
		return CollisionReturn::Break;

	}
}



void Bale::Update(float _DeltaTime)
{
	GamePlayMonster::Update(_DeltaTime); 

	if (GameEngineInput::GetInst()->IsDown("Debug8"))
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
	else if (GameEngineInput::GetInst()->IsDown("Debug9"))
	{
		Barrier_HP = 0;
	}

	if (Barrier_On == false)
	{
		Barrier_CoolTime -= _DeltaTime;
		if (Barrier_CoolTime <= 0)
		{
			Barrier_On = true;
			Barrier_HP = 1518000;
			Texure_Barrier->On();
			Manager_StatManager->SetBuild();
			//Texure_Barrier_Effect_Front->On();
			//Texure_Barrier_Effect_FrontDodge->On();
		}
	}
	else
	{
		if (Barrier_HP <= 0)
		{
			Barrier_On = false;// 대사
			Barrier_CoolTime = 60.f;
			Texure_Barrier->Off();
			Texure_Barrier_Effect_Front->Off();
			Texure_Barrier_Effect_FrontDodge->Off();
			Manager_StatManager->SetSuperarmorEnd();
			Manager_StatManager->SetBuildEnd();
			SetVoice("bale_skill_05.ogg");
			Actor_SpeechPopUp->CreatePopup("크르르... 루크님의 선물이...!");
		}
		else
		{
			Manager_StatManager->SetSuperarmor();
		}

		if (GameEngineRandom::MainRandom.RandomInt(0, 90) == 0)
		{
		//	GameEngineEffectRenderer* Renderer = CreateComponent<GameEngineEffectRenderer>();

			//float4 Pos = { GameEngineRandom::MainRandom.RandomFloat(-80.f, 80.f) , GameEngineRandom::MainRandom.RandomFloat(-40.f, 40.f)};
			//Renderer->GetTransform().SetLocalPosition(Pos);
			//Renderer->CreateFrameAnimationFolder("Bale_back_dodge", FrameAnimation_DESC("Bale_back_dodge", 0.0625f, false));
			//Renderer->ChangeFrameAnimation("Bale_back_dodge");
			////Renderer->ChangeCamera(CAMERAORDER::MAINCAMERA);
			//Renderer->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
			//Renderer->ScaleToTexture();
			//Renderer->AnimationBindEnd("Bale_back_dodge", [](const FrameAnimation_DESC& _DECS)
			//	{
			//		_DECS.Renderer->Off();
			//		_DECS.Renderer->Death();
			//	});
			//Renderer = CreateComponent<GameEngineEffectRenderer>();
			//Renderer->GetTransform().SetLocalPosition(Pos);
			//Renderer->CreateFrameAnimationFolder("Bale_back_normal", FrameAnimation_DESC("Bale_back_dodge", 0.0625f, false));
			//Renderer->ChangeFrameAnimation("Bale_back_normal");
			//Renderer->ScaleToTexture();
			//Renderer->AnimationBindEnd("Bale_back_normal", [](const FrameAnimation_DESC& _DECS)
			//	{
			//		_DECS.Renderer->Off();
			//		_DECS.Renderer->Death();
			//	});
			
		}


	}



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
				NearMiss = false;
				PlayerHit = false;
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
	
	Manager_StatManager->GetFSMManager().CreateStateMember
	("Skill_Tracking", std::bind(&Bale::FSM_Skill_Tracking_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Skill_Tracking_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Skill_Tracking_End, this, std::placeholders::_1));

	Manager_StatManager->GetFSMManager().CreateStateMember
	("Skill_Tentacle", std::bind(&Bale::FSM_Skill_BringTentacle_Update, this, std::placeholders::_1, std::placeholders::_2)
		, std::bind(&Bale::FSM_Skill_BringTentacle_Start, this, std::placeholders::_1)
		, std::bind(&Bale::FSM_Skill_BringTentacle_End, this, std::placeholders::_1));
	
	
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
		Collision_PlayerLessPos->SetParent(Actor_Dummy);
		const float4& Pos = GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition();
		Collision_PlayerLessPos->GetTransform().SetWorldPosition({ Pos.x , Pos.z, Pos.z });
	}
	
	StayStandDelay = 1.5f;
}
void Bale::FSM_Move_Stand_Update(float _DeltaTime, const StateInfo& _Info)
{
	//if (Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))
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

	if (!Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
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
	if (!Manager_StatManager->IsBeHit())
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void Bale::FSM_Hit_Stand_End(const StateInfo& _Info)
{
	Manager_StatManager->SetHit_StandEnd();
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
	Manager_StatManager->SetAerialEnd();
}

void Bale::FSM_Hit_Aerial_DoingDown_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetAerial();
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
	Manager_StatManager->SetAerialEnd();
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
	Collision_PlayerLessPos->SetParent(GamePlayCharacter::GetInst());
	Collision_PlayerLessPos->GetTransform().SetLocalPosition(float4::ZERO);
}
void Bale::FSM_Move_Walk_Update(float _DeltaTime, const StateInfo& _Info)
{

	MoveDelay -= _DeltaTime;
	bool IsArrive = false;
	if (MoveDelay <= 0 || (IsArrive = Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE)))
	{
		if (IsArrive == true)
		{
			if (Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Player, CollisionType::CT_SPHERE))
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


		Collision_PlayerLessPos->GetTransform().SetLocalPosition(Pos);
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

	
	const float4& Collision = Collision_PlayerLessPos->GetTransform().GetWorldPosition();
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


	Manager_MoveManager->SetCharacterMoveCheck({ Dir.x * _DeltaTime, Dir.z * _DeltaTime }, Collision);

	
}
void Bale::FSM_Move_Walk_End(const StateInfo& _Info)
{
	MoveDelay = 0;
}

void Bale::FSM_Att_Sting_Start(const StateInfo& _Info)
{			  
	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_Sting");

	Actor_TrackingObject->GetTransform().SetLocalPosition(GetTransform().GetWorldPosition());
	GetTransform().GetLocalScale().x > 0 ? Actor_TrackingObject->GetTransform().PixLocalPositiveX() : Actor_TrackingObject->GetTransform().PixLocalNegativeX();
	Manager_StatManager->SetSuperarmor();

}
void Bale::FSM_Att_Sting_Update(float _DeltaTime, const StateInfo& _Info)
{

}
void Bale::FSM_Att_Sting_End(const StateInfo& _Info)
{
	All_CollTime["Att_Sting"] = 2.f;
	Manager_StatManager->SetDoSkillEnd();
	Manager_StatManager->SetSuperarmorEnd();
	if (NearMiss == true && PlayerHit == false)
	{
		GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::NearMiss);
	}
}


void Bale::Sting_Update(const FrameAnimation_DESC& _DESC)
{
	switch (_DESC.CurFrame)
	{
	case 2:
		SetVoice("bale_atk_01.ogg");
		Texture_StingEffect_Puple[0]->On();
		Texture_StingEffect_Puple[0]->ChangeFrameAnimation("Sting", true);

		Texture_StingEffect_Slash[0]->On();
		Texture_StingEffect_Slash[0]->ChangeFrameAnimation("Bale_talon_n", true);


		Texture_StingEffect_Puple[1]->On();
		Texture_StingEffect_Puple[1]->ChangeFrameAnimation("Sting", true);

		Texture_StingEffect_Slash[1]->On();
		Texture_StingEffect_Slash[1]->ChangeFrameAnimation("Bale_talon_n", true);


		Texture_StingEffect_Puple[2]->On();
		Texture_StingEffect_Puple[2]->ChangeFrameAnimation("Sting", true);

		Texture_StingEffect_Slash[2]->On();
		Texture_StingEffect_Slash[2]->ChangeFrameAnimation("Bale_talon_n", true);


		Texture_StingEffect_Puple[3]->On();
		Texture_StingEffect_Puple[3]->ChangeFrameAnimation("Sting", true);

		Texture_StingEffect_Slash[3]->On();
		Texture_StingEffect_Slash[3]->ChangeFrameAnimation("Bale_talon_n", true);

		Collision_StingHit->On();
		if (Collision_StingHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB,
			std::bind(&Bale::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
		{
			switch (GameEngineRandom::MainRandom.RandomInt(0, 6))
			{
			case 0:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_01.ogg").Volume(0.8f);
				break;
			case 1:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_02.ogg").Volume(0.8f);
				break;
			case 2:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_03.ogg").Volume(0.8f);
				break;
			case 3:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_04.ogg").Volume(0.8f);
				break;
			case 4:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_05.ogg").Volume(0.8f);
				break;
			case 5:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_06.ogg").Volume(0.8f);
				break;
			case 6:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_07.ogg").Volume(0.8f);
				break;
			default:
				break;
			}
			int Dir = Collision_StampingHit->GetTransform().GetWorldPosition().x - Hit_Player->GetTransform().GetWorldPosition().x > 0 ? -1 : 1;
			Hit_Player->BeHit({ 30, 0, 0, 40.f }, HitPostureType::Standing, nullptr, nullptr, Dir, 1000);
		}
		else if (Collision_StingHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB))
		{
			NearMiss = true;
		}
		Collision_StingHit->Off();
		break;
	case 7:
		SetVoice("bale_atk_02.ogg");
		Texture_StingEffect_Puple[4]->On();
		Texture_StingEffect_Puple[4]->ChangeFrameAnimation("Sting", true);

		Texture_StingEffect_Slash[4]->On();
		Texture_StingEffect_Slash[4]->ChangeFrameAnimation("Bale_talon_n", true);


		Texture_StingEffect_Puple[5]->On();
		Texture_StingEffect_Puple[5]->ChangeFrameAnimation("Sting", true);

		Texture_StingEffect_Slash[5]->On();
		Texture_StingEffect_Slash[5]->ChangeFrameAnimation("Bale_talon_n", true);


		Texture_StingEffect_Puple[6]->On();
		Texture_StingEffect_Puple[6]->ChangeFrameAnimation("Sting", true);

		Texture_StingEffect_Slash[6]->On();
		Texture_StingEffect_Slash[6]->ChangeFrameAnimation("Bale_talon_n", true);


		//Texture_StingEffect_Puple[7]->On();
		//Texture_StingEffect_Puple[7]->ChangeFrameAnimation("Sting", true);

		//Texture_StingEffect_Slash[7]->On();
		//Texture_StingEffect_Slash[7]->ChangeFrameAnimation("Bale_talon_n", true);

		Collision_StingHit->On();
		if (Collision_StingHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB,
			std::bind(&Bale::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
		{
			switch (GameEngineRandom::MainRandom.RandomInt(0, 6))
			{
			case 0:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_01.ogg").Volume(0.8f);
				break;
			case 1:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_02.ogg").Volume(0.8f);
				break;
			case 2:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_03.ogg").Volume(0.8f);
				break;
			case 3:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_04.ogg").Volume(0.8f);
				break;
			case 4:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_05.ogg").Volume(0.8f);
				break;
			case 5:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_06.ogg").Volume(0.8f);
				break;
			case 6:
				GameEngineSound::SoundPlayControl("mon_long_sword_hit_07.ogg").Volume(0.8f);
				break;
			default:
				break;
			}

			int Dir = Collision_StampingHit->GetTransform().GetWorldPosition().x - Hit_Player->GetTransform().GetWorldPosition().x > 0 ? -1 : 1;
			Hit_Player->BeHit({ 30, 0, 0, 40.f }, HitPostureType::Standing, nullptr, nullptr, Dir, 1000);
		}
		else if (Collision_StingHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB))
		{
			NearMiss = true;
		}

		Collision_StingHit->Off();


		break;
	default:
		break;
	}

}

void Bale::Sting_End(const FrameAnimation_DESC& _DESC)
{
	Manager_StatManager->GetFSMManager().ChangeState("None");

}

void Bale::FSM_Att_Stamping_Start(const StateInfo& _Info)
{

	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_Stamping");
	StampingEnd = 10.f;

	Manager_StatManager->SetSuperarmor();

}
void Bale::FSM_Att_Stamping_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (StampingEnd < 0.125f)
	{
		StampingEnd -= _DeltaTime;
		if (StampingEnd <= 0)
		{
			Manager_StatManager->GetFSMManager().ChangeState("None");
		}
	}

}
void Bale::FSM_Att_Stamping_End(const StateInfo& _Info)
{
	All_CollTime["Att_Stamping"] = 3.f;
	Manager_StatManager->SetDoSkillEnd();
	StampingEnd = 10.f;

	Manager_StatManager->SetSuperarmorEnd();

	if (NearMiss == true)
	{
		GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::NearMiss);
	}

}

void Bale::Bale_Stamping(const FrameAnimation_DESC& _DESC)
{
	if (_DESC.CurFrame == 3)
	{
		SetVoice("bale_atk_04.ogg");

		
		const float4& Pos = GetTransform().GetWorldPosition();


		Texture_StampingEffect->SetParent(this);
		Texture_StampingEffect_Floor->SetParent(this);
		Texture_SmokeEffect->SetParent(this);

		Texture_StampingEffect->GetTransform().SetLocalPosition({ 52, 90, -10.0001f });
		Texture_StampingEffect_Floor->GetTransform().SetLocalPosition({ 52, 150, 10.0002f });
		Texture_SmokeEffect->GetTransform().SetLocalPosition({ 165, 60, 10.0000f });

		//GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		//Renderer->CreateFrameAnimationFolder("Earthquakering", FrameAnimation_DESC("Earthquakering", 0.125f, false));
		//Renderer->ChangeFrameAnimation("Earthquakering");
		//Renderer->AnimationBindEnd("Earthquakering", [](const FrameAnimation_DESC& _DESC)
		//	{
		//		_DESC.Renderer->Death();
		//	});
		//Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalPosition({ 20, 50, 10.0000f });



		float4 StampingPos = Texture_StampingEffect->GetTransform().GetWorldPosition();
		float4 SmokePos = Texture_SmokeEffect->GetTransform().GetWorldPosition();

		Texture_StampingEffect->SetParent(Actor_Dummy);
		Texture_StampingEffect_Floor->SetParent(Actor_Dummy);
		Texture_SmokeEffect->SetParent(Actor_Dummy);

		Texture_StampingEffect->GetTransform().SetWorldPosition(StampingPos);
		Texture_StampingEffect_Floor->GetTransform().SetWorldPosition(StampingPos);
		Texture_SmokeEffect->GetTransform().SetWorldPosition(SmokePos);



		Texture_StampingEffect->ChangeFrameAnimation("Stamping", true);
		Texture_StampingEffect_Floor->ChangeFrameAnimation("Stamping", true);
		Texture_SmokeEffect->ChangeFrameAnimation("Smoke", true);
		Texture_StampingEffect->On();
		Texture_StampingEffect_Floor->On();





		//Texture_SmokeEffect->On();


		//Texture_SmokeEffect->GetTransform().SetWorldPosition({ Pos.x, Pos.y  , Pos.z  });
		//Texture_StampingEffect_Floor->GetTransform().SetWorldPosition({ Pos.x  , Pos.y , Pos.z  });
		//Texture_StampingEffect->GetTransform().SetWorldPosition({ Pos.x, Pos.y , Pos.z });


		Collision_StampingHit->On();
		GameEngineSound::SoundPlayControl("shockwave_hit_01.ogg").Volume(0.8f);
		if (Collision_StampingHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player ,CollisionType::CT_AABB,
			std::bind(&Bale::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
		{


			switch (GameEngineRandom::MainRandom.RandomInt(0, 8))
			{
			case 0:
				GameEngineSound::SoundPlayControl("mon_dark_hit_01.ogg").Volume(0.8f);
				break;
			case 1:
				GameEngineSound::SoundPlayControl("mon_dark_hit_02.ogg").Volume(0.8f);
				break;
			case 2:
				GameEngineSound::SoundPlayControl("mon_dark_hit_03.ogg").Volume(0.8f);
				break;
			case 3:
				GameEngineSound::SoundPlayControl("mon_dark_hit_04.ogg").Volume(0.8f);
				break;
			case 4:
				GameEngineSound::SoundPlayControl("mon_dark_hit_05.ogg").Volume(0.8f);
				break;
			case 5:
				GameEngineSound::SoundPlayControl("mon_dark_hit_06.ogg").Volume(0.8f);
				break;
			case 6:
				GameEngineSound::SoundPlayControl("mon_dark_hit_07.ogg").Volume(0.8f);
				break;
			case 7:
				GameEngineSound::SoundPlayControl("mon_dark_hit_08.ogg").Volume(0.8f);
				break;
			case 8:
				GameEngineSound::SoundPlayControl("mon_dark_hit_09.ogg").Volume(0.8f);
				break;
			default:
				break;
			}

			int Dir = Collision_StampingHit->GetTransform().GetWorldPosition().x - Hit_Player->GetTransform().GetWorldPosition().x > 0 ? -1 : 1;
			Hit_Player->BeHit({ 50, 300 }, HitPostureType::Aerial, nullptr, nullptr, Dir, 4200);
		}
		else if (Collision_StampingHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB))
		{
			NearMiss = true;
		}
		Collision_StampingHit->Off();
	}
	if (_DESC.CurFrame == 4)
	{
		StampingEnd = 0.1f;
		Collision_StampingHit->Off();
	}

}


void Bale::FSM_Att_Dash_Start(const StateInfo& _Info)
{

	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_RunReady");

	Collision_ect = CreateComponent<GameEngineCollision>("Dash");
	Collision_ect->SetParent(Actor_Dummy);
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
	PlayerDashHit = false;
	Collision_ect->GetTransform().SetWorldPosition({ Dir.x + GetTransform().GetWorldPosition().x, Dir.z + GetTransform().GetWorldPosition().y, Dir.z + GetTransform().GetWorldPosition().z });
	DashUpdate = false;
	MoveDelay = 0;

	Manager_StatManager->SetSuperarmor();

}


void Bale::Bale_DashStart(const FrameAnimation_DESC& _DESC)
{
	Texture_Monster->ChangeFrameAnimation("Bale_Running");
	DashUpdate = true;
	BeforePos = GetTransform().GetWorldPosition();
	Texture_BlackBack->GetPixelData().PlusColor = { 1, 1, 1, 0 };
	DashColorDelay = 1;
	VisionDelay = 0;

	SetVoice("bale_atk_05.ogg");
	GameEngineSound::SoundPlayControl("bale_dash.ogg").Volume(0.7f);

	//Texture_BlackBack->GetPixelData().MulColor.a = 1;
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


		if (Collision_DashHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB,
			std::bind(&Bale::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
		{
			switch (GameEngineRandom::MainRandom.RandomInt(0, 9))
			{
			case 0:
				GameEngineSound::SoundPlayControl("mon_sword_hit_01.ogg").Volume(0.8f);
				break;
			case 1:
				GameEngineSound::SoundPlayControl("mon_sword_hit_02.ogg").Volume(0.8f);
				break;
			case 2:
				GameEngineSound::SoundPlayControl("mon_sword_hit_03.ogg").Volume(0.8f);
				break;
			case 3:
				GameEngineSound::SoundPlayControl("mon_sword_hit_04.ogg").Volume(0.8f);
				break;
			case 4:
				GameEngineSound::SoundPlayControl("mon_sword_hit_05.ogg").Volume(0.8f);
				break;
			case 5:
				GameEngineSound::SoundPlayControl("mon_sword_hit_06.ogg").Volume(0.8f);
				break;
			case 6:
				GameEngineSound::SoundPlayControl("mon_sword_hit_07.ogg").Volume(0.8f);
				break;
			case 7:
				GameEngineSound::SoundPlayControl("mon_sword_hit_08.ogg").Volume(0.8f);
				break;
			case 8:
				GameEngineSound::SoundPlayControl("mon_sword_hit_09.ogg").Volume(0.8f);
				break;
			case 9:
				GameEngineSound::SoundPlayControl("mon_sword_hit_10.ogg").Volume(0.8f);
				break;

			default:
				break;
			}

			int Dir = Collision_DashHit->GetTransform().GetWorldPosition().x - Hit_Player->GetTransform().GetWorldPosition().x > 0 ? -1 : 1;
			Hit_Player->BeHit({ 50, 0,0,30 }, HitPostureType::Standing, nullptr, nullptr, Dir, 1000);
			Collision_DashHit->Off();
		}
		else if (Collision_StampingHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB))
		{
			NearMiss = true;
		}
	}

	if (Collision_ect->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE) || _Info.StateTime > 4.f)
	{
		Texture_Monster->ChangeFrameAnimation("Bale_RunEnd");
	}


	//Bale_RunReady
	//	Bale_Running"
	//	Bale_RunEnd",
}

void Bale::Bale_DashUpdate(const FrameAnimation_DESC& _DESC, float _Time)
{
	if (DashColorDelay  > -1.f)
	{
		float index = 0;
		if (DashColorDelay > 0)
		{
			DashColorDelay -= _Time * 4.f;
			if (DashColorDelay < 0)
			{
				DashColorDelay = 0;
			}
			index += DashColorDelay ;
		}
		else
		{
			DashColorDelay -= _Time * 4.f;
			if (DashColorDelay < -1.f)
			{
				DashColorDelay = -1.f;
			}
			index += DashColorDelay * -1.f;
		}

		Texture_BlackBack->GetPixelData().PlusColor = {1, 1, 1, 1.f - index};
	}
	else
	{

		DashColorDelay = -1.f;
		Texture_BlackBack->GetPixelData().PlusColor.a = 0;
	}
	VisionDelay += _Time;
	if (VisionDelay > 0.0125f)
	{
		Avata_Vision* Renderer = GetLevel()->CreateActor<Avata_Vision>();
		Renderer->CreateVision(Texture_Monster, { 0,0,0,0.8f }, 0.8f);
		if (GetTransform().GetLocalScale().x < 0)
		{
			Renderer->GetTransform().PixLocalNegativeX();
		}

		VisionDelay = 0;
	}

}

void Bale::Bale_DashFrame(const FrameAnimation_DESC& _DESC)
{


	switch (_DESC.CurFrame)
	{
	case 1:
	{
		Collision_DashHit->On();
		const float4& Pos = GetTransform().GetWorldPosition();

		GameEngineEffectRenderer* Renderer = CreateComponent<GameEngineEffectRenderer>();
		Renderer->CreateFrameAnimationFolder("Bale_slash000", FrameAnimation_DESC("Bale_slash000", 0.15f));
		Renderer->AnimationBindEnd("Bale_slash000", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->ChangeFrameAnimation("Bale_slash000");
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Renderer->GetPixelData().PlusColor.a = 1.0f;
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetWorldPosition({ Pos.x , Pos.y, Pos.z + 0.0002f });
		Renderer->GetTransform().SetLocalRotate({ 0, 0, GameEngineRandom::MainRandom.RandomFloat(25.f, 65.f) });


		Renderer = CreateComponent<GameEngineEffectRenderer>();
		Renderer->CreateFrameAnimationFolder("Bale_boom_purple_009", FrameAnimation_DESC("Bale_boom_purple_009", 0.075f));
		Renderer->AnimationBindEnd("Bale_boom_purple_009", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->ChangeFrameAnimation("Bale_boom_purple_009");
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Renderer->GetPixelData().PlusColor.a = 0.7f;
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetWorldPosition({ Pos.x , Pos.y, Pos.z + 0.f });
		//Renderer->GetTransform().SetLocalRotate({ 0, 0, 45.f });

		Renderer = CreateComponent<GameEngineEffectRenderer>();
		Renderer->CreateFrameAnimationFolder("Bale_boom_purple_011", FrameAnimation_DESC("Bale_boom_purple_011", 0.0125f));
		Renderer->AnimationBindEnd("Bale_boom_purple_011", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->ChangeFrameAnimation("Bale_boom_purple_011");
		Renderer->SetScaleRatio(0.3f);
		Renderer->GetPixelData().MulColor.a = 0.7f;
		Renderer->SetParent(Actor_Dummy);
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetWorldPosition({ Pos.x , Pos.y, Pos.z + 0.0001f });
		//Renderer->GetTransform().SetLocalRotate({ 0, 0, 45.f });
	}



	break;
	case 2:
	{
		const float4& Pos = GetTransform().GetWorldPosition();

		GameEngineEffectRenderer* Renderer = CreateComponent<GameEngineEffectRenderer>();
		Renderer->CreateFrameAnimationFolder("Bale_slash000", FrameAnimation_DESC("Bale_slash000", 0.15f));
		Renderer->AnimationBindEnd("Bale_slash000", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->ChangeFrameAnimation("Bale_slash000");
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Renderer->GetPixelData().PlusColor.a = 1.0f;
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetWorldPosition({ Pos.x , Pos.y + GameEngineRandom::MainRandom.RandomFloat(-20.f, 20.f), Pos.z + 0.0002f});
		Renderer->GetTransform().SetLocalRotate({ 0, 0,  GameEngineRandom::MainRandom.RandomFloat(115.f, 155.f) });


		Renderer = CreateComponent<GameEngineEffectRenderer>();
		Renderer->CreateFrameAnimationFolder("Bale_slash000", FrameAnimation_DESC("Bale_slash000_ect", 0.15f));
		Renderer->AnimationBindEnd("Bale_slash000", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->ChangeFrameAnimation("Bale_slash000");
		Renderer->SetParent(Actor_Dummy);
		//Renderer->GetPixelData().PlusColor.a = 1.0f;
		Renderer->GetPixelData().MulColor = { 0.1f, 0.1f, 0.1f,1.f };
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetWorldPosition({ Pos.x , Pos.y + GameEngineRandom::MainRandom.RandomFloat(-20.f, 20.f), Pos.z + 0.0002f });
		Renderer->GetTransform().SetLocalRotate({ 0, 0,  GameEngineRandom::MainRandom.RandomFloat(35.f, 55.f) });
	}
	break;
	default:
		break;
	}
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
	Texture_BlackBack->GetPixelData().PlusColor.a = 0;
	Manager_StatManager->SetDoSkillEnd();

	Manager_StatManager->SetSuperarmorEnd();

	if (NearMiss == true && PlayerHit == false)
	{
		GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::NearMiss);
	}

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

	Manager_StatManager->SetSuperarmor();
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
	All_CollTime["Att_Dash"] = 5.f;
	Manager_StatManager->SetDoSkillEnd();
	Manager_StatManager->SetSuperarmorEnd();
}

void Bale::FSM_Skill_Tracking_Start(const StateInfo& _Info)
{
	switch (GameEngineRandom::MainRandom.RandomInt(0, 2))
	{
	case 0:
		SetVoice("bale_skill_01_1.ogg");
		break;
	case 1:
		SetVoice("bale_skill_01_2.ogg");
		break;
	case 2:
		SetVoice("bale_skill_01_3.ogg");
		break;
	default:
		break;
	}
	GameEngineSound::SoundPlayControl("bale_cast.ogg").Volume(0.6f);
	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_TrackingReady");
	Texture_BlackBack->GetPixelData().PlusColor = {0, 0, 0, 0};
	Collision_PlayerLessPos->SetParent(GamePlayCharacter::GetInst());
	Collision_PlayerLessPos->GetTransform().SetLocalPosition({80,0,0});
	Manager_StatManager->SetSuperarmor();
}
void Bale::FSM_Skill_Tracking_Update(float _DeltaTime, const StateInfo& _Info)
{
	if (Texture_BlackBack->GetPixelData().PlusColor.a < 1)
	{
		Texture_BlackBack->GetPixelData().PlusColor.a += _DeltaTime;
	}
	else
	{
		Texture_BlackBack->GetPixelData().PlusColor.a = 1;
	}

	if (_Info.StateTime > 5.f)
	{
		Texture_Monster->ChangeFrameAnimation("Bale_TrackEnd");
		Texture_BlackBack->GetPixelData().PlusColor.a -= _DeltaTime * 2.f;
	}


	
}
void Bale::FSM_Skill_Tracking_End(const StateInfo& _Info)
{
	Texture_BlackBack->GetPixelData().PlusColor.a = 0;
	Collision_PlayerLessPos->GetTransform().SetLocalPosition(float4::ZERO); 
	if (dynamic_cast<GamePlayCharacter*>(Hit_Player) != nullptr)
	{
		dynamic_cast<GamePlayCharacter*>(Hit_Player)->SetCamHoldOff();
	}
	
	All_CollTime["Skill_Tracking"] = 20.f;
	Manager_StatManager->SetDoSkillEnd();
	Manager_StatManager->SetSuperarmorEnd();

	if (NearMiss == true && PlayerHit == false)
	{
		GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::NearMiss);
	}
}

void Bale::Bale_TrackReadyEnd(const FrameAnimation_DESC& _DESC)
{
	Texture_Monster->ChangeFrameAnimation("Bale_Tracking");
}
void Bale::Bale_TrackFrmae(const FrameAnimation_DESC& _DESC)
{
	//switch (_DESC.CurFrame)
	//{
	//case 1:
	//	const float4 & Pos = GamePlayCharacter::GetInst()->GetTransform().GetWorldPosition();

	//	Collision_PlayerLessPos

	//	break;
	//default:
	//	break;
	//}
}
void Bale::Bale_TrackUpdate(const FrameAnimation_DESC& _DESC, float _Time)
{

	if (Collision_HitBody_Mid->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB,
		std::bind(&Bale::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
	{

		Texture_Monster->ChangeFrameAnimation("Bale_TrackCatch");
		Texture_Monster->CurAnimationPauseOff();
		int Dir = Collision_StampingHit->GetTransform().GetWorldPosition().x - Hit_Player->GetTransform().GetWorldPosition().x > 0 ? -1 : 1;
		Hit_Player->BeHit({ 0, 0, 0, 2000}, HitPostureType::Hold, nullptr, nullptr, Dir, 500);

		const float4& Pos = GetTransform().GetWorldPosition();
		if (GetTransform().GetLocalScale().x >= 0)
		{
			Hit_Player->GetTransform().SetWorldPosition({ Pos.x + 50, Pos.y + 100, Pos.z });
			Hit_Player->GetTransform().PixLocalNegativeX();
		}
		else
		{
			Hit_Player->GetTransform().SetWorldPosition({ Pos.x - 50, Pos.y + 100, Pos.z });
			Hit_Player->GetTransform().PixLocalPositiveX();
		}
		Hit_Player->GetStatManager()->SetAerial();
		dynamic_cast<GamePlayCharacter*>(Hit_Player)->SetCamHoldOn();
		Texture_BlackBack->GetPixelData().PlusColor.a = 0;
		return;
	}
	float4 Dir = Collision_PlayerLessPos->GetTransform().GetWorldPosition() - GetTransform().GetWorldPosition();

	Dir.x = Dir.x > 0 ? 1.f : -1.f;
	Dir.z = Dir.z > 0 ? 0.8f : -0.8f;

	Manager_MoveManager->SetCharacterMove({ Dir.x * 480.f * _Time, Dir.z * 350.f * _Time });
	if (Collision_PlayerLessPos->IsCollision(CollisionType::CT_SPHERE, CollisionOrder::Monster, CollisionType::CT_SPHERE))
	{
		Collision_PlayerLessPos->GetTransform().SetLocalPosition(Collision_PlayerLessPos->GetTransform().GetLocalPosition() * -1.f);
	}

	if (Collision_PlayerLessPos->GetTransform().GetWorldPosition().x > GetTransform().GetWorldPosition().x)
	{
		GetTransform().PixLocalPositiveX();
	}
	else
	{
		GetTransform().PixLocalNegativeX();
	}
}

void Bale::Bale_TrackCatchUpdate(const FrameAnimation_DESC& _DESC, float _Time)
{
	Texture_BlackBack->GetPixelData().PlusColor.a = 0;


}
void Bale::Bale_TrackCatchFrame(const FrameAnimation_DESC& _DESC)
{
	const float4& Pos = GetTransform().GetWorldPosition();
	int Dir = Texture_Monster->GetTransform().GetWorldPosition().x - Hit_Player->GetTransform().GetWorldPosition().x > 0 ? -1 : 1;

	switch (_DESC.CurFrame)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		//if (GetTransform().GetLocalScale().x >= 0)
		//{
		//	Hit_Player->GetTransform().SetWorldPosition({ Pos.x - 30, Pos.y + 100, Pos.z });
		//}
		//else
		//{
		//	Hit_Player->GetTransform().SetWorldPosition({ Pos.x + 30, Pos.y + 100, Pos.z });
		//}
		break;
	case 12:
		SetVoice("bale_atk_03.ogg");

		if (GetTransform().GetLocalScale().x >= 0)
		{
			Hit_Player->GetTransform().SetWorldPosition({ Pos.x + 50, Pos.y + 100, Pos.z });
		}
		else
		{
			Hit_Player->GetTransform().SetWorldPosition({ Pos.x - 50, Pos.y + 100, Pos.z });
		}
		break;
	case 13:
	{
		Hit_Player->GetStatManager()->GetFSMManager().ChangeState("Hit_Down");
		if (GetTransform().GetLocalScale().x >= 0)
		{
			Hit_Player->GetTransform().SetWorldPosition({ Pos.x + 50, Pos.z , Pos.z });
		}
		else
		{
			Hit_Player->GetTransform().SetWorldPosition({ Pos.x - 50, Pos.z , Pos.z });
		}

		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->CreateFrameAnimationFolder("Stone006", FrameAnimation_DESC("Stone006", 0.125f, false));
		Renderer->ChangeFrameAnimation("Stone006");
		Renderer->AnimationBindEnd("Stone006", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->GetTransform().SetLocalPosition({ 70, -60, -1.f });
		float4 Pos = Renderer->GetTransform().GetWorldPosition();
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetTransform().SetWorldPosition(Pos);
		Renderer->ScaleToTexture();

		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->CreateFrameAnimationFolder("Crack005", FrameAnimation_DESC("Crack005", 0.125f, false));
		Renderer->ChangeFrameAnimation("Crack005");
		Renderer->AnimationBindEnd("Crack005", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->GetTransform().SetLocalPosition({ 70, -60, 20.f });
		Pos = Renderer->GetTransform().GetWorldPosition();
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetTransform().SetWorldPosition(Pos);
		Renderer->ScaleToTexture();


	}
	break;
	case 16:
	{
	
		Hit_Player->BeHit({ 200, 600, 0, 0 }, HitPostureType::Aerial, nullptr, nullptr, -Dir, 8000);
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->CreateFrameAnimationFolder("Bale_boom_purple_026", FrameAnimation_DESC("Bale_boom_purple_026", 15, 28, 0.075f, false));
		Renderer->ChangeFrameAnimation("Bale_boom_purple_026");
		Renderer->SetScaleRatio(1.5f);
		Renderer->AnimationBindEnd("Bale_boom_purple_026", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->GetTransform().SetLocalPosition({ 70, 80 });
		float4 Pos = Renderer->GetTransform().GetWorldPosition();
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetTransform().SetWorldPosition(Pos);
		Renderer->ScaleToTexture();



	}
		break;
	default:
		break;
	}

	//{ 37, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39, 40, 41, 42, 43, 44, 44, 44, 44 };
}



void Bale::FSM_Skill_BringTentacle_Start(const StateInfo& _Info)
{
	Manager_StatManager->SetDoSkill();
	Texture_Monster->ChangeFrameAnimation("Bale_TentacleSet");
	BringTentacleIndex = 10;

	Actor_Tentacle = GetLevel()->CreateActor<BaleTentacle>();
	Actor_Tentacle->GetTransform().SetLocalPosition(GetTransform().GetWorldPosition());
	Manager_StatManager->SetSuperarmor();

	switch (GameEngineRandom::MainRandom.RandomInt(0, 2))
	{
	case 0:
		SetVoice("bale_skill_03_1.ogg");
		break;
	case 1:
		SetVoice("bale_skill_03_2.ogg");
		break;
	case 2:
		SetVoice("bale_skill_03_3.ogg");
		break;
	default:
		break;
	}



}

void Bale::Bale_TentacleReadyEnd(const FrameAnimation_DESC& _DESC)
{

	if (GameEngineRandom::MainRandom.RandomInt(0, 3) == 0)
	{
		BringTentacleIndex = 17000;
	}
}

void Bale::Bale_TentacleFrame(const FrameAnimation_DESC& _DESC)
{
	if (_DESC.CurFrame == 2)
	{
		if (GameEngineRandom::MainRandom.RandomInt(0, 1) == 0)
		{
			Actor_SpeechPopUp->CreatePopup("찢어주마!");
		}
		else
		{
			Actor_SpeechPopUp->CreatePopup("카카하! 어둠의 송곳니!");
		}
	
		GameEngineSound::SoundPlayControl("scyclone_crash.ogg").Volume(0.9f);

		Actor_Tentacle->CreateTentacle();

		if (Coliision_TentacleHit->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB, std::bind(&Bale::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
		{
			int Dir = Texture_Monster->GetTransform().GetWorldPosition().x - Hit_Player->GetTransform().GetWorldPosition().x > 0 ? -1 : 1;
			Hit_Player->BeHit({ 200, 600, 0, 0 }, HitPostureType::Aerial, nullptr, nullptr, -Dir, 3000);
		}
		//32 36


		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->CreateFrameAnimationFolder("Stone006", FrameAnimation_DESC("Stone006", 0.125f, false));
		Renderer->ChangeFrameAnimation("Stone006");
		Renderer->AnimationBindEnd("Stone006", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->GetTransform().SetLocalPosition({ 70, -60, -1.f });
		float4 Pos = Renderer->GetTransform().GetWorldPosition();
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetTransform().SetWorldPosition(Pos);
		Renderer->ScaleToTexture();

		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->CreateFrameAnimationFolder("Crack005", FrameAnimation_DESC("Crack005", 0, 8, 0.125f, false));
		Renderer->ChangeFrameAnimation("Crack005");
		Renderer->AnimationBindEnd("Crack005", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->GetTransform().SetLocalPosition({ 70, -60, 20.f });
		Pos = Renderer->GetTransform().GetWorldPosition();
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetTransform().SetWorldPosition(Pos);
		Renderer->ScaleToTexture();


		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->CreateFrameAnimationFolder("Bale_boom_purple_026", FrameAnimation_DESC("Bale_boom_purple_026", 15, 28, 0.075f, false));
		Renderer->ChangeFrameAnimation("Bale_boom_purple_026");
		Renderer->SetScaleRatio(1.2f);
		Renderer->AnimationBindEnd("Bale_boom_purple_026", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Death();
			});
		Renderer->GetTransform().SetLocalPosition({ 70, 40 });
		Pos = Renderer->GetTransform().GetWorldPosition();
		Renderer->SetParent(Actor_Dummy);
		Renderer->GetTransform().SetWorldPosition(Pos);
		Renderer->ScaleToTexture();
	}
	

}



void Bale::FSM_Skill_BringTentacle_Update(float _DeltaTime, const StateInfo& _Info)
{

	BringTentacleIndex += GameEngineRandom::MainRandom.RandomInt(10, 50);




	
	if (BringTentacleIndex > 20000)
	{
		Texture_Monster->ChangeFrameAnimation("Bale_TentacleReady", true);
		BringTentacleIndex = 0;
	}

	if (_Info.StateTime > 20.f)
	{
		Manager_StatManager->GetFSMManager().ChangeState("Move_Stand");
	}
}
void Bale::FSM_Skill_BringTentacle_End(const StateInfo& _Info)
{
	All_CollTime["Skill_Tentacle"] = 60.f;
	Manager_StatManager->SetDoSkillEnd();
	Manager_StatManager->SetSuperarmorEnd();
}


void Bale::LevelStartEvent()
{
	SetVoice("bale_meet_01.ogg");

	All_CollTime["Move_Teleport"] = 10.f;
	All_CollTime["Att_Dash"] = 10.f;
	All_CollTime["Skill_Tentacle"] = 25.f;
	All_CollTime["Skill_Tracking"] = 10.f;
}


unsigned int Bale::SetHPFromHit(unsigned int _Damage)
{
	GamePlayMonsterHPBar::SetMonster(this);
	float Def = MonsterAbilityStat.Def;
	if (MonsterAbilityStat.GetDef() > 1000.f)
	{
		Def = 1000.f;
	}
	//if (_Damage)
	//{

	//}
	unsigned int Damage = _Damage / static_cast<unsigned int>(Def); /*- static_cast<unsigned int>((255.f * MonsterAbilityStat.Def) * 0.8f);*/
	if (GameEngineInput::GetInst()->IsPress("Debug6"))
	{
		Damage = 100000000; // 99,999,999
	}


	if (Barrier_HP <= 0)
	{
		if (MonsterAbilityStat.HP < Damage)
		{
			Dead();
			GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
			MonsterAbilityStat.HP = 0;
			GamePlayMonsterHPBar::SetHitDamage(0);
		}
		else
		{
			MonsterAbilityStat.HP -= Damage;
			GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
		}
	}
	else
	{
		GameEngineDamageRenderer* Font = GetLevel()->CreateActor<GameEngineDamageRenderer>();
		Font->GetTransform().SetLocalPosition({ GetTransform().GetLocalPosition().x ,GetTransform().GetLocalPosition().y, -10.f });
		Font->SetDamage(_Damage / 10000, DamageFontClass::TrueDamage);

		Barrier_HP -= _Damage / 10000;


		Damage = -1;
	}
	// 구조짤때 델타타임으로 역경직시간 넣을껄


	return Damage;
}


unsigned int Bale::SetHPFromHit(unsigned int _Damage, const std::vector<float>& _AddDamage)
{
	GamePlayMonsterHPBar::SetMonster(this);

	if (MonsterAbilityStat.Def > 1000.f)
	{
		MonsterAbilityStat.Def = 1000.f;
	}
	//if (_Damage)
	//{

	//}
	unsigned int Damage = _Damage / static_cast<unsigned int>(MonsterAbilityStat.Def); /*- static_cast<unsigned int>((255.f * MonsterAbilityStat.Def) * 0.8f);*/
	if (GameEngineInput::GetInst()->IsPress("Debug6"))
	{
		Damage = 100000000; // 99,999,999
	}
	unsigned int AddDamage = Damage;

	for (float Iter : _AddDamage)
	{
		AddDamage += static_cast<unsigned int>(static_cast<float>(_Damage) * Iter);
	}



	if (Barrier_HP <= 0)
	{
		if (MonsterAbilityStat.HP < AddDamage)
		{
			Dead();
			GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
			MonsterAbilityStat.HP = 0;
			GamePlayMonsterHPBar::SetHitDamage(0);
		}
		else
		{
			MonsterAbilityStat.HP -= AddDamage;
			GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
		}
	}
	else
	{
		GameEngineDamageRenderer* Font = GetLevel()->CreateActor<GameEngineDamageRenderer>();
		Font->GetTransform().SetLocalPosition({ GetTransform().GetLocalPosition().x ,GetTransform().GetLocalPosition().y, -10.f });
		Font->SetDamage(_Damage / 10000, _AddDamage ,DamageFontClass::TrueDamage);

		Barrier_HP -= AddDamage / 10000;
		if (MonsterAbilityStat.HP < AddDamage / 10000)
		{
			Dead();
			GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
			MonsterAbilityStat.HP = 0;
			GamePlayMonsterHPBar::SetHitDamage(0);
		}
		else
		{
			MonsterAbilityStat.HP -= AddDamage / 10000;
			GamePlayMonsterHPBar::SetHitDamage(MonsterAbilityStat.HP);
		}
		Damage = -1;
	}


	return Damage;
}


void Bale::OffEvent()
{
	GamePlayMonster::OffEvent();
	SetVoice("bale_die.ogg");
	Actor_SpeechPopUp->CreatePopup("이럴...수가...");
}