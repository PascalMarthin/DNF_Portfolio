#pragma once
#include <GameEngineCore/GameEngineActor.h>

#include "GameEngineUIFontRenderer.h"

// Ό³Έν :
enum class InteractionMenuDo;
class GameEngineUIRenderer;
class GamePlayObjectNPC;
class GamePlayNPCInteractionTalk : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayNPCInteractionTalk();
	~GamePlayNPCInteractionTalk();

	// delete Function
	GamePlayNPCInteractionTalk(const GamePlayNPCInteractionTalk& _Other) = delete;
	GamePlayNPCInteractionTalk(GamePlayNPCInteractionTalk&& _Other) noexcept = delete;
	GamePlayNPCInteractionTalk& operator=(const GamePlayNPCInteractionTalk& _Other) = delete;
	GamePlayNPCInteractionTalk& operator=(GamePlayNPCInteractionTalk&& _Other) noexcept = delete;

	void SetNPCInteraction_Talk(std::vector<std::string>* _vector, GamePlayObjectNPC* _NPC);
	void SetNPCInteraction_Quest(std::vector<std::string>* _vector, GamePlayObjectNPC* _NPC);


	InteractionMenuDo CheckInput();

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void LevelStartEvent() override;
	void LevelEndEvent() override;

private:
	GameEngineUIRenderer* Texture_MessageBox;
	GameEngineUIRenderer* Texture_NameBox;
	GameEngineUIRenderer* Texture_UI_Enter;
	GameEngineUIRenderer* Texture_NPCFace;

	GameEngineUIFontRenderer* Font_Name;

	std::vector<GameEngineUIFontRenderer*> vector_Font_Talk;
	std::vector<std::string>* vector_TalkString;

	int TalkingIndex;
	float StartTalkDelay;

	void ShowStringBr(const std::string& _String);
};

