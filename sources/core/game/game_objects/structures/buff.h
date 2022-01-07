#pragma once
#include <core/game/game_objects/enums.h>
#include <core/game/Offsets.h>

namespace game
{

	class Buff
	{
	public:

		union
		{
			DEFINE_MEMBER_N(buff_type type, Offsets::BuffManager::type);
			DEFINE_MEMBER_N(float start_time, Offsets::BuffManager::start_time);
			DEFINE_MEMBER_N(float end_time, Offsets::BuffManager::end_time);
		};

		bool IsAlive()const;

		bool IsValid()const;

		DWORD GetCountAlt()const noexcept;

		const char* GetName()const;

		buff_hash GetHash() const noexcept;

	};
}