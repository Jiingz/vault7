#pragma once 

#include <core/memory/accessor.h>
#include <core/memory/member.h>
#include <core/game/manager/manager_iterator.h>
#include <core/game/game_objects/game_object.h>

#include <attackable_units/AttackableUnit.h>

#include <attackable_units/hero.h>
#include <attackable_units/minion.h>

#include <attackable_units/Building.h>
#include <attackable_units/turret.h>
#include <attackable_units/Inhibitor.h>


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

		ManagerTemplateIterator<TType> at(int index)
		{
			return ManagerTemplateIterator<TType>(manager_, index);
		}

	private:
		ManagerTemplate* manager_;
	};

	//Provider class for ManagerTemplates
	class ManagerTemplateProvider
	{
	public:
		static ManagerTemplateAccessor<AttackableUnit> GetAttackableUnits();
		static ManagerTemplateAccessor<Hero> GetHeroManager();
		static ManagerTemplateAccessor<Minion> GetMinionManager();
		static ManagerTemplateAccessor<Turret> GetTurretManager();
		static ManagerTemplateAccessor<GameObject> GetShopManager();
		static ManagerTemplateAccessor<Inhibitor> GetInhibitorManager();
		static ManagerTemplateAccessor<Building> GetBuildingManager();
	};
};

