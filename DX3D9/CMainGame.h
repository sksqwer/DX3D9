#pragma once
#include "framework.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

private:
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pD3DDevice;

public:
	void Setup();
	void Update();
	void Render();

};

