#include <Windows.h>

#include <core/game/game_objects/game_object.h>
#include <core/utilities.h>


float GameObject::GetPercentageHealth() const
{
	return 0.0f;
}

AIManager* game::GameObject::GetAIManager()
{
	typedef AIManager* (__thiscall* OriginalFn)(PVOID);
	return core::utilities::CallVirtual<OriginalFn>(this, 149)(this);
}
