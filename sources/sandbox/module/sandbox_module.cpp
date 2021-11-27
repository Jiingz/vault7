#include <sandbox/module/sandbox_module.h>
#include <sandbox/champions/ezreal.h>

using namespace sandbox::champions;
using namespace sandbox;
using namespace sdk;


SandboxModule::SandboxModule()
    : ModuleBase("Sandbox", "1.0.0", "Vault7")
{
}


void SandboxModule::OnRegistration()
{
    this->RegisterScript<Ezreal>("Ezreal");
}


ModuleBase* ResolveModule()
{
    return new SandboxModule();
}

