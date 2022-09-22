#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// Ό³Έν :
class InterfaceHUD : public GameEngineActor
{
public:
	// constrcuter destructer
	InterfaceHUD();
	~InterfaceHUD();

	// delete Function
	InterfaceHUD(const InterfaceHUD& _Other) = delete;
	InterfaceHUD(InterfaceHUD&& _Other) noexcept = delete;
	InterfaceHUD& operator=(const InterfaceHUD& _Other) = delete;
	InterfaceHUD& operator=(InterfaceHUD&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

	void LevelStartEvent();
	void LevelEndEvent();
private:
	int CurrentHP;
	int CurrentBeHindHP;
	int CurrentHitHP;

	GameEngineTextureRenderer* HUDBase;
	GameEngineTextureRenderer* HPBar_Outline;
	GameEngineTextureRenderer* MPBar_Outline;

	GameEngineTextureRenderer* HPBar;
	GameEngineTextureRenderer* HPBar_Behind;
	GameEngineTextureRenderer* HPBar_Hit;

	void HPUpdate(float _Time);
	void MPUpdate(float _Time);


	int CurrentMP;
	int CurrentBeHindMP;
	int CurrentHitMP;

	GameEngineTextureRenderer* MPBar;
	GameEngineTextureRenderer* MPBar_Behind;
	GameEngineTextureRenderer* MPBar_Hit;

	GameEngineTextureRenderer* EXPBar;

	std::vector<GameEngineTextureRenderer*> SkillInterface;
	GameEngineTextureRenderer* SkillPage;


	float4 SkillInterfacePivot;
	float4 HUDBasePivot;
	float4 HPBarPivot;
	float4 MPBarPivot;
	float4 EXPBarPivot;
};

