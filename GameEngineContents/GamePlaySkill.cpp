#include "PreCompile.h"
#include "GamePlaySkill.h"
#include "GamePlayObject.h"
#include "GamePlayCharacter.h"
#include "GamePlayComboSystem.h"

GamePlaySkill::GamePlaySkill()
	: int_ComboStuck(0)
	, TimePass(0.f)
	, Is_CollisionCheck(false)
	, CoolTime(0.f)
	, CurrentCoolTime(0.f)
	, SomeOneHit(false)
	, Actor_DummyActor(nullptr)
	, Texture_Thumbnail(nullptr)
	, CastingTime(0)
	, CurrentCastingTime(0)
	, int_SkillLevel(1)
	, Texture_CastingBuff(nullptr)
{
}

GamePlaySkill::~GamePlaySkill() 
{
}


void GamePlaySkill::Start()
{
	Actor_DummyActor = GetActor()->GetLevel()->CreateActor<DummyActor>();

}


void GamePlaySkill::CheckCollision()
{
	bool_MultiHit = false;
	Collision_AllCollisionList[int_ComboStuck]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&GamePlaySkill::CollsionHitFunction, this, std::placeholders::_1, std::placeholders::_2));
	bool_MultiHit = false;
}

void GamePlaySkill::CheckCollision(int _Combo)
{
	bool_MultiHit = false;
	Collision_AllCollisionList[_Combo]->IsCollision(CollisionType::CT_AABB, CollisionOrder::Monster, CollisionType::CT_AABB,
		std::bind(&GamePlaySkill::CollsionHitFunction, this, std::placeholders::_1, std::placeholders::_2));
	bool_MultiHit = false;
}

CollisionReturn GamePlaySkill::CollsionHitFunction(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	GamePlayObject* Actor = _Other->GetActor<GamePlayObject>();

	if (GamePlaySkill::IsHitObject(Actor, Class_Power[int_ComboStuck].int_MaxHit))
	{
		return CollisionReturn::ContinueCheck;
	}

	if (bool_MultiHit == false)
	{
		bool_MultiHit = true;
	}
	else
	{
		GamePlayComboSystem::GetInst()->SetComboClass(ComboClass::MultiHit);
	}
	TriggerSkill_ect(_This, _Other);
	SomeOneHit = true;
	Object_HitList[Actor] += 1;
	Actor->BeHit(this, _Other, GetActor<GamePlayObject>(), CheckDir(_This, _Other), Class_Power[int_ComboStuck].int_SkillDamage); //

	return CollisionReturn::ContinueCheck;
}


bool GamePlaySkill::IsHitObject(GamePlayObject* _Object, int _HitOrder)
{
	if (Object_HitList[_Object] >= _HitOrder)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GamePlaySkill::CheckDir(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (_This->GetActor()->GetTransform().GetLocalPosition().x > _Other->GetActor()->GetTransform().GetLocalPosition().x)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}


float GamePlaySkill::FSM_Move_Helper()
{
	bool Left = false;
	bool Right = false;
	float MoveIndex = 0.f;
	GamePlayObject* Object = GetActor<GamePlayObject>();
	if (GameEngineInput::GetInst()->IsDown("Right_Arrow") || GameEngineInput::GetInst()->IsPress("Right_Arrow"))
	{
		if (Object->GetObjectDir())
		{
			MoveIndex = 6.f;
		}
		else
		{
			MoveIndex = 0.f;
		}
		Right = true;
	}

	if ((GameEngineInput::GetInst()->IsDown("Left_Arrow")) || GameEngineInput::GetInst()->IsPress("Left_Arrow"))
	{
		if (Object->GetObjectDir())
		{
			MoveIndex = 0.f;
		}
		else
		{
			MoveIndex = -6.f;
		}
		Left = true;
	}

	if (Left == true && Right == true)
	{
		MoveIndex = 0.f;
	}
	else if (Left == false && Right == false)
	{
		if (Object->GetObjectDir())
		{
			MoveIndex = 0.5f;
		}
		else
		{
			MoveIndex = -0.5f;
		}
	}
	return MoveIndex;
}
void GamePlaySkill::CreateCastingTexture(float _CastingTime)
{
	CastingTime = _CastingTime;
	CurrentCastingTime = 0;
	GameEngineFolderTexture* Texture = GameEngineFolderTexture::Find("Casting");
	GameEngineEffectRenderer* Casting = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	Casting->SetTexture(Texture->GetTexture(0));
	Casting->ScaleToTexture();
	Casting->GetTransform().SetLocalPosition({ 0, 45, -100});
	Vector_CastingTexture.push_back(Casting);
	Casting->Off();

	Casting = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	Casting->SetTexture(Texture->GetTexture(1));
	Casting->ScaleToTexture();
	Casting->GetTransform().SetLocalPosition({ 0, 45, -100});
	Casting->GetTransform().PixLocalNegativeX();
	Vector_CastingTexture.push_back(Casting);
	Casting->Off();

	Casting = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	Casting->SetTexture(Texture->GetTexture(2));
	Casting->ScaleToTexture();
	Casting->GetTransform().SetLocalPosition({ 0, 45, -100 });
	Vector_CastingTexture.push_back(Casting);
	Casting->Off();

	Casting = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	//Casting->SetTexture(Texture->GetTexture(2));
	Casting->CreateFrameAnimationFolder("CastingEnd", FrameAnimation_DESC("Casting",4, 9, 0.1f, false));
	Casting->ChangeFrameAnimation("CastingEnd");
	Casting->AnimationBindEnd("CastingEnd",
		[](const FrameAnimation_DESC& _DESC)
		{
			_DESC.Renderer->Off();
		});
	Casting->ScaleToTexture();
	Casting->GetTransform().SetLocalPosition({ 0, 45, -100 });
	Vector_CastingTexture.push_back(Casting);
	Casting->Off();


	Texture_CastingBuff = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	//Texture_CastingBuff->SetTexture("CastingBuff");
	Texture_CastingBuff->CreateFrameAnimationFolder("Casting", FrameAnimation_DESC("CastingBuff", 0, 22, 0.04f, true));
	Texture_CastingBuff->CreateFrameAnimationFolder("End", FrameAnimation_DESC("CastingBuff", 23, 29, 0.04f, true));
	Texture_CastingBuff->GetPixelData().PlusColor = 0.3f;
	Texture_CastingBuff->GetPixelData().PlusColor.a = 0;
	Texture_CastingBuff->AnimationBindEnd("End",
		[](const FrameAnimation_DESC& _DESC)
		{
			_DESC.Renderer->Off();
		});
	Texture_CastingBuff->ChangeFrameAnimation("Casting");
	Texture_CastingBuff->ScaleToTexture();
	Texture_CastingBuff->GetTransform().SetLocalPosition({78, 145, -100.1f});
	Texture_CastingBuff->Off();



	//Casting = GetActor()->CreateComponent<GameEngineTextureRenderer>();
	//Casting->SetTexture(Texture->GetTexture(4));
	//Casting->ScaleToTexture();
	//Casting->GetTransform().SetLocalPosition({ 0, 55, -100 });
	//Vector_CastingTexture.push_back(Casting);
	//Casting->Off();
}


void GamePlaySkill::Casting(CharacterStatManager* _Stat, AvataManager* _Avata)
{
	GameEngineSound::SoundPlayOneShot("mcurtain_light.ogg");
	int_ComboStuck = 1;
	CurrentCastingTime = 0;

	
	_Stat->SetCasting();
	_Avata->ChangeAvataAnimation("Att_Casting");
	for (size_t i = 0; i < Vector_CastingTexture.size() - 1; i++)
	{
		Vector_CastingTexture[i]->SetParent(Actor_DummyActor);
		Vector_CastingTexture[i]->On();
	}

	//Vector_CastingTexture[1]->GetTransform().SetLocalScale({0, Vector_CastingTexture[2]->GetTransform().GetLocalScale().y});
	Vector_CastingTexture[1]->GetPixelData().Slice.x = 1;
}

void GamePlaySkill::CastingBuff()
{
	Texture_CastingBuff->On();
	Texture_CastingBuff->ChangeFrameAnimation("Casting", true);

}
void GamePlaySkill::CastingBuffEnd()
{
	Texture_CastingBuff->ChangeFrameAnimation("End", true);
}


void GamePlaySkill::Update(float _DeltaTime)
{
	if (CastingTime != 0)
	{
		if (CastingTime > CurrentCastingTime && int_ComboStuck == 1)
		{
			Actor_DummyActor->GetTransform().SetLocalPosition(GetActor()->GetTransform().GetLocalPosition());
			CurrentCastingTime += _DeltaTime;
			
			Vector_CastingTexture[1]->GetPixelData().Slice.x = (1 - (CurrentCastingTime / CastingTime));

			if (CastingTime <= CurrentCastingTime)
			{
				int_ComboStuck = 2;
			}

		}
	}


}

void GamePlaySkill::CastingEnd(CharacterStatManager* _Stat, AvataManager* _Avata)
{
	_Stat->SetCastingEnd();
	Vector_CastingTexture[1]->GetPixelData().Slice.x = 0;
	Vector_CastingTexture[3]->ChangeFrameAnimation("CastingEnd", true);
	Vector_CastingTexture[3]->On();
	//CastingTime = 0;
	for (size_t i = 0; i < Vector_CastingTexture.size() - 1; i++)
	{
		Vector_CastingTexture[i]->Off();
	}
}

void GamePlaySkill::OnEvent()
{
	if (Actor_DummyActor == nullptr)
	{
		Actor_DummyActor = GetActor()->GetLevel()->CreateActor<DummyActor>();
	}
	Object_HitList.clear();
	Is_CollisionCheck = false;
	SomeOneHit = false;
}

void GamePlaySkill::OffEvent()
{
	int_ComboStuck = 0;
	TimePass = 0.f;
	if (Texture_CastingBuff != nullptr)
	{
		Texture_CastingBuff->Off();
		for (size_t i = 0; i < Vector_CastingTexture.size() - 1; i++)
		{
			Vector_CastingTexture[i]->Off();
		}
	}

}

void GamePlaySkill::LevelStartEvent()
{
	//int_SkillLevel
}

void GamePlaySkill::LevelEndEvent()
{
	//int_SkillLevel
}