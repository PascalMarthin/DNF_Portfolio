#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class FrameAnimation_DESC;
enum class HPMPEnum
{
	MP,
	HP
};
class GameEngineEffectRenderer;
class HealHPAni : public GameEngineActor
{
public:
	// constrcuter destructer
	HealHPAni();
	~HealHPAni();

	// delete Function
	HealHPAni(const HealHPAni& _Other) = delete;
	HealHPAni(HealHPAni&& _Other) noexcept = delete;
	HealHPAni& operator=(const HealHPAni& _Other) = delete;
	HealHPAni& operator=(HealHPAni&& _Other) noexcept = delete;

	void SetMPHPHeal(HPMPEnum _Enum, int _Heal);

	void EndFrame(const FrameAnimation_DESC& _DESC);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	//void OnEvent();
	// void OffEvent() override {}
	void LevelStartEvent() override;
private:
	GameEngineEffectRenderer* Texture_EffectAni; 

};

