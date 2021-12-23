#pragma once
#include <core/features/helper/target_selector.h>

namespace feature
{
	class IFeature
	{
	protected:

		//called on module load
		virtual void Initialize() = 0;

		//called every frame in present hook
		virtual void OnTick() = 0;

		//returns the best target. If not overwritten, it returns the lowestHP target in auto attack range.
		virtual game::Hero* GetBestTarget() { return helper::TargetSelector::GetBestTarget(); };
	};
}