#include <Windows.h>
#include <core/sdk/prediction/damage.h>

using namespace sdk::prediction;

float Damage::CalculateAutoAttackDamage(AttackableUnit* source, AttackableUnit* target) {
	auto autoAttackDamageType = DamageType_Physical;
	auto rawPhysicalDamage = 0.0f;
	auto rawMagicalDamage = 0.0f;
	auto rawTrueDamage = 0.0f;
	auto calculatedPhysicalDamage = 0.0f;
	auto calculatedMagicalDamage = 0.0f;
	auto rawTotalDamage = source->base_ad + source->bonus_ad;

	//auto targetFlags = target->Flags();
	//auto sourceFlags = source->Flags();

	//if (targetFlags && AttackableUnitFlags_AIMinionClient) {
	if (target->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIMinionClient)) {
		if (target->max_health <= 6.0f) {
			return 1.0f;
		}
	}

	//if (sourceFlags & AttackableUnitFlags_AIHeroClient) {
	if (source->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIHeroClient)) {
		auto damageOnHit = ComputeDamageOnHit(source, target);
		rawPhysicalDamage += damageOnHit.PhysicalDamage;
		rawMagicalDamage += damageOnHit.MagicalDamage;
		rawTrueDamage += damageOnHit.TrueDamage;
	}

	switch (autoAttackDamageType) {
	case DamageType_Physical:
		rawPhysicalDamage += rawTotalDamage;
		break;
	case DamageType_Magical:
		rawMagicalDamage += rawTotalDamage;
		break;
	}

	calculatedPhysicalDamage += CalculatePhysicalDamage(source, target, rawPhysicalDamage);
	calculatedMagicalDamage += CalculateMagicalDamage(source, target, rawMagicalDamage);

	auto totalDmg = calculatedPhysicalDamage + calculatedMagicalDamage + rawTrueDamage;

	return source->crit_mod == 1.f ? totalDmg * 2 : totalDmg; //Critrate, not sure if mod or flat
}

float Damage::CalculatePhysicalDamage(AttackableUnit* source, AttackableUnit* target, float amount) {
	if (amount <= 0.0f) {
		return 0.0f;
	}

	auto flatArmorPenetration = source->flat_lethality * (0.6f + 0.4f * source->level / 18.0f);
	auto percentArmorPenetration = source->armor_pen_mod;
	auto percentBonusArmorPenetration = source->armor_pen_mod;//source->PercentBonusArmorPenetration;
	auto armor = target->armor;
	auto bonusArmor = target->bonus_armor;

	if (source->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIMinionClient)) {
		percentArmorPenetration = 1.0f;
		percentBonusArmorPenetration = 1.0f;
	}
	if (source->CompareObjectTypeFlags(object_flag::GameObjectFlags_AITurretClient)) {
		percentArmorPenetration = 0.7f;
		percentBonusArmorPenetration = 1.0f;
	}
	/*auto sourceType = source->GetClassData()->Type();
	switch (sourceType) { // rito fix pls...
	case AttackableUnitType::AIMinionClient: {
		percentArmorPenetration = 1.0f;
		percentBonusArmorPenetration = 1.0f;
		break;
	}
	case AttackableUnitType::AITurretClient: {
		percentArmorPenetration = 0.7f;
		percentBonusArmorPenetration = 1.0f;
		break;
	}
	}*/

	auto bonusTrueDamage = 0.0f;

	//if (sourceType == AttackableUnitType::AIHeroClient && target->Flags() & AttackableUnitFlags_AIHeroClient) {
	if (source->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIHeroClient) && target->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIHeroClient)) {

		if (source->buff_manager.GetBuffEntryByHash(buff_hash::ConquerorEnrage)) { // "ASSETS/Perks/Styles/Precision/Conqueror/ConquerorEnrage.lua"
			bonusTrueDamage += amount * 0.2f;
			amount *= 0.8f;
		}
	}

	/*
	auto damageModifier = ComputeDamageModifier(source, target, DamageType_Physical);
	amount += damageModifier.Flat;
	if(damageModifier.Percent > 0.0f)
	amount *= damageModifier.Percent;
	*/

	if (armor < 0.0f) {
		amount *= 2.0f - 100.0f / (100.0f - armor);
	}
	else if (armor * percentArmorPenetration - bonusArmor * (1.0f - percentBonusArmorPenetration) - flatArmorPenetration >= 0.0f) {
		amount *= 100.0f / (100.0f + (armor * percentArmorPenetration) - (bonusArmor * (1.0f - percentBonusArmorPenetration)) - flatArmorPenetration);
	}

	return max(amount + bonusTrueDamage, 0.0f) - target->physical_shield;
}

float Damage::CalculateMagicalDamage(AttackableUnit* source, AttackableUnit* target, float amount) {
	if (amount <= 0.0f) {
		return 0.0f;
	}

	auto flatMagicPenetration = source->flat_magic_pen;
	auto percentMagicPenetration = source->magic_pen_mod;
	auto magicResist = target->magic_resist;

	auto bonusTrueDamage = 0.0f;


	if (target->buff_manager.GetBuffEntryByHash(buff_hash::cursedtouch)) { // "cursedtouch"
		bonusTrueDamage += amount * 0.1f;
	}

	//auto sourceType = source->Type();

	//if (source->Flags() & AttackableUnitFlags_AIHeroClient) {

	if (source->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIHeroClient)) {
		if (source->buff_manager.GetBuffEntryByHash(buff_hash::ConquerorEnrage)) { // "ASSETS/Perks/Styles/Precision/Conqueror/ConquerorEnrage.lua"
			bonusTrueDamage += amount * 0.2f;
			amount *= 0.8f;
		}
	}
	/*
	auto damageModifier = ComputeDamageModifier(source, target, DamageType_Magical);
	amount += damageModifier.Flat;
	if (damageModifier.Percent > 0.f)
		amount *= damageModifier.Percent;
*/
	if (magicResist < 0.0f) {
		amount *= 2.0f - 100.0f / (100.0f - magicResist);
	}
	else if (magicResist * percentMagicPenetration - flatMagicPenetration >= 0.0f) {
		amount *= 100.0f / (100.0f + magicResist * percentMagicPenetration - flatMagicPenetration);
	}
	return max(amount + bonusTrueDamage, 0.0f) - target->magical_shield;
}

//TODO ADD BUFFS
DamageModifierResult Damage::ComputeDamageModifier(AttackableUnit* source, AttackableUnit* target, kDamageType damageType) {
	DamageModifierResult result;
	result.Flat = -source->flat_magic_pen;
	result.Percent = 1.0f - source->magic_pen_mod;

	//auto sourceFlags = source->Flags();
	//auto targetFlags = target->Flags();

#pragma region Pushing advatange
			/* TODO add DamageReductionFromBarracksMinionMod
			//if (sourceFlags & AttackableUnitFlags_AIMinionClient && source->IsLaneMinion() && targetFlags & AttackableUnitFlags_AIMinionClient && target->IsLaneMinion()) {
			if (source->CompareObjectTypeFlags(Enums::eObjectTypeFlag::Minion) && source->IsLaneMinion() && target->CompareObjectTypeFlags(Enums::eObjectTypeFlag::Minion) && target->IsLaneMinion()) {
				result.Flat -= target->FlatDamageReductionFromBarracksMinionMod;
				result.Percent *= 1.0f + source->PercentDamageToBarracksMinionMod;
			}*/
#pragma endregion

#pragma region Target buffs
	if (target->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIHeroClient)) {
		switch (target->character_data->hash_name) {
		case hash_name::Annie: {
			if (target->buff_manager.GetBuffEntryByHash(buff_hash::MoltenShield)) { // "MoltenShield"
				result.Percent *= 1.0f;
			}
			break;
		}
		case hash_name::Braum: {
			if (target->buff_manager.GetBuffEntryByHash(buff_hash::braumeshieldbuff)) { // "braumeshieldbuff"					
				result.Percent *= 1.0f;
			}
			break;
		}
		case hash_name::Galio: {
			if (damageType == DamageType_Physical && target->buff_manager.GetBuffEntryByHash(buff_hash::GalioW)) { // "GalioW"
				result.Percent *= 1.0f;
			}
			break;
		}
		case hash_name::Kassadin: {
			if (damageType == DamageType_Magical) {
				result.Percent *= 0.85f;
			}
			break;
		}
		case hash_name::Malzahar: {
			if (target->buff_manager.GetBuffEntryByHash(buff_hash::malzaharpassiveshield)) { // "malzaharpassiveshield"
				result.Percent *= 0.1f;
			}
			break;
		}
		case hash_name::MasterYi: {
			if (target->buff_manager.GetBuffEntryByHash(buff_hash::Meditate)) { // "Meditate"
				result.Percent *= 1.0f;
			}
			break;
		}
		}
	}
#pragma endregion

#pragma region Source buffs
	//if (sourceFlags & AttackableUnitFlags_AIHeroClient) {
	if (source->CompareObjectTypeFlags(object_flag::GameObjectFlags_AIHeroClient))
	{
		auto buffs = source->buff_manager.GetBuffEntries();

		for (auto buff : buffs)
		{
			switch (buff->GetHash()) {
			case 0x6F2D5F3D: // "SummonerExhaust"
				result.Percent *= 0.6f;
				break;
			case 0xAF037A39: // "sonapassivedebuff"
				result.Percent *= 1 - (0.25f + 0.0004f * source->ability_power);
				break;
			case 0xD68F930B: // "itemsmitechallenge"
				if (source->networkid == target->networkid) {
					result.Percent *= 0.8f;
				}
				break;
			case 0xD1F5085E: // "itemphantomdancerdebuff"
				if (source->networkid == target->networkid) {
					result.Percent *= 0.88f;
				}
				break;
			case 0xD7D32CF6: // "barontarget"
				if (target->team == game_object_team::Neutral && target->character_data->hash_name == hash_name::SRU_Baron) {
					result.Percent *= 0.5f;
				}
				break;

			}
		}
	}



#pragma endregion

	return result;
}

DamageOnHitResult Damage::ComputeDamageOnHit(AttackableUnit* source, AttackableUnit* target) {
	DamageOnHitResult result;

	//auto targetFlags = target->Flags();

#pragma region Source items


#pragma endregion

#pragma region Source buffs

	auto buffs = source->buff_manager.GetBuffEntries();

	for (auto buff : buffs)
	{
		switch (buff->GetHash()) {
		case 0x6F2D5F3D: // "SummonerExhaust"
			result.TrueDamage *= 0.6f;
			break;
		case 0xAF037A39: // "sonapassivedebuff"
			result.MagicalDamage *= 1 - (0.25f + 0.0004f * source->ability_power);
			break;
		case 0xD68F930B: // "itemsmitechallenge"
			if (source->networkid == target->networkid) {
				result.TrueDamage *= 0.8f;
			}
			break;
		case 0xD1F5085E: // "itemphantomdancerdebuff"
			if (source->networkid == target->networkid) {
				result.TrueDamage *= 0.88f;
			}
			break;
		case 0xD7D32CF6: // "barontarget"
			if (target->team == game_object_team::Neutral && target->character_data->hash_name == hash_name::SRU_Baron) {
				result.TrueDamage *= 0.5f;
			}
			break;

		}
	}

#pragma endregion

	return result;

}