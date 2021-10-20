#include "framework.h"
#include "CMainGame.h"
#include "CDeviceManager.h"

CMainGame::CMainGame()
	: m_pD3D(NULL)
	, m_pD3DDevice(NULL)
{
	
}

CMainGame::~CMainGame()
{
}

void CMainGame::Setup()
{
	
}

void CMainGame::Update()
{

}

void CMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	g_pD3DDevice->BeginScene();
	// >> : draw


	// << :

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}