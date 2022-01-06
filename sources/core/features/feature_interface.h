#pragma once
#include <core/sdk/target_selector.h>

#define SetOnTick(NAME,FUNC) void NAME() { FUNC();}
#define SetOnDraw(NAME,FUNC) void NAME() { FUNC();}
#define SetOnBasicAttack(NAME,FUNC) void NAME(event::OnBasicAttackArgs args) { FUNC(args);}

namespace feature
{
	class IFeature
	{
	protected:

		//called on module load
		virtual void Initialize() = 0;

		//returns the best target. If not overwritten, it returns the lowestHP target in auto attack range.
		virtual game::Hero* GetBestTarget() { return sdk::TargetSelector::GetBestTarget(); };

		virtual void SaveConfig() = 0;

		virtual void LoadConfig() = 0;
	};
}