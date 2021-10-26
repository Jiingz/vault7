#pragma once

#ifdef CORE_EXPORTS
#define VAULT7_CORE_DLL __declspec(dllexport)
#else
#define VAULT7_CORE_DLL __declspec(dllimport)
#endif // SDK_EXPORTS