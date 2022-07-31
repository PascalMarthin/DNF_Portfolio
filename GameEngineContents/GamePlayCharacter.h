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



protected:
	void Start() override;



protected:
	PlayerInterface* PlayerUserInterface;

private:


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

	std::function<void()> Input_SkillSlot_01;
	std::function<void()> Input_SkillSlot_02;
	std::function<void()> Input_SkillSlot_03;
	std::function<void()> Input_SkillSlot_04;
	std::function<void()> Input_SkillSlot_05;
	std::function<void()> Input_SkillSlot_06;
	std::function<void()> Input_SkillSlot_07;
	std::function<void()> Input_SkillSlot_08;
	std::function<void()> Input_SkillSlot_09;
	std::function<void()> Input_SkillSlot_10;
	std::function<void()> Input_SkillSlot_11;
	std::function<void()> Input_SkillSlot_12;
	std::function<void()> Input_SkillSlot_13;
	std::function<void()> Input_SkillSlot_14;

private:


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
