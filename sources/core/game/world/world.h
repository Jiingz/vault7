#pragma once
#include <memory>

#include <core/game/manager/manager.h>


namespace game
{
	class World
	{
	public:
		World();

		ManagerTemplateAccessor<Hero> GetHeroList() const;

	private:
		ManagerTemplateAccessor<Hero>  HeroList;
	};
}
