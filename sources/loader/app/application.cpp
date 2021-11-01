#include <loader/app/application.h>

#include <loader/glad/glad.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_opengl3.h>


using namespace loader;


Application::Application()
    : is_closed_(false)
{
    this->Initialize();
}


Application::~Application()
{
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
        ImGui_ImplSDL2_ProcessEvent(&event);

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
}


void Application::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Render
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window_);
    ImGui::NewFrame();

    // ImGui::ShowDemoWindow();

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Modules"))
        {
            ImGui::MenuItem("Load modules");

            ImGui::EndMenu();
        }


        ImGui::EndMainMenuBar();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(window_);
}


void Application::Initialize()
{
    // TODO We need error checks

    // Initialize SDL, OpenGL and ImGui
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    window_ = SDL_CreateWindow("Vault7", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);


    context_ = SDL_GL_CreateContext(window_);
    SDL_GL_MakeCurrent(window_, context_);
    
    SDL_GL_SetSwapInterval(1);
    
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    ImGui::CreateContext();

    ImGui_ImplSDL2_InitForOpenGL(window_, context_);
    ImGui_ImplOpenGL3_Init("#version 130");


    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Candara.ttf", 13.0f);
    io.Fonts->TexGlyphPadding = 1;

    io.Fonts->Build();
}
