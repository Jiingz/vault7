#pragma once

#include <sdk/metadata.h>
#include <sdk/champion.h>
#include <sdk/exports.h>

#include <unordered_map>
#include <functional>
#include <memory>
#include <vector>


namespace sdk
{
    class VAULT7_SDK_DLL ModuleBase
    {
    private:
        using RegistrationMap = std::unordered_map<std::string, ChampionRegistration>;

    public:
        ModuleBase(std::string_view name, std::string_view version, std::string_view author);

        virtual void OnRegistration() = 0;

        const std::vector<std::string> GetSupportedChampions() const;

        const ModuleExportInfo& GetExportInfo() const;

        // virtual std::vector<std::unique_ptr<IChampion>> GetChampions() = 0;

    protected:
        /**
        * @name Name of the champion.
        * 
        * @remarks You should not add a duplicated champion.
        */
        template <typename TChampion>
        inline void RegisterChampion(std::string name) {
            ChampionRegistration registration;
            registration.name = name;
            registration.factory = []() -> std::unique_ptr<IChampion>
            {
                return std::make_unique<TChampion>(); // TODO Maybe resolve the arguments if needed?
            };

            registered_champs_[name] = registration;
        }

    private:
        RegistrationMap registered_champs_;
        ModuleExportInfo info_;
    };


    typedef ModuleBase*(*FnResolveModule)();
}
