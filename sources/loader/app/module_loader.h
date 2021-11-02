#pragma once

#include <sdk/module.h>

#include <memory>


namespace loader
{
    class ModuleLoader
    {
    public:
        std::unique_ptr<sdk::ModuleBase> LoadModule(const std::wstring_view path);

    private:

    };
}

