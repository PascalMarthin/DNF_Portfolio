#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "GameEngineUIFontRenderer.h"
#include <queue>

// 설명 :
enum class ComboClass
{
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
class GamePlayComboSystem : public GameEngineActor
{
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


protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;
private:

	unsigned __int64 ComboScore;

	


	std::vector<GameEngineUIRenderer*> vector_Texture_Combo_num;
	std::vector<GameEngineUIRenderer*> vector_Texture_Combo_bonus;
	std::vector<float> vector_Combo_bonus_Time;
	//std::vector<float> vector_Combo_BrightIndex;
	int FindBlank(size_t _Index);
	std::vector<GameEngineUIRenderer*> vector_Texture_Combo_Aerial;
	std::vector<GameEngineUIRenderer*> vector_Texture_Combo_Effect;
	std::queue<ComboClass> Queue_ComboClass;
	unsigned int ComboStack;
	float ComboDelay;
	float BrightIndex;
	void PlusCombo();
	void RenewalCombo();

	void SetBrighting(size_t _Pos);

	

	std::vector<GameEngineUIRenderer*> vector_Texture_Dungeon_Rank;
	std::vector<GameEngineUIRenderer*> vector_Texture_Dungeon_score;
	void RenewalScore();
	void RenewalRank(unsigned __int64 _Score);

	std::vector<GameEngineUIRenderer*> vector_Texture_Killpoint_num;

	
	std::vector<GameEngineUIRenderer*> vector_Texture_Monster_killcount;
	std::vector<GameEngineUIRenderer*> vector_Texture_Monsterkill;
	std::vector<GameEngineUIRenderer*> vector_Texture_Monsterkill_grade;

	static GameEngineFolderTexture* TextureR_Combo_num;
	static GameEngineFolderTexture* TextureR_Combo_bonus;
	static inline GameEngineTexture* GetComboClass(ComboClass _Class)
	{
		switch (_Class)
		{
		case ComboClass::Aerial:
			return TextureR_Combo_bonus->GetTexture(1);
			break;
		case ComboClass::CounterHold:
			return TextureR_Combo_bonus->GetTexture(2);
			break;
		case ComboClass::GhostFrame:
			return TextureR_Combo_bonus->GetTexture(3);
			break;
		case ComboClass::NearMiss:
			return TextureR_Combo_bonus->GetTexture(4);
			break;
		case ComboClass::Combo:
			return TextureR_Combo_bonus->GetTexture(5);
			break;
		case ComboClass::BackAttack:
			return TextureR_Combo_bonus->GetTexture(6);
			break;
		case ComboClass::Critical:
			return TextureR_Combo_bonus->GetTexture(7);
			break;
		case ComboClass::Counter:
			return TextureR_Combo_bonus->GetTexture(8);
			break;
		case ComboClass::LastKill:
			return TextureR_Combo_bonus->GetTexture(9);
			break;
		default:
			break;
		}
		MsgBoxAssert("없는 효과입니다");
		return nullptr;
	}
	static GameEngineFolderTexture* TextureR_Dungeon_Rank;
	static GameEngineFolderTexture* TextureR_Dungeon_score;
	static GameEngineFolderTexture* TextureR_Killpoint_num;
	static GameEngineFolderTexture* TextureR_Monster_killcount;
	static GameEngineFolderTexture* TextureR_Monsterkill;
	static GameEngineFolderTexture* TextureR_Monsterkill_grade;

	static GamePlayComboSystem* Inst;
	static GamePlayComboSystem* Before;
};

