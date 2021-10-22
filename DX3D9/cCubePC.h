#pragma once


class cCubePC
{
public:
	cCubePC();
	~cCubePC();

private:
	std::vector<ST_PC_VERTEX> m_vecVertex; // �׸��� ���� ���ؽ����� �����Ѵ�
	float m_fRotY;
	D3DXVECTOR3 m_vDirection;
	D3DXVECTOR3 m_vPosition;
	D3DXMATRIXA16 m_matWorld;


public:
	void SetUp();
	void Update();
	void Render();

	D3DXVECTOR3& GetPosition();



};
