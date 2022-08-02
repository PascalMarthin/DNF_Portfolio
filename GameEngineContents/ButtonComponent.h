#pragma once
#include <vector>
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :

enum class ButtonSize
{
	None,
	Short,
	Long,
	LongLong,
	VeryLongLong
};

enum class ButtonCondition
{
	None,
	Off,
	On,
	Push
};


class ButtonComponent : public GameEngineActor
{
public:
	// constrcuter destructer
	ButtonComponent();
	~ButtonComponent();

	// delete Function
	ButtonComponent(const ButtonComponent& _Other) = delete;
	ButtonComponent(ButtonComponent&& _Other) noexcept = delete;
	ButtonComponent& operator=(const ButtonComponent& _Other) = delete;
	ButtonComponent& operator=(ButtonComponent&& _Other) noexcept = delete;

	void SetOption(ButtonSize _Button , const float4& _Size = float4::ZERO);
	bool UpdateButtonPush();
protected:
	void Start() override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}
private:
	GameEngineTextureRenderer* Texture_CreateCharacterButton;
	GameEngineCollision* Collision_CreateCharacterButton;

	std::vector<GameEngineTexture*> Texture_AllButton;
	ButtonSize Enum_ButtonSize;
	ButtonCondition Enum_ButtonCondition;

};

