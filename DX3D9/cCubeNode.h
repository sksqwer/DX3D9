#pragma once
#include "cCubePNT.h"

class cCubeNode : public cCubePNT
{
public:
	cCubeNode();
	virtual ~cCubeNode();

protected:
	D3DXVECTOR3		m_vLocalPos;

	D3DXMATRIX		m_matLocallTM;
	D3DXMATRIX		m_matWorlddTM;
	std::vector<cCubeNode*> m_vecChild;
	Synthesize(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	Synthesize(float, m_fRotDeltaX, RotDeltaX);

public:
	virtual void AddChild(cCubeNode* pChild);
	virtual void Destroy();

	virtual void SetUp() override;
	virtual void Update() override;
	virtual void Render() override;


};

