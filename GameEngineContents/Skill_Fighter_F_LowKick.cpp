#include "PreCompile.h"
#include "Skill_Fighter_F_LowKick.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


Skill_Fighter_F_LowKick::Skill_Fighter_F_LowKick()
	: Texture_LowKick(nullptr)
	, Texture_LowKick_WaveEffect09(nullptr)
	, Texture_LowKick_WaveEffect06(nullptr)
	, IsReady(false)
{
}

Skill_Fighter_F_LowKick::~Skill_Fighter_F_LowKick() 
{
}


void Skill_Fighter_F_LowKick::Start()
{
	Class_Power.push_back(SkillComboPower(200, 1, { 60, 0.f, 0.f, 80.f }, HitPostureType::Standing, HitType::Hit));
	{
		GameEngineCollision* LowKick = GetActor()->CreateComponent<GameEngineCollision>("LowKick");
		LowKick->GetTransform().SetLocalScale({ 70.f, 40.f, 20.f });
		LowKick->GetTransform().SetLocalPosition({ 30, -50.f, 0 });
		LowKick->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 , 0, 0 });
		Collision_AllCollisionList.push_back(LowKick);
	}


	{
		Texture_LowKick = GetActor()->CreateComponent<GameEngineEffectRenderer>("Lowkick");
		Texture_LowKick->GetTransform().SetLocalPosition({ 70.f, 75.f, -0.01f });
		Texture_LowKick->CreateFrameAnimationFolder("Lowkick", FrameAnimation_DESC("Lowkick", 0.05f));
		Texture_LowKick->AnimationBindEnd("Lowkick",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_LowKick->ChangeFrameAnimation("Lowkick");
		Texture_LowKick->ScaleToTexture();
		Texture_LowKick->GetPixelData().MulColor = { 1.2f, 1.2f, 1.2f, 1.2f };
		Texture_LowKick->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_LowKick->Off();
	}
	//{
	//	Texture_LowKick_WaveEffect09 = GetActor()->CreateComponent<GameEngineTextureRenderer>("Wave09");
	//	Texture_LowKick_WaveEffect09->GetTransform().SetLocalPosition({ 0.f, -72.f, 100.f });
	//	Texture_LowKick_WaveEffect09->CreateFrameAnimationFolder("Wave09", FrameAnimation_DESC("Wave09", 0.05f, true));
	//	Texture_LowKick_WaveEffect09->AnimationBindEnd("Wave09",
	//		[](const FrameAnimation_DESC& _Desc)
	//		{
	//			_Desc.Renderer->Off();
	//		});
	//	Texture_LowKick_WaveEffect09->ChangeFrameAnimation("Wave09");
	//	Texture_LowKick_WaveEffect09->ScaleToTexture();
	//	//Texture_LowKick_WaveEffect09->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
	//	Texture_LowKick_WaveEffect09->Off();
	//}
	//
	//{
	//	Texture_LowKick_WaveEffect06 = GetActor()->CreateComponent<GameEngineTextureRenderer>("Wave06");
	//	Texture_LowKick_WaveEffect06->GetTransform().SetLocalPosition({ 0.f, -72.f, 100.f });
	//	Texture_LowKick_WaveEffect06->CreateFrameAnimationFolder("Wave06", FrameAnimation_DESC("Wave06", 0.1f, true));
	//	Texture_LowKick_WaveEffect06->AnimationBindEnd("Wave06",
	//		[](const FrameAnimation_DESC& _Desc)
	//		{
	//			_Desc.Renderer->Off();
	//		});
	//	Texture_LowKick_WaveEffect06->ChangeFrameAnimation("Wave06");
	//	Texture_LowKick_WaveEffect06->ScaleToTexture();
	//	//Texture_LowKick_WaveEffect06->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
	//	Texture_LowKick_WaveEffect06->Off();
	//}
	Off();

	//GameEngineDebug::OutPutString(std::to_string(Collision_HamerKick->GetTransform().GetWorldScale().z));
}

bool Skill_Fighter_F_LowKick::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	TimePass += _DeltaTime;
	if (_Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 0 && TimePass <= 0.05f)
	{
		Texture_LowKick->CurAnimationPauseSwitch();
		_Avata->SetAllAvataManualControl();
	}
	else if(IsReady == false)
	{
		Texture_LowKick->CurAnimationPauseSwitch();
		_Avata->SetAllAvataAutoControl(false);
		IsReady = true;
	}

	if (Is_CollisionCheck == false && _Avata->GetAvata_Skin()->GetCurrentFrameStuck() == 2)
	{
		CheckCollision();
		Is_CollisionCheck = true;
	}
	else if (_Avata->GetAvata_Skin()->IsEndFrame())
	{
		Off();
		return true;
	}
	return false;

}

bool Skill_Fighter_F_LowKick::TriggerSkill_ect(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	//Texture_LowKick_WaveEffect09->SetParent(_Other->GetActor());
	//Texture_LowKick_WaveEffect09->On();
	//Texture_LowKick_WaveEffect06->SetParent(_Other->GetActor());
	//Texture_LowKick_WaveEffect06->On();
	
	return false;
}

void Skill_Fighter_F_LowKick::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_LowKick1");
	Texture_LowKick->On();
	Texture_LowKick->ChangeFrameAnimation("Lowkick", true);
	IsReady = false;
}