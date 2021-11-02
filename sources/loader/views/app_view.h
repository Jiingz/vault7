#pragma once

#include <ShlObj_core.h>
#include <ShObjIdl.h>

#include <sdk/metadata.h>

#include <vector>


namespace loader::views
{
    class AppView
    {
    public:
        AppView();

        void Render();

    private:
        void LoadModules();

    private:
        bool modules_loaded_;

        std::vector<sdk::ModuleExportInfo> loaded_module_information_;
    };
}
