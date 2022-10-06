#include "PreCompile.h"
#include "BaleTentacle.h"
#include "GamePlayCharacter.h"
#include <d3d11.h>
#include "GamePlayCharacter.h"
#include "GamePlaySkill.h"

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
	for (size_t i = 0; i < 10; i++)
	{
		TentacleKal* kal = GetActor()->CreateComponent<TentacleKal>();
		kal->Off();
		//kal->SetParent(this);
		list_WaitCollision.push_back(kal);
	}


	//Rotation = 0;
	GetTransform().SetLocalPosition({50, -20, 0});
	Lena = 100;
	Lenb = 40;
	DirIndexX = -1.f;
	DirIndexY = 1.f;
}
void TentacleTextureCollision::Update(float _Time)
{
	Time += _Time;



	//Lena += _Time * 30.f;
	//Lenb += _Time * 6.f;


	if ((abs(Lena) - abs(LenX)) / abs(Lena) < 0.05f)
	{
		Lena += _Time * 20.f;
		LenX += _Time * (50.f * (1.f - ((abs(Lena) - abs(LenX)) / abs(Lena) * 0.02f)) + 400.f * ((abs(Lena) - abs(LenX)) / abs(Lena) * 0.02f)) * DirIndexX;
	}
	else
	{
		Lena += _Time * 50.f;
		Lenb += _Time * 15.f;
		LenX += _Time * 400.f * DirIndexX;
	}



//	LenX += _Time * (100.f * (1.f - ((abs(Lena) - abs(LenX)) / abs(Lena))) + 400.f * ((abs(Lena) - abs(LenX)) / abs(Lena))) * DirIndexX;
	if (abs(Lena) <= abs(LenX))
	{
		LenX = Lena * DirIndexX;

		DirIndexX *= -1.f;
		DirIndexY *= -1.f;
	}

	float Y = 0;
	Y = sqrt((1 - ((LenX * LenX) / (Lena * Lena))) * (Lenb * Lenb)) * DirIndexY;


	if (!list_ActiveCollision.empty())
	{
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
	Delay -= _Time;
	if (Delay < 0)
	{
		if (!list_WaitCollision.empty())
		{
			list_WaitCollision.front()->On();
			//	list_WaitCollision.front()->GetTransform().Set

			float index = 0;
			if (GetTransform().GetLocalPosition().x >= 0)
			{
				index = 1.f;
			}
			else
			{
				index = -1.f;
			}
			list_WaitCollision.front()->GetTransform().SetLocalPosition({ LenX + (50.f * index), Y - (20.f), Y - (20.f) });


		//	GameEngineDebug::OutPutString(std::to_string(GetTransform().GetWorldPosition().x * Pos.Arr2D[0][0] * Pos.Arr2D[2][0]) + " + " + std::to_string(GetTransform().GetWorldPosition().z * Pos.Arr2D[0][2] * Pos.Arr2D[2][2]));
			list_ActiveCollision.push_back(list_WaitCollision.front());
			list_WaitCollision.erase(list_WaitCollision.begin());
		}
		Delay = 0.125f + (Time * 0.01f);
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
	Collision_Tentacle->SetParent(this);
	Collision_Tentacle->GetTransform().SetLocalScale({ 50, 50, 50 });
	Collision_Tentacle->GetTransform().SetLocalPosition({ 2, -78 });
	Collision_Tentacle->ChangeOrder(CollisionOrder::Monster_Att);
	Collision_Tentacle->SetDebugSetting(CollisionType::CT_SPHERE, float4::BLACK);
	Delay = 0;
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

	if (Time > 1.2f)
	{
		Texture_Tentacle->GetPixelData().MulColor.a -= _Time * 3.f;
		Collision_Tentacle->Off();
	}
	else
	{
		Collision_Tentacle->On();
		if (Delay < 0)
		{
			if (Collision_Tentacle->IsCollision(CollisionType::CT_AABB, CollisionOrder::Player, CollisionType::CT_AABB,
				std::bind(&TentacleKal::GetPlayer, this, std::placeholders::_1, std::placeholders::_2)))
			{
				switch (GameEngineRandom::MainRandom.RandomInt(0, 6))
				{
				case 0:
					Sound_Hit.Stop();
					Sound_Hit = GameEngineSound::SoundPlayControl("mon_long_sword_hit_01.ogg");
					Sound_Hit.Volume(0.8f);
					break;
				case 1:
					Sound_Hit.Stop();
					Sound_Hit = GameEngineSound::SoundPlayControl("mon_long_sword_hit_02.ogg");
					Sound_Hit.Volume(0.8f);
					break;
				case 2:
					Sound_Hit.Stop();
					Sound_Hit = GameEngineSound::SoundPlayControl("mon_long_sword_hit_03.ogg");
					Sound_Hit.Volume(0.8f);
					break;
				case 3:
					Sound_Hit.Stop();
					Sound_Hit = GameEngineSound::SoundPlayControl("mon_long_sword_hit_04.ogg");
					Sound_Hit.Volume(0.8f);
					break;
				case 4:
					Sound_Hit.Stop();
					Sound_Hit = GameEngineSound::SoundPlayControl("mon_long_sword_hit_05.ogg");
					Sound_Hit.Volume(0.8f);
					break;
				case 5:
					Sound_Hit.Stop();
					Sound_Hit = GameEngineSound::SoundPlayControl("mon_long_sword_hit_06.ogg");
					Sound_Hit.Volume(0.8f);
					break;
				case 6:
					Sound_Hit.Stop();
					Sound_Hit = GameEngineSound::SoundPlayControl("mon_long_sword_hit_07.ogg");
					Sound_Hit.Volume(0.8f);
					break;
				default:
					break;
				}

				Texture_KalEffect->ChangeFrameAnimation("Texture_KalEffect", true);
				Texture_KalEffect->On();

				Texture_Kal->ChangeFrameAnimation("Texture_Kal", true);
				Texture_Kal->On();
				Delay = 1.5f;
				Player_Target->BeHit({ 0,0,0,20.f }, HitPostureType::Standing, nullptr, nullptr, GetTransform().GetWorldPosition().x > Player_Target->GetTransform().GetWorldPosition().x ? 1 : -1
					, Player_Target->GetStatManager()->GetAbilityStat()->GetMAXHP() / 100);

			}
		}
	}
	Delay -= _Time;

}

void TentacleKal::OnEvent()
{
	Texture_Tentacle->GetPixelData().MulColor.a = 0;
	Time = 0;
}

CollisionReturn TentacleKal::GetPlayer(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	int a = 0;

	Player_Target = _Other->GetActor<GamePlayCharacter>();
	//_Other->GetActor<GamePlayCharacter>()->BeHit();
	return CollisionReturn::Break;
}