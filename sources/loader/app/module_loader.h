#pragma once

#include <sdk/module.h>

#include <memory>


namespace loader
{
    class ModuleLoader
    {
    public:
        static std::unique_ptr<sdk::ModuleBase> LoadModule(const std::wstring& path);

    private:

    };
}

