#pragma once
#include <core/game/game_objects/attackable_units/AttackableUnit.h>
namespace sdk
{
	static class Controller
	{
	public:
		static int Attack(AttackableUnit* target);
		static int Move(Vector3* pos);
	};
}