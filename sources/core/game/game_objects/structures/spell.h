#pragma once
#include <core/game/Offsets.h>



class SpellData
{
public:
	union
	{
		DEFINE_MEMBER_N(char* missile_name, 0x006C);
		DEFINE_MEMBER_N(char* spell_name, 0x0090);
		DEFINE_MEMBER_N(char* spell_slot_name, 0x0204);
		DEFINE_MEMBER_N(float speed, 0x0460);
		DEFINE_MEMBER_N(char mana_cost[5], 0x052C);
	};

}; //Size: 0x0554

class SpellInfo
{
public:
	union
	{
		DEFINE_MEMBER_N(SpellData* spell_data, 0x0044);
	};

}; //Size: 0x0064

class SpellBook
{
public:
	union
	{
		DEFINE_MEMBER_N(int level, 0x0020);
		DEFINE_MEMBER_N(float cooldown_max, 0x0028);
		DEFINE_MEMBER_N(SpellInfo* spell_info, 0x013C);
	};

}; //Size: 0x0194