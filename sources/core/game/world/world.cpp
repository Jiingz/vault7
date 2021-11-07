#include <core/game/world/world.h>

using namespace game;

World::World()
{
	this->HeroList = ManagerTemplateProvider::GetHeroManager();
}

ManagerTemplateAccessor<Hero> game::World::GetHeroList() const
{
	return this->HeroList;
}
