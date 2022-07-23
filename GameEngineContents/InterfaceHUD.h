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
private:
	GameEngineTextureRenderer* HUDBase;
	GameEngineTextureRenderer* HPBar;
	GameEngineTextureRenderer* HPBar_Hit;
	GameEngineTextureRenderer* MPBar;

	float4 HUDBasePivot;
	float4 HPBarPivot;
	float4 MPBarPivot;
};

