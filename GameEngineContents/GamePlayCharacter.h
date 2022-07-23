#pragma once
#include "GameEnginePlusTextureRenderer.h"
#include "CharacterStatManager.h"
#include "GamePlayObject.h"
#include "GamePlayEnum.h"

// 설명 :

class PlayerInterface;
class InterfaceHUD;
class GamePlayKeyManager;

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

	

	void ChangeAvataAnimation(const std::string& _AnimationName);

	inline CharacterStatManager* GetStatManager() const
	{
		return StatManager;
	}
	inline PlayerInterface* GetInterface() const
	{
		return PlayerUserInterface;
	}

	inline CharacterStatManager** GetStatManagerDoublePtr()
	{
		return &StatManager;
	}
	inline PlayerInterface** GetInterfaceDoublePtr()
	{
		return &PlayerUserInterface;
	}



protected:
	void Start() override;



protected:
	
private:
	PlayerInterface* PlayerUserInterface;
	// ItemBag 관련


private:
	GamePlayKeyManager* KeyInTown;
	GamePlayKeyManager* KeyInDungeon;

protected:
	//virtual void SettingCharacterAnimation(GameEngineTextureRenderer* _TextureRenderer, const std::string& _AvataClass, unsigned int _AvataCode = -1) = 0;

	// 아바타
	GameEnginePlusTextureRenderer* Avata_Belt;
	GameEnginePlusTextureRenderer* Avata_Cap;
	GameEnginePlusTextureRenderer* Avata_Coat;
	GameEnginePlusTextureRenderer* Avata_Face;
	GameEnginePlusTextureRenderer* Avata_Hair_a;
	GameEnginePlusTextureRenderer* Avata_Hair_b;
	GameEnginePlusTextureRenderer* Avata_Neck;
	GameEnginePlusTextureRenderer* Avata_Pants;
	GameEnginePlusTextureRenderer* Avata_Shoes;
	GameEnginePlusTextureRenderer* Avata_Skin;
	std::vector<GameEnginePlusTextureRenderer*> AllAvatas;

	std::map<GameEnginePlusTextureRenderer*, GamePlayItemCode> CurrentAvataCode;


public:

private:
	CharacterStatManager* StatManager;
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
