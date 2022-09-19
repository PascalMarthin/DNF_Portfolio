#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

// Ό³Έν :
class GamePlayDataBase;
class TitleCharacterSlot;
class SelectCharacterLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	SelectCharacterLevel();
	~SelectCharacterLevel();

	// delete Function
	SelectCharacterLevel(const SelectCharacterLevel& _Other) = delete;
	SelectCharacterLevel(SelectCharacterLevel&& _Other) noexcept = delete;
	SelectCharacterLevel& operator=(const SelectCharacterLevel& _Other) = delete;
	SelectCharacterLevel& operator=(SelectCharacterLevel&& _Other) noexcept = delete;

	std::vector<GamePlayDataBase*>& GetCharacterData()
	{
		return DataBase_SelectCharacter;
	}
	inline GameEngineCameraActor* GetAvataCamera() const
	{
		return Camera_MainAvata;
	}

	inline GameEngineCameraActor* GetOutLineCamera() const
	{
		return Camera_OutLine;
	}

	inline GameEngineCameraActor* GetUIFontCamera() const
	{
		return Camera_UIFont;
	}



protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	// void OnEvent() {}
	// void OffEvent() {}

private:
	static std::vector<TitleCharacterSlot*> CharacterSlot;

private:
	static std::vector<GamePlayDataBase*> DataBase_SelectCharacter;

	static GamePlayDataBase* CurrentCharacterSlotData;
public:
	static void PushCharacterData(GamePlayDataBase* _Data);
	static void StartPlayLevel();

	inline static void SetCurrentSelectCharacter(GamePlayDataBase* _Data)
	{
		CurrentCharacterSlotData = _Data;
	}
	inline static GamePlayDataBase* GetCurrentCharacterData()
	{
		return CurrentCharacterSlotData;
	}

private:
	GameEngineCameraActor* Camera_MainAvata;
	GameEngineCameraActor* Camera_OutLine;
	GameEngineCameraActor* Camera_UIFont;
};

