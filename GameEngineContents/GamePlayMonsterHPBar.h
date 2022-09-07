#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
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

	static inline void SetMonster(GamePlayMonster* _Monster)
	{
		GamePlayMonsterHPBar::CurrentActor->SetMonster_InMember(_Monster);
	}

	static inline void SetHitDamage(unsigned int _CurrentHP)
	{
		GamePlayMonsterHPBar::CurrentActor->SetHitDamage_InMember(_CurrentHP);
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:
	GameEngineUIRenderer* Texture_MonsterHPBar_UI;
	GameEngineUIRenderer* Texture_MonsterHPBar_UIEnd;

	static GameEngineTexture* Texture_NomalHPBar;
	static GameEngineTexture* Texture_BossHPBar;

	std::vector<GameEngineUIRenderer*> All_HPFont; // 4자리까지 지원
	static GameEngineFolderTexture* TextureFolder_HPFont;

	static GameEngineTexture* Texture_NomalHPBarEnd;
	static GameEngineTexture* Texture_BossHPBarEnd;

	static std::vector<GameEngineTexture*> Vector_BossColor;
	static std::vector<GameEngineTexture*> Vector_NomalColor;

	static GameEngineTexture* Texture_BossColor;
	static GameEngineTexture* Texture_NomalColor;

	std::vector<GameEngineUIRenderer*> All_MonsterCategory;


	//std::vector<GameEngineUIRenderer*>;
	GameEngineUIRenderer* Texture_HP1_Front;
	GameEngineUIRenderer* Texture_HP1_Back;

	GameEngineUIRenderer* Texture_HP2_Front;
	GameEngineUIRenderer* Texture_HP2_Back;

	GameEngineUIRenderer* Texture_HP1_White;
	GameEngineUIRenderer* Texture_HP1_Black;
	GameEngineUIRenderer* Texture_HP2_White;
	GameEngineUIRenderer* Texture_HP2_Black;

	GameEngineUIRenderer* Texture_MonsterHP_Delete;

	bool HP1Front;


	// Monster
	GamePlayMonster* Monster_Target;
	unsigned int Monster_CurrentHP;
	unsigned int Monster_BeforeHPLine;
	unsigned int Monster_GoalHPLine;

	float FlashTime;
	int MaxSpeed;
	float FrameSpeed;
	float DecreaseTime;
	float DeathBlink;


	//

	static GamePlayMonsterHPBar* CurrentActor;


	void SetMonster_InMember(GamePlayMonster* _Monster);

	void SetHitDamage_InMember(unsigned int _CurrentHP);

	void SwitchingHP1and2();
	bool SetHPBarRatioTexture_Front(int _Ratio);
	void SetDecreaseHP(int _Decrease);
	void SetHPTexture();
	void SetHPStack();

};

