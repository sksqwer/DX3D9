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
	:m_pRoot(NULL)
{
}

cCubeMan::~cCubeMan()
{
	if(m_pRoot)
		m_pRoot->Destroy();
}

void cCubeMan::Setup()
{
	cCharacter::Setup();

	// : 몸의 각 부위 조합

	//m_pRoot = new cCubeNode;	//m_pRoot->SetUp();	//m_pRoot->SetParentWorldTM(&m_matWorld);



	cBody* pBody = new cBody;	pBody->SetUp();	pBody->SetParentWorldTM(&m_matWorld);	m_pRoot = pBody;


	cHead* p_head = new cHead;
	p_head->SetUp();
	m_pRoot->AddChild(p_head);

	cLeftArm* p_left_arm = new cLeftArm;
	p_left_arm->SetUp();
	m_pRoot->AddChild(p_left_arm);

	cRightArm* p_right_arm = new cRightArm;
	p_right_arm->SetUp();
	m_pRoot->AddChild(p_right_arm);

	cLeftLeg* p_left_leg = new cLeftLeg;
	p_left_leg->SetUp();
	m_pRoot->AddChild(p_left_leg);

	cRightLeg* p_right_leg = new cRightLeg;
	p_right_leg->SetUp();
	m_pRoot->AddChild(p_right_leg);


}

void cCubeMan::Update()
{
	cCharacter::Update();

	if (m_pRoot)
		m_pRoot->Update();
}

void cCubeMan::Render()
{
	if(g_pD3DDevice)
	{
		//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

		cCharacter::Render();
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		if (m_pRoot)
			m_pRoot->Render();
	}

}
