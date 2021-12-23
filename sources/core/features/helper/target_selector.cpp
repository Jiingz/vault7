#include <Windows.h>
#include <core/features/helper/target_selector.h>
#include <core/game/manager/manager.h>
#include <core/locator.h>

using namespace helper;

Hero* TargetSelector::GetBestTarget()
{
	Hero* best_target = nullptr;

	for (auto& unit : game::ManagerTemplateProvider::GetHeroManager())
	{
		if (unit.team == local_player->team)
			continue;

		if (!unit.targetable || !unit.IsAlive())
			continue;

		if (unit.GetDistanceTo(local_player) > local_player->GetRealRange())
			continue;



		if (!best_target || unit.health < local_player->health)
			best_target = &unit;
	}

	return best_target;
}