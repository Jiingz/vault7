#pragma once

#include <functional>
#include <memory>
#include <string>


namespace sdk
{
    struct INativeScript;

    struct ScriptFeature
    {
        std::string name;
        std::string friendly_name;
        std::string description;
    };

    struct ScriptRegistration
    {
        std::string name;
        std::function<std::unique_ptr<INativeScript>()> factory;
    };

    struct ModuleExportInfo
    {
        std::string name;
        std::string author;
        std::string version;
    };
}
