#include "PreCompile.h"
#include "SelectCharacterLevel.h"
#include "TitleBackGroundAndUI.h"
#include "MouseCursorComponent.h"

SelectCharacterLevel::SelectCharacterLevel() 
{
}

SelectCharacterLevel::~SelectCharacterLevel() 
{
}

void SelectCharacterLevel::Start()
{
	CreateActor<MouseCursorComponent>();
	CreateActor<TitleBackGroundAndUI>();

}

void SelectCharacterLevel::Update(float _DeltaTime)
{

}
