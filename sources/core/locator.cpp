#include <core/locator.h>

using namespace core;
using namespace event;


Locator Locator::s_locator_ = Locator();


void Locator::Initialize()
{
    s_locator_.event_bus_ = std::make_shared<EventBus>();
}


void Locator::Finalize()
{
    s_locator_.event_bus_.reset();
}


const std::shared_ptr<EventBus> Locator::GetEventBus()
{
    return s_locator_.event_bus_;
}
