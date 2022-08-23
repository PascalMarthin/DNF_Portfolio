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

	inline std::vector<GameEnginePlusTextureRenderer*>& GetAllAvatas()
	{
		return AllAvatas;
	}

	//inline GameEnginePlusTextureRenderer* GetAvata_Belt()
	//{ 
	//	return Avata_Belt;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Cap()
	//{
	//	return Avata_Cap;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Coat()
	//{ 
	//	return Avata_Coat;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Face()
	//{ 
	//	return Avata_Face;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Hair_a()
	//{
	//	return Avata_Hair_a;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Hair_b()
	//{ 
	//	return Avata_Hair_b;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Neck()
	//{ 
	//	return Avata_Neck;
	//}
	//inline GameEnginePlusTextureRenderer* GetAvata_Pants()
	//{
	//	return Avata_Pants;
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
	void SetCharacterDefaultAvata(AllCharacterClass _Class);

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
	// void OffEvent() {}
private:
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

	ObjectType Enum_Type;


private:
	void CreateCharacterAvata();
	void CreateNPCAvata();
	void CreateCustomAvata();

	void DeleteCharacterAvata();

	GamePlayDataBase* CurrentClassData;

	static std::map<GamePlayItem_DESC*, std::map<char, GameEngineTexture*>> Static_AllAvataItemData;
public:
	static void CreateAvataData();
};

