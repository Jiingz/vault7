#pragma once
#include <attackable_units/AttackableUnit.h>

namespace game
{
	class Hero : public game::AttackableUnit
	{
	public:
		bool ForceAttack();
	};


}
