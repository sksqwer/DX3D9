// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
extern  HWND g_hWnd;
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//DirectX
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "D:/DirectXSDK/DX9/Lib/x86/d3dx9.lib")

extern  HWND g_hWnd;

#define SAFE_REALEASE(p) {if(p) p->Release(); p = NULL;}

#define SINGLETON(class_name) \
private: \
class_name(void) ; \
~class_name(void) ; \
public :\
static class_name* GetInstance() \
{ \
static class_name instance; \
return &instance ;\
}