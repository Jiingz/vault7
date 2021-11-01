#pragma once

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

        void GetChampionDefinitions() final override;
    };
}


extern "C" SANDBOX_DLL sdk::ModuleBase* ResolveModule();

