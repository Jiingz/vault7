#include <core/game/manager/manager.h>
#include <core/game/Offsets.h>

using namespace game;

ManagerTemplateAccessor<Hero> ManagerTemplateProvider::GetHeroManager() {
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, Offsets::ManagerTemplate::AIHeroClient>();
	return ManagerTemplateAccessor<Hero>(manager);
}

ManagerTemplateAccessor<Minion> ManagerTemplateProvider::GetMinionManager() {
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, Offsets::ManagerTemplate::AIMinionClient>();
	return ManagerTemplateAccessor<Minion>(manager);
}

ManagerTemplateAccessor<Turret> ManagerTemplateProvider::GetTurretManager() {
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, Offsets::ManagerTemplate::AITurretClient>();
	return ManagerTemplateAccessor<Turret>(manager);
}
