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
	Setup_Line();
	Setup_Triangle();
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void CMainGame::Update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXVECTOR3 vEye = D3DXVECTOR3(0, 0, -5.0F);
	D3DXVECTOR3 vLookAt = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 vUp = D3DXVECTOR3(0, 1, 0);
	D3DXMATRIXA16 matView;

	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;

	// 시야에 근거해서 LH(왼손좌표계) Perspective 투영 행렬을 구한다
	D3DXMatrixPerspectiveFovLH(&matProj,						// result out
		D3DX_PI / 4.0f,					// y 방향에서의 시야
		rc.right / (float)rc.bottom,	// 가로세로 비율
		1.0f, 1000.0f);					// nearView farView Z값

	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);


}

void CMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	g_pD3DDevice->BeginScene();

	// >> : draw
	Draw_Line();
	Draw_Triangle();


	// << :

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void CMainGame::Setup_Line()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(0, 2, 0);
	m_vecLineVertex.push_back(v);

	v.p = D3DXVECTOR3(0, -2, 0);
	m_vecLineVertex.push_back(v);
}

void CMainGame::Draw_Line()
{
	D3DXMATRIX	matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, 
		m_vecLineVertex.size() / 2,
		&m_vecLineVertex[0],
		sizeof(ST_PC_VERTEX));
}

void CMainGame::Setup_Triangle()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(0, 255, 255);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	m_vecTriangleVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	m_vecTriangleVertex.push_back(v);


	v.p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	m_vecTriangleVertex.push_back(v);
}

void CMainGame::Draw_Triangle()
{
	D3DXMATRIX	matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecTriangleVertex.size() / 3.0f,
		&m_vecTriangleVertex[0],
		sizeof(ST_PC_VERTEX));
}
