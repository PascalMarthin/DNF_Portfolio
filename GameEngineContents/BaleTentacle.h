#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineTransformComponent.h>
// Ό³Έν :
class TentacleTextureCollision;
class GameEngineCollision;
class GameEngineEffectRenderer;
class GameEngineFolderTexture;
class GamePlayCharacter;
class BaleTentacle : public GameEngineActor
{
public:
	// constrcuter destructer
	BaleTentacle();
	~BaleTentacle();

	// delete Function
	BaleTentacle(const BaleTentacle& _Other) = delete;
	BaleTentacle(BaleTentacle&& _Other) noexcept = delete;
	BaleTentacle& operator=(const BaleTentacle& _Other) = delete;
	BaleTentacle& operator=(BaleTentacle&& _Other) noexcept = delete;


	void CreateTentacle();
protected:
	//void Start() override;
	//void Update(float _Time) override;

private:
	std::list<TentacleTextureCollision*> Component_TentacleTextureCollision;
};

class TentacleKal;
class TentacleTextureCollision : public GameEngineTransformComponent
{
	friend BaleTentacle;
public:
	// constrcuter destructer
	TentacleTextureCollision()
	: //Rotation(0),
		Time(0)
	{}
	~TentacleTextureCollision() {}

	// delete Function
	TentacleTextureCollision(const TentacleTextureCollision& _Other) = delete;
	TentacleTextureCollision(TentacleTextureCollision&& _Other) noexcept = delete;
	TentacleTextureCollision& operator=(const TentacleTextureCollision& _Other) = delete;
	TentacleTextureCollision& operator=(TentacleTextureCollision&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Time) override;
private:
	std::list<TentacleKal*> list_ActiveCollision;
	std::list<TentacleKal*> list_WaitCollision;

	float Time;
//	float Rotation;
	float DirIndexX;
	float DirIndexY;
	float LenX;
	float Lena;
	float Lenb;

	float Delay;

};

enum class CollisionReturn;
class TentacleKal : public GameEngineTransformComponent
{
	friend TentacleTextureCollision;
public:
	// constrcuter destructer
	TentacleKal() 
	: Collision_Tentacle(nullptr)
	, Texture_Tentacle(nullptr)
	, Texture_KalEffect(nullptr)
	, Texture_Kal(nullptr)
		, Time(0)
	{}	  
	~TentacleKal() {}

	// delete Function
	TentacleKal(const TentacleKal& _Other) = delete;
	TentacleKal(TentacleKal&& _Other) noexcept = delete;
	TentacleKal& operator=(const TentacleKal& _Other) = delete;
	TentacleKal& operator=(TentacleKal&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Time) override;

	void OnEvent() override;
private:
	GameEngineCollision* Collision_Tentacle;
	GameEngineEffectRenderer* Texture_Tentacle;
	GameEngineEffectRenderer* Texture_KalEffect;
	GameEngineEffectRenderer* Texture_Kal;

	float Delay;
	CollisionReturn GetPlayer(GameEngineCollision* _This, GameEngineCollision* _Other);

	float Time;

	GameEngineSoundPlayer Sound_Hit;
	GamePlayCharacter* Player_Target;
};