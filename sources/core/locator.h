#pragma once

#include <core/event/event_bus.h>
#include <core/game/world/world.h>

#include <memory>


namespace core
{
	static class Locator
	{
		//Getter for Instances
	public:
		static event::EventBus* GetEventBus();
		static game::World* GetWorld();


		//Singletons
	private:
		static std::unique_ptr<event::EventBus> s_event_bus_;
		static std::unique_ptr<game::World> s_world_;
	};
}
