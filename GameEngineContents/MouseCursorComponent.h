#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>

// ���� :
class MouseCursorComponent : public GameEngineActor
{
public:
	// constrcuter destructer
	MouseCursorComponent();
	~MouseCursorComponent();

	// delete Function
	MouseCursorComponent(const MouseCursorComponent& _Other) = delete;
	MouseCursorComponent(MouseCursorComponent&& _Other) noexcept = delete;
	MouseCursorComponent& operator=(const MouseCursorComponent& _Other) = delete;
	MouseCursorComponent& operator=(MouseCursorComponent&& _Other) noexcept = delete;

	static inline MouseCursorComponent* GetInst()
	{
		return MouseCursorComponent::Inst;
	}

	inline GameEngineCollision* GetMainCamMouseCursor() const
	{
		return Collision_MainCam_MouseCursor;
	}

	inline GameEngineCollision* GetUICamMouseCursor() const
	{
		return Collision_UICam_MouseCursor;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

	void LevelStartEvent() override;
	void LevelEndEvent() override;

private:
	GameEngineUIRenderer* Texture_Cursor;
	GameEngineCollision* Collision_MainCam_MouseCursor;
	GameEngineCollision* Collision_UICam_MouseCursor;

	static MouseCursorComponent* Inst;

};

