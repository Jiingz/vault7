#pragma once
#include <core/game/game_objects/enums.h>

namespace game
{

	class Buff
	{
	public:

		BYTE GetType()const noexcept;

		bool IsAlive()const;

		bool IsValid()const;

		float GetStartTime()const noexcept;

		float GetEndTime()const noexcept;

		DWORD GetCountAlt()const noexcept;

		const char* GetName()const;

		buff_hash GetHash() const noexcept;

	};
}