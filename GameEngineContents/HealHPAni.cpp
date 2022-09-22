#include "PreCompile.h"
#include "HealHPAni.h"
#include "GameEngineDamageRenderer.h"

HealHPAni::HealHPAni() 
	: Texture_EffectAni(nullptr)
{
}

HealHPAni::~HealHPAni() 
{
}

void HealHPAni::Start()
{
	Texture_EffectAni = CreateComponent<GameEngineEffectRenderer>();
	Texture_EffectAni->CreateFrameAnimationFolder("HPHeal", FrameAnimation_DESC("HPHealEffect", 0.075f, false ));
	Texture_EffectAni->AnimationBindEnd("HPHeal", std::bind(&HealHPAni::EndFrame, this, std::placeholders::_1));
	Texture_EffectAni->CreateFrameAnimationFolder("MPHeal", FrameAnimation_DESC("MPHealEffect", 0.075f, false));
	Texture_EffectAni->AnimationBindEnd("MPHeal", std::bind(&HealHPAni::EndFrame, this, std::placeholders::_1));
	Texture_EffectAni->GetTransform().SetLocalPosition({18, 30});
}

void HealHPAni::EndFrame(const FrameAnimation_DESC& _DESC)
{
	Death();
}

void HealHPAni::SetMPHPHeal(HPMPEnum _Enum, int _Heal)
{
	GameEngineDamageRenderer* Renderer = GetLevel()->CreateActor<GameEngineDamageRenderer>();
	Renderer->GetTransform().SetLocalPosition(GetParent<GameEngineTransformBase>()->GetTransform().GetLocalPosition());
	if (_Enum == HPMPEnum::HP)
	{
		Texture_EffectAni->ChangeFrameAnimation("HPHeal");
		Renderer->SetDamage(_Heal, DamageFontClass::HPHeal);
	}

	if (_Enum == HPMPEnum::MP)
	{
		Texture_EffectAni->ChangeFrameAnimation("MPHeal");
		Renderer->SetDamage(_Heal, DamageFontClass::MPHeal);
	}

	Texture_EffectAni->ScaleToTexture();
}

void HealHPAni::Update(float _DeltaTime)
{

}
void HealHPAni::LevelStartEvent()
{

}