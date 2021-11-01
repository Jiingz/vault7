#include <sandbox/module/module.h>

using namespace sandbox;


SandboxModule::SandboxModule()
    : sdk::ModuleBase("Sandbox", "1.0.0", "Vault7")
{
}


void SandboxModule::GetChampionDefinitions()
{
    std::cout << "Returning multiple champions...\n";
}


sdk::ModuleBase* ResolveModule()
{
    return new SandboxModule();
}
