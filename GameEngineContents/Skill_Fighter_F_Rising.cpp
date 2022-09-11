#include "PreCompile.h"
#include "Skill_Fighter_F_Rising.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"


GameEngineFolderTexture* Skill_Fighter_F_Rising::FolderTexture_Rising_spin = nullptr;
GameEngineFolderTexture* Skill_Fighter_F_Rising::FolderTexture_Tigerstrike_00 = nullptr;
//
//GameEngineFolderTexture* Skill_Fighter_F_Rising::FolderTexture_Rising_spin = nullptr;


Skill_Fighter_F_Rising::Skill_Fighter_F_Rising() 
	: Texture_Wind_0(nullptr)
	, Texture_Wind_2(nullptr)
	, Texture_Wind_5(nullptr)
	, JumpTime(0)
	, LandPos(float4::ZERO)
{
}

Skill_Fighter_F_Rising::~Skill_Fighter_F_Rising() 
{
}

void Skill_Fighter_F_Rising::Start()
{
	Class_Power.push_back(SkillComboPower(200, 1, { 700.f, 0.f, 0, 0.f }, HitPostureType::Aerial, HitType::Hit));

	{
		GameEngineCollision* Rising = GetActor()->CreateComponent<GameEngineCollision>("Rising_Up_1");
		Rising->GetTransform().SetLocalScale({ 120.f, 40.f, 30.f });
		Rising->GetTransform().SetLocalPosition({ 0, 0.f, 0 });
		Rising->ChangeOrder(CollisionOrder::Player_Att);
		Rising->SetDebugSetting(CollisionType::CT_AABB, { 0, 0 ,0, 0 });
		Collision_AllCollisionList.push_back(Rising);
	}


	{
		GameEngineCollision* Rising = GetActor()->CreateComponent<GameEngineCollision>("Rising_Up_2");
		Rising->GetTransform().SetLocalScale({ 80.f, 60.f, 30.f });
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
		GameEngineTextureRenderer* Texture_Rising_Spin = GetActor()->CreateComponent<GameEngineTextureRenderer>("Texture_Rising_spin");
		Texture_Rising_Spin->CreateFrameAnimationFolder("Texture_Rising_spin", FrameAnimation_DESC("Rising_spin", 0.05f, false));
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
		Texture_Rising_Spin->GetTransform().SetLocalPosition({ -5 , 25.f, -90.f });
		Texture_Rising_Spin->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Rising_Spin->GetPixelData().MulColor = { 2.3f, 2.3f , 2.3f , 1.5f };
		//Texture_Rising_Spin->GetPixelData().PlusColor = { 0, 0 ,0 , 0.9f };
		Texture_Rising_Spin->Off();
		Texture_Rising_spin.push_back(Texture_Rising_Spin); // Small


		Texture_Rising_Spin = GetActor()->CreateComponent<GameEngineTextureRenderer>("Texture_Rising_spin");
		Texture_Rising_Spin->CreateFrameAnimationFolder("Texture_Rising_spin", FrameAnimation_DESC("Rising_spin", 0.0625f, true));
		Texture_Rising_Spin->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		Texture_Rising_Spin->AnimationBindEnd("Texture_Rising_spin",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		Texture_Rising_Spin->ChangeFrameAnimation("Texture_Rising_spin");
		//Texture_Rising_Spin->SetScaleRatio(1.2f);
		Texture_Rising_Spin->ScaleToTexture();
		Texture_Rising_Spin->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x , Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.8f });
		Texture_Rising_Spin->GetTransform().SetLocalRotate({ 0, 0 , 90 });
		Texture_Rising_Spin->GetTransform().SetLocalPosition({ -10 , -30.f, -10.f });
		Texture_Rising_Spin->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
		Texture_Rising_Spin->GetPixelData().MulColor = { 2.3f, 2.3f , 2.3f , 1.5f };
		//Texture_Rising_Spin->GetPixelData().PlusColor = { 0, 0 ,0 , 0.9f };
		Texture_Rising_Spin->Off();
		Texture_Rising_spin.push_back(Texture_Rising_Spin); // Big
	}

	{
		GameEngineTextureRenderer* RisingEffect = GetActor()->CreateComponent<GameEngineTextureRenderer>("RisingEffect");
		RisingEffect->CreateFrameAnimationFolder("RisingEffect", FrameAnimation_DESC("Tigerstrike_00", 0, 4, 0.075f, true));
		RisingEffect->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Rising_spin", 3, 9, 0.04f, false));

		RisingEffect->AnimationBindEnd("RisingEffect",
			[](const FrameAnimation_DESC& _Desc)
			{
				_Desc.Renderer->Off();
			});
		RisingEffect->ChangeFrameAnimation("RisingEffect");
		RisingEffect->SetScaleRatio(0.8f);
		RisingEffect->ScaleToTexture();
		RisingEffect->GetTransform().SetLocalRotate({ 0, 0 , 90 });
		RisingEffect->GetTransform().SetLocalPosition({ -10 , -30.f, -10.f });
		RisingEffect->GetPixelData().MulColor = { 1.f, 1.f, 1.f, 0.8f };
		RisingEffect->Off();
		Texture_RisingEffect.push_back(RisingEffect); 

	}
	{
		
	//	Texture_Wind_0 = GetActor()->CreateComponent<GameEngineTextureRenderer>("Texture_Wind_0");
	//	Texture_Wind_0->CreateFrameAnimationFolder("Texture_Wind_0", FrameAnimation_DESC("Texture_Wind_0", 0.04f, false));
	//	Texture_Wind_0->CreateFrameAnimationFolder("None", FrameAnimation_DESC("Texture_Wind_0", 0.04f, false));
	//	Texture_Wind_0->AnimationBindEnd("Texture_Rising_spin",
	//		[](const FrameAnimation_DESC& _Desc)
	//		{
	//			_Desc.Renderer->Off();
	//		});
	//	Texture_Wind_0->ChangeFrameAnimation("Texture_Rising_spin");
	//	Texture_Wind_0->ScaleToTexture();
	////	Texture_Wind_0->GetTransform().SetLocalScale({ Texture_Rising_Spin->GetTransform().GetLocalScale().x * 0.8f, Texture_Rising_Spin->GetTransform().GetLocalScale().y * 0.5f });
	//	//Texture_Wind_0->GetTransform().SetLocalRotate({ 0, 0 , 90 });
	//	Texture_Wind_0->GetTransform().SetLocalPosition({ -20 , 50.f, -90.f });
	//	Texture_Wind_0->GetPipeLine()->SetOutputMergerBlend("TransparentBlend");
	//	Texture_Wind_0->Off();
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
		if (_Avata->GetAvata_Skin()->EndFrame)
		{
			_Stat->SetJump();
			_Avata->ChangeAvataAnimation("Att_RisingUpper_Jump");
			LandPos = GetActor()->GetTransform().GetWorldPosition();
			JumpTime = _DeltaTime;
			int_ComboStuck = 1;

			{
				//Texture_Rising_spin[0]->ChangeFrameAnimation("None");
				//Texture_Rising_spin[0]->ChangeFrameAnimation("Texture_Rising_spin");
				//Texture_Rising_spin[0]->On();
			}
			{
				//Texture_Rising_spin[1]->ChangeFrameAnimation("None");
				//Texture_Rising_spin[1]->ChangeFrameAnimation("Texture_Rising_spin");
				//Texture_Rising_spin[1]->On();
			}
			{
				Texture_RisingEffect[0]->ChangeFrameAnimation("None");
				Texture_RisingEffect[0]->ChangeFrameAnimation("RisingEffect");
				Texture_RisingEffect[0]->On();

			}

			return false;
		}
		break;
	case 1:
	{
		JumpTime += _DeltaTime;

		if (JumpTime * 7.5f >= 1.f)
		{
			GetActor()->GetTransform().SetLocalPosition({ LandPos.x, LandPos.y + Skill_Rising_High, LandPos.z });
			_Avata->ChangeAvataAnimation("Att_RisingUpper_Spin");
			JumpTime = 0;
			int_ComboStuck = 2;
			return false;
		}
		else
		{
			GetActor()->GetTransform().SetLocalPosition(float4::LerpLimit(LandPos, { LandPos.x, LandPos.y + Skill_Rising_High, LandPos.z }, JumpTime * 7.5f));
			return false;
		}
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
		JumpTime += _DeltaTime;
		GetActor()->GetTransform().SetLocalMove({ 0, -Skill_Rising_High * JumpTime, 0 });
		if (GetActor()->GetTransform().GetWorldPosition().y <= LandPos.y)
		{
			_Stat->SetJumpEnd();
			GetActor()->GetTransform().SetLocalPosition(LandPos);
			_Avata->ChangeAvataAnimation("Att_RisingUpper_Landing");
			int_ComboStuck = 5;
			JumpTime = 0;
		}


		break;
	case 5:
		JumpTime += _DeltaTime; // Delay
		if (JumpTime * 2.f >= 1.f)
		{
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

void Skill_Fighter_F_Rising::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	_Avata->ChangeAvataAnimation("Att_RisingUpper_Ready");
	int_ComboStuck = 0;
	JumpTime = 0;
	LandPos = float4::ZERO;
	_Avata->SetShake(2.f, 0.2f);



}

