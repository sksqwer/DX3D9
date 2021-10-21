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
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <assert.h>

//#include  <D3DX9math.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

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

struct ST_PC_VERTEX
{
	D3DXVECTOR3	p;
	D3DCOLOR	c;

	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};
