#pragma once
#include <core/game/game_objects/attackable_units/hero.h>

namespace helper
{
	static class TargetSelector
	{
	public:
		static Hero* GetBestTarget();
	};
}