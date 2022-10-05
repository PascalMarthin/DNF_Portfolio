#include "PreCompile.h"
#include "Skill_Fighter_F_StrongLowKick.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "Dungeon_Luke.h"

Skill_Fighter_F_StrongLowKick::Skill_Fighter_F_StrongLowKick() 
{
}

Skill_Fighter_F_StrongLowKick::~Skill_Fighter_F_StrongLowKick() 
{
}


void Skill_Fighter_F_StrongLowKick::Start()
{
	GamePlaySkill::Start();

	Class_Power.push_back(SkillComboPower(200, 1, { 0, 10.f, 0.f, 10.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(200, 1, { 0, 10.f, 0.f, 10.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(200, 1, { 0, 10.f, 0.f, 10.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(500000, 1, { 0, 0.f, 0.f, 200.f }, HitPostureType::Standing, HitType::Hit));
	{
		GameEngineCollision* LowKick = GetActor()->CreateComponent<GameEngineCollision>("LowKick");
		LowKick->GetTransform().SetLocalScale({ 800.f, 100.f, 500.f });
		LowKick->GetTransform().SetLocalPosition({ 50, -20.f, 0 });
		LowKick->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 , 0, 0 });
		Collision_AllCollisionList.push_back(LowKick);


		LowKick = GetActor()->CreateComponent<GameEngineCollision>("LowKick");
		LowKick->GetTransform().SetLocalScale({ 300.f, 200.f, 300.f });
		LowKick->GetTransform().SetLocalPosition({ 50, -20.f, 0 });
		LowKick->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 , 0, 0 });
		Collision_AllCollisionList.push_back(LowKick);
	}

	{
		Texture_BackGround = GetActor()->CreateComponent<GameEngineEffectRenderer>("BlackBack");
		Texture_BackGround->GetTransform().SetLocalScale({ 3500, 1300, 0 });
		Texture_BackGround->GetTransform().SetWorldPosition({ 0, 0, -0.001f });
		Texture_BackGround->SetTexture("BlackBackground.png");
		Texture_BackGround->SetPivot(PIVOTMODE::LEFTTOP);
		Texture_BackGround->GetPixelData().MulColor.a = 0.3f;
		Texture_BackGround->GetPixelData().PlusColor = { 0.7f, 0.3f , 0, 0 };
		Texture_BackGround->Off();
	}


	{

		GameEngineEffectRenderer* Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Lowkick");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_start",FrameAnimation_DESC("StrongestLowKick_start",0, 0 , 0.75f, false));
		Renderer->AnimationBindEnd("StrongestLowKick_start", std::bind(&Skill_Fighter_F_StrongLowKick::StrongestLowKick_startEnd, this, std::placeholders::_1));
		Renderer->ChangeFrameAnimation("StrongestLowKick_start");
		Renderer->ScaleToTexture();
		Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Renderer->GetPixelData().PlusColor.a = 0.8f;
		Renderer->GetPixelData().MulColor = {1.5f, 1.5f, 1.2f};
		Renderer->GetTransform().SetLocalPosition({ 30, -20, 50 });
		Renderer->Off();

		Texture_Start.push_back(Renderer);

		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Lowkick");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_start", FrameAnimation_DESC("StrongestLowKick_start", 1, 1, 0.75f, false));
		Renderer->AnimationBindEnd("StrongestLowKick_start", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ChangeFrameAnimation("StrongestLowKick_start");
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetLocalPosition({ 30, -20, 50 });
		Renderer->Off();

		Texture_Start.push_back(Renderer);

		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Lowkick");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_start", FrameAnimation_DESC("StrongestLowKick_start", 2, 2, 0.75f, false));
		Renderer->AnimationBindEnd("StrongestLowKick_start", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Renderer->ChangeFrameAnimation("StrongestLowKick_start");
		Renderer->ScaleToTexture();
		Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Renderer->GetTransform().SetLocalPosition({ 30, -20, 50});
		Renderer->GetPixelData().PlusColor.a = 0.8f;
		Renderer->GetPixelData().MulColor = { 1.5f, 1.5f, 1.2f };
		Renderer->Off();

		Texture_Start.push_back(Renderer);



	}

	{
		Texture_Spin = GetActor()->CreateComponent<GameEngineEffectRenderer>("Spin");
		Texture_Spin->CreateFrameAnimationFolder("StrongestLowKick_spin", FrameAnimation_DESC("StrongestLowKick_spin", 0.08f, false));
		Texture_Spin->AnimationBindEnd("StrongestLowKick_spin", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Texture_Spin->ChangeFrameAnimation("StrongestLowKick_spin");
		Texture_Spin->GetTransform().SetLocalPosition({ 0, -30, -0.1f });
		Texture_Spin->ScaleToTexture();
		Texture_Spin->Off();


		Texture_Spin_dust = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_Spin_dust");
		Texture_Spin_dust->CreateFrameAnimationFolder("StrongestLowKick_spin_dust", FrameAnimation_DESC("StrongestLowKick_spin_dust", 0.0625f, false));
		Texture_Spin_dust->AnimationBindEnd("StrongestLowKick_spin_dust", [](const FrameAnimation_DESC& _DESC)
			{
				_DESC.Renderer->Off();
			});
		Texture_Spin_dust->ChangeFrameAnimation("StrongestLowKick_spin_dust");
		Texture_Spin_dust->GetTransform().SetLocalPosition({ 10, -35, 50 });
		Texture_Spin_dust->ScaleToTexture();
		Texture_Spin_dust->Off();
	}

	{
		GameEngineEffectRenderer* Renderer =  GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_Leg");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_leg", FrameAnimation_DESC("StrongestLowKick_in-circle", 0.0625f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_leg");
		Renderer->GetTransform().SetLocalPosition({ -20, -12, -10.f });
		Renderer->GetPixelData().MulColor.a = 0.9f;
		Renderer->SetScaleRatio(1.7f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		vector_Texture_Leg.push_back(Renderer);
			
		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_Leg");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_leg", FrameAnimation_DESC("StrongestLowKick_in-line", 0.0625f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_leg");
		Renderer->GetTransform().SetLocalPosition({ -20, -12, -10.f });
		Renderer->GetPixelData().MulColor.a = 0.9f;
		Renderer->SetScaleRatio(1.7f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		vector_Texture_Leg.push_back(Renderer);
			
		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_Leg");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_leg", FrameAnimation_DESC("StrongestLowKick_leg", 1, 4, 0.0625f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_leg");
		Renderer->GetTransform().SetLocalPosition({ -38, -14, -10.f });
		Renderer->ScaleToTexture();
		Renderer->Off();


		vector_Texture_Leg.push_back(Renderer);
	}

	{
		GameEngineEffectRenderer* Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_wind", FrameAnimation_DESC("StrongestLowKick_wind-1", 0.075f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_wind");
		Renderer->SetPivot(PIVOTMODE::LEFTBOT);
		Renderer->GetTransform().SetLocalPosition({ -40, -20,  0.0001f });
		Renderer->SetScaleRatio(1.5f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		vector_Texture_Wind.push_back(Renderer);

		std::vector<unsigned int> Int2 = {  7, 8, 9, 10, 11, 12, 0, 1, 2, 3, 4, 5, 6};

		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_wind", FrameAnimation_DESC("StrongestLowKick_wind-2", Int2, 0.075f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_wind");
		Renderer->SetPivot(PIVOTMODE::LEFTTOP);
		Renderer->GetTransform().SetLocalPosition({ -40, 0,  0.0001f });
		Renderer->SetScaleRatio(1.5f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		vector_Texture_Wind.push_back(Renderer);

		
		std::vector<unsigned int> Int3 = {4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2, 3};

		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_wind", FrameAnimation_DESC("StrongestLowKick_wind-3", Int3, 0.075f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_wind");
		Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->GetTransform().SetLocalPosition({ -40, 0,  0.0001f });
		Renderer->SetScaleRatio(1.5f);
		Renderer->ScaleToTexture();
		Renderer->Off();

		vector_Texture_Wind.push_back(Renderer);

		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_wind", FrameAnimation_DESC("StrongestLowKick_wind-circle", 0.075f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_wind");
		Renderer->GetTransform().SetLocalPosition({ -30, -10, 0.001f });
		Renderer->ScaleToTexture();
		Renderer->Off();

		vector_Texture_Wind.push_back(Renderer);
	}

	{
		std::vector<unsigned int> Int3 = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2, 3 };

		GameEngineEffectRenderer* Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_wind", FrameAnimation_DESC("StrongestLowKick_wind-1", Int3, 0.075f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_wind");
		Renderer->SetPivot(PIVOTMODE::LEFTBOT);
		Renderer->GetTransform().SetLocalPosition({ -20, -20, 0 });
		Renderer->GetTransform().PixLocalNegativeY();
		Renderer->GetTransform().PixLocalNegativeX();
		Renderer->SetScaleRatio(1.5f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		vector_Texture_Wind.push_back(Renderer);

	

		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_wind", FrameAnimation_DESC("StrongestLowKick_wind-2", 0.075f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_wind");
		Renderer->SetPivot(PIVOTMODE::LEFTTOP);
		Renderer->GetTransform().SetLocalPosition({ -15, -10, 0 });
		Renderer->GetTransform().PixLocalNegativeY();
		Renderer->GetTransform().PixLocalNegativeX();
		Renderer->SetScaleRatio(1.5f);
		Renderer->ScaleToTexture();
		Renderer->Off();
		vector_Texture_Wind.push_back(Renderer);


		std::vector<unsigned int> Int2 = { 7, 8, 9, 10, 11, 12, 0, 1, 2, 3, 4, 5, 6 };

		Renderer = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Renderer->CreateFrameAnimationFolder("StrongestLowKick_wind", FrameAnimation_DESC("StrongestLowKick_wind-3", Int2, 0.075f, true));
		Renderer->ChangeFrameAnimation("StrongestLowKick_wind");
		Renderer->GetTransform().PixLocalNegativeX();
		Renderer->SetPivot(PIVOTMODE::LEFT);
		Renderer->GetTransform().SetLocalPosition({ -10, 0, 0 });
		Renderer->SetScaleRatio(1.5f);
		Renderer->ScaleToTexture();
		Renderer->Off();

		vector_Texture_Wind.push_back(Renderer);
	}

	// 각성
	{
		Texture_1stFace = GetActor()->CreateComponent<GameEngineUIRenderer>("1stFace");
		Texture_1stFace->SetTexture("1stCutin.png");
		Texture_1stFace->SetParent(Actor_DummyActor);
		Texture_1stFace->GetTransform().SetWorldPosition({-GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() });
		Texture_1stFace->SetScaleRatio(1.2f);
		Texture_1stFace->SetPivot(PIVOTMODE::LEFTBOT);
		Texture_1stFace->ScaleToTexture();
		Texture_1stFace->Off();
	}

	{
		Texture_AttLowKick = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Texture_AttLowKick->CreateFrameAnimationFolder("StrongestLowKick_attackt", FrameAnimation_DESC("StrongestLowKick_attackt", 0.125f, false));
		Texture_AttLowKick->ChangeFrameAnimation("StrongestLowKick_attackt");
		Texture_AttLowKick->GetTransform().SetLocalPosition({ -38, -14, -10.f });
		Texture_AttLowKick->SetScaleRatio(1.2f);
		Texture_AttLowKick->ScaleToTexture();
		Texture_AttLowKick->AnimationBindEnd("StrongestLowKick_attackt", std::bind(&Skill_Fighter_F_StrongLowKick::AttLowKickEnd, this, std::placeholders::_1));
		Texture_AttLowKick->Off();
	}

	// 히트

	{
		{
			GameEngineUIRenderer* Renderer = GetActor()->CreateComponent<GameEngineUIRenderer>("Texture_wind");
			Renderer->CreateFrameAnimationFolder("StrongestLowKick_finish", FrameAnimation_DESC("StrongestLowKick_finish", 0.5f, false));
			Renderer->ChangeFrameAnimation("StrongestLowKick_finish");
			Renderer->SetParent(Actor_DummyActor);
			Renderer->SetPivot(PIVOTMODE::LEFTTOP);
			Renderer->GetTransform().SetLocalPosition({ -GameEngineWindow::GetScale().hx(), GameEngineWindow::GetScale().hx(), 100 });
			Renderer->AnimationBindEnd("StrongestLowKick_finish", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->Off();
				});
			Renderer->SetScaleRatio(1.2f);
			Renderer->ScaleToTexture();
			Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
			Renderer->Off();

			vector_finish.push_back(Renderer);

			Renderer = GetActor()->CreateComponent<GameEngineUIRenderer>("Texture_wind");
			Renderer->CreateFrameAnimationFolder("StrongestLowKick_finish", FrameAnimation_DESC("StrongestLowKick_finish", 0.5f, false));
			Renderer->ChangeFrameAnimation("StrongestLowKick_finish");
			Renderer->SetParent(Actor_DummyActor);
			Renderer->SetPivot(PIVOTMODE::RIGHTTOP);
			Renderer->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), GameEngineWindow::GetScale().hx(), 100 });
			Renderer->AnimationBindEnd("StrongestLowKick_finish", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->Off();
				});
			Renderer->SetScaleRatio(1.2f);
			Renderer->ScaleToTexture();
			Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
			Renderer->Off();

			vector_finish.push_back(Renderer);

			Renderer = GetActor()->CreateComponent<GameEngineUIRenderer>("Texture_wind");
			Renderer->CreateFrameAnimationFolder("StrongestLowKick_finish", FrameAnimation_DESC("StrongestLowKick_finish", 0.5f, false));
			Renderer->ChangeFrameAnimation("StrongestLowKick_finish");
			Renderer->SetParent(Actor_DummyActor);
			Renderer->SetPivot(PIVOTMODE::RIGHTBOT);
			Renderer->GetTransform().SetLocalPosition({ GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hx(), 100 });
			Renderer->AnimationBindEnd("StrongestLowKick_finish", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->Off();
				});
			Renderer->SetScaleRatio(1.2f);
			Renderer->ScaleToTexture();
			Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
			Renderer->Off();

			vector_finish.push_back(Renderer);

			Renderer = GetActor()->CreateComponent<GameEngineUIRenderer>("Texture_wind");
			Renderer->CreateFrameAnimationFolder("StrongestLowKick_finish", FrameAnimation_DESC("StrongestLowKick_finish", 0.5f, false));
			Renderer->AnimationBindEnd("StrongestLowKick_finish", [](const FrameAnimation_DESC& _DESC)
				{
					_DESC.Renderer->Off();
				});
			Renderer->ChangeFrameAnimation("StrongestLowKick_finish");
			Renderer->SetParent(Actor_DummyActor);
			Renderer->SetPivot(PIVOTMODE::LEFTBOT);
			Renderer->GetTransform().SetLocalPosition({ -GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hx(), 100 });
			Renderer->SetScaleRatio(1.2f);
			Renderer->ScaleToTexture();
			Renderer->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
			Renderer->Off();

			vector_finish.push_back(Renderer);
		}


		Texture_universe = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Texture_universe->CreateFrameAnimationFolder("StrongestLowKick_finish", FrameAnimation_DESC("StrongestLowKick_universe", 0.125f, false));
		Texture_universe->ChangeFrameAnimation("StrongestLowKick_finish");
		Texture_universe->SetParent(Actor_DummyActor);
		Texture_universe->GetTransform().SetWorldPosition({ GetTransform().GetWorldPosition().x + (GetActor()->GetTransform().GetWorldScale().x > 0 ? 1.f : -1.f) * 50.f, GetTransform().GetWorldPosition().y - 30.f, 0.001f});
		//Texture_universe->GetTransform().SetWorldPosition({ GetTransform().GetWorldPosition().x , GetTransform().GetWorldPosition().y , 0 });
		Texture_universe->SetScaleRatio(2.5f);
		Texture_universe->ScaleToTexture();
		Texture_universe->Off();

		Texture_typeC = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_wind");
		Texture_typeC->CreateFrameAnimationFolder("StrongestLowKick_finish", FrameAnimation_DESC("StrongestLowKick_type-c", 0.1f, false));
		Texture_typeC->ChangeFrameAnimation("StrongestLowKick_finish");
		Texture_typeC->AnimationBindEnd("StrongestLowKick_finish", std::bind(&Skill_Fighter_F_StrongLowKick::AttSkillEnd, this, std::placeholders::_1));
		Texture_typeC->GetTransform().SetLocalPosition({ 38, -14, -100.f });
		Texture_typeC->SetScaleRatio(1.2f);
		Texture_typeC->ScaleToTexture();
		Texture_typeC->Off();
	}
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}


void Skill_Fighter_F_StrongLowKick::AttSkillEnd(const FrameAnimation_DESC& _DESC)
{
	int_ComboStuck = 4;
}


void Skill_Fighter_F_StrongLowKick::AttLowKickEnd(const FrameAnimation_DESC& _DESC)
{
	_DESC.Renderer->Off();
	int_ComboStuck = 3;		
	map_AllBool[StrongLowKickPoint::Kick] = false;
	Is_CollisionCheck = false;
}

void Skill_Fighter_F_StrongLowKick::StrongestLowKick_startEnd(const FrameAnimation_DESC& _DESC)
{
	map_AllBool[StrongLowKickPoint::StartEffectEnd] = true;
	_DESC.Renderer->Off();
}

void Skill_Fighter_F_StrongLowKick::Update(float _DeltaTime)
{
	GamePlaySkill::Update(_DeltaTime);
	if (map_AllBool[StrongLowKickPoint::CameraZoomOn] == true && map_AllBool[StrongLowKickPoint::CameraZoomOff] == false)
	{
		CameraZoomDelay += _DeltaTime * 15.f;
		const float4& WindowScale = GameEngineWindow::GetScale();


		const float4& CamWorldPos = GetActor()->GetLevel()->GetMainCameraActor()->GetTransform().GetWorldPosition();
		const float4& PlayerWorldPos = GetActor()->GetTransform().GetWorldPosition();
		
		if (CameraZoomDelay > 1.f)
		{
			CameraZoomDelay = 1.f;
			map_AllBool[StrongLowKickPoint::CameraZoomOff] = true;
		}
		float X =((WindowScale.x * -0.4f + (PlayerWorldPos.x - CamWorldPos.x) * -0.4f) * CameraZoomDelay) - (GetActor()->GetTransform().GetWorldScale().x > 0 ? 50.f : -50.f);
		float Y = ((WindowScale.y * -0.4f + (PlayerWorldPos.y - CamWorldPos.y) * 0.4f) * CameraZoomDelay) - 50.f;



		GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().TopLeftX = ((WindowScale.x * -0.4f + (PlayerWorldPos.x - CamWorldPos.x) * -0.9f - (GetActor()->GetTransform().GetWorldScale().x > 0 ? 50.f : -50.f)) * CameraZoomDelay) ;
		GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().TopLeftY = ((WindowScale.y * -0.4f + (PlayerWorldPos.y - CamWorldPos.y) * 0.9f - 50.f) * CameraZoomDelay) ;
		GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().Width = WindowScale.x * (1.f - CameraZoomDelay) + WindowScale.x * 1.8f * CameraZoomDelay;
		GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().Height = WindowScale.y * (1.f - CameraZoomDelay) + WindowScale.y * 1.8f * CameraZoomDelay;

	}

}

bool Skill_Fighter_F_StrongLowKick::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 0: 
	{
		if (Texture_1stFace->IsUpdate())
		{
			Texture_1stFace->GetTransform().SetLocalMove({ _DeltaTime * 1000.f, 0 });
			if (Texture_1stFace->GetTransform().GetWorldPosition().x >= -GameEngineWindow::GetScale().hx())
			{
				Texture_1stFace->GetTransform().SetWorldPosition({ -GameEngineWindow::GetScale().hx() , -GameEngineWindow::GetScale().hy() });
			}
		}
		



		if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 3 && map_AllBool[StrongLowKickPoint::StartEvent] == false)
		{
			GameEngineSound::SoundPlayControl("strong_lowkick.ogg").Volume(0.8f);
			CheckCollision(0);
			for (size_t i = 0; i < Texture_Start.size(); i++)
			{
				Texture_Start[i]->ChangeFrameAnimation("StrongestLowKick_start", true);
				Texture_Start[i]->On();
			}

			{
				Texture_BackGround->GetPixelData().MulColor.a = 0.4f;
				Texture_BackGround->GetPixelData().PlusColor = { 0.7f, 0.3f , 0, 0 };
				Texture_BackGround->On();
			}

			map_AllBool[StrongLowKickPoint::StartEvent] = true;
		}
		else if(map_AllBool[StrongLowKickPoint::StartEffectEnd] == true)
		{
			_Avata->ChangeAvataAnimation("Att_StrongLowKick_Spin");

			Texture_Spin->ChangeFrameAnimation("StrongestLowKick_spin", true);
			Texture_Spin->On();

			Texture_Spin_dust->ChangeFrameAnimation("StrongestLowKick_spin_dust", true);
			Texture_Spin_dust->On();
			Texture_BackGround->Off();

			GameEngineSound::SoundPlayControl("strong_lowkick_ready.ogg").Volume(0.75f);

			GamePlayCharacter::SetVoice("ft_fin_lowkick_get.ogg");

			int_ComboStuck = 1;
		}

		if (Texture_BackGround->IsUpdate())
		{
			Texture_BackGround->GetPixelData().MulColor.a -= _DeltaTime * 2.f;
			if (Texture_BackGround->GetPixelData().MulColor.a <= 0)
			{
				Texture_BackGround->GetPixelData().MulColor.a = 0;
				Texture_BackGround->Off();
			}
		}
	}
		break;
	case 1:
	{
		if (Texture_1stFace->IsUpdate())
		{
			Texture_1stFace->GetTransform().SetLocalMove({ -_DeltaTime * 700.f, 0 });
			if (Texture_1stFace->GetTransform().GetWorldPosition().x <= -GameEngineWindow::GetScale().hx() - 300.f)
			{
				Texture_1stFace->GetTransform().SetWorldPosition({ -GameEngineWindow::GetScale().hx() - 300.f, -GameEngineWindow::GetScale().hy() });
				Texture_1stFace->Off();
			}
		}

		if (_Avata->GetAvata_Skin()->EndFrame == true)
		{
			for (size_t i = 0; i < vector_Texture_Leg.size(); i++)
			{
				vector_Texture_Leg[i]->ChangeFrameAnimation("StrongestLowKick_leg", true);
				vector_Texture_Leg[i]->On();
			}

			for (size_t i = 0; i < vector_Texture_Wind.size(); i++)
			{
				vector_Texture_Wind[i]->ChangeFrameAnimation("StrongestLowKick_wind", true);
				vector_Texture_Wind[i]->On();
			}

			switch (GameEngineRandom::MainRandom.RandomInt(0, 1))
			{
			case 0:
				GameEngineSound::SoundPlayControl("strong_lowkick_get_01.ogg").Volume(0.75f);
				break;
			case 1:
				GameEngineSound::SoundPlayControl("strong_lowkick_get_02.ogg").Volume(0.75f);
				break;
			default:
				break;
			}

			Sound_Wind = GameEngineSound::SoundPlayControl("strong_lowkick_loop.ogg", -1);
			Sound_Wind.Volume(0.6f);

			_Avata->ChangeAvataAnimation("Att_StrongLowKick_ing");



			int_ComboStuck = 2;
		}
	}
		break;
	case 2:
	{	
		Dungeon_Luke* Map = GetActor()->GetLevel<Dungeon_Luke>();

		float Power = 400.f;
		
		if (GameEngineInput::GetInst()->IsDown("Jump"))
		{
			Power = 800.f;
		}
		else if(GameEngineInput::GetInst()->IsDown("BaseAtt") && map_AllBool[StrongLowKickPoint::Kick] == false)
		{
			Sound_Wind.Stop();

			for (size_t i = 0; i < vector_Texture_Leg.size(); i++)
			{
				//vector_Texture_Leg[i]->ChangeFrameAnimation("StrongestLowKick_leg", true);
				vector_Texture_Leg[i]->Off();
			}

			for (size_t i = 0; i < vector_Texture_Wind.size(); i++)
			{
			//	vector_Texture_Wind[i]->ChangeFrameAnimation("StrongestLowKick_wind", true);
				vector_Texture_Wind[i]->Off();
			}
			GameEngineSound::SoundPlayControl("strong_lowkick_flash.ogg").Volume(0.75f);
			Texture_AttLowKick->ChangeFrameAnimation("StrongestLowKick_attackt", true);
			Texture_AttLowKick->On();

			map_AllBool[StrongLowKickPoint::Kick] = true;



		}


		if (Map != nullptr)
		{
			float4 Pos = { GetTransform().GetWorldPosition().x + (50 * (GetTransform().GetWorldScale().x > 0 ? 1.f : -1.f)), GetTransform().GetWorldPosition().y - 30, GetTransform().GetWorldPosition().y - 30 };
			for (auto& Iter : Map->GetAllMonster())
			{
				float4 Dir = Pos - Iter->GetTransform().GetWorldPosition();
				Dir.Normalize();

				Iter->GetMoveManager()->SetCharacterMoveCheck(Dir * Power * _DeltaTime, Pos);
			}
		}
	}
	break;
	case 3:
	{
		if (map_AllBool[StrongLowKickPoint::Kick] == false)
		{
			GameEngineSound::SoundPlayControl("strong_lowkick_swing.ogg").Volume(0.75f);
			_Avata->ChangeAvataAnimation("Att_StrongLowKick_Kick");
			map_AllBool[StrongLowKickPoint::Kick] = true;
			return false;
		}

		if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 2 && Is_CollisionCheck == false)
		{

			Object_HitList.clear();
			CheckCollision(1);
			if (map_AllBool[StrongLowKickPoint::Hit] == true)
			{
				GamePlayCharacter::SetVoice("ft_fin_lowkick_fin.ogg");
				for (size_t i = 0; i < vector_finish.size(); i++)
				{
					vector_finish[i]->ChangeFrameAnimation("StrongestLowKick_finish", true);
					vector_finish[i]->On();
				}

				Texture_typeC->ChangeFrameAnimation("StrongestLowKick_finish", true);
				Texture_typeC->On();

				GameEngineSound::SoundPlayControl("3rd_strong_lowkick_hit.ogg").Volume(0.8f);

				Texture_universe->GetTransform().SetWorldPosition({ GetTransform().GetWorldPosition().x + (GetActor()->GetTransform().GetWorldScale().x > 0 ? 1.f : -1.f) * 50.f, GetTransform().GetWorldPosition().y - 30.f, 0.001f });
				Texture_universe->On();

				map_AllBool[StrongLowKickPoint::CameraZoomOn] = true;
			}
			else
			{

				map_AllBool[StrongLowKickPoint::NoHItDelay] = true;
			}
			Is_CollisionCheck = true;
		}

		if (true)
		{

		}

		if (map_AllBool[StrongLowKickPoint::NoHItDelay] == true && _Avata->GetAvata_Skin()->EndFrame)
		{
			int_ComboStuck = 4;
		}

	
	}
	break;
	case 4:
	{
		if (map_AllBool[StrongLowKickPoint::CameraZoomOn] == true && map_AllBool[StrongLowKickPoint::CameraZoomOff] == true)
		{

			CameraZoomDelay -= _DeltaTime * 10.f;
			const float4& WindowScale = GameEngineWindow::GetScale();


			const float4& CamWorldPos = GetActor()->GetLevel()->GetMainCameraActor()->GetTransform().GetWorldPosition();
			const float4& PlayerWorldPos = GetActor()->GetTransform().GetWorldPosition();

			if (CameraZoomDelay < 0)
			{
				return true;
			}
			else
			{
				GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().TopLeftX = ((WindowScale.x * -0.4f + (PlayerWorldPos.x - CamWorldPos.x) * -0.9f - (GetActor()->GetTransform().GetWorldScale().x > 0 ? 50.f : -50.f)) * CameraZoomDelay);
				GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().TopLeftY = ((WindowScale.y * -0.4f + (PlayerWorldPos.y - CamWorldPos.y) * 0.9f - 50.f) * CameraZoomDelay);
				GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().Width = WindowScale.x * 1.8f * CameraZoomDelay + WindowScale.x * (1.f- CameraZoomDelay);
				GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().Height = WindowScale.y * 1.8f * CameraZoomDelay + WindowScale.y * (1.f - CameraZoomDelay);
			}
			return false;
			
		}
		else
		{
			return true;
		}


	
	}
	break;
	default:
		break;
	}



	return false;

}
bool Skill_Fighter_F_StrongLowKick::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	map_AllBool[StrongLowKickPoint::Hit] = true;

	return false;
}

void Skill_Fighter_F_StrongLowKick::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	int_ComboStuck = 0;

	GamePlayCharacter::SetVoice("ft_fin_lowkick.ogg");

	_Avata->ChangeAvataAnimation("Att_StrongLowKick_Ready");

	Texture_1stFace->GetTransform().SetWorldPosition({ -GameEngineWindow::GetScale().hx() - 300.f, -GameEngineWindow::GetScale().hy() });
	Texture_1stFace->On();

	{
		map_AllBool[StrongLowKickPoint::StartEvent] = false;
		map_AllBool[StrongLowKickPoint::StartEffectEnd] = false;
		map_AllBool[StrongLowKickPoint::Kick] = false;
		map_AllBool[StrongLowKickPoint::Hit] = false;
		map_AllBool[StrongLowKickPoint::EndSkill] = false;
		map_AllBool[StrongLowKickPoint::NoHItDelay] = false;
		map_AllBool[StrongLowKickPoint::CameraZoomOn] = false;
		map_AllBool[StrongLowKickPoint::CameraZoomOff] = false;
		
	}
	Is_CollisionCheck = true;
	_Stat->SetInvincibility();
	EndDelay = 0;
	CameraZoomDelay = 0;
}

void Skill_Fighter_F_StrongLowKick::EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	Texture_BackGround->Off();
	_Stat->SetInvincibilityEnd();
	Texture_universe->Off();
	Texture_typeC->Off();

	for (size_t i = 0; i < vector_finish.size(); i++)
	{
		vector_finish[i]->Off();
	}
	Sound_Wind.Stop();
	Texture_1stFace->GetTransform().SetWorldPosition({ -GameEngineWindow::GetScale().hx(), -GameEngineWindow::GetScale().hy() });

	const float4& WindowScale = GameEngineWindow::GetScale();

	GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().TopLeftX = 0;
	GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().TopLeftY = 0;
	GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().Width = WindowScale.x;
	GetActor()->GetLevel()->GetMainCamera()->GetViewDesc().Height = WindowScale.y;
}
