#pragma once
#include "framework.h"

class cCubePC;
class cCamera;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

private:
	cCubePC*			m_pCubePC;
	cCamera*			m_pCamera;
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
};

