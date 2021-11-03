#pragma once

#include <sdk/champion.h>
#include <sdk/module.h>

#include <iostream>

#ifdef SANDBOX_EXPORTS
#define SANDBOX_DLL __declspec(dllexport)
#else
#define SANDBOX_DLL __declspec(dllimport)
#endif //


namespace sandbox
{
    class SandboxModule : public sdk::ModuleBase
    {
    public:
        SandboxModule();

        void OnRegistration() final override;

        // std::vector<std::unique_ptr<sdk::IChampion>> GetChampions() final override;

    private:
    };
}


extern "C" SANDBOX_DLL sdk::ModuleBase* ResolveModule();
