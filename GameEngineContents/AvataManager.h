#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayEnum.h"
#include <queue>

// Ό³Έν :
class GamePlayItem_DESC;
class GamePlayDataBase;
class Avata_Vision;
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

	inline GameEnginePlusTextureRenderer* GetAvata_Skin()
	{ 
		return Avata_Skin;
	}

	void CreateVision();


	GameEnginePlusTextureRenderer* CreateEctAvata(AllSkillEnum _Enum, const std::string& _TextureName, const float4& _Color);
	GameEnginePlusTextureRenderer* CreateEctAvata(AllSkillEnum _Enum, GameEnginePlusTextureRenderer* _Texture);
	void DestroyEctAvata(AllSkillEnum _Enum);


	void SetAvataSetup(ObjectType _Type);
	void SetCharacterDefaultAvata(AllCharacterClass _Class, AllAvataClass _Avata);

	void ReadCharacterDataBase(GamePlayDataBase* _Data);

	void ChangeAvataAnimation(const std::string& _AnimationName, bool _bool = false) const;
	void SetAllAvataManualControl();
	void SetAllAvataAutoControl(bool _Reset = true);
	void ChangeFrame_Manual(int _Frame = -1) const;

	// ------SuperArmor-----------
	void SetSuperArmor();
	void SetSuperArmorUpdate(float _DeltaTime);
	float SuperArmorColorIndex;
private:
	bool StartSuperArmor;
public:

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

	static AvataManager* BeforeAvata;
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

	std::map<AllSkillEnum, GameEnginePlusTextureRenderer*> Texture_ect;

	//std::vector<GameEngineTextureRenderer*> vector_SuperArmor;



	//std::map<std::vector<GameEngineTextureRenderer*>> vector_Vision;


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

class Avata_Vision : public GameEngineActor
{
public:
	Avata_Vision()
		: Dealy(0)
	{

	}

	void Start() override
	{
		Death(0.5f);
		//GetTransform().SetLocalPosition({ 0, 72.f, 0 });
	}

	void CreateVision(const std::vector<GameEnginePlusTextureRenderer*>& _Avata, const float4& _Color = { 1,1,1,0.9f })
	{
		//if (_Avata[0]->GetTransform().GetLocalScale().x < 0)
		//{
		//	GetTransform().PixLocalNegativeX();
		//}

		for (size_t i = 0; i < _Avata.size(); i++)
		{
			GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
			Renderer->GetTransform().SetLocalScale({ 500, 500 });
			Renderer->GetTransform().SetLocalPosition({ 0, 0, 0.1f });
			Renderer->GetPixelData().MulColor = float4::ZERO;
			Renderer->GetPixelData().PlusColor = _Color;
			Renderer->SetTexture(_Avata[i]->GetCurTexture());
			Renderer->SetPivot(PIVOTMODE::BOT);
			vector_AvataVision.push_back(Renderer);

			//Renderer->SetPipeLine("Outline");
			//Renderer->ShaderResources.SetConstantBufferLink("PixelData", Renderer->GetPixelData());

			//Renderer->ShaderResources.SetConstantBufferLink("AtlasData", Renderer->Geta);
			Time = 0.5f;
		}
	}

	void CreateVision(GameEngineTextureRenderer* _Avata, const float4& _Color, float _Time)
	{
		Time = _Time;
		GetTransform().SetLocalPosition(_Avata->GetTransform().GetWorldPosition());
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition({ 0, 0, 0.1f });
		Renderer->GetPixelData().MulColor = float4::ZERO;
		Renderer->GetPixelData().PlusColor = _Color;
		Renderer->SetTexture(_Avata->GetCurTexture());
		Renderer->ScaleToTexture();
		vector_AvataVision.push_back(Renderer);
		//Renderer->SetPipeLine("Outline");
		//Renderer->ShaderResources.SetConstantBufferLink("PixelData", Renderer->GetPixelData());

		//Renderer->ShaderResources.SetConstantBufferLink("AtlasData", Renderer->Geta);

		
	}

	void Update(float _DeltaTime) override
	{
		Dealy += _DeltaTime;
		for (auto* Renderer : vector_AvataVision)
		{
			float Lerp = 0.9f - (Dealy / Time);
			Renderer->GetPixelData().PlusColor.a =  Lerp ;
		}
		
	}
	float Time;
	float Dealy;
	std::vector<GameEngineTextureRenderer*> vector_AvataVision;
};