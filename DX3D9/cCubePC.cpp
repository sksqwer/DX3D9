#include "framework.h"
#include "cCubePC.h"

cCubePC::cCubePC()
	: m_vDirection(0, 0, 1)
	, m_vPosition(0, 0, 0)
	, m_fRotY(0.0f)
{
	D3DXMatrixIdentity(&m_matWorld); // 초기화
}

cCubePC::~cCubePC()
{
}

void cCubePC::SetUp()
{
	// 시계방향으로 그려진다
	// 삼각형
	//ST_PC_VERTEX v;
	//v.c = D3DCOLOR_XRGB(255, 0, 0); // R

	//v.p = D3DXVECTOR3(-1.0F, -1.0F, 0.0F);
	//m_vecVertex.push_back(v);

	//v.c = D3DCOLOR_XRGB(0, 255, 0);	// G
	//v.p = D3DXVECTOR3(-1.0F, 1.0F, 0.0F);
	//m_vecVertex.push_back(v);

	//v.c = D3DCOLOR_XRGB(0, 0, 255);	// B
	//v.p = D3DXVECTOR3(1.0F, 1.0F, 0.0F);
	//m_vecVertex.push_back(v);

	//Cube
	ST_PC_VERTEX v;
	// front
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);

	// back
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);

	// left
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);

	// right
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);

	// top
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

	v.p = D3DXVECTOR3(-1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);

	// bottom
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);


}

void cCubePC::Update()
{
	if(GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}

	if(GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}


	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
	}

	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
	}


	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY); // y를 회전축으로 해서 회전하는 행렬을 matR에 생성한다
	m_vDirection = D3DXVECTOR3(0, 0, 1);

	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;
}

void cCubePC::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX));
}

D3DXVECTOR3 & cCubePC::GetPosition()
{
	return m_vPosition;
}
