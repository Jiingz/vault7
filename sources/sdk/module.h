#pragma once

#include <sdk/metadata.h>
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
        using RegistrationMap = std::unordered_map<std::string, ScriptRegistration>;

    public:
        ModuleBase(std::string_view name, std::string_view version, std::string_view author);

        virtual void OnRegistration() = 0;

        const std::vector<std::string> GetSupportedScriptNames() const;

        const ModuleExportInfo& GetModuleInfo() const;

        // virtual std::vector<std::unique_ptr<IChampion>> GetChampions() = 0;

    protected:
        /**
        * @name Name of the script.
        * 
        * @remarks You should not add a duplicated script.
        */
        template <typename TScript>
        inline void RegisterScript(std::string name) {
            ScriptRegistration registration;
            registration.name = name;
            registration.factory = []() -> std::unique_ptr<TScript>
            {
                return std::make_unique<TScript>(); // TODO Maybe resolve the arguments if needed?
            };

            registered_scripts_[name] = registration;
        }

    private:
        RegistrationMap registered_scripts_;
        ModuleExportInfo info_;
    };


    typedef ModuleBase*(*FnResolveModule)();
}
