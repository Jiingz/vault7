#include <loader/app/module_loader.h>

#include <windows.h>


using namespace loader;
using namespace sdk;



std::unique_ptr<ModuleBase> ModuleLoader::LoadModule(const std::wstring_view path)
{
    HMODULE module_handle = LoadLibrary(path.data());

    if (!module_handle)
    {
        // TODO 
        return nullptr;
    }

    FARPROC function_address = GetProcAddress(module_handle, "ResolveModule");

    if (!function_address)
    {
        // TODO 
        return nullptr;
    }

    auto factory = reinterpret_cast<FnResolveModule>(function_address);
    auto module = factory();

    return std::unique_ptr<ModuleBase>(module);
}
