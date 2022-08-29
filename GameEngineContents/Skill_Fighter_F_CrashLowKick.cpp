#include "PreCompile.h"
#include "Skill_Fighter_F_CrashLowKick.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


Skill_Fighter_F_CrashLowKick::Skill_Fighter_F_CrashLowKick() 
	: Texture_CrashLowKick(nullptr)
	, IsReady(false)
	, Texture_CrashLowKick_Hit1(nullptr)
	, Texture_CrashLowKick_Hit3(nullptr)
	, Texture_CrashLowKick_Bone(nullptr)
	//, Texture_CrashLowKick_Wave01(nullptr)
{
}

Skill_Fighter_F_CrashLowKick::~Skill_Fighter_F_CrashLowKick() 
{
}


void Skill_Fighter_F_CrashLowKick::Start()
{
	Class_Power.push_back(SkillComboPower(800, 1, { 60, 0.f, 0.f, 150.f }, HitPostureType::Standing, HitType::Hit));
	{
		GameEngineCollision* LowKick = GetActor()->CreateComponent<GameEngineCollision>("CrashLowKick");
		LowKick->GetTransform().SetLocalScale({ 80.f, 40.f, 20.f });
		LowKick->GetTransform().SetLocalPosition({ 30, -50.f, 0 });
		LowKick->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,1.f, 1.f });
		Collision_AllCollisionList.push_back(LowKick);
	}


	{
		Texture_CrashLowKick = GetActor()->CreateComponent<GameEngineTextureRenderer>("CrashLowKick");
		Texture_CrashLowKick->GetTransform().SetLocalPosition({ 35.f, -45.f, -0.001f });
		Texture_CrashLowKick->CreateFrameAnimationFolder("CrashLowKick_Base", FrameAnimation_DESC("CrashLowKick", 0, 10 ,0.04f, true));
		Texture_CrashLowKick->CreateFrameAnimationFolder("CrashLowKick_Hit", FrameAnimation_DESC("CrashLowKick", 11, 14, 0.04f, true));
		Texture_CrashLowKick->AnimationBindEnd("CrashLowKick_Base",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_CrashLowKick->AnimationBindEnd("CrashLowKick_Hit",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_CrashLowKick->ChangeFrameAnimation("CrashLowKick_Base");
		Texture_CrashLowKick->ScaleToTexture();
		//cTexture_CrashLowKick->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_CrashLowKick->Off();
	}

	{
		Texture_CrashLowKick_Hit1 = GetActor()->CreateComponent<GameEngineTextureRenderer>("CrashLowKick_Hit1");
		Texture_CrashLowKick_Hit1->GetTransform().SetLocalPosition({ 75 , -55.f, 100.f });
		Texture_CrashLowKick_Hit1->GetTransform().SetLocalRotate({ 0 , 0 , 45.f });
		Texture_CrashLowKick_Hit1->CreateFrameAnimationFolder("CrashLowKick_Hit1", FrameAnimation_DESC("CrashLowKick_Hit1", 0.04f, true));
		Texture_CrashLowKick_Hit1->AnimationBindEnd("CrashLowKick_Hit1",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_CrashLowKick_Hit1->ChangeFrameAnimation("CrashLowKick_Hit1");
		Texture_CrashLowKick_Hit1->ScaleToTexture();
		//Texture_CrashLowKick_Hit1->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_CrashLowKick_Hit1->Off();
	}


	{
		Texture_CrashLowKick_Hit3 = GetActor()->CreateComponent<GameEngineTextureRenderer>("CrashLowKick_Hit3");
		Texture_CrashLowKick_Hit3->GetTransform().SetLocalPosition({ 80.f, -55.f, -0.001f });
		Texture_CrashLowKick_Hit3->CreateFrameAnimationFolder("CrashLowKick_Hit3", FrameAnimation_DESC("CrashLowKick_Hit3", 0.04f, true));
		Texture_CrashLowKick_Hit3->AnimationBindEnd("CrashLowKick_Hit3",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_CrashLowKick_Hit3->ChangeFrameAnimation("CrashLowKick_Hit3");
		Texture_CrashLowKick_Hit3->ScaleToTexture();
		//Texture_CrashLowKick->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_CrashLowKick_Hit3->Off();
	}

	{
		Texture_CrashLowKick_Bone = GetActor()->CreateComponent<GameEngineTextureRenderer>("CrashLowKick_Bone");
		Texture_CrashLowKick_Bone->GetTransform().SetLocalPosition({ 0, -40, -10.f });
		Texture_CrashLowKick_Bone->CreateFrameAnimationFolder("CrashLowKick_Bone", FrameAnimation_DESC("CrashLowKick_Bone", 0.1f, true));
		Texture_CrashLowKick_Bone->AnimationBindEnd("CrashLowKick_Bone",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_CrashLowKick_Bone->ChangeFrameAnimation("CrashLowKick_Bone");
		Texture_CrashLowKick_Bone->GetTransform().SetLocalScale({ 90.f, 82.f });
		//Texture_CrashLowKick->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_CrashLowKick_Bone->Off();
	}

	//{
	//	Texture_CrashLowKick_Wave01 = GetActor()->CreateComponent<GameEngineTextureRenderer>("Wave01");
	//	Texture_CrashLowKick_Wave01->GetTransform().SetLocalPosition({ 30, -40, 100.f });
	//	Texture_CrashLowKick_Wave01->CreateFrameAnimationFolder("Wave01", FrameAnimation_DESC("Wave01", 0.04f, true));
	//	Texture_CrashLowKick_Wave01->AnimationBindEnd("Wave01",
	//		[](const FrameAnimation_DESC& _Desc)
	//		{
	//			_Desc.Renderer->Off();
	//		});
	//	Texture_CrashLowKick_Wave01->ChangeFrameAnimation("Wave01");
	//	Texture_CrashLowKick_Wave01->ScaleToTexture();
	//	Texture_CrashLowKick_Wave01->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
	//	Texture_CrashLowKick_Wave01->Off();
	//}
	

	Off();


}

bool Skill_Fighter_F_CrashLowKick::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	TimePass += _DeltaTime;
	if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 0 && TimePass <= 0.16f)
	{
		//Texture_CrashLowKick->CurAnimationPauseSwitch();
		_Avata->SetAllAvataManualControl();
	}
	else if (IsReady == false)
	{
		//Texture_CrashLowKick->CurAnimationPauseSwitch();
		_Avata->SetAllAvataAutoControl(false);
		IsReady = true;
	}

	if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 2)
	{
		Object_HitList;
		CheckCollision();
		Is_CollisionCheck = true;


		//Texture_CrashLowKick_Wave01->On();
	}
	else if (_Avata->GetAvata_Skin()->IsEndFrame())
	{
		Off();
		return true;
	}
	return false;

}

bool Skill_Fighter_F_CrashLowKick::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	//Texture_LowKick_WaveEffect09
	//Texture_LowKick_WaveEffect09->On();
	//Texture_LowKick_WaveEffect06->SetParent(_Other->GetActor());
	//Texture_LowKick_WaveEffect06->On();

	if (!SomeOneHit)
	{
		GamePlayObject* Object = _Other->GetActor<GamePlayObject>();
		Texture_CrashLowKick->ChangeFrameAnimation("CrashLowKick_Hit");
		Texture_CrashLowKick_Hit1->On();
		Texture_CrashLowKick_Hit3->On();
		Texture_CrashLowKick_Bone->SetParent(Object);
		Texture_CrashLowKick_Bone->On();
	}

	return false;
}

void Skill_Fighter_F_CrashLowKick::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_LowKick2");
	Texture_CrashLowKick->ChangeFrameAnimation("CrashLowKick_Base");
	Texture_CrashLowKick->On();
	IsReady = false;
}