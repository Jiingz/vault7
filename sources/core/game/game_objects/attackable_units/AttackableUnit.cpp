#include <Windows.h>
#include <attackable_units/AttackableUnit.h>
#include <core/locator.h>

using namespace game::gameObjects;

float AttackableUnit::GetAttackDelay()
{
	return core::Locator::GetFunctionAccessor()->GetAttackDelay(this);
}
