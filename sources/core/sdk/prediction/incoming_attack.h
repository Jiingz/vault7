#pragma once
#include <core/hooking/structs.h>
#include <core/game/game_objects/attackable_units/AttackableUnit.h>
#include <vector>

namespace sdk::prediction
{
	struct IncomingAttack
	{
		ActiveSpell* atk;
		AttackableUnit* source;
		AttackableUnit* target;
		Vector3 source_position;
		float delay;
		float animation_delay;
		float missile_speed;
		float start_time;
		float end_time;
		float damage;
		bool processed;

		IncomingAttack(AttackableUnit* source, AttackableUnit* target, Vector3 sourcePosition, float delay, float animationTime, float missileSpeed, float startTime, float endTime, float damage, ActiveSpell* attack);
	};

	static std::vector<IncomingAttack> IncomingAttacks;
}

