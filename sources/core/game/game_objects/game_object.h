#pragma once
#include <windef.h>
#include <stdint.h>
#include <core/memory/member.h>
#include <core/drawings/geometry/vector.h>
#include "enums.h"
#include <core/game/game_objects/structures/ai_manager.h>
#include <core/game/game_objects/structures/buff_manager.h>
#include <core/game/Offsets.h>

namespace game {

	class CharacterData
	{
	public:
		DEFINE_MEMBER_N(uint32_t hash_name, 0x0010);
	}; //Size: 0x0014


	class GameObject
	{
	public:

		union
		{
			DEFINE_MEMBER_N(int32_t index, 0x0020);
			DEFINE_MEMBER_N(game_object_team team, 0x004C);
			DEFINE_MEMBER_N(int32_t networkid, 0x00CC);
			DEFINE_MEMBER_N(Vector3 position, 0x01F4);
			DEFINE_MEMBER_N(int32_t dead, 0x0234);
			DEFINE_MEMBER_N(visible_type visible, 0x028F);
			DEFINE_MEMBER_N(float resource, 0x02B4);
			DEFINE_MEMBER_N(float max_resource, 0x02C4);
			DEFINE_MEMBER_N(int32_t status_flag, 0x03EC);
			DEFINE_MEMBER_N(bool targetable, 0x0D1C);
			DEFINE_MEMBER_N(recall_state recall_state, 0x0DA8);
			DEFINE_MEMBER_N(float health, 0x0DB4);
			DEFINE_MEMBER_N(float max_health, 0x0DC4);
			DEFINE_MEMBER_N(float shield, 0x0DF4);
			DEFINE_MEMBER_N(float physical_shield, 0x0E04);
			DEFINE_MEMBER_N(float magical_shield, 0x0E14);
			DEFINE_MEMBER_N(int32_t skin_id, 0x0EFC);
			DEFINE_MEMBER_N(float flat_magic_pen, 0x11DC);
			DEFINE_MEMBER_N(float armor_pen_mod, 0x11E0);
			DEFINE_MEMBER_N(float magic_pen_mod, 0x11E4);
			DEFINE_MEMBER_N(float flat_lethality, 0x11F8);
			DEFINE_MEMBER_N(float bonus_ad, 0x1234);
			DEFINE_MEMBER_N(float ability_power, 0x1244);
			DEFINE_MEMBER_N(float bonus_ap_mod, 0x1248);
			DEFINE_MEMBER_N(float base_ad, 0x12BC);
			DEFINE_MEMBER_N(float crit_mod, 0x12D0);
			DEFINE_MEMBER_N(float crit_rate_decimal, 0x12E0);
			DEFINE_MEMBER_N(float armor, 0x12E4);
			DEFINE_MEMBER_N(float bonus_armor, 0x12E8);
			DEFINE_MEMBER_N(float magic_resist, 0x12EC);
			DEFINE_MEMBER_N(float bonus_magic_resist, 0x12F0);
			DEFINE_MEMBER_N(float health_regen, 0x12F8);
			DEFINE_MEMBER_N(float move_speed, 0x12FC);
			DEFINE_MEMBER_N(float attack_range, 0x1304);
			DEFINE_MEMBER_N(float current_gold, 0x1B98);
			DEFINE_MEMBER_N(float total_gold, 0x1BA8);
			DEFINE_MEMBER_N(Vector3 direction, 0x1BF0);
			DEFINE_MEMBER_N(combat_type combat_type, 0x20E8);
			DEFINE_MEMBER_N(CharacterData* character_data, 0x2B58);
			DEFINE_MEMBER_N(BuffManager buff_manager, 0x21B8);
			DEFINE_MEMBER_N(int32_t active_target_index, 0x2DC8);
			DEFINE_MEMBER_N(int32_t level_up_points, 0x33BC);
		};

	public:
		float GetPercentageHealth() const;
		AIManager* GetAIManager();
	};

}
using namespace game;