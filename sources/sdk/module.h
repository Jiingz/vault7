#pragma once

#include <sdk/definition.h>


namespace sdk
{
    class ModuleBase
    {
    public:
        ModuleBase(std::string_view name, std::string_view version, std::string_view author)
        {
            definition_.name = name;
            definition_.version = version;
            definition_.author = author;
        }

        const ModuleExportDefintion& GetExportDefinition() const {
            return definition_;
        }

        virtual void GetChampionDefinitions() = 0;

    private:
        ModuleExportDefintion definition_;
    };


    typedef ModuleBase*(*FnResolveModule)();
}
