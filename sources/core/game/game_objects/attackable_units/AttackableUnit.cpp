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

SpellData* game::AttackableUnit::GetBasicAttack()
{
	typedef SpellData** (__thiscall* fnGetBasicAttack)(GameObject* target, unsigned slot);
	auto ret = reinterpret_cast<fnGetBasicAttack>(DEFINE_RVA(Offsets::Functions::GetBasicAttack)
		)(this, 0x41);
	if (ret) {
		return *ret;
	}
	return nullptr;
}

bool game::AttackableUnit::IsAlive()
{
	return this->dead % 2 == 0;
}
