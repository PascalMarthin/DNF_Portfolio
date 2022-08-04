#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "CharacterStatManager.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :

class PlayerInterface;
class AvataManager;
class InterfaceHUD;
class GamePlayDataBase;
class GamePlayCharacter : public GamePlayObject
{

public:
	// constrcuter destructer
	GamePlayCharacter();	
	~GamePlayCharacter();

	// delete Function
	GamePlayCharacter(const GamePlayCharacter& _Other) = delete;
	GamePlayCharacter(GamePlayCharacter&& _Other) noexcept = delete;
	GamePlayCharacter& operator=(const GamePlayCharacter& _Other) = delete;
	GamePlayCharacter& operator=(GamePlayCharacter&& _Other) noexcept = delete;

	

	inline CharacterStatManager* GetStatManager() const
	{
		return Manager_StatManager;
	}
	inline PlayerInterface* GetInterface() const
	{
		return PlayerUserInterface;
	}
	inline AllCharacterClass GetPlayerClass() const
	{
		return PlayerClass;
	}

protected:
	void Start() override;



protected:
	PlayerInterface* PlayerUserInterface;

private:
	AllCharacterClass PlayerClass;

protected:

	// 아바타


protected:
	CharacterStatManager* Manager_StatManager;
	AvataManager* Manager_AvataManager;

	virtual void Set_Default_FSMManager() {}
	void SetRightDir();
	void SetLeftDir();

private:
	static std::list<GamePlayDataBase*> AllCharacterData;

public:
	static GamePlayDataBase* CreateCharacterBase(CharacterFormerClass _Class, const std::string& _NickName = "Debug");

};

