#pragma once
#include <windef.h>
#include <stdint.h>
#include <core/memory/member.h>

struct Vector3
{
	float x;
	float y;
	float z;
};
namespace game::gameObjects {

	class GameObject
	{
	public:
		memory::AlignedMember<uint16_t, 32> index; //0x0024
		memory::AlignedMember<uint32_t, 42> team; //0x0050
		memory::AlignedMember<class m_name*, 28> p_name; //0x0070
		memory::AlignedMember<uint32_t, 92> network_i_d; //0x00D0
		memory::AlignedMember<Vector3, 292> position; //0x01F8
		memory::AlignedMember<uint32_t, 52> dead; //0x0238
		memory::AlignedMember<bool, 84> visible; //0x0290
		memory::AlignedMember<uint16_t, 31> source_i_d; //0x02B0
		memory::AlignedMember<float, 6> resource; //0x02B8
		memory::AlignedMember<float, 12> max_resource; //0x02C8
		memory::AlignedMember<uint8_t, 76> resource_type; //0x0318
		memory::AlignedMember<float, 15> ammo; //0x0328
		memory::AlignedMember<float, 12> max_ammo; //0x0338
		memory::AlignedMember<uint32_t, 180> status_flags; //0x03F0
		memory::AlignedMember<bool, 2348> targetable; //0x0D20
		memory::AlignedMember<int32_t, 139> recall_state; //0x0DAC
		memory::AlignedMember<float, 8> health; //0x0DB8
		memory::AlignedMember<float, 12> max_health; //0x0DC8
		memory::AlignedMember<float, 44> shield; //0x0DF8
		memory::AlignedMember<float, 12> physical_shield; //0x0E08
		memory::AlignedMember<float, 12> magical_shield; //0x0E18
		memory::AlignedMember<uint32_t, 228> skin_i_d; //0x0F00
		memory::AlignedMember<float, 524> ability_haste; //0x1110
		memory::AlignedMember<float, 64> resource_regen; //0x1154
		memory::AlignedMember<float, 136> flat_magic_pen; //0x11E0
		memory::AlignedMember<float, 0> armor_pen_mod; //0x11E4
		memory::AlignedMember<float, 0> magic_pen_mod; //0x11E8
		memory::AlignedMember<float, 16> lethality; //0x11FC
		memory::AlignedMember<float, 56> bonus_atk; //0x1238
		memory::AlignedMember<float, 12> ability_power; //0x1248
		memory::AlignedMember<float, 0> bonus_a_p_multiplier; //0x124C
		memory::AlignedMember<float, 64> attack_speed_mod; //0x1290
		memory::AlignedMember<float, 36> total_a_s; //0x12B8
		memory::AlignedMember<float, 0> base_atk; //0x12BC
		memory::AlignedMember<float, 16> crit_mod; //0x12D0
		memory::AlignedMember<float, 12> crit_rate; //0x12E0
		memory::AlignedMember<float, 0> armor; //0x12E4
		memory::AlignedMember<float, 0> bonus_armor; //0x12E8
		memory::AlignedMember<float, 0> magic_resist; //0x12EC
		memory::AlignedMember<float, 0> bonus_magic_resist; //0x12F0
		memory::AlignedMember<float, 4> health_regen; //0x12F8
		memory::AlignedMember<float, 0> move_speed; //0x12FC
		memory::AlignedMember<float, 4> attack_range; //0x1304
		memory::AlignedMember<float, 2192> current_gold; //0x1B98
		memory::AlignedMember<float, 12> total_gold; //0x1BA8
		memory::AlignedMember<Vector3, 68> direction; //0x1BF0
		memory::AlignedMember<uint32_t, 1264> combat_type; //0x20EC
		memory::AlignedMember<class BuffManager*, 204> p_buff_manager; //0x21BC
		memory::AlignedMember<class BuffArray*, 12> p_buff_array; //0x21CC
		memory::AlignedMember<uint32_t, 1528> channeling; //0x27C8
		memory::AlignedMember<uint32_t, 44> spell_book; //0x27F8
		memory::AlignedMember<class CharacterData*, 860> p_character_data; //0x2B58
		memory::AlignedMember<char*, 136> champ_name; //0x2BE4
		memory::AlignedMember<uint32_t, 488> active_target_index; //0x2DD0
		memory::AlignedMember<uint32_t, 1292> moving; //0x32E0
		memory::AlignedMember<float, 168> experience; //0x338C
		memory::AlignedMember<uint32_t, 12> level; //0x339C
		memory::AlignedMember<uint32_t, 36> level_up_points; //0x33C4

	public:
		float GetPercentageHealth() const;
	};

}

using namespace game::gameObjects;
