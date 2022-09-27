#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GamePlayObjectNPC;
class GamePlayItem_DESC;
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


	CollisionReturn CheckCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	//void OffEvent() override;
	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:
	std::vector<GameEngineUIRenderer*> vector_ItemSlot;
	std::vector<GameEngineUIRenderer*> vector_ItemIcon;
	std::vector<GameEngineCollision*> vector_Collision;
	std::map<GameEngineCollision*, GameEngineUIRenderer*> map_CollisionRenderer; 
	std::map<GameEngineUIRenderer*, GamePlayItem_DESC*> map_RendererCode;
	

	GameEngineUIRenderer* Texture_OutLine;

	GameEngineCollision* Current_Collision;
	GamePlayItem_DESC* Current_DESC;

	std::map<GamePlayItemCode, int>* map_SellList;
	GameEngineUIRenderer* Texture_Window;
};

