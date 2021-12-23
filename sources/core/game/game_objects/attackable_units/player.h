#pragma once
#include <core/game/game_objects/attackable_units/hero.h>

#define local_player core::Locator::GetWorld()->GetPlayer()

namespace game
{
	class Player : public Hero
	{
	public:
		bool Attack(AttackableUnit* unit) const;
		bool Move(Vector3 pos) const;
	};
}