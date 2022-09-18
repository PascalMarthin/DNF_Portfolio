#include "PreCompile.h"
#include "Skill_Fighter_F_LightingDance.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

Skill_Fighter_F_LightingDance::Skill_Fighter_F_LightingDance()
	: Collision_CheckHitArea(nullptr)
	, Texture_Kick(nullptr)
	, Texture_Illusion_1(nullptr)
	, Texture_Illusion_2(nullptr)
	, Texture_Flash(nullptr)
	, Texture_Shock(nullptr)
	, Texture_Apply(nullptr)
	, HitDelay(0)
	, LightingStuck(0)
{

}


Skill_Fighter_F_LightingDance::~Skill_Fighter_F_LightingDance() 
{
}


void Skill_Fighter_F_LightingDance::Start()
{
	GamePlaySkill::Start();
	SetCoolTime(5.f);
	Class_Power.push_back(SkillComboPower(1500, 1, { 20.f, 20.f, 0, 0.5f }, HitPostureType::Standing, HitType::Hit));
	Class_Power.push_back(SkillComboPower(1200, 1, { 10.f, 20.f, 0, 0.2f }, HitPostureType::Standing, HitType::Hit));
	{
		GameEngineCollision* Collision_HamerKick = GetActor()->CreateComponent<GameEngineCollision>("LightingDance");
		Collision_HamerKick->GetTransform().SetLocalScale({ 100.f, 80.f, 40.f });
		Collision_HamerKick->GetTransform().SetLocalPosition({ 30, -10.f, 0 });
		Collision_HamerKick->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(Collision_HamerKick);
		Off();
	}

	{
		Collision_CheckHitArea = GetActor()->CreateComponent<GameEngineCollision>("LightingDance_Pos");
		Collision_CheckHitArea->GetTransform().SetLocalScale({ 700.f, 90.f, 400.f });
		Collision_CheckHitArea->SetDebugSetting(CollisionType::CT_AABB, { 0, 1 ,1, 0.0f });
		Collision_CheckHitArea->GetTransform().SetLocalPosition({ -200.f , 0.f});
		Off();
	}

	{
		
		Texture_Kick = GetActor()->CreateComponent<GameEngineTextureRenderer>("Kick");
		Texture_Kick->GetTransform().SetLocalPosition({ -20, 70, -100.f });
		Texture_Kick->CreateFrameAnimationFolder("Kick", FrameAnimation_DESC("Kick", 0.06f, true));
		Texture_Kick->AnimationBindEnd("Kick",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Kick->ChangeFrameAnimation("Kick");
		Texture_Kick->ScaleToTexture();
		Texture_Kick->Off();
		//Texture_Dashpunchsub->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
	}

	{

		Texture_Illusion_1 = GetActor()->CreateComponent<GameEngineTextureRenderer>("Illusion_1");
		Texture_Illusion_1->GetTransform().SetLocalPosition({ 0, 0, -100.f });
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_70", FrameAnimation_DESC("Illusion_70", 0.0625f, true));
		Texture_Illusion_1->AnimationBindFrame("Illusion_70", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_70",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_150", FrameAnimation_DESC("Illusion_150", 0.0625f, true));
		Texture_Illusion_1->AnimationBindFrame("Illusion_150", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_150",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_230", FrameAnimation_DESC("Illusion_230", 0.0625f, true));
		Texture_Illusion_1->AnimationBindFrame("Illusion_230", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this , std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_230",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_310", FrameAnimation_DESC("Illusion_310", 0.0625f, true));
		//Texture_Illusion_1->AnimationBindFrame("Illusion_310", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_310",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});

		Texture_Illusion_1->ChangeFrameAnimation("Illusion_310");
		Texture_Illusion_1->ScaleToTexture();
		Texture_Illusion_1->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Illusion_1->GetPixelData().MulColor = { 2.f, 2.f , 2.f , 1.2f };
		Texture_Illusion_1->SetParent(Actor_DummyActor);
		Texture_Illusion_1->Off();
	}

	{

		Texture_Illusion_2 = GetActor()->CreateComponent<GameEngineTextureRenderer>("Illusion_2");
		Texture_Illusion_2->GetTransform().SetLocalPosition({ 0, 0, -100.f });
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_70", FrameAnimation_DESC("Illusion_70", 0.0625f, true));
		//Texture_Illusion_2->AnimationBindFrame("Illusion_70", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_70",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_150", FrameAnimation_DESC("Illusion_150", 0.0625f, true));
		//Texture_Illusion_2->AnimationBindFrame("Illusion_150", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_150",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_230", FrameAnimation_DESC("Illusion_230", 0.0625f, true));
		//Texture_Illusion_2->AnimationBindFrame("Illusion_230", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_230",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_310", FrameAnimation_DESC("Illusion_310", 0.0625f, true));
		//Texture_Illusion_2->AnimationBindFrame("Illusion_310", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_310",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});

		Texture_Illusion_2->ChangeFrameAnimation("Illusion_310");
		Texture_Illusion_2->ScaleToTexture();
		Texture_Illusion_2->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Illusion_2->GetPixelData().MulColor = { 2.f, 2.f , 2.f , 1.2f };
		Texture_Illusion_2->SetParent(Actor_DummyActor);
		Texture_Illusion_2->Off();
	}

	{
		Texture_Flash = GetActor()->CreateComponent<GameEngineTextureRenderer>("Flash1");
		Texture_Flash->GetTransform().SetLocalPosition({ 0, 0, -100.f });
		Texture_Flash->CreateFrameAnimationFolder("Lighting_Flash", FrameAnimation_DESC("Lighting_Flash", 0.08f, true));
		Texture_Flash->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Lighting_Flash", 0.02f, true));
		Texture_Flash->AnimationBindEnd("Lighting_Flash",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->ChangeFrameAnimation("None");
				_Desc.Renderer->Off();
			});
		Texture_Flash->ChangeFrameAnimation("Lighting_Flash");
		Texture_Flash->ScaleToTexture();
		Texture_Flash->GetTransform().SetLocalPosition({-50.f, 10.f});
		Texture_Flash->GetPixelData().MulColor = { 1, 1, 1, 0.8f };
		Texture_Flash->SetParent(Actor_DummyActor);
		Texture_Flash->Off();
	}
	{
		Texture_Shock = GetActor()->CreateComponent<GameEngineTextureRenderer>("Flash2");
		Texture_Shock->GetTransform().SetLocalPosition({ 0, 0, -100.f });
		Texture_Shock->CreateFrameAnimationFolder("Lighting_Shock", FrameAnimation_DESC("Lighting_Shock", 0.08f, true));
		Texture_Shock->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Lighting_Shock", 0.02f, true));
		Texture_Shock->AnimationBindEnd("Lighting_Shock",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->ChangeFrameAnimation("None");
				_Desc.Renderer->Off();
			});
		Texture_Shock->ChangeFrameAnimation("Lighting_Shock");
		Texture_Shock->SetScaleRatio(1.2f);
		Texture_Shock->ScaleToTexture();
		Texture_Shock->GetTransform().SetLocalPosition({ -50.f, 10.f });
		Texture_Shock->SetParent(Actor_DummyActor);
		//Texture_Shock->GetPixelData().MulColor = { 1, 1, 1, 0.9f };
		Texture_Shock->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Shock->Off();
	}
	{
		Texture_Apply = GetActor()->CreateComponent<GameEngineTextureRenderer>("Lighting_Apply");
		Texture_Apply->GetTransform().SetLocalPosition({ 0, 0, -100.f });
		Texture_Apply->CreateFrameAnimationFolder("Lighting_Apply", FrameAnimation_DESC("Lighting_Apply", 0.08f, true));
		Texture_Apply->AnimationBindEnd("Lighting_Apply",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Apply->ChangeFrameAnimation("Lighting_Apply");
		Texture_Apply->SetScaleRatio(1.2f);
		Texture_Apply->ScaleToTexture();
		Texture_Apply->SetParent(Actor_DummyActor);
		Texture_Apply->GetTransform().SetLocalPosition({ -180.f, 80.f });
		//Texture_Shock->GetPixelData().MulColor = { 1, 1, 1, 0.9f };
		//Texture_Apply->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Apply->Off();
	}
	

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_LightingDance::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 0:
	{
		if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 2)
		{
			//Texture_Punch00->On();
			Texture_Kick->On();
			CheckCollision();
			Is_CollisionCheck = true;
			return false;
		}
		else if (_Avata->GetAvata_Skin()->IsEndFrame() && Is_CollisionCheck == true )
		{
			if (!Object_HitList.empty())
			{
				++int_ComboStuck;
				Is_CollisionCheck = false;
				--LightingStuck;
				if (Collision_CheckHitArea->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
					std::bind(&Skill_Fighter_F_LightingDance::GetTarget, this, std::placeholders::_1, std::placeholders::_2)))
				{
					_Avata->ChangeAvataAnimation("Att_LightingDanceHit");
				}
				else
				{
					_Avata->ChangeAvataAnimation("Move_QuickStand");
					NoHitFunction();
				}
				return false;
			}
			else
			{
				GetActor<GamePlayCharacter>()->SetCamHoldOff();
				return true;
			}
	
		}
	}
	break;
	case 1:
	{
		if (LightingStuck <= 0)
		{
			GetActor<GamePlayCharacter>()->SetCamHoldOff();
			return true;
		}
		HitDelay += _DeltaTime;
		if (HitDelay > 0.08f)
		{
			if (Collision_CheckHitArea->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
				std::bind(&Skill_Fighter_F_LightingDance::GetTarget, this, std::placeholders::_1, std::placeholders::_2)))
			{
				_Avata->ChangeAvataAnimation("Att_LightingDanceHit");
			}
			else
			{
				if (Object_HitList.empty()) // 전에 한번 때린적 있는가?
				{
					GetActor<GamePlayCharacter>()->SetCamHoldOff();
					return true;
				}
				else
				{
					_Avata->ChangeAvataAnimation("Move_QuickStand");
					NoHitFunction();
				}
			}
			--LightingStuck;
			HitDelay = 0;
			return false;
		}

	}
	break;
	default:
		break;
	}
	//if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
	//{
	//	//Texture_Punch00->On();
	//	CheckCollision();
	//	Is_CollisionCheck = true;
	//	return false;
	//}
	//else if (_Avata->GetAvata_Skin()->IsEndFrame() && int_ComboStuck == 0 && Is_CollisionCheck == true)
	//{
	//	//FirstHit_Animation = true;
	//	//DanceFrameEnd = true;
	//	return false;
	//}

	//if (FirstHit_Animation == true && SomeOneHit == true )
	//{
	//	if (DanceFrameEnd == true)
	//	{
	//		if (DanceStuck > 0)
	//		{
	//			DanceFrameEnd = false;
	//			if (Collision_CheckHitArea->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
	//				std::bind(&Skill_Fighter_F_LightingDance::GetTarget, this, std::placeholders::_1, std::placeholders::_2)))
	//			{
	//				_Avata->ChangeAvataAnimation("Att_BaseKick");
	//				DanceStuck -= 1;
	//				//GetActor()->GetTransform().SetWorldPosition(NextTargetPos);
	//			}
	//			else
	//			{
	//				GameEngineTextureRenderer* Renderer = nullptr;
	//				if (DanceStuck % 2)
	//				{
	//					Renderer = Texture_Illusion_1;
	//					Renderer->SetParent(Actor_DummyActor);
	//				}
	//				else
	//				{
	//					Renderer = Texture_Illusion_2;
	//					Renderer->SetParent(Actor_DummyActor);
	//				}
	//				_Avata->ChangeAvataAnimation("Move_QuickStand");
	//				float Move = (Collision_CheckHitArea->GetTransform().GetLocalScale().x - 200.f) * (GetActor<GamePlayObject>()->GetObjectDir() ? -1.f : 1.f);

	//				GetActor()->GetTransform().SetLocalMove({ Move , 0 , 0 });
	//				//	Renderer->GetTransform().SetLocalRotation({ 0, 0 , float4::VectorXYtoRadian(0, 0) });


	//				Renderer->GetTransform().SetLocalPosition({ GetActor()->GetTransform().GetLocalPosition().x + Collision_CheckHitArea->GetTransform().GetLocalScale().hx() * (GetActor<GamePlayObject>()->GetObjectDir() ? 1.f : -1.f) , GetActor()->GetTransform().GetLocalPosition().y });
	//				Renderer->On();
	//				if (Move >= 0)
	//				{
	//					GetActor<GamePlayObject>()->SetRightDir();
	//				}
	//				else
	//				{
	//					GetActor<GamePlayObject>()->SetLeftDir();
	//				}
	//				DanceStuck -= 1;
	//				IsHitFloor = true;
	//				Object_HitList.clear();
	//				return false;
	//			}

	//		}
	//		else
	//		{
	//			Object_HitList.clear();
	//			Off();
	//			return true;
	//		}
	//	}


	//	// 무적

	//}
	//else if(FirstHit_Animation == true && SomeOneHit == false)
	//{
	//	Off();
	//	return true;
	//}
	return false;
}

void Skill_Fighter_F_LightingDance::NoHitFunction()
{
	GameEngineTextureRenderer* Renderer = nullptr;


	if (LightingStuck % 2)
	{
		Renderer = Texture_Illusion_1;
	}
	else
	{
		Renderer = Texture_Illusion_2;
	}
	Renderer->On();
	Renderer->ChangeFrameAnimation("Illusion_310", true);


	float4 BeforePos = GetActor()->GetTransform().GetWorldPosition();

	float Dir = GetActor<GamePlayObject>()->GetObjectDir() ? 1.f : -1.f;
	GetActor()->GetTransform().SetLocalMove({ 300.f * -(Dir) , -50, -50 });

	float4 AfterPos = GetActor()->GetTransform().GetWorldPosition();

	if (BeforePos.x - AfterPos.x > 0)
	{
		Renderer->GetTransform().PixLocalPositiveX();
	}
	else
	{
		Renderer->GetTransform().PixLocalNegativeX();
	}
	
	AfterPos.y -= 50.f;
	BeforePos.y -= 50.f;

	Renderer->GetTransform().SetLocalRotation({ 0, 0 ,  float4::VectorXYtoRadian(BeforePos, AfterPos) * Dir });

	if (BeforePos.x - AfterPos.x > 0)
	{
		BeforePos.y += 50.f;
	}
	else
	{
		AfterPos.y += 50.f;
	}


	Renderer->GetTransform().SetWorldPosition({ AfterPos.x + (AfterPos.x - BeforePos.x) * -0.5f, (AfterPos.y + (AfterPos.y - BeforePos.y) * -0.5f), -10.f });
	Renderer->On();

	GetActor()->GetTransform().SetLocalMove({ 0 , 20  });

	GetActor<GamePlayObject>()->SetDirSwitch();
	Object_HitList.clear();
}



bool Skill_Fighter_F_LightingDance::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	return false;
}

void Skill_Fighter_F_LightingDance::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_BaseKick");
	Texture_Illusion_1->Off();
	Texture_Illusion_2->Off();
	HitDelay = 0;
	int_ComboStuck = 0;
	LightingStuck = 12;
	Object_HitList.clear();

	GetActor<GamePlayCharacter>()->SetCamHoldOn();

	//FirstHit_Animation = false;
//	NextTargetPos = float4::ZERO;
	//DanceStuck = 12;
	//IsHitFloor = false;
//	DanceFrameEnd = false;
}
bool Skill_Fighter_F_LightingDance::GetTarget(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	GamePlayObject* PoeObject = _Other->GetActor<GamePlayObject>();
	if (Object_HitList[PoeObject] == 1)
	{
		return false;
	}
	float4 PlayerPos = GetActor()->GetTransform().GetWorldPosition();
	float4 PoePos = _Other->GetActor()->GetTransform().GetWorldPosition();
	float Dir = GetActor<GamePlayObject>()->GetObjectDir() ? 1.f : -1.f;




	GameEngineTextureRenderer* Renderer = nullptr;
	if (LightingStuck % 2)
	{
		Renderer = Texture_Illusion_1;

	}
	else
	{
		Renderer = Texture_Illusion_2;

	}
	Renderer->On();
	Renderer->ChangeFrameAnimation("Illusion_310", true);


	float PoeScale = 80.f;

	float Range = PoePos.x - PlayerPos.x;

	if (Range > 0)
	{
		PoeScale = -PoeScale;
	}


	GetActor()->GetTransform().SetLocalPosition({ PoePos.x + PoeScale, PoePos.y, PoePos.y });

	if (Range > 0)
	{
		PlayerPos.y -= 50.f;
		PoePos.y -= 50.f;
		Renderer->GetTransform().PixLocalNegativeX();

		Renderer->GetTransform().SetLocalRotation({ 0, 0 , float4::VectorXYtoRadian(PoePos, PlayerPos) });
	}
	else
	{
		PoePos.y -= 50.f;
		PlayerPos.y -= 50.f;
		Renderer->GetTransform().PixLocalPositiveX();
		Renderer->GetTransform().SetLocalRotation({ 0, 0 , -float4::VectorXYtoRadian(PoePos, PlayerPos) });
	}
	//if (Range > 0)
	//{
	//	PlayerPos.y -= 50.f;
	//	PoePos.y -= 50.f;
	//}
	//else
	//{
	//	PoePos.y -= 50.f;
	//	PlayerPos.y -= 50.f;
	//}


	Renderer->GetTransform().SetWorldPosition({ PoePos.x - (PoePos.x - PlayerPos.x) * 0.5f, PoePos.y - 25.f + (PoePos.y - PlayerPos.y) * 0.5f, -10.f });

	if (Range > 0)
	{
		GetActor<GamePlayObject>()->SetRightDir();
	}
	else
	{
		GetActor<GamePlayObject>()->SetLeftDir();
	}

	PoeObject->BeHit(this, _Other, GamePlayCharacter::GetCurrentCharacterData(), CheckDir(_This, _Other), 1200);
	Object_HitList.clear();
	Object_HitList[_Other->GetActor<GamePlayObject>()] = 1;


	Texture_Flash->ChangeFrameAnimation("Lighting_Flash", true);
	Texture_Flash->On();


	Texture_Flash->SetParent(Actor_DummyActor);
	if (GetActor()->GetTransform().GetLocalScale().x < 0)
	{
		Texture_Flash->GetTransform().PixLocalNegativeX();
	}
	else
	{
		Texture_Flash->GetTransform().PixLocalPositiveX();
	}
	Texture_Flash->GetTransform().SetWorldPosition({GetActor()->GetTransform().GetWorldPosition().x, GetActor()->GetTransform().GetWorldPosition().y + 20.f });

	Texture_Shock->ChangeFrameAnimation("Lighting_Shock", true);
	Texture_Shock->On();

	PoePos.y += 50.f;
	//Texture_Shock->SetParent(Actor_DummyActor);
	//Texture_Shock->GetTransform().SetWorldPosition(PoePos);


	
	Texture_Apply->ChangeFrameAnimation("Lighting_Apply", true);
	Texture_Apply->On();

	//
	Actor_DummyActor->GetTransform().SetLocalPosition(PoePos);

	//if (PastPlayerPos.x > PoePos.x)
	//{
	//	PoePos += _Other->GetActor()->GetTransform().GetLocalScale().hx();
	//	GetActor()->GetTransform().SetLocalPosition(PoePos);
	//	Renderer->GetTransform().SetLocalRotation({ 0, 0 , float4::VectorXYtoRadian(PoePos, PastPlayerPos) });
	//	Renderer->GetTransform().SetLocalPosition({ PoePos.x + ((PastPlayerPos.x - PoePos.x) * 0.5f)
	//												, PastPlayerPos.y > PoePos.y ? PastPlayerPos.y + (PastPlayerPos.y - PoePos.y) * 0.5f : PoePos.y + (PoePos.y - PastPlayerPos.y) * 0.5f, 100.f });
	//	GetActor<GamePlayObject>()->SetDirSwitch();
	//}
	//else
	//{
	//	PoePos -= _Other->GetActor()->GetTransform().GetLocalScale().hx();
	//}
	//IsHitFloor = false;
	//Object_HitList.clear();
	//Object_HitList[_Other->GetActor<GamePlayObject>()] = 1;
	return true;
}


void Skill_Fighter_F_LightingDance::LightingAnimition(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	
}

void Skill_Fighter_F_LightingDance::EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	
}

void Skill_Fighter_F_LightingDance::CheckEffectFrame(const FrameAnimation_DESC& _Desc)
{
	//switch (_Desc.CurFrame)
	//{
	//case 2:
	//	DanceFrameEnd = true;
	//	break;
	//default:
	//	break;
	//}
}

