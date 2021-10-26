#pragma once 
#include <core/exports.h>
#include <core/memory/accessor.h>
#include <core/memory/member.h>
#include <core/game/manager/manager_iterator.h>
#include <core/game/game_objects/game_object.h>

namespace game
{

	class VAULT7_CORE_DLL ManagerTemplateAccessor
	{
	public:
		ManagerTemplateAccessor(ManagerTemplate* manager);

		ManagerTemplateIterator<GameObject> Begin();

		ManagerTemplateIterator<GameObject> End();



		ManagerTemplateIterator<GameObject> begin();

		ManagerTemplateIterator<GameObject> end();

	private:
		ManagerTemplate* manager_;
	};

	//Provider class for ManagerTemplates
	class ManagerTemplateProvider
	{
	public:
		static ManagerTemplateAccessor VAULT7_CORE_DLL GetAIHeroManager();

		//FORCEINLINE static ManagerTemplateAccessor GetAIMinionManager();

		//FORCEINLINE static ManagerTemplateAccessor GetAITurretClient();
	};



	//FORCEINLINE  ManagerTemplateAccessor ManagerTemplateProvider::GetAIMinionManager() {
	//	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate* /* TODO Offset */>();
	//	return game::ManagerTemplateAccessor(manager);
	//}

	//FORCEINLINE  ManagerTemplateAccessor game::ManagerTemplateProvider::GetAITurretClient() {
	//	auto manager = memory::Accessor::AccessModuleAddress<ManagerTemplate* /* TODO Offset */>();
	//	return ManagerTemplateAccessor(manager);
	//}

};

