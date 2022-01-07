#pragma once
#include <core/game/Offsets.h>
#include <core/drawings/geometry/vector.h>
#include <core/game/game_objects/structures/spell.h>
#include <vector>

class ActiveSpell
{
public:
	union
	{
		DEFINE_MEMBER_N(short slot, 0x4);
		DEFINE_MEMBER_N(float end_time, 0x8);
		DEFINE_MEMBER_N(const char* sender_name, 0x18);
		DEFINE_MEMBER_N(DWORD sender_network_id, 0x6C);
		DEFINE_MEMBER_N(DWORD sender_index, 0x64);
		DEFINE_MEMBER_N(Vector3 start_pos, 0x7C);
		DEFINE_MEMBER_N(Vector3 end_pos, 0x88);
		DEFINE_MEMBER_N(Vector3 cast_pos, 0x94);
		DEFINE_MEMBER_N(Vector3 direction, 0xAC);
		DEFINE_MEMBER_N(DWORD target_array_ptr, 0xB8);
		DEFINE_MEMBER_N(DWORD target_array_size, Offsets::TargetArraySize);
		DEFINE_MEMBER_N(float cast_delay, Offsets::CastDelay);
		DEFINE_MEMBER_N(float animation_delay, Offsets::AnimationDelay);
		DEFINE_MEMBER_N(float cooldown, Offsets::Cooldown);
		DEFINE_MEMBER_N(bool is_spell, Offsets::IsSpell);
		DEFINE_MEMBER_N(bool is_basic_attack, Offsets::IsBasicAttack);
		DEFINE_MEMBER_N(bool is_special_attack, Offsets::IsSpecialAttack);
		DEFINE_MEMBER_N(bool is_headshot_attack, Offsets::IsHeadshotAttack);
		DEFINE_MEMBER_N(float mana_costs, Offsets::ManaCost);
	};

	SpellInfo* GetSpellInfo()
	{
		return *reinterpret_cast<SpellInfo**>(reinterpret_cast<ULONG>(this));
	}

	std::vector<short> GetTargetsIndexVector()
	{
		std::vector<short>targetsVector;
		for (int i = 0; i < this->target_array_size; i++)
			targetsVector.push_back(*reinterpret_cast<short*>(this->target_array_ptr + 0x10 * i));

		return targetsVector;
	}

	float GetStartTime()
	{
		return end_time - cast_delay;
	}
};