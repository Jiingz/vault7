#include <core/game/world/world.h>

using namespace game;

World::World()
{
	this->heroes_ = ManagerTemplateProvider::GetHeroManager();
	this->minions_ = ManagerTemplateProvider::GetMinionManager();
	this->player_ = memory::Accessor::AccessModuleAddress<Hero*>(Offsets::LocalPlayer);
}

ManagerTemplateAccessor<Hero> game::World::GetHeroes() const
{
	return this->heroes_;
}

ManagerTemplateAccessor<Minion> game::World::GetMinions() const
{
	return this->minions_;
}

ManagerTemplateAccessor<Turret> game::World::GetTurrets() const
{
	return this->turrets_;
}

ManagerTemplateAccessor<Inhibitor> game::World::GetInhibitors() const
{
	return this->inhibitors_;
}

ManagerTemplateAccessor<Building> game::World::GetBuildings() const
{
	return this->buildings_;
}

ManagerTemplateAccessor<GameObject> game::World::GetShops() const
{
	return this->shops_;
}

Hero* World::GetPlayer() const
{
	return this->player_;
}