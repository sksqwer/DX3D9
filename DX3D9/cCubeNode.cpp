#include "framework.h"
#include "cCubeNode.h"

cCubeNode::cCubeNode()
	: m_fRotDeltaX(0.0f)
	, m_pParentWorldTM(NULL)
	, m_vLocalPos(0.0f, 0.0f, 0.f)
{
	D3DXMatrixIdentity(&m_matLocallTM);
	D3DXMatrixIdentity(&m_matWorlddTM);
}

cCubeNode::~cCubeNode()
{
}

void cCubeNode::AddChild(cCubeNode* pChild)
{
	pChild->m_pParentWorldTM = &m_matWorlddTM;
	m_vecChild.push_back(pChild);
}

void cCubeNode::Destroy()
{
	for(auto p : m_vecChild)
	{
		p->Destroy();
	}
	delete this;
}

void cCubeNode::SetUp()
{
	cCubePNT::SetUp();
}

void cCubeNode::Update()
{
	cCubePNT::Update();

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	m_matLocallTM = matR * matT;

	m_matWorlddTM = m_matLocallTM;
	if(m_pParentWorldTM) // 부모 자식관계에 따라 부모가 움직인 값에 비례하여 반영
	{
		m_matWorlddTM *= *m_pParentWorldTM;
	}

	for(auto p : m_vecChild)
	{
		p->Update();
	}


}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorlddTM);
	cCubePNT::Render();

	for(auto p : m_vecChild)
	{
		p->Render();
	}

}
