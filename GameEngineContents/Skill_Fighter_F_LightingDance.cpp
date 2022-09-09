#include "PreCompile.h"
#include "Skill_Fighter_F_LightingDance.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

Skill_Fighter_F_LightingDance::Skill_Fighter_F_LightingDance()
	: Collision_CheckHitPos(nullptr)
	, Texture_Kick(nullptr)
	, Texture_Illusion_1(nullptr)
	, Texture_Illusion_2(nullptr)
	, Texture_Flash(nullptr)
	, FirstHit_Animation(false)
	, TargetPos(float4::ZERO)
	, DanceStuck(12)
	, IsHitFloor(false)
{

}


Skill_Fighter_F_LightingDance::~Skill_Fighter_F_LightingDance() 
{
}


void Skill_Fighter_F_LightingDance::Start()
{
	SetCoolTime(5.f);
	Class_Power.push_back(SkillComboPower(1000, 1, { 0.f, 0.f, 0, 1.f }, HitPostureType::Hold, HitType::None));
	{
		GameEngineCollision* Collision_HamerKick = GetActor()->CreateComponent<GameEngineCollision>("LightingDance");
		Collision_HamerKick->GetTransform().SetLocalScale({ 100.f, 80.f, 40.f });
		Collision_HamerKick->GetTransform().SetLocalPosition({ 30, -10.f, 0 });
		//Collision_HamerKick->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(Collision_HamerKick);
		Off();
	}

	{
		Collision_CheckHitPos = GetActor()->CreateComponent<GameEngineCollision>("LightingDance_Pos");
		Collision_CheckHitPos->GetTransform().SetLocalScale({ 500.f, 90.f, 400.f });
		//Collision_CheckHitPos->SetDebugSetting(CollisionType::CT_AABB, { 0, 1 ,1, 0.7f });
		Collision_CheckHitPos->GetTransform().SetLocalPosition({ -50.f , 0.f});
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
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_70", FrameAnimation_DESC("Illusion_70", 0.05f, true));
		Texture_Illusion_1->AnimationBindFrame("Illusion_70", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_70",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_150", FrameAnimation_DESC("Illusion_150", 0.05f, true));
		Texture_Illusion_1->AnimationBindFrame("Illusion_150", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_150",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_230", FrameAnimation_DESC("Illusion_230", 0.05f, true));
		Texture_Illusion_1->AnimationBindFrame("Illusion_230", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this , std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_230",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_1->CreateFrameAnimationFolder("Illusion_310", FrameAnimation_DESC("Illusion_310", 0.05f, true));
		Texture_Illusion_1->AnimationBindFrame("Illusion_310", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_1->AnimationBindEnd("Illusion_310",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});

		Texture_Illusion_1->ChangeFrameAnimation("Illusion_230");
		Texture_Illusion_1->ScaleToTexture();
		Texture_Illusion_1->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Illusion_1->Off();
	}

	{

		Texture_Illusion_2 = GetActor()->CreateComponent<GameEngineTextureRenderer>("Illusion_2");
		Texture_Illusion_2->GetTransform().SetLocalPosition({ 0, 0, -100.f });
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_70", FrameAnimation_DESC("Illusion_70", 0.04f, true));
		Texture_Illusion_2->AnimationBindFrame("Illusion_70", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_70",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_150", FrameAnimation_DESC("Illusion_150", 0.04f, true));
		Texture_Illusion_2->AnimationBindFrame("Illusion_150", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_150",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_230", FrameAnimation_DESC("Illusion_230", 0.04f, true));
		Texture_Illusion_2->AnimationBindFrame("Illusion_230", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_230",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Illusion_2->CreateFrameAnimationFolder("Illusion_310", FrameAnimation_DESC("Illusion_310", 0.04f, true));
		Texture_Illusion_2->AnimationBindFrame("Illusion_310", std::bind(&Skill_Fighter_F_LightingDance::CheckEffectFrame, this, std::placeholders::_1));
		Texture_Illusion_2->AnimationBindEnd("Illusion_310",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});

		Texture_Illusion_2->ChangeFrameAnimation("Illusion_230");
		Texture_Illusion_2->ScaleToTexture();
		//Texture_Illusion_2->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Illusion_2->Off();
	}


	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_LightingDance::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
	{
		//Texture_Punch00->On();
		CheckCollision();
		Is_CollisionCheck = true;
		return false;

	}
	else if (_Avata->GetAvata_Skin()->IsEndFrame() && FirstHit_Animation == false)
	{
		FirstHit_Animation = true;
		DanceFrameEnd = true;
		return false;
	}

	if (FirstHit_Animation == true && SomeOneHit == true )
	{
		if (DanceFrameEnd == true)
		{
			if (DanceStuck > 0)
			{
				DanceFrameEnd = false;
				if (Collision_CheckHitPos->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
					std::bind(&Skill_Fighter_F_LightingDance::GetTarget, this, std::placeholders::_1, std::placeholders::_2)))
				{
					_Avata->ChangeAvataAnimation("Att_BaseKick");
					DanceStuck -= 1;
					//GetActor()->GetTransform().SetWorldPosition(TargetPos);
				}
				else
				{
					GameEngineTextureRenderer* Renderer = nullptr;
					if (DanceStuck % 2)
					{
						Renderer = Texture_Illusion_1;
						Renderer->SetParent(Actor_DummyActor);
					}
					else
					{
						Renderer = Texture_Illusion_2;
						Renderer->SetParent(Actor_DummyActor);
					}
					_Avata->ChangeAvataAnimation("Move_QuickStand");
					float Move = (Collision_CheckHitPos->GetTransform().GetLocalScale().x - 200.f) * (GetActor<GamePlayObject>()->GetObjectDir() ? -1.f : 1.f);

					GetActor()->GetTransform().SetLocalMove({ Move , 0 , 0 });
					//	Renderer->GetTransform().SetLocalRotation({ 0, 0 , float4::VectorXYtoRadian(0, 0) });


					Renderer->GetTransform().SetLocalPosition({ GetActor()->GetTransform().GetLocalPosition().x + Collision_CheckHitPos->GetTransform().GetLocalScale().hx() * (GetActor<GamePlayObject>()->GetObjectDir() ? 1.f : -1.f) , GetActor()->GetTransform().GetLocalPosition().y });
					Renderer->On();
					if (Move >= 0)
					{
						GetActor<GamePlayObject>()->SetRightDir();
					}
					else
					{
						GetActor<GamePlayObject>()->SetLeftDir();
					}
					DanceStuck -= 1;
					IsHitFloor = true;
					Object_HitList.clear();
					return false;
				}

			}
			else
			{
				Object_HitList.clear();
				Off();
				return true;
			}
		}


		// ¹«Àû

	}
	else if(FirstHit_Animation == true && SomeOneHit == false)
	{
		Off();
		return true;
	}
	return false;
}

bool Skill_Fighter_F_LightingDance::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	return false;
}

void Skill_Fighter_F_LightingDance::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_BaseKick");
	Texture_Kick->On();
	FirstHit_Animation = false;
	TargetPos = float4::ZERO;
	DanceStuck = 12;
	IsHitFloor = false;
	DanceFrameEnd = false;
}
bool Skill_Fighter_F_LightingDance::GetTarget(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (Object_HitList[_Other->GetActor<GamePlayObject>()] == 1)
	{
		return false;
	}
	float4 PastPlayerPos = GetActor()->GetTransform().GetWorldPosition();
	float4 CurrentPoePos = _Other->GetActor()->GetTransform().GetWorldPosition();
	float Dir = GetActor<GamePlayObject>()->GetObjectDir() ? 1.f : -1.f;

	GameEngineTextureRenderer* Renderer = nullptr;
	if (DanceStuck % 2)
	{
		Renderer = Texture_Illusion_1;
		Renderer->SetParent(Actor_DummyActor);
	}
	else
	{
		Renderer = Texture_Illusion_2;
		Renderer->SetParent(Actor_DummyActor);
	}



	GetActor()->GetTransform().SetLocalMove({ _Other->GetActor()->GetTransform().GetLocalScale().hx() * Dir + (CurrentPoePos.x - PastPlayerPos.x), CurrentPoePos.y - PastPlayerPos.y });
	Renderer->GetTransform().SetLocalRotation({ 0, 0 , float4::VectorXYtoRadian(CurrentPoePos, PastPlayerPos) });
	Renderer->GetTransform().SetLocalPosition({ CurrentPoePos.x + (CurrentPoePos.x - PastPlayerPos.x) * 0.5f, CurrentPoePos.y + (CurrentPoePos.y - PastPlayerPos.y) * 0.5f, -10.f });

	if ((CurrentPoePos.x - PastPlayerPos.x) >= 0)
	{
		GetActor<GamePlayObject>()->SetRightDir();
	}
	else
	{
		GetActor<GamePlayObject>()->SetLeftDir();
	}


	//if (PastPlayerPos.x > CurrentPoePos.x)
	//{
	//	CurrentPoePos += _Other->GetActor()->GetTransform().GetLocalScale().hx();
	//	GetActor()->GetTransform().SetLocalPosition(CurrentPoePos);
	//	Renderer->GetTransform().SetLocalRotation({ 0, 0 , float4::VectorXYtoRadian(CurrentPoePos, PastPlayerPos) });
	//	Renderer->GetTransform().SetLocalPosition({ CurrentPoePos.x + ((PastPlayerPos.x - CurrentPoePos.x) * 0.5f)
	//												, PastPlayerPos.y > CurrentPoePos.y ? PastPlayerPos.y + (PastPlayerPos.y - CurrentPoePos.y) * 0.5f : CurrentPoePos.y + (CurrentPoePos.y - PastPlayerPos.y) * 0.5f, 100.f });
	//	GetActor<GamePlayObject>()->SetDirSwitch();
	//}
	//else
	//{
	//	CurrentPoePos -= _Other->GetActor()->GetTransform().GetLocalScale().hx();
	//}
	IsHitFloor = false;
	Object_HitList.clear();
	Object_HitList[_Other->GetActor<GamePlayObject>()] = 1;
	return true;
}


void Skill_Fighter_F_LightingDance::LightingAnimition(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	
}

void Skill_Fighter_F_LightingDance::CheckEffectFrame(const FrameAnimation_DESC& _Desc)
{
	switch (_Desc.CurFrame)
	{
	case 2:
		DanceFrameEnd = true;
		break;
	default:
		break;
	}
}

