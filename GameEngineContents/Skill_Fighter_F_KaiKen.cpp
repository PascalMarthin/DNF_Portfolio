#include "PreCompile.h"
#include "Skill_Fighter_F_KaiKen.h"
#include "GamePlayCharacter.h"
#include "CharacterSkillManager.h"

Skill_Fighter_F_KaiKen::Skill_Fighter_F_KaiKen() 
	: Texture_Casting(nullptr)
{
}

Skill_Fighter_F_KaiKen::~Skill_Fighter_F_KaiKen() 
{
}
void Skill_Fighter_F_KaiKen::Start()
{
	CreateCastingTexture(Keiken_CastingTime);
	Texture_Casting = GetActor()->CreateComponent<GameEngineTextureRenderer>();
	Texture_Casting->CreateFrameAnimationFolder("Casting", FrameAnimation_DESC("Keiken_Casting", 0.0625f, false ));
	Texture_Casting->AnimationBindEnd("Casting", [](const FrameAnimation_DESC& _DESC)
		{
			_DESC.Renderer->Off();
		});
	Texture_Casting->ChangeFrameAnimation("Casting");
	Texture_Casting->ScaleToTexture();
	Texture_Casting->SetPivot(PIVOTMODE::BOT);
	Texture_Casting->GetTransform().SetLocalPosition({ 0, -188.f, 0 });
	Texture_Casting->GetPixelData().MulColor = { 0.9f, 0.25f, 0.25f, 0.8f };
	Texture_Casting->Off();

	Texture_Casting->ChangeCamera(CAMERAORDER::Object);
	
}

bool Skill_Fighter_F_KaiKen::ActiveSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata, float _DeltaTime)
{
	switch (int_ComboStuck)
	{
	case 2:
		CastingEnd(_Stat, _Avata);
		_Avata->CreateEctAvata(AllSkillEnum::Fighter_F_KaiKen, "Keiken_Buff", { 0.9f, 0.25f, 0.25f, 0.8f });
		GetActor<GamePlayCharacter>()->GetSkillManager()->InsertBuff( AllSkillEnum::Fighter_F_KaiKen, 20.f);
		GetActor<GamePlayCharacter>()->GetSkillManager()->InsertBuffStat( AllSkillEnum::Fighter_F_KaiKen, StatClass::STR, (static_cast<__int64>(500) * GetSkillLevel()));

		Texture_Casting->On();
		Texture_Casting->ChangeFrameAnimation("Casting", true);
		return true;
		break;
	default:
		break;
	}
	return false;
}

bool Skill_Fighter_F_KaiKen::BuffUpdate(CharacterStatManager* _Stat) 
{
	return false;
}

void Skill_Fighter_F_KaiKen::BuffEnd()
{
	GamePlayCharacter* Character = GetActor<GamePlayCharacter>();
	Character->GetAvataManager()->DestroyEctAvata(AllSkillEnum::Fighter_F_KaiKen);
	//Character->GetStatManager()->DestroyBuffStat(AllSkillEnum::Fighter_F_KaiKen);
}

void Skill_Fighter_F_KaiKen::StartSkill(CharacterStatManager* _Stat, MoveManager* _Move, AvataManager* _Avata)
{
	int_ComboStuck = 0;
	Casting(_Stat, _Avata);

}
