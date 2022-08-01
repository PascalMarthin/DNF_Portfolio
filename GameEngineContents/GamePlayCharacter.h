#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "CharacterStatManager.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :

class PlayerInterface;
class InterfaceHUD;

class GamePlayCharacter : public GamePlayObject
{
public:
	static int CharacterIndex;
public:
	// constrcuter destructer
	GamePlayCharacter();	
	~GamePlayCharacter();

	// delete Function
	GamePlayCharacter(const GamePlayCharacter& _Other) = delete;
	GamePlayCharacter(GamePlayCharacter&& _Other) noexcept = delete;
	GamePlayCharacter& operator=(const GamePlayCharacter& _Other) = delete;
	GamePlayCharacter& operator=(GamePlayCharacter&& _Other) noexcept = delete;

	

	void ChangeAvataAnimation(const std::string& _AnimationName) const;
	void SetAllAvataManualControl();
	void SetAllAvataAutoControl();
	void ChangeFrame_Manual(int _Frame = -1) const;

	inline CharacterStatManager* GetStatManager() const
	{
		return StatManager;
	}
	inline PlayerInterface* GetInterface() const
	{
		return PlayerUserInterface;
	}


	inline CharacterClass GetPlayerClass() const
	{
		return PlayerClass;
	}

protected:
	void Start() override;



protected:
	PlayerInterface* PlayerUserInterface;

private:
	CharacterClass PlayerClass;

protected:

	// 아바타
	GameEnginePlusTextureRenderer* Avata_Belt;
	GameEnginePlusTextureRenderer* Avata_Cap;
	GameEnginePlusTextureRenderer* Avata_Coat;
	GameEnginePlusTextureRenderer* Avata_Face;
	GameEnginePlusTextureRenderer* Avata_Hair_a;
	GameEnginePlusTextureRenderer* Avata_Hair_b;
	GameEnginePlusTextureRenderer* Avata_Neck;
	GameEnginePlusTextureRenderer* Avata_Pants;
	GameEnginePlusTextureRenderer* Avata_Shoes_a;
	GameEnginePlusTextureRenderer* Avata_Shoes_b;
	GameEnginePlusTextureRenderer* Avata_Skin;
	std::vector<GameEnginePlusTextureRenderer*> AllAvatas;

	std::map<GameEnginePlusTextureRenderer*, GamePlayItemCode> CurrentAvataCode;

protected:
	CharacterStatManager* StatManager;

	virtual void Set_Default_FSMManager() {}
	void SetRightDir();
	void SetLeftDir();


private:

public:

};



//enum class AvataClass
//{
//	Belt,
//	Cap,
//	Coat,
//	Face,
//	Hair,
//	Neck,
//	Pants,
//	Shoes,
//	Skin
//};
