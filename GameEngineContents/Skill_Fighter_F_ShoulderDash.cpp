#include "PreCompile.h"
#include "Skill_Fighter_F_ShoulderDash.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
bool Skill_Fighter_F_ShoulderDash::FirstTime = false;

Skill_Fighter_F_ShoulderDash::Skill_Fighter_F_ShoulderDash() 
	: DelayPunch(false)
	, MoveDistance(0.f)
{
}

Skill_Fighter_F_ShoulderDash::~Skill_Fighter_F_ShoulderDash() 
{
}


void Skill_Fighter_F_ShoulderDash::Start()
{
	Class_Power.push_back(SkillComboPower(500, 1, { 80, 200.f, 0, 0 }, HitPostureType::Aerial, HitType::Hit));
	{
		GameEngineCollision* Upper = GetActor()->CreateComponent<GameEngineCollision>("DashHit");
		Upper->GetTransform().SetLocalScale({ 100.f, 60.f, 80.f });
		Upper->GetTransform().SetLocalPosition({ 30, 20.f, 0 });
		Upper->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(Upper);
	}

	Texture_Effect = GetActor()->CreateComponent<GameEngineTextureRenderer>();
	Texture_Effect->CreateFrameAnimationFolder("Skill_ShoulderEffect", FrameAnimation_DESC("Skill_ShoulderEffect",0.05f ,false));
	Texture_Effect->ChangeFrameAnimation("Skill_ShoulderEffect");
	Texture_Effect->AnimationBindEnd("Skill_ShoulderEffect", [](const FrameAnimation_DESC& _DESC)
		{
			_DESC.Renderer->Off();
		});
	Texture_Effect->SetScaleRatio(1.2f);
	Texture_Effect->ScaleToTexture();
	Texture_Effect->GetTransform().SetLocalPosition({ 0, -30.f, 0 });
	Texture_Effect->Off();

		
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_ShoulderDash::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 0:
	{
		if (DelayPunch == false)
		{
			if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() < 2)
			{
				if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
				{
					CheckCollision();
					Is_CollisionCheck = true;
				}
				_Move->SetCharacterMove({ (GetTransform().GetWorldScale().x > 0 ? 1.f : -1.f) * 600 * _DeltaTime, 0 });
			}
			else if (_Avata->GetAvata_Skin()->IsEndFrame())
			{
				_Avata->ChangeAvataAnimation("Att_ShoulderDash_Delay");
				DelayPunch = true;
			}
		}
		else
		{
			if (_Avata->GetAvata_Skin()->IsEndFrame())
			{
				_Stat->SetSuperarmorEnd();
				Off();
				return true;
			}
		}
		return false;
	}
	default:
		break;
	}
	return false;
}

bool Skill_Fighter_F_ShoulderDash::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (!Object_HitList.empty())
	{
		GameEngineSound::SoundPlayControl("cv_hit_fin.ogg").Volume(0.6f);
	}


	return false;
}



void Skill_Fighter_F_ShoulderDash::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	switch (GameEngineRandom::MainRandom.RandomInt(0, 1))
	{
	case 0:
		GamePlayCharacter::SetVoice("ft_shoulder_01.ogg");
		break;
	case 1:
		GamePlayCharacter::SetVoice("ft_shoulder_02.ogg");
		break;
	default:
		break;
	}


	DelayPunch = false;
	_Avata->ChangeAvataAnimation("Att_ShoulderDash");
	_Avata->SetSuperArmor();
	_Stat->SetSuperarmor();
	MoveDistance = FSM_Move_Helper();
	Texture_Effect->ChangeFrameAnimation("Skill_ShoulderEffect", true);
	Texture_Effect->On();

}

void Skill_Fighter_F_ShoulderDash::EndSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Stat->SetSuperarmorEnd();
}
