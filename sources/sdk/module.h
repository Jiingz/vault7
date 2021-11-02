#pragma once

#include <sdk/metadata.h>


namespace sdk
{
    class ModuleBase
    {
    public:
        ModuleBase(std::string_view name, std::string_view version, std::string_view author)
        {
            info_.name = name;
            info_.version = version;
            info_.author = author;
        }

        const ModuleExportInfo& GetExportInfo() const {
            return info_;
        }

        virtual void GetChampionDefinitions() = 0;

    private:
        ModuleExportInfo info_;
    };


    typedef ModuleBase*(*FnResolveModule)();
}
