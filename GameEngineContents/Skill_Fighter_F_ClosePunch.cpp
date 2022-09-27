#include "PreCompile.h"
#include "Skill_Fighter_F_ClosePunch.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"

Skill_Fighter_F_ClosePunch::Skill_Fighter_F_ClosePunch()
	: Texture_W_Front_d(nullptr)
	, Texture_W_Back_d(nullptr)
	, Texture_W_Middle_d(nullptr)
	, Texture_Punch00(nullptr)
	, Texture_Punch01(nullptr)
	, Texture_Punch02(nullptr)
	, Texture_Punch03(nullptr)
	, Texture_W_1_d(nullptr)
	, Texture_W_2_d(nullptr)
	, Att_ClosePunch_Delay(0.f)
	, Bool_Texture_W_Middle_d_Start(false)

{
}

Skill_Fighter_F_ClosePunch::~Skill_Fighter_F_ClosePunch() 
{
}


void Skill_Fighter_F_ClosePunch::Start()
{
	Class_Power.push_back(SkillComboPower(3000, 1, { 0.f, 0.f, 0, 1.f }, HitPostureType::Hold, HitType::None));
	Class_Power.push_back(SkillComboPower(2000, 1, { 50, 100.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));
	{
		GameEngineCollision* ClosePunch = GetActor()->CreateComponent<GameEngineCollision>("ClosePunch");
		ClosePunch->GetTransform().SetLocalScale({ 20.f, 40.f, 30.f });
		ClosePunch->GetTransform().SetLocalPosition({ 30, 20.f, 0 });
		ClosePunch->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(ClosePunch);
	}


	{
		GameEngineCollision* ClosePunch = GetActor()->CreateComponent<GameEngineCollision>("ClosePunch_AfterHit");
		ClosePunch->GetTransform().SetLocalScale({ 150, 60, 80 });
		ClosePunch->GetTransform().SetLocalPosition({ 30, 0, 0 });
		ClosePunch->ChangeOrder(CollisionOrder::Player_Att);
		ClosePunch->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.0f });
		Collision_AllCollisionList.push_back(ClosePunch);
	}



	{
		Texture_Punch00 = GetActor()->CreateComponent<GameEngineEffectRenderer>("Punch00");
		Texture_Punch00->GetTransform().SetLocalPosition({ 65 , 15.f, -100.f });
		Texture_Punch00->CreateFrameAnimationFolder("Punch00", FrameAnimation_DESC("Punch00", 0.04f, true));
		Texture_Punch00->AnimationBindEnd("Punch00",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Punch00->ChangeFrameAnimation("Punch00");
		Texture_Punch00->ScaleToTexture();
		Texture_Punch00->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Punch00->Off();
	}

	{
		Texture_Punch01 = GetActor()->CreateComponent<GameEngineEffectRenderer>("Punch01");
		Texture_Punch01->GetTransform().SetLocalPosition({ 65 , 15.f, -100.f });
		Texture_Punch01->CreateFrameAnimationFolder("Punch01", FrameAnimation_DESC("Punch01", 0.04f, true));
		Texture_Punch01->AnimationBindEnd("Punch01",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Punch01->ChangeFrameAnimation("Punch01");
		Texture_Punch01->ScaleToTexture();
		Texture_Punch01->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Punch01->Off();
	}
	{
		Texture_Punch02 = GetActor()->CreateComponent<GameEngineEffectRenderer>("Punch02");
		Texture_Punch02->GetTransform().SetLocalPosition({ 65 , 15.f, -100.f });
		Texture_Punch02->CreateFrameAnimationFolder("Punch02", FrameAnimation_DESC("Punch02", 0.04f, true));
		Texture_Punch02->AnimationBindFrame("Punch02",
			std::bind(&Skill_Fighter_F_ClosePunch::Texture_Punch02_Animation_Frame, this, std::placeholders::_1));
		
		Texture_Punch02->AnimationBindEnd("Punch02",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Punch02->ChangeFrameAnimation("Punch02");
		Texture_Punch02->ScaleToTexture();
		Texture_Punch02->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Punch02->Off();
	}
	{
		Texture_Punch03 = GetActor()->CreateComponent<GameEngineEffectRenderer>("Punch03");
		Texture_Punch03->GetTransform().SetLocalPosition({ 65 , 10.f, -100.f });
		Texture_Punch03->CreateFrameAnimationFolder("Punch03", FrameAnimation_DESC("Punch03", 0.08f, true));
		Texture_Punch03->AnimationBindEnd("Punch03",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Punch03->ChangeFrameAnimation("Punch03");
		Texture_Punch03->ScaleToTexture();
		Texture_Punch03->GetClonePipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Punch03->Off();
	}
	{
		Texture_W_Front_d = GetActor()->CreateComponent<GameEngineEffectRenderer>("W_Front_d");
		Texture_W_Front_d->GetTransform().SetLocalPosition({ 88 , -7.f, -90.f });
		Texture_W_Front_d->CreateFrameAnimationFolder("W_Front_d", FrameAnimation_DESC("W_Front_d", 0.04f, true));
	//	Texture_W_Front_d->AnimationBindStart("W_Front_d", std::bind(&Skill_Fighter_F_ClosePunch::Texture_W_Front_d_Animation_Start, this, std::placeholders::_1));
		Texture_W_Front_d->AnimationBindFrame("W_Front_d", std::bind(&Skill_Fighter_F_ClosePunch::Texture_W_Front_d_Animation_Frame, this, std::placeholders::_1));
		Texture_W_Front_d->AnimationBindEnd("W_Front_d",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_W_Front_d->ChangeFrameAnimation("W_Front_d");
		Texture_W_Front_d->ScaleToTexture();
		//Texture_W_Front_d->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_W_Front_d->Off();
	}
	{
		Texture_W_Back_d = GetActor()->CreateComponent<GameEngineEffectRenderer>("W_Back_d");
		Texture_W_Back_d->GetTransform().SetLocalPosition({ 88 , -7.f, -90.f });
		Texture_W_Back_d->CreateFrameAnimationFolder("W_Back_d", FrameAnimation_DESC("W_Back_d", 0.04f, true));
		Texture_W_Back_d->AnimationBindEnd("W_Back_d",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_W_Back_d->ChangeFrameAnimation("W_Back_d");
		Texture_W_Back_d->ScaleToTexture();
		//Texture_W_Front_d->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_W_Back_d->Off();
	}

	{
		Texture_W_Middle_d = GetActor()->CreateComponent<GameEngineEffectRenderer>("W_Middle_d");
		Texture_W_Middle_d->GetTransform().SetLocalPosition({ 88 , -7.f, -90.f });
		Texture_W_Middle_d->CreateFrameAnimationFolder("W_Middle_d", FrameAnimation_DESC("W_Middle_d", 0.04f, true));
		Texture_W_Middle_d->AnimationBindFrame("W_Middle_d",
			std::bind(&Skill_Fighter_F_ClosePunch::Texture_W_Middle_d_Animation_Frame, this, std::placeholders::_1));

		Texture_W_Middle_d->AnimationBindEnd("W_Middle_d",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_W_Middle_d->ChangeFrameAnimation("W_Middle_d");
		Texture_W_Middle_d->ScaleToTexture();
		//Texture_W_Middle_d->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_W_Middle_d->Off();
	}


	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_ClosePunch::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{

	if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
	{
		//Texture_Punch00->On();
		CheckCollision();
		Is_CollisionCheck = true;
		if (Object_HitList.empty())
		{
			_Avata->SetShake(10, _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 6.f);
			Texture_W_Front_d->CurAnimationPauseSwitch();
		}
		else
		{
			Object_HitList.clear();
			SomeOneHit = true;
			++int_ComboStuck;
		}

		_Avata->SetAllAvataManualControl();

	}

	if (Is_CollisionCheck == true)
	{
		Att_ClosePunch_Delay += _DeltaTime;
		if (int_ComboStuck == 1)
		{
			if (Bool_Texture_W_Middle_d_Start == false && Att_ClosePunch_Delay >= _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 2.f)
			{
				_Avata->SetShake(10, _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 6.f);
				Texture_W_Middle_d->On();
				Bool_Texture_W_Middle_d_Start = true;
			}
			else if (Texture_Punch02->IsUpdate())
			{
				_Avata->SetAllAvataAutoControl(false);
			}

		}
		else if (Att_ClosePunch_Delay >= _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 6.f)
		{
			_Avata->SetAllAvataAutoControl(false);
		}

		if (_Avata->GetAvata_Skin()->IsEndFrame())
		{
			Off();
			return true;
		}
	}

	return false;
	
}

bool Skill_Fighter_F_ClosePunch::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
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
			//Texture_Punch02->On();
			//Texture_Punch03->On();
		}
		break;
	default:
		break;
	}

	// 강제경직 함수 필요
	return false;
}

void Skill_Fighter_F_ClosePunch::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_OneinchPunch");
	Texture_W_Front_d->On();
	Texture_W_Front_d->CurAnimationPauseSwitch();
	Att_ClosePunch_Delay = 0.f;
	Bool_Texture_W_Middle_d_Start = false;
	Texture_W_Front_ = false;
	_Avata->SetAllAvataAutoControl(false);
}

void Skill_Fighter_F_ClosePunch::Texture_W_Front_d_Animation_Start(const FrameAnimation_DESC& _Desc)
{

}
void Skill_Fighter_F_ClosePunch::Texture_W_Front_d_Animation_Frame(const FrameAnimation_DESC& _Desc)
{
	switch (_Desc.CurFrame)
	{
	case 0:
		break;
	case 1:
		{
			Texture_Punch00->On();
		}
		break;
	case 2:
		Texture_Punch01->On();
		break;
	case 3:
		break;
	default:
		break;
	}


}

void Skill_Fighter_F_ClosePunch::Texture_W_Middle_d_Animation_Frame(const FrameAnimation_DESC& _Desc)
{
	switch (_Desc.CurFrame)
	{
	case 2:
		Texture_W_Back_d->On();
		break;
	case 5:
		if (Texture_W_Front_ == false)
		{
			Texture_W_Front_d->CurAnimationPauseSwitch();
			Texture_W_Front_ = true;
		}
		break;
	case 6:
	{
		Texture_Punch02->On();
		CheckCollision();
	}
	
		break;
	default:
		break;
	}

}

void Skill_Fighter_F_ClosePunch::Texture_Punch02_Animation_Frame(const FrameAnimation_DESC& _Desc)
{
	switch (_Desc.CurFrame)
	{
	case 1:
	{
		Texture_Punch03->On();
	}
	break;
	default:
		break;
	}
}