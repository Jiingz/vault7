#include <core/game/world/world.h>

using namespace game;

World::World()
{
	this->HeroList = ManagerTemplateProvider::GetHeroManager();
}

ManagerTemplateAccessor<Hero> game::World::GetHeroList()
{
	return this->HeroList;
}
