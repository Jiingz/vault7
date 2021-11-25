#include <core/locator.h>

using namespace core;
using namespace event;
using namespace game;

std::unique_ptr<event::EventBus> Locator::s_event_bus_;
std::unique_ptr<game::World> Locator::s_world_;
std::unique_ptr<HookingService> Locator::s_hooking_service_;
std::unique_ptr<FunctionAccessor> Locator::s_function_accessor_;
std::unique_ptr<DrawFactory> Locator::s_draw_factory_;
std::unique_ptr<Debugger> Locator::s_debugger_;
std::unique_ptr<Engine> Locator::s_engine_;

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

HookingService* Locator::GetHookingService()
{
	if (!s_hooking_service_)
	{
		s_hooking_service_ = std::make_unique<HookingService>();
	}
	return s_hooking_service_.get();
}

FunctionAccessor* Locator::GetFunctionAccessor()
{
	if (!s_function_accessor_)
	{
		s_function_accessor_ = std::make_unique<FunctionAccessor>();
	}
	return s_function_accessor_.get();
}

DrawFactory* Locator::GetDrawFactory()
{
	if (!s_draw_factory_)
	{
		s_draw_factory_ = std::make_unique<DrawFactory>();
	}
	return s_draw_factory_.get();
}

Debugger* Locator::GetDebugger()
{
	if (!s_debugger_)
	{
		s_debugger_ = std::make_unique<Debugger>();
	}
	return s_debugger_.get();
}

Engine* core::Locator::GetEngine()
{
	if (!s_engine_)
	{
		s_engine_ = std::make_unique<Engine>();
	}
	return s_engine_.get();
}
