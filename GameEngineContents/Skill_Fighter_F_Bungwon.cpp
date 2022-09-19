#include "PreCompile.h"
#include "Skill_Fighter_F_Bungwon.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


Skill_Fighter_F_Bungwon::Skill_Fighter_F_Bungwon() 
	: MoveDistance(0.f)
	, Att_Bungwon_Delay(0.f)
	, Texture_Dashpunch(nullptr)
	, Texture_Dashpunchdust(nullptr)
	, Texture_Dashpunchsub(nullptr)
	, Coefficient(0)
{
}

Skill_Fighter_F_Bungwon::~Skill_Fighter_F_Bungwon() 
{
}


void Skill_Fighter_F_Bungwon::Start()
{
	Class_Power.push_back(SkillComboPower(180, 1, { 50.f, 0.f, 0, 70.f }, HitPostureType::Standing, HitType::Hit));
	{
		Texture_Dashpunch = GetActor()->CreateComponent<GameEngineTextureRenderer>("Dashpunch");
		Texture_Dashpunch->GetTransform().SetLocalPosition({ 56, -12, -0.01f });
		Texture_Dashpunch->CreateFrameAnimationFolder("Dashpunch", FrameAnimation_DESC("Dashpunch", FighterAnimationInter, true));
		Texture_Dashpunch->AnimationBindEnd("Dashpunch",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Dashpunch->ChangeFrameAnimation("Dashpunch");
		Texture_Dashpunch->ScaleToTexture();
		Texture_Dashpunch->Off();
		//Texture_Dashpunch->Option.IsMask = 1;
		//Texture_Dashpunch->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
	}
	{
		Texture_Dashpunchdust = GetActor()->CreateComponent<GameEngineTextureRenderer>("Dashpunchdust");
		Texture_Dashpunchdust->GetTransform().SetLocalPosition({ 56, -12, -0.01f });
		Texture_Dashpunchdust->CreateFrameAnimationFolder("Dashpunchdust", FrameAnimation_DESC("Dashpunchdust", FighterAnimationInter, true));
		Texture_Dashpunchdust->AnimationBindEnd("Dashpunchdust",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Dashpunchdust->ChangeFrameAnimation("Dashpunchdust");
		Texture_Dashpunchdust->ScaleToTexture();
		Texture_Dashpunchdust->Off();
	}
	{
		Texture_Dashpunchsub = GetActor()->CreateComponent<GameEngineTextureRenderer>("Dashpunchsub");
		Texture_Dashpunchsub->GetTransform().SetLocalPosition({ 56, -12, -0.015f });
		Texture_Dashpunchsub->CreateFrameAnimationFolder("Dashpunchsub", FrameAnimation_DESC("Dashpunchsub", 0.05f, true));
		Texture_Dashpunchsub->AnimationBindEnd("Dashpunchsub",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Dashpunchsub->ChangeFrameAnimation("Dashpunchsub");
		Texture_Dashpunchsub->ScaleToTexture();
		Texture_Dashpunchsub->Off();
		//Texture_Dashpunchsub->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		
	}

	

	{
		GameEngineCollision* BaseHit = GetActor()->CreateComponent<GameEngineCollision>("Dashpunch");
		BaseHit->GetTransform().SetLocalScale({ 80, 60, 20 });
		BaseHit->GetTransform().SetLocalPosition({ 30, 20 });
		BaseHit->ChangeOrder(CollisionOrder::Player_Att);
		BaseHit->SetDebugSetting(CollisionType::CT_AABB, { 1, 1, 0, 0.f });
		Collision_AllCollisionList.push_back(BaseHit);
	}
	Off();

}

bool Skill_Fighter_F_Bungwon::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 1)
	{
		Att_Bungwon_Delay += _DeltaTime;
		CheckCollision();
		if (Is_CollisionCheck == false)
		{
			Texture_Dashpunch->On();
			Texture_Dashpunchdust->On();
			Is_CollisionCheck = true;
			_Avata->SetAllAvataManualControl();
			//_Avata->ChangeFrame_Manual(1);
		}

		if (Att_Bungwon_Delay >= _Avata->GetAvata_Skin()->GetFrameAnimation()->GetInfo().Inter * 2.5f)
		{
			//_Avata->ChangeFrame_Manual(2);
			_Avata->SetAllAvataAutoControl(false);
		}
		else
		{

			float Range = (1000.f + Coefficient - (Coefficient * Coefficient));
			Coefficient += Att_Bungwon_Delay + Coefficient ;
			if (Range < 0)
			{
				Range = 0;
			}

			//float4 Pos = GetActor()->GetTransform().GetWorldPosition();
			//Pos -= float4::Lerp(Pos, { Pos.x + (MoveDistance * DefaultMove * 0.035f), Pos.y, Pos.z }, Att_Bungwon_Delay * 10.f );
			_Move->SetCharacterMove({ (Range * MoveDistance) * _DeltaTime, 0 });
		}
	}

	if (_Avata->GetAvata_Skin()->IsEndFrame())
	{
		Off();
		return true;
	}
	return false;
}

bool Skill_Fighter_F_Bungwon::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (!Texture_Dashpunchsub->IsUpdate())
	{
		Texture_Dashpunchsub->On();
	}

	return false;
}

void Skill_Fighter_F_Bungwon::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_Punch_Off");
	MoveDistance = FSM_Move_Helper();
	MoveDistance *= 0.5f;
	Att_Bungwon_Delay = 0.f;
	Coefficient = 0;

}




