#pragma once 

#include <core/memory/accessor.h>
#include <core/memory/member.h>
#include <core/game/manager/manager_iterator.h>
#include <core/game/game_objects/game_object.h>
#include <core/game/game_objects/hero/hero.h>
#include <core/game/game_objects/minion/minion.h>
#include <core/game/game_objects/turret/turret.h>

namespace game
{
	template <typename TType>
	class ManagerTemplateAccessor
	{
	public:
		ManagerTemplateAccessor()
			: manager_(nullptr) { }

		ManagerTemplateAccessor(ManagerTemplate* manager)
			: manager_(manager) { }


		ManagerTemplateIterator<TType> Begin() {
			return this->begin();
		}


		ManagerTemplateIterator<TType> End() {
			return this->end();
		}


		ManagerTemplateIterator<TType> begin() {
			return ManagerTemplateIterator<TType>(manager_, 0);
		}


		ManagerTemplateIterator<TType> end() {
			return ManagerTemplateIterator<TType>(manager_, manager_->size.value);
		}

	private:
		ManagerTemplate* manager_;
	};

	//Provider class for ManagerTemplates
	class ManagerTemplateProvider
	{
	public:
		static ManagerTemplateAccessor<Hero> GetHeroManager();
		static ManagerTemplateAccessor<Minion> GetMinionManager();
		static ManagerTemplateAccessor<Turret> GetTurretManager();
	};
};

