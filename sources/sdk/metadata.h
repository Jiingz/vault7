#pragma once

#include <functional>
#include <memory>
#include <string>


namespace sdk
{
    struct IChampion;


    struct ChampionFeature
    {
        std::string name;
        std::string friendly_name;
        std::string description;
    };

    struct ChampionRegistration
    {
        std::string name;
        std::function<std::unique_ptr<IChampion>()> factory;
    };

    struct ModuleExportInfo
    {
        std::string name;
        std::string author;
        std::string version;
    };
}
