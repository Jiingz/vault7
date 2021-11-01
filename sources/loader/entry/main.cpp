#include <windows.h>

#include <loader/app/application.h>


#ifdef main
    #undef main
#endif


int main()
{
    loader::Application application;
    return application.Run();
}
