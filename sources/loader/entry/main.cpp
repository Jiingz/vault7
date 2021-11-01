#include <windows.h>

#include <iostream>

#include <SDL.h>
#include <imgui.h>
#include <imgui_sdl.h>


#ifdef main
#undef main
#endif


int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    auto window = SDL_CreateWindow("Vault7", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    ImGui::CreateContext();
    ImGuiSDL::Initialize(renderer, 800, 600);


    if (!window)
    {
        return -1;
    }

    bool is_closed = false;

    while (!is_closed)
    {
        ImGuiIO& io = ImGui::GetIO();

        INT mouse_wheel = 0;

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_closed = true;
            }
            else if (event.type == SDL_WINDOWEVENT)
            {
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    io.DisplaySize.x = static_cast<FLOAT>(event.window.data1);
                    io.DisplaySize.y = static_cast<FLOAT>(event.window.data2);
                }
            }
            else if (event.type == SDL_MOUSEWHEEL)
            {
                mouse_wheel = event.wheel.y;
            }
        }

        // Redirect mouse events
        INT mouse_x, mouse_y;
        const int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

        io.DeltaTime = 1.0f / 60.0f;
        io.MousePos = ImVec2(static_cast<FLOAT>(mouse_x), static_cast<FLOAT>(mouse_y));
        io.MouseDown[0] = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
        io.MouseDown[1] = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
        io.MouseWheel = static_cast<FLOAT>(mouse_wheel);

        // Render
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();

        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
        SDL_RenderClear(renderer);

        ImGui::Render();
        ImGuiSDL::Render(ImGui::GetDrawData());

        SDL_RenderPresent(renderer);
    }

    ImGuiSDL::Deinitialize();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    ImGui::DestroyContext();

    return 0;
}
