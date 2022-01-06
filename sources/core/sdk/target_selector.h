#pragma once
#include <core/game/game_objects/attackable_units/hero.h>

namespace sdk
{
	static class TargetSelector
	{
	public:
		static Hero* GetBestTarget();
	};
}