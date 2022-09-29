#include "PreCompile.h"
#include "BaleTentacle.h"
#include "GamePlayCharacter.h"
#include <d3d11.h>

BaleTentacle::BaleTentacle() 
{
}

BaleTentacle::~BaleTentacle() 
{
}

void BaleTentacle::CreateTentacle()
{

	TentacleTextureCollision* Collision = CreateComponent<TentacleTextureCollision>();


	Component_TentacleTextureCollision.push_back(Collision);
}



void TentacleTextureCollision::Start()
{
	for (size_t i = 0; i < 1; i++)
	{
		TentacleKal* kal = GetActor()->CreateComponent<TentacleKal>();
		//kal->SetParent(this);
		list_WaitCollision.push_back(kal);
	}

	Texture_Test = GetActor()->CreateComponent<GameEngineTextureRenderer>();
	Texture_Test->GetTransform().SetLocalScale({ 50, 50, 50 });
	Texture_Test->SetParent(this);
	Rotation = 0;
	GetTransform().SetLocalPosition({50, -20, 0});
	GetTransform().SetLocalRotate({ 45, 0, 0 });
}
void TentacleTextureCollision::Update(float _Time)
{
	Time += _Time;
	
	{
		//float MoveIndex = 0;

		Rotation += _Time * 20.f;
		if (Rotation > 360.f)
		{
			Rotation -= 360.f;
		}
		
		//float Result = Rotation;
		//if ((Result / 180.f) > 1.f)
		//{
		//	Result -= 180.f;
		//}
		//
		//if (Result > 90.f)
		//{
		//	Result -= 90.f
		//	MoveIndex = 0;
		//}
		//else
		//{
		//	MoveIndex = 20.f ;
		//}
	


		Texture_Test->GetTransform().SetLocalMove({ _Time * (15.f), 0 });
	}
	GetTransform().SetLocalRotation({ 45 ,Rotation, 0 });
	Texture_Test->GetTransform().SetWorldRotation({ 0,0,0});


	const float4x4& Pos = GetTransformData().WorldWorldMatrix;




	if (!list_ActiveCollision.empty())
	{
		//for (auto& Iter : list_ActiveCollision)
		//{
		//	if (!Iter->IsUpdate())
		//	{
		//		list_WaitCollision.push_back(Iter);
		//		list_ActiveCollision.erase(Iter);
		//		break;
		//	}
		//}
		std::list<TentacleKal*>::iterator StartIter = list_ActiveCollision.begin();
		std::list<TentacleKal*>::iterator EndIter = list_ActiveCollision.end();

		for (; StartIter != EndIter;)
		{
			if (!(*StartIter)->IsUpdate())
			{
				list_WaitCollision.push_back((*StartIter));
				list_ActiveCollision.erase(StartIter);
				break;
			}
			StartIter++;
		}
	}

	if (!list_WaitCollision.empty())
	{
		list_WaitCollision.front()->On();
	//	list_WaitCollision.front()->GetTransform().Set
		//list_WaitCollision.front()->GetTransform().SetWorldPosition({ (GetTransform().GetWorldPosition().x * Pos.Arr2D[0][0]) + (GetTransform().GetWorldPosition().y * Pos.Arr2D[0][1]),
			//(GetTransform().GetWorldPosition().x * Pos.Arr2D[1][0]) + (GetTransform().GetWorldPosition().y * Pos.Arr2D[1][1]),
			//GetTransform().GetWorldPosition().z });
		//GameEngineDebug::OutPutString(std::to_string(list_WaitCollision.front()->GetTransform().GetWorldPosition().x) + " " + std::to_string(list_WaitCollision.front()->GetTransform().GetWorldPosition().y) + " " + std::to_string(list_WaitCollision.front()->GetTransform().GetWorldPosition().x));
		
		//list_WaitCollision.front()->GetTransform().SetAddWorldRotation(GetTransform().GetLocalRotation());


		//list_WaitCollision.front()->GetTransform().SetLocalPosition({ Time * 100.f , 0,0});
		//list_WaitCollision.front()->GetTransform().SetAddWorldRotation({0, _Time , _Time });

		//const float4& Pos = list_WaitCollision.front()->GetTransform().GetWorldPosition();
		//const float4& Ros = list_WaitCollision.front()->GetTransform().GetWorldPosition();

		
			



			
			

	//	GameEngineDebug::OutPutString(std::to_string(GetTransform().GetWorldPosition().x * Pos.Arr2D[0][0] * Pos.Arr2D[2][0]) + " + " + std::to_string(GetTransform().GetWorldPosition().z * Pos.Arr2D[0][2] * Pos.Arr2D[2][2]));
		list_ActiveCollision.push_back(list_WaitCollision.front());
		list_WaitCollision.erase(list_WaitCollision.begin());
	}


}


void TentacleKal::Start()
{
	Texture_Tentacle = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	Texture_Tentacle->SetParent(this);
	Texture_Tentacle->CreateFrameAnimationFolder("Texture_Tentacle", FrameAnimation_DESC(("Shadowbinding_foot"), 0.125f, true));
	Texture_Tentacle->ChangeFrameAnimation("Texture_Tentacle");
	Texture_Tentacle->ScaleToTexture();
	

	Texture_KalEffect = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	Texture_KalEffect->SetParent(this);
	Texture_KalEffect->CreateFrameAnimationFolder("Texture_KalEffect", FrameAnimation_DESC(("Kal_effect"), 0.125f, true));
	Texture_KalEffect->ChangeFrameAnimation("Texture_KalEffect");
	Texture_KalEffect->AnimationBindEnd("Texture_KalEffect", [](const FrameAnimation_DESC& _DESC)
		{
			_DESC.Renderer->Off();
		});
	Texture_KalEffect->ScaleToTexture();
	Texture_KalEffect->Off();


	Texture_Kal = GetActor()->CreateComponent<GameEngineEffectRenderer>();
	Texture_Kal->SetParent(this);
	Texture_Kal->CreateFrameAnimationFolder("Texture_Kal", FrameAnimation_DESC(("Kal"), 0.125f, true));
	Texture_Kal->ChangeFrameAnimation("Texture_Kal");
	Texture_Kal->AnimationBindEnd("Texture_Kal", [](const FrameAnimation_DESC& _DESC)
		{
			_DESC.Renderer->Off();
		});
	Texture_Kal->ScaleToTexture();
	Texture_Kal->Off();

	Collision_Tentacle = GetActor()->CreateComponent<GameEngineCollision>();
	Collision_Tentacle->GetTransform().SetLocalScale({ 50, 50, 50 });
	Collision_Tentacle->GetTransform().SetLocalPosition({ 2, -78 });
	Collision_Tentacle->ChangeOrder(CollisionOrder::Monster_Att);
	Collision_Tentacle->SetDebugSetting(CollisionType::CT_SPHERE, float4::BLACK);

}
void TentacleKal::Update(float _Time)
{
	if (Texture_Tentacle->GetPixelData().MulColor.a < 1)
	{
		Collision_Tentacle->Off(); 
		if (Time == 0)
		{
			Texture_Tentacle->GetPixelData().MulColor.a += _Time * 3.f;
			if (Texture_Tentacle->GetPixelData().MulColor.a >= 1.f)
			{
				Texture_Tentacle->GetPixelData().MulColor.a = 1;
				Collision_Tentacle->On();
			}
		}
		else
		{
			Texture_Tentacle->GetPixelData().MulColor.a -= _Time * 3.f;
			if (Texture_Tentacle->GetPixelData().MulColor.a < 0)
			{
				Texture_Tentacle->GetPixelData().MulColor.a = 0;
				Off();
			}
		}
	}
	else if (Texture_Tentacle->GetPixelData().MulColor.a >= 1)
	{
		Texture_Tentacle->GetPixelData().MulColor.a = 1;
		Collision_Tentacle->On();
		Time += _Time;
	}

	if (Time > 2.f)
	{
		Texture_Tentacle->GetPixelData().MulColor.a -= _Time * 3.f;
		Collision_Tentacle->Off();
	}




	if (Collision_Tentacle->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB, 
		std::bind(&TentacleKal::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
	{
		Texture_KalEffect->ChangeFrameAnimation("Texture_KalEffect", true);
		//Texture_KalEffect->On();

		//Texture_Kal->ChangeFrameAnimation("Texture_Kal", true);
		//Texture_Kal->On();
	}
}

void TentacleKal::OnEvent()
{
	Texture_Tentacle->GetPixelData().MulColor.a = 0;
	Time = 0;
}

CollisionReturn TentacleKal::GetPlayer(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	int a = 0;
	//_Other->GetActor<GamePlayCharacter>()->BeHit();
	return CollisionReturn::Break;
}