#pragma once

#include <core/event/event_bus.h>
#include <core/game/world/world.h>

#include <memory>


namespace core
{
	class Locator
	{
		//Getter for Instances
	public:
		static const std::shared_ptr<Locator> GetLocator();

		const std::shared_ptr<event::EventBus> GetEventBus();
		const std::shared_ptr<game::World> GetWorld();

		//Singletons
	private:
		static std::shared_ptr<Locator> locator_;

		std::shared_ptr<event::EventBus> event_bus_;
		std::shared_ptr<game::World> world_;
	};
}
