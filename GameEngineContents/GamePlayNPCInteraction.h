#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "GamePlayInteractionWindow.h"

// Ό³Έν :


class GameEngineUIFontRenderer;
class GamePlayObjectNPC;
class GamePlayInteractionWindow;
class GamePlayNPCInteractionTalk;
class GamePlayInteractionShop;
class GamePlayNPCInteraction : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayNPCInteraction();
	~GamePlayNPCInteraction();

	// delete Function
	GamePlayNPCInteraction(const GamePlayNPCInteraction& _Other) = delete;
	GamePlayNPCInteraction(GamePlayNPCInteraction&& _Other) noexcept = delete;
	GamePlayNPCInteraction& operator=(const GamePlayNPCInteraction& _Other) = delete;
	GamePlayNPCInteraction& operator=(GamePlayNPCInteraction&& _Other) noexcept = delete;

	static GamePlayNPCInteraction* GetInst()
	{
		return Inst;
	}
	//inline GamePlayInteractionWindow* GetInteractionWindow() const
	//{
	//	return Actor_InteractWindow;
	//}
	inline GamePlayNPCInteractionTalk* GetInteractionTalk() const
	{
		return Actor_Talk;
	}

	void SetNPCInteractionMenu(GamePlayObjectNPC* _NPC);
	void SetNPCInteraction(InteractOption _Option);
	void NPCInteractionEnd();

	InteractOption CheckInput();
	void EndInteraction();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelStartEvent() override;
	void LevelEndEvent() override;
	// void End() override {}
	// void OnEvent() override {}
	// void OffEvent() override {}
private:
	GamePlayObjectNPC* NPC_Interaction;


	GamePlayInteractionWindow* Actor_InteractWindow;
	GamePlayNPCInteractionTalk* Actor_Talk;
	GamePlayInteractionShop* Actor_Shop;


	InteractOption CurrentActiveInteract;

	static GamePlayNPCInteraction* Inst;
};

