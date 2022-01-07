#pragma once
#include <core/game/game_objects/structures/buff.h>
#include <core/game/Offsets.h>
#include <vector>

namespace game
{
	class BuffManager {

	public:

		union
		{
			DEFINE_MEMBER_N(DWORD start, 0x10);
			DEFINE_MEMBER_N(DWORD end, 0x14);
		};

		Buff* GetBuffEntryByName(const char* BuffName) const;

		Buff* GetBuffEntryByHash(buff_hash hash);
		std::vector<Buff*> GetBuffEntries();
	};
}
