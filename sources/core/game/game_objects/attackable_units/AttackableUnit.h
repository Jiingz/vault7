#pragma once
#include <core/game/game_objects/game_object.h>
#include <core/game/game_objects/structures/spell.h>
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

		SpellData* GetBasicAttack();

		bool IsAlive();
	};
}