#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GamePlayMonster;
class GameEngineUIRenderer;
class GamePlayMonsterHPBar : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayMonsterHPBar();
	~GamePlayMonsterHPBar();

	// delete Function
	GamePlayMonsterHPBar(const GamePlayMonsterHPBar& _Other) = delete;
	GamePlayMonsterHPBar(GamePlayMonsterHPBar&& _Other) noexcept = delete;
	GamePlayMonsterHPBar& operator=(const GamePlayMonsterHPBar& _Other) = delete;
	GamePlayMonsterHPBar& operator=(GamePlayMonsterHPBar&& _Other) noexcept = delete;

	static void SetMonster(GamePlayMonster* _Monster);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:
	GameEngineUIRenderer* Texture_MonsterHPBar_UI;
	GameEngineUIRenderer* Texture_MonsterHPBar_UI;

	static GameEngineTexture* Texture_NomalHPBar;
	static GameEngineTexture* Texture_BossHPBar;

	static std::vector<GameEngineTexture*> Vector_BossColor;
	static std::vector<GameEngineTexture*> Vector_NomalColor;

	static GameEngineTexture* Texture_BossColor;
	static GameEngineTexture* Texture_NomalColor;


	//std::vector<GameEngineUIRenderer*>;
	GameEngineUIRenderer* Texture_HP1_Front;
	GameEngineUIRenderer* Texture_HP1_Back;

	GameEngineUIRenderer* Texture_HP2_Front;
	GameEngineUIRenderer* Texture_HP2_Back;

	GameEngineUIRenderer* Texture_HP_White;


	int CurrentIndex;
	// Monster
	GamePlayMonster* Monster_Target;
	unsigned int Mpnster_CurrentHP;
	//MonsterClass Monster_CurrentMonsterClass;
	//

	static GamePlayMonsterHPBar* CurrentActor;

};

