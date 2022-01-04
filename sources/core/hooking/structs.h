#pragma once
#include <core/game/Offsets.h>
#include <core/drawings/geometry/vector.h>

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
};