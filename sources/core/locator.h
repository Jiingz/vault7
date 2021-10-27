#pragma once

#include <core/event/event_bus.h>

#include <memory>


namespace core
{
    class Locator
    {
    public:
        static void Initialize();
        static void Finalize();

        static const std::shared_ptr<event::EventBus> GetEventBus();


    private:
        std::shared_ptr<event::EventBus> event_bus_;

        static Locator s_locator_;
    };
}
