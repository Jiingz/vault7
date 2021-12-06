#pragma once

#include <core/event/event_bus.h>
#include <core/game/world/world.h>
#include <core/hooking/hooking_service.h>

#include <memory>
#include <core/game/functions/function_accessor.h>
#include <core/drawings/draw_factory.h>
#include <core/game/game_components/game_component.h>

namespace core
{
	static class Locator
	{
		//Getter for Instances
	public:
		static event::EventBus* GetEventBus();
		static game::World* GetWorld();
		static HookingService* GetHookingService();
		static game::FunctionAccessor* GetFunctionAccessor();
		static DrawFactory* GetDrawFactory();
		static game::GameComponent* GetGameComponents();

		//Singletons
	private:
		static std::unique_ptr<event::EventBus> s_event_bus_;
		static std::unique_ptr<game::World> s_world_;
		static std::unique_ptr<HookingService> s_hooking_service_;
		static std::unique_ptr<game::FunctionAccessor> s_function_accessor_;
		static std::unique_ptr<DrawFactory> s_draw_factory_;
		static std::unique_ptr<game::GameComponent> s_game_component_;
	};
}
