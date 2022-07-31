#include "PreCompile.h"
#include "SelectCharacterLevel.h"
#include "TitleBackGroundAndUI.h"

SelectCharacterLevel::SelectCharacterLevel() 
{
}

SelectCharacterLevel::~SelectCharacterLevel() 
{
}

void SelectCharacterLevel::Start()
{
	CreateActor<TitleBackGroundAndUI>();
}

void SelectCharacterLevel::Update(float _DeltaTime)
{

}
