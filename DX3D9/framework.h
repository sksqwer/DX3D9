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

#define Safe_Relaese(p) {if(p) p->Release(); p = NULL;}
#define Safe_Delete(p) { if(p) delete p; p = NULL; }

#define Singleton(class_name) \
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

//
#include "CDeviceManager.h"

struct ST_PNT_VERTEX
{
	D3DXVECTOR3	p;
	D3DXVECTOR3	n;
	D3DXVECTOR2	t;

	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };
};

struct ST_PT_VERTEX
{
	D3DXVECTOR3	p;
	D3DXVECTOR2	t;

	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };
};

// ## 문자열 합치기
#define Synthesize(varType, varName, funName)\
	protected:\
		varType varName;\
	public:\
		inline varType Get##funName(void) const {return varName;}\
	public:\
		inline void Set##funName(varType var) {varName = var;}

#define Synthesize_Pass_By_Ref(varType, varName, funName)\
	protected:\
		varType varName;\
	public:\
		inline varType& Get##funName(void) {return varName;}\
	public:\
		inline void Set##funName(varType& var) {varName = var;}


