#include <core/locator.h>

using namespace core;
using namespace event;
using namespace game;

std::shared_ptr<Locator> Locator::locator_;


const std::shared_ptr<Locator> Locator::GetLocator()
{
	if (!locator_)
	{
		locator_ = std::make_shared<Locator>();
	}
	return locator_;
}

const std::shared_ptr<EventBus> Locator::GetEventBus()
{
	if (!event_bus_)
	{
		event_bus_ = std::make_shared<EventBus>();
	}
	return event_bus_;
}

const std::shared_ptr<game::World> core::Locator::GetWorld()
{
	if (!world_)
	{
		world_ = std::make_shared<game::World>();

	}
	return world_;
}
