#include "PreCompile.h"
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayDataBase.h"
#include "GamePlayCharacter.h"
#include "AvataManager.h"

std::map<GamePlayItem_DESC*, std::map<char, GameEngineTexture*>> AvataManager::Static_AllAvataItemData;

AvataManager::AvataManager() 
	: Avata_Belt(nullptr)
	, Avata_Skin(nullptr)
	, Avata_Cap(nullptr)
	, Avata_Coat(nullptr)
	, Avata_Face(nullptr)
	, Avata_Hair_a(nullptr)
	, Avata_Hair_b(nullptr)
	, Avata_Neck(nullptr)
	, Avata_Pants(nullptr)
	, Avata_Shoes_a(nullptr)
	, Avata_Shoes_b(nullptr)

	, Enum_Type(ObjectType::None)

{
}

AvataManager::~AvataManager() 
{
}

//----------------- Start-------------------
void AvataManager::Start()
{

}

void AvataManager::CreateAvataData()
{

}

void AvataManager::SetAvataSetup(ObjectType _Type)
{
	Enum_Type = _Type;
	switch (_Type)
	{
		break;
	case ObjectType::Character:
		CreateCharacterAvata();
		break;
	case ObjectType::NPC:
		CreateNPCAvata();
		break;
	case ObjectType::Custom:
		CreateCustomAvata();
		break;
	case ObjectType::None:
	default:
		break;
	}

}

void AvataManager::SetCharacterDefaultAvata(AllCharacterClass _Class)
{
	// ���� ��
	switch (_Class)
	{
	case AllCharacterClass::Fighter_F:
	{
		Avata_Coat->SetDefaultCharacterAvata("ft_coat0000a");
		Avata_Hair_b->SetDefaultCharacterAvata("ft_hair0000a");
		Avata_Hair_a->SetDefaultCharacterAvata("ft_hair0000b");
		Avata_Pants->SetDefaultCharacterAvata("ft_pants0000d");
		Avata_Shoes_a->SetDefaultCharacterAvata("ft_shoes0000a");
		Avata_Shoes_b->SetDefaultCharacterAvata("ft_shoes0000b");
		Avata_Skin->SetDefaultCharacterAvata("ft_body0011");
	}
		break;
	case AllCharacterClass::Gunner_M:
		break;
	case AllCharacterClass::Fighter_M:
	case AllCharacterClass::None:
	case AllCharacterClass::Swordman_M:
	case AllCharacterClass::Swordman_F:
	case AllCharacterClass::Gunner_F:
	case AllCharacterClass::Mage_M:
	case AllCharacterClass::Mage_F:
	case AllCharacterClass::Priest_M:
	case AllCharacterClass::Priest_F:
	case AllCharacterClass::Thief:
	case AllCharacterClass::Knight:
	case AllCharacterClass::Demoniclancer:
	case AllCharacterClass::Gunblader:
	case AllCharacterClass::Darknight:
	case AllCharacterClass::Creator:
	case AllCharacterClass::AllCharacterClass_Max:
	default:
		break;
	}
}

void AvataManager::CreateCharacterAvata()
{
	AllAvatas.push_back(Avata_Skin = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Belt = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Cap = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Coat = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Face = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Pants = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Shoes_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Shoes_b = CreateComponent<GameEnginePlusTextureRenderer>());
	for (GameEnginePlusTextureRenderer* Iter : AllAvatas)
	{
		Iter->GetTransform().SetLocalScale({500.f, 500.f});
	}
}

void AvataManager::DeleteCharacterAvata()
{
	if (AllAvatas.empty())
	{
		int a = 0;
	}
	for (GameEnginePlusTextureRenderer* Iter : AllAvatas)
	{
		Iter->Death();
	}
	AllAvatas.clear();
}
void AvataManager::CreateNPCAvata()
{
	MsgBoxAssert("���� NPC ����� ��������� �ʾҽ��ϴ�");
	//AllAvatas.push_back(Avata_Skin = CreateComponent<GameEnginePlusTextureRenderer>());
}
void AvataManager::CreateCustomAvata()
{
	MsgBoxAssert("���� Ŀ���� ����� ��������� �ʾҽ��ϴ�");
}


//----------------- Update-------------------
void AvataManager::Update(float _DeltaTime)
{

}

void AvataManager::ReadCharacterDataBase(GamePlayDataBase* _Data)
{
	std::vector<InventoryData*>& AvataInventory = _Data->GetInventoryData(InventoryBag::Inventory_Avata_Wear);
	for (InventoryData* AvataIter : AvataInventory)
	{

	}

}

void AvataManager::ChangeAvataAnimation(const std::string& _AnimationName) const
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->ChangeFrameAnimationPlus(_AnimationName);
	}
}

void AvataManager::ChangeFrame_Manual(int _Frame) const
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->SetFrame_Manual(_Frame);
	}
}

void AvataManager::SetAllAvataManualControl()
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->SetManualControl();
	}
}
void AvataManager::SetAllAvataAutoControl()
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->SetAutoControl();
	}
}

//----------------- On/ Off-------------------

void AvataManager::OnEvent()
{
	if (GamePlayCharacter::GetCurrentCharacterData() != nullptr)
	{
		SetCharacterDefaultAvata(GamePlayCharacter::GetCurrentCharacterData()->GetCharacterClass());
		switch (Enum_Type)
		{
		case ObjectType::Character:
		{
			std::map<std::string, FrameAnimation_DESC*>& DESC = GamePlayDataBase::GetClassAnimation_DESC(GamePlayDataBase::GetCurrentCharacterData()->GetCharacterClass());
			for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
			{
				for (auto& Iter : DESC)
				{
					Avata->CreateFrameAnimationFolderPlus(Iter.first, (*Iter.second));
				}
				Avata->ChangeFrameAnimationPlus("Move_Stand");
			}
			Avata_Belt->GetTransform().SetLocalPosition({ 0, 74 , 0.02f });
			Avata_Cap->GetTransform().SetLocalPosition({ 0, 74 , 0.01f });
			Avata_Coat->GetTransform().SetLocalPosition({ 0, 74 , 0.01f });
			Avata_Face->GetTransform().SetLocalPosition({ 0, 74 , 0.03f });
			Avata_Hair_a->GetTransform().SetLocalPosition({ 0, 74 , 0.02f });
			Avata_Hair_b->GetTransform().SetLocalPosition({ 0, 74 , 0.02f });
			Avata_Neck->GetTransform().SetLocalPosition({ 0, 74 , 0.01f });
			Avata_Pants->GetTransform().SetLocalPosition({ 0, 74 , 0.03f });
			Avata_Shoes_a->GetTransform().SetLocalPosition({ 0,74 , 0.01f });
			Avata_Shoes_b->GetTransform().SetLocalPosition({ 0, 74 , 0.01f });
			Avata_Skin->GetTransform().SetLocalPosition({ 0, 74 , 0.04f });
		}
		break;
		case ObjectType::NPC:
			break;
		case ObjectType::Custom:
		case ObjectType::None:
		default:
			break;
		}
	}
	 
}