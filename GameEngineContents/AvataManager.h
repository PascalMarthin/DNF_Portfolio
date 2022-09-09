#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class GamePlayItem_DESC;
class GameEnginePlusTextureRenderer;
class GamePlayDataBase;
class AvataManager : public GameEngineActor
{
	friend class GamePlayCharacter;
public:
	// constrcuter destructer
	AvataManager();
	~AvataManager();

	// delete Function
	AvataManager(const AvataManager& _Other) = delete;
	AvataManager(AvataManager&& _Other) noexcept = delete;
	AvataManager& operator=(const AvataManager& _Other) = delete;
	AvataManager& operator=(AvataManager&& _Other) noexcept = delete;

	static inline AvataManager* GetInst()
	{
		return CurrentInst;
	}

	inline std::vector<GameEnginePlusTextureRenderer*>& GetAllAvatas()
	{
		return AllAvatas;
	}

	//inline GameEnginePlusTextureRenderer* GetAvata_Belt()
	//{ 
	//	return Avata_Belt_a;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Cap()
	//{
	//	return Avata_Cap_a;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Coat()
	//{ 
	//	return Avata_Coat_a;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Face()
	//{ 
	//	return Avata_Face_a;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Hair_a()
	//{
	//	return Avata_Hair_b;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Hair_b()
	//{ 
	//	return Avata_Hair_c;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Neck()
	//{ 
	//	return Avata_Neck_a;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Pants()
	//{
	//	return Avata_Pants_d;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Shoes_a()
	//{
	//	return Avata_Shoes_a;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Shoes_b()
	//{ 
	//	return Avata_Shoes_b;
	//}
	inline GameEnginePlusTextureRenderer* GetAvata_Skin()
	{ 
		return Avata_Skin;
	}


	void SetAvataSetup(ObjectType _Type);
	void SetCharacterDefaultAvata(AllCharacterClass _Class, AllAvataClass _Avata);

	void ReadCharacterDataBase(GamePlayDataBase* _Data);

	void ChangeAvataAnimation(const std::string& _AnimationName) const;
	void SetAllAvataManualControl();
	void SetAllAvataAutoControl(bool _Reset = true);
	void ChangeFrame_Manual(int _Frame = -1) const;

	// ------Shake--------------
	void SetShake(float _Power ,float _Time);

private:
	float ShakeTime;
	float CurrentShakeTime;
	float ShakePower;
	// -------------------


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	// void End() override {}
	void LevelStartEvent() override;
	void LevelEndEvent() override;
	// void OffEvent() {}
private:
	GameEnginePlusTextureRenderer* Avata_Neck_f;
	GameEnginePlusTextureRenderer* Avata_Cap_a;
	GameEnginePlusTextureRenderer* Avata_Cap_b;
	GameEnginePlusTextureRenderer* Avata_Cap_c;
	GameEnginePlusTextureRenderer* Avata_Hair_a;
	GameEnginePlusTextureRenderer* Avata_Hair_c;
	GameEnginePlusTextureRenderer* Avata_Cap_d;
	GameEnginePlusTextureRenderer* Avata_Face_a;
	GameEnginePlusTextureRenderer* Avata_Face_b;
	GameEnginePlusTextureRenderer* Avata_Face_c;
	GameEnginePlusTextureRenderer* Avata_Neck_a;
	GameEnginePlusTextureRenderer* Avata_Neck_c;
	GameEnginePlusTextureRenderer* Avata_Neck_e;
	GameEnginePlusTextureRenderer* Avata_Neck_x;
	GameEnginePlusTextureRenderer* Avata_Belt_a;
	GameEnginePlusTextureRenderer* Avata_Belt_c;
	GameEnginePlusTextureRenderer* Avata_Coat_a;
	GameEnginePlusTextureRenderer* Avata_Coat_c;
	GameEnginePlusTextureRenderer* Avata_Pants_a;
	GameEnginePlusTextureRenderer* Avata_Shoes_a;
	GameEnginePlusTextureRenderer* Avata_Shoes_b;
	GameEnginePlusTextureRenderer* Avata_Pants_h;
	GameEnginePlusTextureRenderer* Avata_Pants_b;
	GameEnginePlusTextureRenderer* Avata_Pants_d;
	GameEnginePlusTextureRenderer* Avata_Coat_b;
	GameEnginePlusTextureRenderer* Avata_Coat_d;
	GameEnginePlusTextureRenderer* Avata_Belt_b;
	GameEnginePlusTextureRenderer* Avata_Belt_d;
	GameEnginePlusTextureRenderer* Avata_Neck_b;
	GameEnginePlusTextureRenderer* Avata_Neck_d;
	GameEnginePlusTextureRenderer* Avata_Hair_b;
	GameEnginePlusTextureRenderer* Avata_Hair_d;
	GameEnginePlusTextureRenderer* Avata_Skin;
	GameEnginePlusTextureRenderer* Avata_Neck_k;
	std::vector<GameEnginePlusTextureRenderer*> AllAvatas;

	std::map<AllAvataClass, std::vector<GameEnginePlusTextureRenderer*>> Map_AllAvatas;



	ObjectType Enum_Type;


private:
	void CreateCharacterAvata();
	void CreateNPCAvata();
	void CreateCustomAvata();

	void DeleteCharacterAvata();

	GamePlayDataBase* CurrentClassData;

	static std::map<GamePlayItem_DESC*, std::map<char, GameEngineTexture*>> Static_AllAvataItemData;
	static AvataManager* CurrentInst;
	void ReadAvataCodeandApply(GamePlayItemCode _Code);
public:
	static void CreateAvataData();
};

