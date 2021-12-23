#pragma once
#include <core/game/game_objects/game_object.h>
namespace game
{
	class AttackableUnit : public GameObject
	{
	public:
		float GetAttackDelay();
		float GetAttackCastDelay();
		float GetBoundingRadius();
		float GetRealRange();
		float GetDistanceTo(AttackableUnit* unit);

		bool IsAlive();
	};
}