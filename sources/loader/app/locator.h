#pragma once

#include <loader/app/resource_holder.h>

#include <sdk/module.h>

#include <imgui.h>


namespace loader
{
    class Locator
    {
    public:
        static void Finalize();

        static ResourceHolderNop<ImFont>* GetFonts();
        static ResourceHolder<sdk::ModuleBase>* GetModules();

    private:
        static std::unique_ptr<ResourceHolderNop<ImFont>> s_fonts_;
        static std::unique_ptr<ResourceHolder<sdk::ModuleBase>> s_modules_;
    };
}
