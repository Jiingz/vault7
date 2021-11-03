#pragma once

#include <core/event/event_bus.h>
#include <core/game/world/world.h>

#include <memory>


namespace core
{
	class Locator
	{
	public:
		static void Initialize();
		static void Finalize();

		static const std::shared_ptr<event::EventBus> GetEventBus();
		static const std::shared_ptr<game::World> GetWorld();


	private:
		std::shared_ptr<event::EventBus> event_bus_;
		std::shared_ptr<game::World> world_;

		static Locator s_locator_;
	};
}
