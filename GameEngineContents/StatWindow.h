#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GameEngineFontRenderer;
enum class StatClass;
class StatWindow : public GameEngineActor
{
public:
	// constrcuter destructer
	StatWindow();
	~StatWindow();

	// delete Function
	StatWindow(const StatWindow& _Other) = delete;
	StatWindow(StatWindow&& _Other) noexcept = delete;
	StatWindow& operator=(const StatWindow& _Other) = delete;
	StatWindow& operator=(StatWindow&& _Other) noexcept = delete;

	inline static StatWindow* GetInst()
	{
		return Inst;
	}

	void RefreshStat();
	void SetClone();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}

	void OnEvent() override;
	void OffEvent() override;
	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:
	void SetFontPos();

	std::vector<GameEngineUIRenderer*> Avata_Clone;

	GameEngineUIRenderer* Texture_Profile;
	std::map<StatClass ,GameEngineFontRenderer*> Font_Renderer;
	
	static StatWindow* Inst;
};

