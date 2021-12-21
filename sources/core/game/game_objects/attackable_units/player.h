#pragma once
#include <core/game/game_objects/attackable_units/hero.h>

namespace game
{
	class Player : protected Hero
	{
	public:
		bool Attack(AttackableUnit* unit) const;
		bool Move(Vector3 pos) const;
	};
}