#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>

// Ό³Έν :
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

	inline GameEngineCollision* GetMouseCursor() const
	{
		return Collision_MouseCursor;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	GameEngineTextureRenderer* Texture_Cursor;
	GameEngineCollision* Collision_MouseCursor;
};

