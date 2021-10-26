#include "framework.h"
#include "CMainGame.h"
#include "CDeviceManager.h"
#include "cCubePC.h"
#include  "cCamera.h"
#include  "cGrid.h"

CMainGame::CMainGame()
	: m_pCubePC(NULL)
	, m_pCamera(NULL)
	, m_pGrid(NULL)
{
	
}

CMainGame::~CMainGame()
{
	Safe_Delete(m_pCubePC);
	Safe_Delete(m_pCamera);
	Safe_Delete(m_pGrid);
	g_pDeviceManager->Destroy();
}

void CMainGame::Setup()
{
	m_pCubePC = new cCubePC;
	m_pCubePC->SetUp();

	m_pCamera = new cCamera;
	m_pCamera->SetUp(&m_pCubePC->GetPosition());

	m_pGrid = new cGrid;
	m_pGrid->SetUp();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void CMainGame::Update()
{
	if (m_pCubePC)
		m_pCubePC->Update();

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
	if (m_pCubePC)
		m_pCubePC->Render();

	if(m_pGrid)
		m_pGrid->Render();


	// << :

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void CMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}

//
//void CMainGame::Setup_Line()
//{
//	ST_PC_VERTEX v;
//	v.c = D3DCOLOR_XRGB(255, 0, 0);
//	v.p = D3DXVECTOR3(0, 2, 0);
//	m_vecLineVertex.push_back(v);
//
//	v.p = D3DXVECTOR3(0, -2, 0);
//	m_vecLineVertex.push_back(v);
//}
//
//void CMainGame::Draw_Line()
//{
//	D3DXMATRIX	matWorld;
//	D3DXMatrixIdentity(&matWorld);
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, 
//		m_vecLineVertex.size() / 2,
//		&m_vecLineVertex[0],
//		sizeof(ST_PC_VERTEX));
//}
//
//void CMainGame::Setup_Triangle()
//{
//	ST_PC_VERTEX v;
//	v.c = D3DCOLOR_XRGB(255, 0, 0);
//	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
//	m_vecTriangleVertex.push_back(v);
//
//	v.c = D3DCOLOR_XRGB(0, 255, 0);
//	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
//	m_vecTriangleVertex.push_back(v);
//
//
//	v.c = D3DCOLOR_XRGB(0, 0, 255);
//	v.p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
//	m_vecTriangleVertex.push_back(v);
//}
//
//void CMainGame::Draw_Triangle()
//{
//	D3DXMATRIX	matWorld;
//	D3DXMatrixIdentity(&matWorld);
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//
//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
//
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
//		m_vecTriangleVertex.size() / 3.0f,
//		&m_vecTriangleVertex[0],
//		sizeof(ST_PC_VERTEX));
//}
