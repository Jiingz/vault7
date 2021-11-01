#pragma once

#include <ShlObj_core.h>
#include <ShObjIdl.h>

namespace loader::views
{
    class AppView
    {
    public:
        void Render();

    private:
        void LoadModules();

    private:

    };
}
