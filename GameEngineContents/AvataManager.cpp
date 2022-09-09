#include "PreCompile.h"
#include "GameEnginePlusTextureRenderer.h"
#include "GamePlayDataBase.h"
#include "GamePlayCharacter.h"
#include "AvataManager.h"
#include "GamePlayItem_DESC.h"
#include "Item_Avata.h"

std::map<GamePlayItem_DESC*, std::map<char, GameEngineTexture*>> AvataManager::Static_AllAvataItemData;
AvataManager* AvataManager::CurrentInst = nullptr;

AvataManager::AvataManager() 
	: CurrentClassData(nullptr)
	, ShakeTime(0.f)
	, ShakePower(0.f)
	, CurrentShakeTime(0.f)
	, Enum_Type(ObjectType::None)
	, Avata_Skin(nullptr)
	, Avata_Neck_f(nullptr)
	, Avata_Cap_a(nullptr)
	, Avata_Cap_b(nullptr)
	, Avata_Cap_c(nullptr)
	, Avata_Hair_a(nullptr)
	, Avata_Hair_c(nullptr)
	, Avata_Cap_d(nullptr)
	, Avata_Face_a(nullptr)
	, Avata_Face_b(nullptr)
	, Avata_Face_c(nullptr)
	, Avata_Neck_a(nullptr)
	, Avata_Neck_c(nullptr)
	, Avata_Neck_e(nullptr)
	, Avata_Neck_x(nullptr)
	, Avata_Belt_a(nullptr)
	, Avata_Belt_c(nullptr)
	, Avata_Coat_a(nullptr)
	, Avata_Coat_c(nullptr)
	, Avata_Pants_a(nullptr)
	, Avata_Shoes_a(nullptr)
	, Avata_Shoes_b(nullptr)
	, Avata_Pants_h(nullptr)
	, Avata_Pants_b(nullptr)
	, Avata_Pants_d(nullptr)
	, Avata_Coat_b(nullptr)
	, Avata_Coat_d(nullptr)
	, Avata_Belt_b(nullptr)
	, Avata_Belt_d(nullptr)
	, Avata_Neck_b(nullptr)
	, Avata_Neck_d(nullptr)
	, Avata_Hair_b(nullptr)
	, Avata_Hair_d(nullptr)
	, Avata_Neck_k(nullptr)

{
}

AvataManager::~AvataManager() 
{
}

//----------------- Start-------------------
void AvataManager::Start()
{

	AllAvatas.push_back(Avata_Neck_f = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Face_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Cap_c = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_c = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck_e = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Coat_c = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck_c = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Cap_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck_x = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Belt_c = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Face_c = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Coat_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Belt_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Pants_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Shoes_a = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Pants_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Shoes_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Pants_h = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Pants_d = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Belt_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Coat_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Belt_d = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Cap_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck_d = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Coat_d = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Hair_d = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Cap_d = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Face_b = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Skin = CreateComponent<GameEnginePlusTextureRenderer>());
	AllAvatas.push_back(Avata_Neck_k = CreateComponent<GameEnginePlusTextureRenderer>());






	{
		Map_AllAvatas[AllAvataClass::Belt].push_back(Avata_Belt_a);
		Map_AllAvatas[AllAvataClass::Belt].push_back(Avata_Belt_b);
		Map_AllAvatas[AllAvataClass::Belt].push_back(Avata_Belt_c);
		Map_AllAvatas[AllAvataClass::Belt].push_back(Avata_Belt_d);
	}
	{
		Map_AllAvatas[AllAvataClass::Hair].push_back(Avata_Hair_a);
		Map_AllAvatas[AllAvataClass::Hair].push_back(Avata_Hair_b);
		Map_AllAvatas[AllAvataClass::Hair].push_back(Avata_Hair_c);
		Map_AllAvatas[AllAvataClass::Hair].push_back(Avata_Hair_d);
	}
	{
		Map_AllAvatas[AllAvataClass::Face].push_back(Avata_Face_a);
		Map_AllAvatas[AllAvataClass::Face].push_back(Avata_Face_b);
		Map_AllAvatas[AllAvataClass::Face].push_back(Avata_Face_c);
	}
	{
		Map_AllAvatas[AllAvataClass::Cap].push_back(Avata_Cap_a);
		Map_AllAvatas[AllAvataClass::Cap].push_back(Avata_Cap_b);
		Map_AllAvatas[AllAvataClass::Cap].push_back(Avata_Cap_c);
		Map_AllAvatas[AllAvataClass::Cap].push_back(Avata_Cap_d);

	}
	{
		Map_AllAvatas[AllAvataClass::Coat].push_back(Avata_Coat_a);
		Map_AllAvatas[AllAvataClass::Coat].push_back(Avata_Coat_b);
		Map_AllAvatas[AllAvataClass::Coat].push_back(Avata_Coat_c);
		Map_AllAvatas[AllAvataClass::Coat].push_back(Avata_Coat_d);
	}
	{

		Map_AllAvatas[AllAvataClass::Pants].push_back(Avata_Pants_a);
		Map_AllAvatas[AllAvataClass::Pants].push_back(Avata_Pants_b);
		Map_AllAvatas[AllAvataClass::Pants].push_back(Avata_Pants_d);
		Map_AllAvatas[AllAvataClass::Pants].push_back(Avata_Pants_h);
	}
	{
		Map_AllAvatas[AllAvataClass::Shoes].push_back(Avata_Shoes_a);
		Map_AllAvatas[AllAvataClass::Shoes].push_back(Avata_Shoes_b);
	}
	{
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_a);
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_b);
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_c);
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_d);
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_e);
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_f);
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_k);
		Map_AllAvatas[AllAvataClass::Neck].push_back(Avata_Neck_x);
	}
	{
		Map_AllAvatas[AllAvataClass::Skin].push_back(Avata_Skin);
	}


	for (GameEnginePlusTextureRenderer* Iter : AllAvatas)
	{
		Iter->GetTransform().SetLocalScale({ 500.f, 500.f });
	}

	float ZSort = 0;
	for (size_t i = 0; i < AllAvatas.size(); i++)
	{
		AllAvatas[i]->GetTransform().SetLocalPosition({ 0, 0, ZSort });
		ZSort += 0.001f;
	}
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

void AvataManager::SetCharacterDefaultAvata(AllCharacterClass _Class, AllAvataClass _Avata)
{
	// 수정 요
	// _Class 확장용 인자

	std::vector<GameEnginePlusTextureRenderer*>& Vector = Map_AllAvatas[_Avata];
	for (auto& Renderer : Vector)
	{
		Renderer->ChangeFolderTexturePlus(nullptr);
	}

	switch (_Avata)
	{
	case AllAvataClass::Coat:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat0000a");
		break;
	case AllAvataClass::Hair:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair0000a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair0000b");
		break;
	case AllAvataClass::Pants:
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants0000d");
		break;
	case AllAvataClass::Shoes:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes0000a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes0000b");
		break;
	case AllAvataClass::Skin:
		Avata_Skin->ChangeFolderTexturePlus("ft_body0011");
		break;
	case AllAvataClass::Cap:
	case AllAvataClass::Belt:
	case AllAvataClass::Face:
	case AllAvataClass::Neck:

		break;
	case AllAvataClass::Weapon:
		break;
	case AllAvataClass::None:
	default:
		break;
	}

	//switch (_Class)
	//{
	//case AllCharacterClass::Fighter_F:
	//{
	//}
	//	break;
	//case AllCharacterClass::Gunner_M:
	//	break;
	//case AllCharacterClass::Fighter_M:
	//case AllCharacterClass::None:
	//case AllCharacterClass::Swordman_M:
	//case AllCharacterClass::Swordman_F:
	//case AllCharacterClass::Gunner_F:
	//case AllCharacterClass::Mage_M:
	//case AllCharacterClass::Mage_F:
	//case AllCharacterClass::Priest_M:
	//case AllCharacterClass::Priest_F:
	//case AllCharacterClass::Thief:
	//case AllCharacterClass::Knight:
	//case AllCharacterClass::Demoniclancer:
	//case AllCharacterClass::Gunblader:
	//case AllCharacterClass::Darknight:
	//case AllCharacterClass::Creator:
	//case AllCharacterClass::AllCharacterClass_Max:
	//default:
	//	break;
	//}
}

void AvataManager::CreateCharacterAvata()
{

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
	MsgBoxAssert("아직 NPC 기능을 만들어지지 않았습니다");
	//AllAvatas.push_back(Avata_Skin = CreateComponent<GameEnginePlusTextureRenderer>());
}
void AvataManager::CreateCustomAvata()
{
	MsgBoxAssert("아직 커스텀 기능을 만들어지지 않았습니다");
}


//----------------- Update-------------------
void AvataManager::Update(float _DeltaTime)
{
	if (ShakePower != 0.f)
	{
		CurrentShakeTime += _DeltaTime;
	}
	if (CurrentShakeTime < ShakeTime)
	{
		if (CurrentShakeTime > 0.1f)
		{
			ShakeTime -= 0.1f;
			CurrentShakeTime -= 0.1f;
			ShakePower *= -1.f;
			const float4& Pos = GetTransform().GetLocalPosition();
			GetTransform().SetLocalPosition({ ShakePower * (ShakeTime - CurrentShakeTime) + 0 * CurrentShakeTime , Pos.y , Pos.z });
		}

	}
	else if (ShakePower != 0.f)
	{
		const float4& Pos = GetTransform().GetLocalPosition();
		GetTransform().SetLocalPosition({ 0.f, Pos.y, Pos.z });
		ShakeTime = 0.f;
		ShakePower = 0.f;
		CurrentShakeTime = 0.f;
	}
}

void AvataManager::ReadCharacterDataBase(GamePlayDataBase* _Data)
{
	if (_Data == nullptr)
	{
		_Data = CurrentClassData;
	}
	std::vector<InventoryData*>& AvataWearingInventory = _Data->GetInventoryData(InventoryBag::Inventory_Avata_Wear);
	for (size_t i = 0;i < AvataWearingInventory.size(); ++i)
	{
		if (AvataWearingInventory[i] != nullptr)
		{
			ReadAvataCodeandApply(AvataWearingInventory[i]->Item_DESC->GetItemCode());
		}
		else
		{
			if (static_cast<AllAvataClass>(i) != AllAvataClass::None)
			{
				SetCharacterDefaultAvata(AllCharacterClass::Fighter_F, static_cast<AllAvataClass>(i));
			}
		}

	}

}

void AvataManager::ReadAvataCodeandApply(GamePlayItemCode _Code)
{
	AllAvataClass Class = Item_Avata::FindAvataClass(_Code);
	std::vector<GameEnginePlusTextureRenderer*>& Vector = Map_AllAvatas[Class];
	for (auto& Renderer : Vector)
	{
		Renderer->ChangeFolderTexturePlus(nullptr);
	}

	switch (_Code)
	{
		break;
	case GamePlayItemCode::Fighter_F_Belt_7st_Red:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt8600c");
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt8600d");
		break;
	case GamePlayItemCode::Fighter_F_Belt_7st_Blue:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt8601c");
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt8601d");
		break;
	case GamePlayItemCode::Fighter_F_Belt_7st_Gold:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt8602c");
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt8602d");
	case GamePlayItemCode::Fighter_F_Belt_4st_Black:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt3700c");
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt3700d");
		break;
	case GamePlayItemCode::Fighter_F_Belt_4st_White:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt3702c");
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt3702d");
		break;
	case GamePlayItemCode::Fighter_F_Belt_4st_Gold:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt3703c");
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt3703d");
		break;
	case GamePlayItemCode::Fighter_F_Belt_9st_Gold:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt11100c");
		break;
	case GamePlayItemCode::Fighter_F_Belt_9st_Purple:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt11101c");
		break;
	case GamePlayItemCode::Fighter_F_Belt_14st_White:
		Avata_Belt_c->ChangeFolderTexturePlus("ft_belt15902c");
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt15902d");
		break;
	case GamePlayItemCode::Fighter_F_Belt_Former_Striker:
		Avata_Belt_d->ChangeFolderTexturePlus("ft_belt9900d");
		break;
	case GamePlayItemCode::Fighter_F_Cap_7st_Red:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap10900a");
		Avata_Cap_d->ChangeFolderTexturePlus("ft_cap10900d");
		break;
	case GamePlayItemCode::Fighter_F_Cap_7st_Blue:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap10901a");
		Avata_Cap_d->ChangeFolderTexturePlus("ft_cap10901d");
		break;
	case GamePlayItemCode::Fighter_F_Cap_7st_Gold:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap10902a");
		Avata_Cap_d->ChangeFolderTexturePlus("ft_cap10902d");
		break;
	case GamePlayItemCode::Fighter_F_Cap_4st_Black:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap5000a");
		Avata_Cap_b->ChangeFolderTexturePlus("ft_cap5000b");
		break;
	case GamePlayItemCode::Fighter_F_Cap_4st_White:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap5002a");
		Avata_Cap_b->ChangeFolderTexturePlus("ft_cap5002b");
		break;
	case GamePlayItemCode::Fighter_F_Cap_4st_Gold:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap5003a");
		Avata_Cap_b->ChangeFolderTexturePlus("ft_cap5003b");
		break;
	case GamePlayItemCode::Fighter_F_Cap_9st_Gold:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap14400a");
		Avata_Cap_b->ChangeFolderTexturePlus("ft_cap14400b");
		break;
	case GamePlayItemCode::Fighter_F_Cap_9st_Purple:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap14401a");
		Avata_Cap_b->ChangeFolderTexturePlus("ft_cap14401b");
		break;
	case GamePlayItemCode::Fighter_F_Cap_14st_White:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap19902a");
		Avata_Cap_b->ChangeFolderTexturePlus("ft_cap19902b");
		break;
	case GamePlayItemCode::Fighter_F_Cap_Former_Striker:
		Avata_Cap_a->ChangeFolderTexturePlus("ft_cap12800a");
		break;
	case GamePlayItemCode::Fighter_F_Coat_7st_Red:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat11700a");
		Avata_Coat_c->ChangeFolderTexturePlus("ft_coat11700c");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat11700d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_7st_Blue:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat11701a");
		Avata_Coat_c->ChangeFolderTexturePlus("ft_coat11701c");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat11701d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_7st_Gold:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat11702a");
		Avata_Coat_c->ChangeFolderTexturePlus("ft_coat11702c");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat11702d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_4st_Black:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat6200a");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat6200d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_4st_White:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat6202a");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat6202d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_4st_Gold:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat6203a");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat6203d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_9st_Gold:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat15300a");
		Avata_Coat_c->ChangeFolderTexturePlus("ft_coat15300c");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat15300d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_9st_Purple:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat15301a");
		Avata_Coat_c->ChangeFolderTexturePlus("ft_coat15301c");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat15301d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_14st_White:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat20702a");
		Avata_Coat_b->ChangeFolderTexturePlus("ft_coat20702b");
		Avata_Coat_c->ChangeFolderTexturePlus("ft_coat20702c");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat20702d");
		break;
	case GamePlayItemCode::Fighter_F_Coat_Former_Striker:
		Avata_Coat_a->ChangeFolderTexturePlus("ft_coat13800a");
		Avata_Coat_d->ChangeFolderTexturePlus("ft_coat13800d");
		break;
	case GamePlayItemCode::Fighter_F_Face_7st_Red:
		Avata_Face_c->ChangeFolderTexturePlus("ft_face9400c");
		break;
	case GamePlayItemCode::Fighter_F_Face_7st_Blue:
		Avata_Face_c->ChangeFolderTexturePlus("ft_face9401c");
		break;
	case GamePlayItemCode::Fighter_F_Face_7st_Gold:
		Avata_Face_c->ChangeFolderTexturePlus("ft_face9402c");
		break;
	case GamePlayItemCode::Fighter_F_Face_4st_Black:
		Avata_Face_b->ChangeFolderTexturePlus("ft_face4600b");
		break;
	case GamePlayItemCode::Fighter_F_Face_4st_White:
		Avata_Face_b->ChangeFolderTexturePlus("ft_face4602b");
		break;
	case GamePlayItemCode::Fighter_F_Face_4st_Gold:
		Avata_Face_b->ChangeFolderTexturePlus("ft_face4603b");
		break;
	case GamePlayItemCode::Fighter_F_Face_9st_Gold:
		Avata_Face_b->ChangeFolderTexturePlus("ft_face12000b");
		break;
	case GamePlayItemCode::Fighter_F_Face_9st_Purple:
		Avata_Face_b->ChangeFolderTexturePlus("ft_face12001b");
		break;
	case GamePlayItemCode::Fighter_F_Face_14st_White:
		Avata_Face_c->ChangeFolderTexturePlus("ft_face16402c");
		break;
	case GamePlayItemCode::Fighter_F_Face_Former_Striker:
		Avata_Face_b->ChangeFolderTexturePlus("ft_face10800b");
		break;
	case GamePlayItemCode::Fighter_F_Hair_7st_Red:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair10500a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair10500b");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair10500d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_7st_Blue:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair10501a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair10501b");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair10501d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_7st_Gold:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair10502a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair10502b");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair10502d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_4st_Black:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair5300a");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair5300d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_4st_White:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair5302a");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair5302d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_4st_Gold:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair5303a");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair5303d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_9st_Gold:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair13700a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair13700b");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair13700d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_9st_Purple:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair13701a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair13701b");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair13701d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_14st_White:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair18802a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair18802b");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair18802d");
		break;
	case GamePlayItemCode::Fighter_F_Hair_Former_Striker:
		Avata_Hair_a->ChangeFolderTexturePlus("ft_hair12400a");
		Avata_Hair_b->ChangeFolderTexturePlus("ft_hair12400b");
		Avata_Hair_d->ChangeFolderTexturePlus("ft_hair12400d");
		break;
	case GamePlayItemCode::Fighter_F_Neck_7st_Red:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck9500c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck9500d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck9500x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_7st_Blue:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck9501c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck9501d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck9501x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_7st_Gold:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck9502c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck9502d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck9502x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_4st_Black:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck3800c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck3800d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck3800x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_4st_White:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck3802c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck3802d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck3802x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_4st_Gold:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck3803c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck3803d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck3803x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_9st_Gold:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck12300c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck12300d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck12300x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_9st_Purple:
		Avata_Neck_c->ChangeFolderTexturePlus("ft_neck12301c");
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck12301d");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck12301x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_14st_White:
		Avata_Neck_d->ChangeFolderTexturePlus("ft_neck17102d");
		Avata_Neck_e->ChangeFolderTexturePlus("ft_neck17102e");
		Avata_Neck_k->ChangeFolderTexturePlus("ft_neck17102k");
		Avata_Neck_x->ChangeFolderTexturePlus("ft_neck17102x");
		break;
	case GamePlayItemCode::Fighter_F_Neck_Former_Striker:
		Avata_Neck_a->ChangeFolderTexturePlus("ft_neck11200a");
		break;
	case GamePlayItemCode::Fighter_F_Pants_7st_Red:
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants11100d");
		break;
	case GamePlayItemCode::Fighter_F_Pants_7st_Blue:
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants11101d");
		break;
	case GamePlayItemCode::Fighter_F_Pants_7st_Gold:
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants11102d");
		break;
	case GamePlayItemCode::Fighter_F_Pants_4st_Black:
		Avata_Pants_a->ChangeFolderTexturePlus("ft_pants5800a");
		break;
	case GamePlayItemCode::Fighter_F_Pants_4st_White:
		Avata_Pants_a->ChangeFolderTexturePlus("ft_pants5802a");
		break;
	case GamePlayItemCode::Fighter_F_Pants_4st_Gold:
		Avata_Pants_a->ChangeFolderTexturePlus("ft_pants5803a");
		break;
	case GamePlayItemCode::Fighter_F_Pants_9st_Gold:
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants14300d");
		break;
	case GamePlayItemCode::Fighter_F_Pants_9st_Purple:
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants14301d");
		break;
	case GamePlayItemCode::Fighter_F_Pants_14st_White:
		Avata_Pants_a->ChangeFolderTexturePlus("ft_pants19202a");
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants19202d");
		break;
	case GamePlayItemCode::Fighter_F_Pants_Former_Striker:
		Avata_Pants_d->ChangeFolderTexturePlus("ft_pants13100d");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_7st_Red:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes10600a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes10600b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_7st_Blue:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes10601a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes10601b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_7st_Gold:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes10602a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes10602b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_4st_Black:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes5300a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes5300b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_4st_White:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes5302a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes5302b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_4st_Gold:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes5303a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes5303b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_9st_Gold:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes13500a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes13500b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_9st_Purple:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes13501a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes13501b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_14st_White:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes18702a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes18702b");
		break;
	case GamePlayItemCode::Fighter_F_Shoes_Former_Striker:
		Avata_Shoes_a->ChangeFolderTexturePlus("ft_shoes12100a");
		Avata_Shoes_b->ChangeFolderTexturePlus("ft_shoes12100b");
		break;
	default:
		break;
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
void AvataManager::SetAllAvataAutoControl(bool _Reset)
{
	for (GameEnginePlusTextureRenderer* Avata : AllAvatas)
	{
		Avata->SetAutoControl(_Reset);
	}
}


void AvataManager::SetShake(float _Power, float _Time)
{
	ShakePower = _Power;
	ShakeTime = _Time;
	CurrentShakeTime = 0.f;
}

//----------------- On/ Off-------------------

void AvataManager::LevelStartEvent()
{

	if (GamePlayCharacter::GetCurrentCharacterData() != nullptr)
	{
		
		ReadCharacterDataBase(GamePlayCharacter::GetCurrentCharacterData());
		if (CurrentClassData != GamePlayCharacter::GetCurrentCharacterData())
		{
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

				{
					float ZSort = 0;
					for (size_t i = 0; i < AllAvatas.size(); i++)
					{
						AllAvatas[i]->GetTransform().SetLocalPosition({ 0, 0, ZSort });
						ZSort += 0.001f;
					}
				}

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
	GetTransform().SetLocalPosition({ 0, 72.f, 0 });

	CurrentClassData = GamePlayCharacter::GetCurrentCharacterData();
	ShakeTime = 0.f;
	ShakePower = 0.f;
	CurrentShakeTime = 0.f;
	AvataManager::CurrentInst = this;
}

void AvataManager::LevelEndEvent()
{
	AvataManager::CurrentInst = nullptr;
	for (auto& Avata : AllAvatas)
	{
		Avata->ChangeFolderTexturePlus(nullptr);
	}
}