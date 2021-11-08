#include <core/locator.h>

using namespace core;
using namespace event;
using namespace game;

std::unique_ptr<event::EventBus> Locator::s_event_bus_;
std::unique_ptr<game::World> Locator::s_world_;

EventBus* Locator::GetEventBus()
{
	if (!s_event_bus_)
	{
		s_event_bus_ = std::make_unique<EventBus>();
	}
	return s_event_bus_.get();
}

World* Locator::GetWorld()
{
	if (!s_world_)
	{
		s_world_ = std::make_unique<game::World>();

	}
	return s_world_.get();
}
