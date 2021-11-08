#pragma once

#include <windows.h>

#include <sdl.h>
#include <imgui.h>

#include <loader/views/app_view.h>


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
        void InitializeGraphics();
        void InitializeResources();
        void InitializeViews();
        void InitializeModules();

    private:
        SDL_Window* window_;
        SDL_GLContext context_;

        views::AppView app_view_;

        bool is_closed_;
    };
}
