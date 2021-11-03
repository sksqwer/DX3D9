#include "framework.h"
#include "cCubeMan.h"

#include "cCubeNode.h"
#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include  "cLeftLeg.h"
#include  "cRightLeg.h"


cCubeMan::cCubeMan()
	: m_pRoot(NULL)
	, m_pTexture(NULL)
{
}

cCubeMan::~cCubeMan()
{
	Safe_Release(m_pTexture);
	if(m_pRoot)
		m_pRoot->Destroy();
}

void cCubeMan::Setup()
{
	cCharacter::Setup();

	// : 몸의 각 부위 조합

	//m_pRoot = new cCubeNode;
	//m_pRoot->SetUp();
	//m_pRoot->SetParentWorldTM(&m_matWorld);

	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));

	m_stMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	// #. Texture
	D3DXCreateTextureFromFile(g_pD3DDevice, L"FanDeMeeZoid.png", &m_pTexture);


	cBody* pBody = new cBody;
	pBody->SetUp();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;


	cHead* p_head = new cHead;
	p_head->SetUp();
	p_head->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(p_head);

	cLeftArm* p_left_arm = new cLeftArm;
	p_left_arm->SetUp();
	p_left_arm->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(p_left_arm);

	cRightArm* p_right_arm = new cRightArm;
	p_right_arm->SetUp();
	p_right_arm->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(p_right_arm);

	cLeftLeg* p_left_leg = new cLeftLeg;
	p_left_leg->SetUp();
	p_left_leg->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(p_left_leg);

	cRightLeg* p_right_leg = new cRightLeg;
	p_right_leg->SetUp();
	p_right_leg->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(p_right_leg);


}

void cCubeMan::Update(iMap* pMap)
{
	cCharacter::Update(pMap);

	if (m_pRoot)
		m_pRoot->Update();
}

void cCubeMan::Render()
{
	if(g_pD3DDevice)
	{
		g_pD3DDevice->SetMaterial(&m_stMtl);
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetTexture(0, m_pTexture);

		cCharacter::Render();
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		if (m_pRoot)
			m_pRoot->Render();

		g_pD3DDevice->SetTexture(0, NULL);
	}

}
