#include <core/locator.h>

using namespace core;
using namespace event;


Locator Locator::s_locator_ = Locator();


void Locator::Initialize()
{
	s_locator_.event_bus_ = std::make_shared<EventBus>();
	s_locator_.world_ = std::make_shared<game::World>();
}


void Locator::Finalize()
{
	s_locator_.event_bus_.reset();
	s_locator_.world_.reset();
}


const std::shared_ptr<EventBus> Locator::GetEventBus()
{
	return s_locator_.event_bus_;
}

const std::shared_ptr<game::World> core::Locator::GetWorld()
{
	return s_locator_.world_;
}
