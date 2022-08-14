#pragma once

// Ό³Έν :
class SkillManager
{
public:
	// constrcuter destructer
	SkillManager();
	~SkillManager();

	// delete Function
	SkillManager(const SkillManager& _Other) = delete;
	SkillManager(SkillManager&& _Other) noexcept = delete;
	SkillManager& operator=(const SkillManager& _Other) = delete;
	SkillManager& operator=(SkillManager&& _Other) noexcept = delete;

protected:

private:

};

