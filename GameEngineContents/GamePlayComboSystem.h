#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "GameEngineUIFontRenderer.h"
#include <queue>

// Ό³Έν :
enum class ComboClass
{
	None,
	Aerial,
	CounterHold,
	GhostFrame,
	NearMiss,
	Combo,
	BackAttack,
	Critical,
	Counter,
	LastKill,
	//ArmorBreak,
};
class ComboSystemBlank;
class ComboSystemScore;
class GamePlayComboSystem : public GameEngineActor
{
	friend ComboSystemBlank;
	friend ComboSystemScore;
public:
	GamePlayComboSystem();
	~GamePlayComboSystem();

	GamePlayComboSystem(const GamePlayComboSystem& _Other) = delete;
	GamePlayComboSystem(GamePlayComboSystem&& _Other) noexcept = delete;
	GamePlayComboSystem& operator=(const GamePlayComboSystem& _Other) = delete;
	GamePlayComboSystem& operator=(GamePlayComboSystem&& _Other) noexcept = delete;
	static inline GamePlayComboSystem* GetInst()
	{
		return Inst;
	}

	void PlusScore(unsigned __int64 _Score);



	void SetComboClass(ComboClass _Class);
	void ComboTimeEnd();
	void ComboShowEnd();


protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:

	unsigned __int64 ComboScore;
	
	ComboSystemScore* Actor_ComboSystemScore;


	std::vector<ComboSystemBlank*> vector_ComboBlank;
	void ChangeBlank(ComboSystemBlank* _Before, ComboSystemBlank* _After);


	std::queue<ComboClass> Queue_ComboClass;
	unsigned int ComboStack;
	//float BrightIndex;
	void PlusCombo();
	



	bool PushBack;


	std::vector<GameEngineUIRenderer*> vector_Texture_Killpoint_num;

	
	std::vector<GameEngineUIRenderer*> vector_Texture_Monster_killcount;
	std::vector<GameEngineUIRenderer*> vector_Texture_Monsterkill;
	std::vector<GameEngineUIRenderer*> vector_Texture_Monsterkill_grade;

	static GameEngineFolderTexture* TextureR_Combo_num;
	static GameEngineFolderTexture* TextureR_Combo_bonus;
	static GameEngineFolderTexture* TextureR_Dungeon_Rank;
	static GameEngineFolderTexture* TextureR_Dungeon_score;
	static GameEngineFolderTexture* TextureR_Killpoint_num;
	static GameEngineFolderTexture* TextureR_Monster_killcount;
	static GameEngineFolderTexture* TextureR_Monsterkill;
	static GameEngineFolderTexture* TextureR_Monsterkill_grade;

	static GamePlayComboSystem* Inst;
	static GamePlayComboSystem* Before;
};

