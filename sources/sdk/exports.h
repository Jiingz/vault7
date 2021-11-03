#pragma once

#ifdef SDK_EXPORTS
    #define VAULT7_SDK_DLL __declspec(dllexport)
#else
    #define VAULT7_SDK_DLL __declspec(dllimport)
#endif // SDK_EXPORTS
