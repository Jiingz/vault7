#include <sdk/module.h>

using namespace sdk;


ModuleBase::ModuleBase(std::string_view name, std::string_view version, std::string_view author)
{
    info_.name = name;
    info_.version = version;
    info_.author = author;
}

const std::vector<std::string> ModuleBase::GetSupportedChampions() const
{
    std::vector<std::string> champion_names;

    for (auto it = registered_champs_.begin(); it != registered_champs_.end(); ++it) {
        champion_names.push_back(it->second.name);
    }

    return champion_names;
}


const ModuleExportInfo& ModuleBase::GetExportInfo() const
{
    return info_;
}
