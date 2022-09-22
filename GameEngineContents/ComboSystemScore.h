#pragma once
#include <GameEngineCore/GameEngineActor.h>
#define LikePushbuttonPower 2.f

// Ό³Έν :
enum class RankClass
{
	None,
	SSS,
	SS,
	S,
	A,
	B,
	C,
	D,
	F,
};
class GameEngineUIRenderer;
class ComboSystemScore : public GameEngineActor
{
public:
	// constrcuter destructer
	ComboSystemScore();
	~ComboSystemScore();

	// delete Function
	ComboSystemScore(const ComboSystemScore& _Other) = delete;
	ComboSystemScore(ComboSystemScore&& _Other) noexcept = delete;
	ComboSystemScore& operator=(const ComboSystemScore& _Other) = delete;
	ComboSystemScore& operator=(ComboSystemScore&& _Other) noexcept = delete;


	void RenewalScore(unsigned __int64 _Score);

protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;

private:
	RankClass CurrentRank;

	GameEngineUIRenderer* Texture_Dungeon_Rank;
	GameEngineUIRenderer* Texture_Dungeon_RankColor;
	GameEngineUIRenderer* Texture_Dungeon_Effect;
	std::vector<GameEngineUIRenderer*> vector_Texture_Dungeon_score;

	float ScoreDelay;

	bool Renewal;
	void RenewalRank(unsigned __int64 _Score);
	void SetRankTexure(RankClass _Rank);
	void FillRankColor();
	//void ChangeRank();
	void EffectPlus();
	bool DoEffect;
	float DoEffectDelay;

	float NoInputTime;

	static ComboSystemScore* BeforeInst;
};

