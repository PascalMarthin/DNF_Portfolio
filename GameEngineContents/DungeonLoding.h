#pragma once
#include <GameEngineCore/GameEngineLevel.h>
// Ό³Έν :
class DungeonLoding_BackGround;
enum class LocalDungeon
{
	None,
	Luke_LightOfAltar
};
class DungeonLoding : public GameEngineLevel
{
public:
	// constrcuter destructer
	DungeonLoding();
	~DungeonLoding();

	// delete Function
	DungeonLoding(const DungeonLoding& _Other) = delete;
	DungeonLoding(DungeonLoding&& _Other) noexcept = delete;
	DungeonLoding& operator=(const DungeonLoding& _Other) = delete;
	DungeonLoding& operator=(DungeonLoding&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override {}

	void OnEvent() override;
	void OffEvent() override;
private:

	DungeonLoding_BackGround* Texture_BackGround;

	// ------------Static--------------

public:
	static inline void SetLocalDungeon(LocalDungeon _Dungeon)
	{
		CurrentDungeon = _Dungeon;
	}
private:
	static LocalDungeon CurrentDungeon;

};

