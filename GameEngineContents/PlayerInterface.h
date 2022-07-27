#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class InterfaceHUD;
class InterfaceItemBag;
class GamePlayKeyManager;
class PlayerInterface : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerInterface();
	~PlayerInterface();

	// delete Function
	PlayerInterface(const PlayerInterface& _Other) = delete;
	PlayerInterface(PlayerInterface&& _Other) noexcept = delete;
	PlayerInterface& operator=(const PlayerInterface& _Other) = delete;
	PlayerInterface& operator=(PlayerInterface&& _Other) noexcept = delete;

	inline InterfaceHUD* GetUI_HUD() const
	{
		return PlayerHUD;
	}

	inline InterfaceItemBag* GetUI_ItemBag() const
	{
		return PlayerItemBag;
	}
	inline GamePlayKeyManager* GetUI_KeyManager() const
	{
		return KeyManager;
	}

protected:
	void Start() override;

	void Update(float _DeltaTime) override;

	// void End() override {}
	// void OnEvent() {}
	// void OffEvent() {}

private:
	InterfaceHUD* PlayerHUD;
	InterfaceItemBag* PlayerItemBag;

	GamePlayKeyManager* KeyManager;

};

