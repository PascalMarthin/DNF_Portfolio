#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>

// ���� :

class TitleButtonUI;
class TitleBackGroundAndUI : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleBackGroundAndUI();
	~TitleBackGroundAndUI();

	// delete Function
	TitleBackGroundAndUI(const TitleBackGroundAndUI& _Other) = delete;
	TitleBackGroundAndUI(TitleBackGroundAndUI&& _Other) noexcept = delete;
	TitleBackGroundAndUI& operator=(const TitleBackGroundAndUI& _Other) = delete;
	TitleBackGroundAndUI& operator=(TitleBackGroundAndUI&& _Other) noexcept = delete;

	inline TitleButtonUI* GetButtonActor() const
	{
		return Actor_ButtonUI;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	GameEngineTextureRenderer* BackGround;
	GameEngineTextureRenderer* GuideLine;

	TitleButtonUI* Actor_ButtonUI;
};

