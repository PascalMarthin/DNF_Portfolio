#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
enum class ComboClass;
class ComboSystemBlank : public GameEngineActor
{
	friend class GamePlayComboSystem;
public:
	// constrcuter destructer
	ComboSystemBlank();
	~ComboSystemBlank();

	// delete Function
	ComboSystemBlank(const ComboSystemBlank& _Other) = delete;
	ComboSystemBlank(ComboSystemBlank&& _Other) noexcept = delete;
	ComboSystemBlank& operator=(const ComboSystemBlank& _Other) = delete;
	ComboSystemBlank& operator=(ComboSystemBlank&& _Other) noexcept = delete;

	bool RenewalCombo(unsigned int _Index);

protected:
	void Start() override;

	void Update(float _Delta) override;

	void OnEvent() override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:

	ComboClass CurrentClass;

	std::vector<GameEngineUIRenderer*> Texture_Combo_num;
	GameEngineUIRenderer* Texture_Combo_bonus;
	GameEngineUIRenderer* Texture_Combo_Aerial;
	GameEngineUIRenderer* Texture_Combo_Effect;


	float Combo_bonus_Time;
	float Combo_BrightTime;

	bool EndCombo;
	bool FontSizeUp;

	//std::vector<float> vector_Combo_BrightIndex;
	//float BrightIndex;
	bool RenewalCombo();


	void SetBrighting();
	void SetComboClass(ComboClass _Class);

	void ReSet();




};

