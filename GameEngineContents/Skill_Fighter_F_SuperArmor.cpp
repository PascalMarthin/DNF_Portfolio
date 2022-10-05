#include "PreCompile.h"
#include "Skill_Fighter_F_SuperArmor.h"
#include "GamePlayCharacter.h"
#include "CharacterSkillManager.h"

Skill_Fighter_F_SuperArmor::Skill_Fighter_F_SuperArmor() 
{
}

Skill_Fighter_F_SuperArmor::~Skill_Fighter_F_SuperArmor() 
{
}


void Skill_Fighter_F_SuperArmor::Start()
{
	CreateCastingTexture(0.8f);
	//Texture_Casting = GetActor()->CreateComponent<GameEngineTextureRenderer>();
	//Texture_Casting->CreateFrameAnimationFolder("Casting", FrameAnimation_DESC("Keiken_Casting", 0.0625f, false));
	//Texture_Casting->AnimationBindEnd("Casting", [](const FrameAnimation_DESC& _DESC)
	//	{
	//		_DESC.Renderer->Off();
	//	});
	//Texture_Casting->ChangeFrameAnimation("Casting");
	//Texture_Casting->ScaleToTexture();
	//Texture_Casting->SetPivot(PIVOTMODE::BOT);
	//Texture_Casting->GetTransform().SetLocalPosition({ 0, -188.f, 0 });
	//Texture_Casting->GetPixelData().MulColor = { 0.9f, 0.25f, 0.25f, 0.8f };
	//Texture_Casting->Off();

	//Texture_Casting->ChangeCamera(CAMERAORDER::Object);
	Off();
}

bool Skill_Fighter_F_SuperArmor::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 2:
	{
		CastingEnd(_Stat, _Avata);
		CastingBuffEnd();
		GamePlayCharacter::SetVoice("ft_sarmor.ogg");
		
		//GameEngineEffectRenderer* SkillIcon = GetActor()->CreateComponent<GameEngineEffectRenderer>();
		//SkillIcon->SetTexture("SkillIcon_BackGround.png");
		//SkillIcon->ScaleToTexture();
		//SkillIcon->GetTransform().SetLocalPosition({ 0, 60, 1 });
		//SkillIcon->Death(3.f);
		//SkillIcon->SetFollowScaleOff();
		//SkillIcon->GetPixelData().MulColor.a = 0.8f;
		////SkillIcon->SetParent(Actor_DummyActor);

		//SkillIcon = GetActor()->CreateComponent<GameEngineEffectRenderer>();
		//SkillIcon->SetTexture("SkillIcon_Kaiken.png");
		//SkillIcon->GetTransform().SetLocalPosition({ 0, 60, 1 });
		//SkillIcon->ScaleToTexture();
		//SkillIcon->Death(3.f);
		//SkillIcon->SetFollowScaleOff();
		//SkillIcon->GetPixelData().MulColor.a = 0.8f;
		//SkillIcon->SetParent(Actor_DummyActor);

		_Avata->SetSuperArmor();
		GetActor<GamePlayCharacter>()->GetSkillManager()->InsertBuff(AllSkillEnum::Fighter_F_SuperArmor, 60.f);


		//GameEngineDebug::OutPutString(std::to_string(Texture_CastingBuff->GetTransform().GetWorldPosition().z));

		//GameEngineDebug::OutPutString(std::to_string(SkillIcon->GetTransform().GetWorldPosition().z));
	}
	return true;
	break;
	default:
		break;
	}
	return false;
}

bool Skill_Fighter_F_SuperArmor::BuffUpdate(CharacterStatManager* _Stat)
{
	_Stat->SetSuperarmor();
	return false;
}

void Skill_Fighter_F_SuperArmor::BuffEnd()
{
	GamePlayCharacter* Character = GetActor<GamePlayCharacter>();
	Character->GetStatManager()->SetSuperarmorEnd();
	//Character->GetStatManager()->DestroyBuffStat(AllSkillEnum::Fighter_F_KaiKen);
}

void Skill_Fighter_F_SuperArmor::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	int_ComboStuck = 0;
	Casting(_Stat, _Avata);
	CastingBuff();

}