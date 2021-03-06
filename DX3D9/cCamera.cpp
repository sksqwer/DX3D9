
#include "framework.h"
#include "cCamera.h"

cCamera::cCamera()
	: m_vCamRotAngle(0.0f, 0.0f, 0.0f)
	, m_vEye(0, 0, -5)
	, m_vLookAt(0, 0, 0)
	, m_vUp(0, 1, 0)
	, m_pvTarget(NULL)
	, m_fCameraDistance(5.0f)
	, m_isLButtonDown(false)
{
	m_ptPrevMouse.x = 0;
	m_ptPrevMouse.y = 0;
}

cCamera::~cCamera()
{

}

void cCamera::SetUp(D3DXVECTOR3* pvTarget)
{
	m_pvTarget = pvTarget;

	RECT rc;
	GetClientRect(g_hWnd, &rc);
	D3DXMATRIXA16 matProj;

	// 시야에 근거해서 LH(왼손좌표계) Perspective 투영 행렬을 구한다
	D3DXMatrixPerspectiveFovLH(&matProj,						// result out
		D3DX_PI / 4.0f,					// y 방향에서의 시야
		rc.right / (float)rc.bottom,	// 가로세로 비율
		1.0f, 1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void cCamera::Update()
{
	D3DXMATRIXA16 matR, matRX, matRY;
	D3DXMatrixRotationX(&matRX, m_vCamRotAngle.x);
	D3DXMatrixRotationY(&matRY, m_vCamRotAngle.y);
	matR = matRX * matRY;

	m_vEye = D3DXVECTOR3(0.0f, 0.0f, -m_fCameraDistance);
	D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);

	if(m_pvTarget)
	{
		m_vLookAt = *m_pvTarget;
		m_vEye = m_vEye + *m_pvTarget;
	}

	D3DXMATRIXA16	matView;
	D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);


}

void cCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		m_ptPrevMouse.x = LOWORD(lParam);
		m_ptPrevMouse.y = HIWORD(lParam);
		m_isLButtonDown = true;
		break;
	case WM_LBUTTONUP:
		m_isLButtonDown = false;
		break;
	case WM_MOUSEMOVE:
		if (m_isLButtonDown)
		{
			POINT ptCurMouse;
			ptCurMouse.x = LOWORD(lParam);
			ptCurMouse.y = HIWORD(lParam);
			float fDeltaX = (float)ptCurMouse.x - m_ptPrevMouse.x;
			float fDeltaY = (float)ptCurMouse.y - m_ptPrevMouse.y;

			m_vCamRotAngle.y += (fDeltaX / 100.0f);
			m_vCamRotAngle.x += (fDeltaY / 100.0f);
			if (m_vCamRotAngle.x < -D3DX_PI / 2.0f + D3DX_16F_EPSILON)
				m_vCamRotAngle.x = -D3DX_PI / 2.0f + D3DX_16F_EPSILON;
			if (m_vCamRotAngle.y > D3DX_PI / 2.0f + D3DX_16F_EPSILON)
				m_vCamRotAngle.y = D3DX_PI / 2.0f + D3DX_16F_EPSILON;

			m_ptPrevMouse = ptCurMouse;
		}
		break;
	case WM_MOUSEWHEEL:
		m_fCameraDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 100.0f);
		if (m_fCameraDistance < 2.0001f)
			m_fCameraDistance = 2.0001f;
		break;
	default:
		break;
	}
}
