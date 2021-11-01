#include <iostream>

#include <SDL.h>

#ifdef main
#undef main
#endif


int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow("Vault7", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

    if (!window)
    {
        return -1;
    }


    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
