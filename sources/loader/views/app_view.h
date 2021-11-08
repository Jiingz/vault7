#pragma once

#include <ShlObj_core.h>
#include <ShObjIdl.h>
#include <imgui.h>

#include <loader/app/resource_holder.h>

#include <sdk/metadata.h>
#include <sdk/module.h>

#include <vector>


namespace loader::views
{
    class AppView
    {
    public:
        AppView();

        void Initialize();

        void Render();

    private:
        bool RenderModule(ResourceHolder<sdk::ModuleBase>::Iterator it); /* std::wstring module_filename, sdk::ModuleExportInfo info */
        void RemoveModule(ResourceHolder<sdk::ModuleBase>::Iterator it);

        void LoadModules();

    private:
        bool modules_loaded_;

        ResourceHolder<sdk::ModuleBase>* modules_;

        ImFont* md_main_font_;
        ImFont* md_material_font_;
        ImFont* lg_material_font_;
    };
}
