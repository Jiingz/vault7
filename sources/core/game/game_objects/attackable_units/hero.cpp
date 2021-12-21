#include <Windows.h>

#include <attackable_units/hero.h>
#include <core/memory/accessor.h>
#include <core/game/Offsets.h>
#include <core/locator.h>

bool Hero::ForceAttack()
{
	return core::Locator::GetWorld()->GetPlayer()->Attack(this);
}
