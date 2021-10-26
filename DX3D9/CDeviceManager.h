#pragma once
#include "framework.h"

#define g_pDeviceManager CDeviceManager::GetInstance()
#define g_pD3DDevice	CDeviceManager::GetInstance()->GetDevice()

class CDeviceManager
{
	Singleton(CDeviceManager);

private:
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pD3DDevice;

public:
	LPDIRECT3DDEVICE9	GetDevice();
	void				Destroy();


};

