#pragma once
#include <core/game/game_objects/attackable_units/AttackableUnit.h>

namespace sdk::prediction
{
	enum kDamageType
	{
		DamageType_Physical,
		DamageType_Magical,
		DamageType_True,
		DamageType_Adaptive
	};

	struct DamageModifierResult {
		float Flat = 0.0f;
		float Percent = 0.0f;
	};

	struct DamageOnHitResult {
		float PhysicalDamage = 0.0f;
		float MagicalDamage = 0.0f;
		float TrueDamage = 0.0f;
	};

	class Damage
	{
		float CalculateAutoAttackDamage(AttackableUnit* source, AttackableUnit* target);
		float CalculatePhysicalDamage(AttackableUnit* source, AttackableUnit* target, float amount);
		float CalculateMagicalDamage(AttackableUnit* source, AttackableUnit* target, float amount);
		DamageModifierResult ComputeDamageModifier(AttackableUnit* source, AttackableUnit* target, kDamageType damageType);
		DamageOnHitResult ComputeDamageOnHit(AttackableUnit* source, AttackableUnit* target);
	};
}