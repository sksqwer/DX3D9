#include "CDeviceManager.h"

CDeviceManager::CDeviceManager()
{
	m_pD3D = Direct3DCreate9((D3D_SDK_VERSION));

	D3DCAPS9	stCaps;
	int			nVertexProcessing;
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &stCaps);
	if (stCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	D3DPRESENT_PARAMETERS	stD3DPP;

	ZeroMemory(&stD3DPP, sizeof(D3DPRESENT_PARAMETERS));
	stD3DPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	stD3DPP.Windowed = true;
	stD3DPP.BackBufferFormat = D3DFMT_UNKNOWN;
	stD3DPP.EnableAutoDepthStencil = TRUE;
	stD3DPP.AutoDepthStencilFormat = D3DFMT_D16; // 32로 쓸수 있음

	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing,
		&stD3DPP,
		&m_pD3DDevice
	);
}


CDeviceManager::~CDeviceManager()
{
	g_pDeviceManager->Destroy();
}

LPDIRECT3DDEVICE9 CDeviceManager::GetDevice()
{
	return m_pD3DDevice;
}


void CDeviceManager::Destroy()
{
	SAFE_REALEASE(m_pD3DDevice);
	SAFE_REALEASE(m_pD3D);
}
