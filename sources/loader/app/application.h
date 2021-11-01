#pragma once

#include <windows.h>

#include <sdl.h>
#include <imgui.h>


namespace loader
{
    class Application
    {
    public:
        Application();
        ~Application();

        INT Run();

        void HandleEvents();
        void Render();

    private:
        void Initialize();

    private:
        SDL_Window* window_;
        SDL_GLContext context_;

        bool is_closed_;
    };
}
