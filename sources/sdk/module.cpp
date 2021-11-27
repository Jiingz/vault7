#include <sdk/module.h>

using namespace sdk;


ModuleBase::ModuleBase(std::string_view name, std::string_view version, std::string_view author)
{
    info_.name = name;
    info_.version = version;
    info_.author = author;
}

const std::vector<std::string> ModuleBase::GetSupportedScriptNames() const
{
    std::vector<std::string> script_names;

    for (auto it = registered_scripts_.begin(); it != registered_scripts_.end(); ++it) {
        script_names.push_back(it->second.name);
    }

    return script_names;
}


const ModuleExportInfo& ModuleBase::GetModuleInfo() const
{
    return info_;
}
