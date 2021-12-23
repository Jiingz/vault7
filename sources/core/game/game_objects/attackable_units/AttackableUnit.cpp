#include <Windows.h>
#include <attackable_units/AttackableUnit.h>
#include <core/locator.h>

using namespace game;

float AttackableUnit::GetAttackDelay()
{
	return core::Locator::GetFunctionAccessor()->GetAttackDelay(this);
}

float AttackableUnit::GetAttackCastDelay()
{
	return core::Locator::GetFunctionAccessor()->GetAttackCastDelay(this);
}

float game::AttackableUnit::GetBoundingRadius()
{
	typedef float(__thiscall* OriginalFn)(PVOID);
	return game::CallVirtual<OriginalFn>(this, 35)(this);
}

float game::AttackableUnit::GetRealRange()
{
	return this->attack_range + this->GetBoundingRadius();
}

float game::AttackableUnit::GetDistanceTo(AttackableUnit* unit)
{
	return this->position.DistanceTo(unit->position);
}

bool game::AttackableUnit::IsAlive()
{
	return this->dead % 2 == 0;
}
