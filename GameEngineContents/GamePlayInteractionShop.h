#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GamePlayObjectNPC;
class GamePlayInteractionShop : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayInteractionShop();
	~GamePlayInteractionShop();

	// delete Function
	GamePlayInteractionShop(const GamePlayInteractionShop& _Other) = delete;
	GamePlayInteractionShop(GamePlayInteractionShop&& _Other) noexcept = delete;
	GamePlayInteractionShop& operator=(const GamePlayInteractionShop& _Other) = delete;
	GamePlayInteractionShop& operator=(GamePlayInteractionShop&& _Other) noexcept = delete;

	void SetShopData(GamePlayObjectNPC* _NPC);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:
	std::vector<GameEngineUIRenderer*> vector_ItemSlot;
};

