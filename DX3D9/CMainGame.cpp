#include "framework.h"
#include "CMainGame.h"
#include "CDeviceManager.h"
#include "cCubePC.h"
#include  "cCamera.h"
#include  "cGrid.h"
#include "cCubeMan.h"
#include "cGroup.h"
#include  "cObjLoader.h"

CMainGame::CMainGame()
	: m_pCubePC(NULL)
	, m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pcCubeMan(NULL)
	, m_pTexture(NULL)
{
	
}

CMainGame::~CMainGame()
{
	Safe_Delete(m_pCubePC);
	Safe_Delete(m_pCamera);
	Safe_Delete(m_pGrid);
	Safe_Delete(m_pcCubeMan);
	Safe_Release(m_pTexture);

	for(auto p: m_vecGroup)
	{
		Safe_Release(p);
	}
	m_vecGroup.clear();

	g_pDeviceManager->Destroy();
}

void CMainGame::Setup()
{
	//m_pCubePC = new cCubePC;
	//m_pCubePC->SetUp();

	m_pcCubeMan = new cCubeMan;
	m_pcCubeMan->Setup();

	m_pCamera = new cCamera;
	m_pCamera->SetUp(&m_pcCubeMan->GetPosition());


	m_pGrid = new cGrid;
	m_pGrid->SetUp();

	Set_Light();
	Set_Texture();

	Setup_Obj();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void CMainGame::Update()
{
	if (m_pCubePC)
		m_pCubePC->Update();

	if (m_pcCubeMan)
		m_pcCubeMan->Update();

	if (m_pCamera)
		m_pCamera->Update();

}

void CMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	g_pD3DDevice->BeginScene();

	// >> : draw
	//Draw_Line();
	//Draw_Triangle();
	//if (m_pCubePC)
	//	m_pCubePC->Render();

	if (m_pGrid)
		m_pGrid->Render();

	if (m_pcCubeMan)
		m_pcCubeMan->Render();

	//Draw_Texture();


	Draw_Obj();
	// << :

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void CMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}

void CMainGame::Set_Light()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));

	stLight.Type = D3DLIGHT_DIRECTIONAL;
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);

	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vDir, &vDir);

	stLight.Direction = vDir;

	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0, true);
}

void CMainGame::Set_Texture()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, L"texture.png", &m_pTexture);

	ST_PT_VERTEX v;
	v.p = D3DXVECTOR3(0, 0, 0);
	v.t = D3DXVECTOR2(0, 1);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 2, 0);
	v.t = D3DXVECTOR2(0, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2, 2, 0);
	v.t = D3DXVECTOR2(1, 0);
	m_vecVertex.push_back(v);


}

void CMainGame::Draw_Texture()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetTexture(0, m_pTexture);

	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PT_VERTEX));

	g_pD3DDevice->SetTexture(0, NULL);


}

void CMainGame::Setup_Obj()
{
	cObjLoader loader;
	loader.Load(m_vecGroup, (char*)"obj", (char*)"box.obj");
}

void CMainGame::Draw_Obj()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	D3DXMatrixScaling(&matS, 0.1f, 0.1f, 0.1f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f);
	matWorld = matS * matR;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	for(auto p : m_vecGroup)
	{
		p->Render();
	}

}
