#pragma once
#include "framework.h"

class cCubePC;
class cCamera;
class cGrid;
class cCubeMan;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

private:
	cCubePC*					m_pCubePC;
	cCamera*					m_pCamera;
	cGrid*						m_pGrid;
	cCubeMan*					m_pcCubeMan;

	LPDIRECT3DTEXTURE9			m_pTexture;
	std::vector<ST_PT_VERTEX>	m_vecVertex;


	//LPDIRECT3D9			m_pD3D;
	//LPDIRECT3DDEVICE9	m_pD3DDevice;
	//std::vector<ST_PC_VERTEX> m_vecLineVertex;
	//std::vector<ST_PC_VERTEX> m_vecTriangleVertex;

public:
	void Setup();
	void Update();
	void Render();

	/*void Setup_Line();
	void Draw_Line();

	void Setup_Triangle();
	void Draw_Triangle();*/

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	void Set_Light();
	void Set_Texture();
	void Draw_Texture();
};

