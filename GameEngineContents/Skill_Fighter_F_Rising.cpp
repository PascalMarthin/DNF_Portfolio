#include "PreCompile.h"
#include "Skill_Fighter_F_Rising.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "DummyActor.h"


GameEngineFolderTexture* Skill_Fighter_F_Rising::FolderTexture_Rising_spin = nullptr;
GameEngineFolderTexture* Skill_Fighter_F_Rising::FolderTexture_Tigerstrike_00 = nullptr;
//
//GameEngineFolderTexture* Skill_Fighter_F_Rising::FolderTexture_Rising_spin = nullptr;


Skill_Fighter_F_Rising::Skill_Fighter_F_Rising() 
	: JumpTime(0)
	, LandPos(float4::ZERO)
	, AttDealy(0)
	, DelayPunch(false)
	, HitCount(0)
{
}

Skill_Fighter_F_Rising::~Skill_Fighter_F_Rising() 
{
}

void Skill_Fighter_F_Rising::Start()
{
	Class_Power.push_back(SkillComboPower(200, 1, { 0, 0.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(200, 1, { 0, 500.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(200, 1, { 0, 0.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(200, 1, { 0, 0.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(200, 1, { 0, 0.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	Class_Power.push_back(SkillComboPower(1000, 1, { 100.f, 500.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	//Class_Power.push_back(SkillComboPower(300, 1, { 700.f, 0.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	//Class_Power.push_back(SkillComboPower(400, 1, { 700.f, 0.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));

	Actor_DummyActor = GetActor()->GetLevel()->CreateActor<DummyActor>();
	{
		GameEngineCollision* Rising = GetActor()->CreateComponent<GameEngineCollision>("Rising_Up_1");
		Rising->GetTransform().SetLocalScale({ 150.f, 100.f, 100.f });
		Rising->GetTransform().SetLocalPosition({ 0, 0.f, 0 });
		Rising->ChangeOrder(CollisionOrder::Player_Att);
		Rising->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(Rising);
	}


	{
		GameEngineCollision* Rising = GetActor()->CreateComponent<GameEngineCollision>("Rising_Up_2");
		Rising->GetTransform().SetLocalScale({ 220.f, 100.f, 120.f });
		Rising->GetTransform().SetLocalPosition({ 0, 0.f, 0 });
		Rising->ChangeOrder(CollisionOrder::Player_Att);
		Rising->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(Rising);
	}


	{
		GameEngineCollision* Rising = GetActor()->CreateComponent<GameEngineCollision>("Rising_Down");
		Rising->GetTransform().SetLocalScale({ 150, 60, 80 });
		Rising->GetTransform().SetLocalPosition({ 30, 0, 0 });
		Rising->ChangeOrder(CollisionOrder::Player_Att);
		Rising->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.0f });
		Collision_AllCollisionList.push_back(Rising);
	}

	{
		GameEngineEffectRenderer* Texture_Rising_Spin = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_Rising_spin");
		Texture_Rising_Spin->CreateFrameAnimationFolder("Texture_Rising_spin", FrameAnimation_DESC("Rising_spin",1, 9, 0.075f, false));
		Texture_Rising_Spin->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 0.04f, false));

		Texture_Rising_Spin->AnimationBindEnd("Texture_Rising_spin",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Rising_Spin->ChangeFrameAnimation("Texture_Rising_spin");
		Texture_Rising_Spin->ScaleToTexture();
		Texture_Rising_Spin->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x * 0.8f, Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.5f });

		Texture_Rising_Spin->GetTransform().SetLocalRotate({ 0, 0 , 90});
		Texture_Rising_Spin->GetTransform().SetLocalPosition({ -5 , 25.f, -20.f });
		Texture_Rising_Spin->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Rising_Spin->GetPixelData().MulColor = { 4.f, 2.0f , 0.9f , 1.5f };
		Texture_Rising_Spin->GetPixelData().PlusColor = { 0, 0 ,0 , 1 };
		Texture_Rising_Spin->Off();
		Texture_Rising_spin.push_back(Texture_Rising_Spin); // Small
		

		Texture_Rising_Spin = GetActor()->CreateComponent<GameEngineEffectRenderer>("Texture_Rising_spin");
		Texture_Rising_Spin->CreateFrameAnimationFolder("Texture_Rising_spin", FrameAnimation_DESC("Rising_spin", 2, 9, 0.08f, true));
		Texture_Rising_Spin->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		Texture_Rising_Spin->AnimationBindEnd("Texture_Rising_spin",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Rising_Spin->ChangeFrameAnimation("Texture_Rising_spin");
		Texture_Rising_Spin->SetScaleRatio(1.2f);
		Texture_Rising_Spin->ScaleToTexture();
		Texture_Rising_Spin->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x , Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.8f });
		Texture_Rising_Spin->GetTransform().SetLocalRotate({ 0, 0 , 90 });
		Texture_Rising_Spin->GetTransform().SetLocalPosition({ -10 , -30.f, -20.f });
		Texture_Rising_Spin->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Rising_Spin->GetPixelData().MulColor = { 4.f, 2.0f , 0.9f , 1.5f };
		Texture_Rising_Spin->GetPixelData().PlusColor = { 0, 0 ,0 , 1 };
		Texture_Rising_Spin->Off();
		Texture_Rising_spin.push_back(Texture_Rising_Spin); // Big
	}

	{
		GameEngineEffectRenderer* RisingEffect = GetActor()->CreateComponent<GameEngineEffectRenderer>("RisingEffect");
		RisingEffect->CreateFrameAnimationFolder("RisingEffect", FrameAnimation_DESC("Tigerstrike_00", 1, 4, 0.125f, true));
		RisingEffect->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		RisingEffect->AnimationBindEnd("RisingEffect",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		RisingEffect->ChangeFrameAnimation("RisingEffect");
		RisingEffect->SetScaleRatio(0.8f);
		RisingEffect->ScaleToTexture();
		RisingEffect->GetTransform().SetLocalRotate({ 0, 0  , 105 });
		RisingEffect->GetTransform().SetLocalPosition({ -8.f , 20.f, -10.f });
		RisingEffect->GetPixelData().MulColor = { 1.8f, 1.8f, 3.f, 0.5f };
		RisingEffect->Off();

		Texture_RisingEffect.push_back(RisingEffect);


		RisingEffect = GetActor()->CreateComponent<GameEngineEffectRenderer>("RisingEffect");
		RisingEffect->CreateFrameAnimationFolder("RisingEffect", FrameAnimation_DESC("Tigerstrike_00", 1, 4, 0.125f, true));
		RisingEffect->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		RisingEffect->AnimationBindEnd("RisingEffect",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		RisingEffect->ChangeFrameAnimation("RisingEffect");
		RisingEffect->SetScaleRatio(0.9f);
		RisingEffect->ScaleToTexture();
		RisingEffect->GetTransform().SetLocalRotate({ 0, 0  , -90 });
		RisingEffect->GetTransform().SetLocalPosition({ 20.f , 15.f, -11.f });
		RisingEffect->GetPixelData().MulColor = { 1.8f, 1.8f, 3.f, 0.5f };
		RisingEffect->GetTransform().PixLocalNegativeX();
		RisingEffect->Off();

		Texture_RisingEffect.push_back(RisingEffect); 

		RisingEffect = GetActor()->CreateComponent<GameEngineEffectRenderer>("RisingEffect");
		RisingEffect->CreateFrameAnimationFolder("RisingEffect", FrameAnimation_DESC("Tigerstrike_00", 1, 4, 0.125f, true));
		RisingEffect->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		RisingEffect->AnimationBindEnd("RisingEffect",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		RisingEffect->ChangeFrameAnimation("RisingEffect");
		RisingEffect->SetScaleRatio(0.7f);
		RisingEffect->ScaleToTexture();
		RisingEffect->GetTransform().SetLocalRotate({ 0, 0  , -110 });
		RisingEffect->GetTransform().SetLocalPosition({ 5.f , 25.f, -9.f });
		RisingEffect->GetPixelData().MulColor = { 1.8f, 1.8f, 3.f, 0.5f };
		RisingEffect->GetTransform().PixLocalNegativeX();
		RisingEffect->Off();
		Texture_RisingEffect.push_back(RisingEffect);
	}
	{
		GameEngineEffectRenderer* RisingEffect = GetActor()->CreateComponent<GameEngineEffectRenderer>("RisingEffect");
		RisingEffect->CreateFrameAnimationFolder("RisingEffect", FrameAnimation_DESC("Tigerstrike_00", 5, 9, 0.135f, true));
		RisingEffect->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		RisingEffect->AnimationBindEnd("RisingEffect",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		RisingEffect->ChangeFrameAnimation("RisingEffect");
		RisingEffect->SetScaleRatio(0.75f);
		RisingEffect->ScaleToTexture();
		RisingEffect->GetTransform().SetLocalRotate({ 0, 0  , 85 });
		RisingEffect->GetTransform().SetLocalPosition({ 60.f , 25.f, -8.f });
		RisingEffect->GetPixelData().MulColor = { 0.8f, 0.8f, 1.1f, 0.45f };
		RisingEffect->Off();

		Texture_RisingEffect.push_back(RisingEffect);

		RisingEffect = GetActor()->CreateComponent<GameEngineEffectRenderer>("RisingEffect");
		RisingEffect->CreateFrameAnimationFolder("RisingEffect", FrameAnimation_DESC("Tigerstrike_00", 5, 9, 0.125f, true));
		RisingEffect->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		RisingEffect->AnimationBindEnd("RisingEffect",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		RisingEffect->ChangeFrameAnimation("RisingEffect");
		RisingEffect->SetScaleRatio(0.95f);
		RisingEffect->ScaleToTexture();
		RisingEffect->GetTransform().SetLocalRotate({ 0, 0  , -80 });
		RisingEffect->GetTransform().SetLocalPosition({ -58.f , 10, -8.f });
		RisingEffect->GetTransform().PixLocalNegativeX();
		RisingEffect->GetPixelData().MulColor = { 0.8f, 0.8f, 1.1f, 0.45f };
		RisingEffect->Off();

		Texture_RisingEffect.push_back(RisingEffect);

	}

	{
		
		GameEngineEffectRenderer* Texture_Wind_0 = Actor_DummyActor->CreateComponent<GameEngineEffectRenderer>("Texture_Wind_0");
		Texture_Wind_0->CreateFrameAnimationFolder("Texture_Wind_5", FrameAnimation_DESC("Rising_wind5", 5, 10, 0.2f, false));
		Texture_Wind_0->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_wind", 0.04f, false));
		Texture_Wind_0->AnimationBindEnd("Texture_Wind_5",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Wind_0->ChangeFrameAnimation("Texture_Wind_5");
		Texture_Wind_0->SetScaleRatio(1.2f);
		Texture_Wind_0->ScaleToTexture();
	//	Texture_Wind_0->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x * 0.8f, Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.5f });
		//Texture_Wind_0->GetTransform().SetLocalRotate({ 0, 0 , 90 });
		Texture_Wind_0->GetTransform().SetLocalPosition({ 0 , 0, -20.f });
		Texture_Wind_0->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Wind_0->GetPixelData().MulColor.a = 0.9f;
		Texture_Wind_0->Off();
		Texture_Wind.push_back(Texture_Wind_0);

		Texture_Wind_0 = Actor_DummyActor->CreateComponent<GameEngineEffectRenderer>("Texture_Wind_0");
		Texture_Wind_0->CreateFrameAnimationFolder("Texture_Wind_5", FrameAnimation_DESC("Rising_wind5", 5, 10, 0.2f, false));
		Texture_Wind_0->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_wind", 0.04f, false));
		Texture_Wind_0->AnimationBindEnd("Texture_Wind_5",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Wind_0->ChangeFrameAnimation("Texture_Wind_5");
		Texture_Wind_0->SetScaleRatio(1.8f);
		Texture_Wind_0->ScaleToTexture();
		//	Texture_Wind_0->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x * 0.8f, Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.5f });
			//Texture_Wind_0->GetTransform().SetLocalRotate({ 0, 0 , 90 });
		Texture_Wind_0->GetTransform().SetLocalPosition({ 0 , 0, -20.f });
		Texture_Wind_0->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Wind_0->GetTransform().PixLocalNegativeX();
		Texture_Wind_0->GetPixelData().MulColor.a = 0.9f;
		Texture_Wind_0->Off();
		Texture_Wind.push_back(Texture_Wind_0);

		Texture_Wind_0 = Actor_DummyActor->CreateComponent<GameEngineEffectRenderer>("Texture_Wind_0");
		Texture_Wind_0->CreateFrameAnimationFolder("Texture_Wind_5", FrameAnimation_DESC("Rising_wind5", 0, 4, 0.2f, false));
		Texture_Wind_0->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_wind", 0.04f, false));
		Texture_Wind_0->AnimationBindEnd("Texture_Wind_5",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Wind_0->ChangeFrameAnimation("Texture_Wind_5");
		Texture_Wind_0->SetScaleRatio(1.2f);
		Texture_Wind_0->ScaleToTexture();
		//	Texture_Wind_0->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x * 0.8f, Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.5f });
			//Texture_Wind_0->GetTransform().SetLocalRotate({ 0, 0 , 90 });
		Texture_Wind_0->GetTransform().SetLocalPosition({ 0 , 50, -20.f });
		Texture_Wind_0->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Wind_0->GetTransform().PixLocalNegativeX();
		Texture_Wind_0->GetPixelData().MulColor.a = 0.9f;
		Texture_Wind_0->Off();
		Texture_Wind.push_back(Texture_Wind_0);

		Texture_Wind_0 = Actor_DummyActor->CreateComponent<GameEngineEffectRenderer>("Texture_Wind_0");
		Texture_Wind_0->CreateFrameAnimationFolder("Texture_Wind", FrameAnimation_DESC("Rising_wind", 0, 11, 0.05f, false));
		Texture_Wind_0->CreateFrameAnimationFolder("Texture_Wind_2", FrameAnimation_DESC("Rising_wind", 12, 16, 0.125f, false));
		Texture_Wind_0->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_wind", 0.04f, false));
		Texture_Wind_0->AnimationBindEnd("Texture_Wind",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});

		Texture_Wind_0->AnimationBindEnd("Texture_Wind_2",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Wind_0->ChangeFrameAnimation("Texture_Wind");
		Texture_Wind_0->SetScaleRatio(1.2f);
		Texture_Wind_0->ScaleToTexture();
		//	Texture_Wind_0->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x * 0.8f, Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.5f });
			//Texture_Wind_0->GetTransform().SetLocalRotate({ 0, 0 , 90 });
		Texture_Wind_0->GetTransform().SetLocalPosition({ 0 , 70, -20.f });
		Texture_Wind_0->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Wind_0->GetTransform().PixLocalNegativeX();
		Texture_Wind_0->GetPixelData().MulColor = {1.2f,1.2f,1.2f, 0.7f };
		Texture_Wind_0->Off();
		Texture_Wind.push_back(Texture_Wind_0);
	}

	//{
	//	if (Skill_Fighter_F_Rising::FolderTexture_Rising_spin == nullptr)
	//	{
	//		FolderTexture_Rising_spin = GameEngineFolderTexture::Find("Rising_spin");
	//		FolderTexture_Tigerstrike_00 = GameEngineFolderTexture::Find("FolderTexture_Tigerstrike_00");
	//	}
	//	
	//}


	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_Rising::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{


	switch (int_ComboStuck)
	{
	case 0:
		if (_Avata->GetAvata_Skin()->IsEndFrame())
		{
			_Stat->SetJump();
			_Avata->ChangeAvataAnimation("Att_RisingUpper_Jump");
			LandPos = GetActor()->GetTransform().GetWorldPosition();
			JumpTime = _DeltaTime;
			int_ComboStuck = 1;
			GamePlayCharacter::SetVoice("ft_rising_knuckle_attack.ogg");
			{
				Texture_Rising_spin[0]->ChangeFrameAnimation("None");
				Texture_Rising_spin[0]->ChangeFrameAnimation("Texture_Rising_spin");
				Texture_Rising_spin[0]->On();
			}
			{
				Texture_Rising_spin[1]->ChangeFrameAnimation("None");
				Texture_Rising_spin[1]->ChangeFrameAnimation("Texture_Rising_spin");
				Texture_Rising_spin[1]->On();
			}
			{
				Texture_RisingEffect[0]->ChangeFrameAnimation("None");
				Texture_RisingEffect[0]->ChangeFrameAnimation("RisingEffect");
				Texture_RisingEffect[0]->On();

			}
			{
				Texture_RisingEffect[1]->ChangeFrameAnimation("None");
				Texture_RisingEffect[1]->ChangeFrameAnimation("RisingEffect");
				Texture_RisingEffect[1]->On();

			}
			{
				Texture_RisingEffect[2]->ChangeFrameAnimation("None");
				Texture_RisingEffect[2]->ChangeFrameAnimation("RisingEffect");
				Texture_RisingEffect[2]->On();

			}
			{
				 Texture_RisingEffect[3]->ChangeFrameAnimation("None");
				 Texture_RisingEffect[3]->ChangeFrameAnimation("RisingEffect");
				 Texture_RisingEffect[3]->On();
			}
			{
				Texture_RisingEffect[4]->ChangeFrameAnimation("None");
				Texture_RisingEffect[4]->ChangeFrameAnimation("RisingEffect");
				Texture_RisingEffect[4]->On();
			}


			return false;
		}
		else if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 12 && Is_CollisionCheck ==false)
		{
			Texture_Wind[0]->ChangeFrameAnimation("Texture_Wind_5", true);
			Texture_Wind[0]->On();

			Texture_Wind[1]->ChangeFrameAnimation("Texture_Wind_5", true);
			Texture_Wind[1]->On();

			Texture_Wind[2]->ChangeFrameAnimation("Texture_Wind_5", true);
			Texture_Wind[2]->On();

			Texture_Wind[3]->ChangeFrameAnimation("Texture_Wind", true);
			Texture_Wind[3]->On();

			GameEngineSound::SoundPlayControl("rising_upper_pull.ogg").Volume(0.65f);

			Is_CollisionCheck = true;
		}
		break;
	case 1:
	{
		_Stat->SetJump();


		AttDealy += _DeltaTime;
		JumpTime += _DeltaTime;
		GetActor()->GetTransform().SetLocalMove({ 0, Skill_Rising_High * (JumpTime - _DeltaTime) * 0.7f, 0 });
		if (GetActor()->GetTransform().GetWorldPosition().y >= LandPos.y + Skill_Rising_High) //(JumpTime * 7.5f >= 1.f)
		{
			GetActor()->GetTransform().SetLocalPosition({ LandPos.x, LandPos.y + Skill_Rising_High, LandPos.z });
			_Avata->ChangeAvataAnimation("Att_RisingUpper_Spin");
			JumpTime = 0;
			int_ComboStuck = 2;
			return false;
		}

		if(AttDealy > 0.0125f && HitCount < 3)
		{
			CheckCollision(0);
			Object_HitList.clear();
			++HitCount;
			AttDealy = 0;
		}
		return false;
	}

		break;
	case 2:
		JumpTime += _DeltaTime;
		if (JumpTime >= 0.25f)
		{
			int_ComboStuck = 3;
			JumpTime = 0;
			_Avata->ChangeAvataAnimation("Att_RisingUpper_Down");
			return false;
		}
		break;
	case 3:
		JumpTime += _DeltaTime;
		if (_Avata->GetAvata_Skin()->EndFrame == true)
		{
			int_ComboStuck = 4;
			return false;
		}
		else
		{
			GetActor()->GetTransform().SetLocalPosition(float4::Lerp({ LandPos.x, LandPos.y + Skill_Rising_High, LandPos.z },LandPos, JumpTime * 0.1f));
			return false;
		}
		break;
	case 4:
		_Stat->SetJumpEnd();
		JumpTime += _DeltaTime;
		GetActor()->GetTransform().SetLocalMove({ 0, -Skill_Rising_High * (JumpTime - _DeltaTime), 0 });
		if (GetActor()->GetTransform().GetWorldPosition().y <= LandPos.y)
		{
			_Stat->SetJumpEnd();
			GetActor()->GetTransform().SetLocalPosition(LandPos);
			_Avata->ChangeAvataAnimation("Att_RisingUpper_Landing");
			int_ComboStuck = 5;
			JumpTime = 0;

			Texture_Wind[3]->ChangeFrameAnimation("Texture_Wind_2");
			Texture_Wind[3]->On();

			GameEngineEffectRenderer* RisingEffect = GetActor()->CreateComponent<GameEngineEffectRenderer>("RisingEffect");
			RisingEffect->CreateFrameAnimationFolder("Rising_wave013", FrameAnimation_DESC("Rising_wave013", 1, 4, 0.125f, true));
			RisingEffect->AnimationBindEnd("Rising_wave013",
				[](const FrameAnimation_DESC& _Desc)
				{
					_Desc.Renderer->Death();
				});
			RisingEffect->ChangeFrameAnimation("Rising_wave013");
			RisingEffect->SetScaleRatio(1.f);
			RisingEffect->ScaleToTexture();
			RisingEffect->GetTransform().SetLocalPosition({ 0.f , 70.f, -10.f });
			RisingEffect->GetPixelData().MulColor = { 1.f,1.f,1.f, 1.8f };

			CheckCollision(0);
			Object_HitList.clear();

			return false;
		}


		break;
	case 5:
		JumpTime += _DeltaTime; // Delay
		if (JumpTime * 2.f >= 1.f)
		{
			_Stat->SetSuperarmorEnd();
			return true;
		}
		break;
	default:
		break;
	}
	return false;

	//if (Is_CollisionCheck == true)
	//{
	//	Att_ClosePunch_Delay += _DeltaTime;
	//	if (int_ComboStuck == 1)
	//	{
	//		if (Bool_Texture_W_Middle_d_Start == false && Att_ClosePunch_Delay >= _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 2.f)
	//		{
	//			_Avata->SetShake(10, _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 6.f);
	//			Texture_W_Middle_d->On();
	//			Bool_Texture_W_Middle_d_Start = true;
	//		}
	//		else if (Texture_Punch02->IsUpdate())
	//		{
	//			_Avata->SetAllAvataAutoControl(false);
	//		}

	//	}
	//	else if (Att_ClosePunch_Delay >= _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 6.f)
	//	{
	//		_Avata->SetAllAvataAutoControl(false);
	//	}

	//	if (_Avata->GetAvata_Skin()->IsEndFrame())
	//	{
	//		Off();
	//		return true;
	//	}
	//}


}

bool Skill_Fighter_F_Rising::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	switch (int_ComboStuck)
	{
	case 0:

	{
		//const float4& _OtherPos = _Other->GetActor()->GetTransform().GetWorldPosition();
		//if (_OtherPos.x >= _This->GetActor()->GetTransform().GetWorldPosition().x)
		//{
		//	Texture_Punch02->GetTransform().SetWorldPosition({ _Other->GetTransform().GetLocalScale().hx() + _OtherPos.x, Texture_Punch02->GetTransform().GetWorldPosition().y, Texture_Punch02->GetTransform().GetWorldPosition().z - 1.1f });
		//	Texture_Punch03->GetTransform().SetWorldPosition({ _Other->GetTransform().GetLocalScale().hx() + _OtherPos.x, Texture_W_Back_d->GetTransform().GetWorldPosition().y, Texture_W_Back_d->GetTransform().GetWorldPosition().z - 1.2f });
		//}
		//else
		//{
		//	Texture_Punch02->GetTransform().SetWorldPosition({ _OtherPos.x - _Other->GetTransform().GetLocalScale().hx(), Texture_Punch02->GetTransform().GetWorldPosition().y, Texture_Punch02->GetTransform().GetWorldPosition().z - 1.1f });
		//	Texture_Punch03->GetTransform().SetWorldPosition({ _OtherPos.x - _Other->GetTransform().GetLocalScale().hx() , Texture_W_Back_d->GetTransform().GetWorldPosition().y, Texture_W_Back_d->GetTransform().GetWorldPosition().z - 1.2f });
		//}
	}
	break;
	case 1:
		if (!Object_HitList.empty())
		{
			 GameEngineSound::SoundPlayControl("bgloveb_Hit_02.ogg").Volume(0.6f);
		}
		break;
	default:
		break;
	}

	// 강제경직 함수 필요
	return false;
}

void Skill_Fighter_F_Rising::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	GamePlayCharacter::SetVoice("ft_rising_knuckle_dash.ogg");
	
	_Avata->SetSuperArmor();
	_Stat->SetSuperarmor();
	_Avata->ChangeAvataAnimation("Att_RisingUpper_Ready");
	int_ComboStuck = 0;
	JumpTime = 0;
	LandPos = GetActor()->GetTransform().GetWorldPosition();
	Actor_DummyActor->GetTransform().SetLocalPosition(LandPos);
	_Avata->SetShake(2.f, 0.2f);
	AttDealy = 0;
	HitCount = 0;



}

void Skill_Fighter_F_Rising::EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Stat->SetSuperarmorEnd();
}

