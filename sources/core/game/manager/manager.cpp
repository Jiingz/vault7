#include <core/game/manager/manager.h>
#include <core/game/Offsets.h>

using namespace game;

ManagerTemplateAccessor<AttackableUnit> ManagerTemplateProvider::GetAttackableUnits() {
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, Offsets::ManagerTemplate::AIAttackableUnitClient>();
	return ManagerTemplateAccessor<AttackableUnit>(manager);
}

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

ManagerTemplateAccessor<GameObject> game::ManagerTemplateProvider::GetShopManager()
{
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, Offsets::ManagerTemplate::AIShopClient>();
	return ManagerTemplateAccessor<GameObject>(manager);
}

ManagerTemplateAccessor<Inhibitor> game::ManagerTemplateProvider::GetInhibitorManager()
{
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, Offsets::ManagerTemplate::AIInhibitorClient>();
	return ManagerTemplateAccessor<Inhibitor>(manager);
}

ManagerTemplateAccessor<Building> game::ManagerTemplateProvider::GetBuildingManager()
{
	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate*, Offsets::ManagerTemplate::AIBuildingClient>();
	return ManagerTemplateAccessor<Building>(manager);
}