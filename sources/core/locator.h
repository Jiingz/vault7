#pragma once

#include <core/event/event_bus.h>
#include <core/game/world/world.h>
#include <core/hooking/hooking_service.h>

#include <memory>


namespace core
{
	static class Locator
	{
		//Getter for Instances
	public:
		static event::EventBus* GetEventBus();
		static game::World* GetWorld();
		static HookingService* GetHookingService();


		//Singletons
	private:
		static std::unique_ptr<event::EventBus> s_event_bus_;
		static std::unique_ptr<game::World> s_world_;
		static std::unique_ptr<HookingService> s_hooking_service_;
	};
}
