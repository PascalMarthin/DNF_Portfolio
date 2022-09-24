#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
enum class InteractionMenuDo;
enum class InteractOption;
class GameEngineUIRenderer;
class GamePlayObjectNPC;
class GameEngineFontRenderer;
class GamePlayInteractionWindow : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayInteractionWindow();
	~GamePlayInteractionWindow();

	// delete Function
	GamePlayInteractionWindow(const GamePlayInteractionWindow& _Other) = delete;
	GamePlayInteractionWindow(GamePlayInteractionWindow&& _Other) noexcept = delete;
	GamePlayInteractionWindow& operator=(const GamePlayInteractionWindow& _Other) = delete;
	GamePlayInteractionWindow& operator=(GamePlayInteractionWindow&& _Other) noexcept = delete;

	void SetInteractUIOn(GamePlayObjectNPC* _NPC);
	void SetInteractUIOff();

	InteractionMenuDo CheckInput();
	inline InteractOption GetInteractOption() const
	{
		return CurrentOption;
	}


protected:
	//void Start() override;
	//void Update(float _Delta) override;


private:
	std::map<InteractOption, GameEngineUIRenderer*> map_Texture_InteractUI;
	std::vector<InteractOption> vector_AllCurrentOption;
	int CurrentOptionIndex;
	InteractOption CurrentOption;
	GameEngineFontRenderer* Font_Name;


	void SetTextureInteractOption(InteractOption _Option, GameEngineUIRenderer* _Renderer);

};

