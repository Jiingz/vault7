#include <loader/app/application.h>
#include <imgui_sdl.h>

using namespace loader;


Application::Application()
    : is_closed_(false)
{
    this->Initialize();
}


Application::~Application()
{
    ImGuiSDL::Deinitialize();

    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();

    ImGui::DestroyContext();
}


INT Application::Run()
{
    while (!is_closed_)
    {
        this->HandleEvents();
        this->Render();
    }

    return 0;
}

void Application::HandleEvents()
{
    ImGuiIO& io = ImGui::GetIO();
    SDL_Event event;

    INT mouse_wheel = 0;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            is_closed_ =true;
        }

        if (event.type == SDL_QUIT)
        {
            is_closed_= true;
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
}


void Application::Render()
{
    // Render
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    SDL_SetRenderDrawColor(renderer_, 40, 40, 40, 255);
    SDL_RenderClear(renderer_);

    ImGui::Render();
    ImGuiSDL::Render(ImGui::GetDrawData());

    SDL_RenderPresent(renderer_);
}


void Application::Initialize()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    window_ = SDL_CreateWindow("Vault7", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

    ImGui::CreateContext();
    ImGuiSDL::Initialize(renderer_, 800, 600);
}
