#pragma once
#include "Plane.h"

struct RectUV
{
	TVector2 uv[4];
};

class Sprite : public DXCore::Plane
{
public:
	vector<RectUV>		m_uvList;
	int					m_iIndex;

	float				m_fOffsetTime;
	float				m_fLifeTime;
	int					m_iCurrentFrame;
	float				m_fCurrentTime;
public:
	//--------------------------------------------------------------------------------------
	// Rect값 초기화
	//--------------------------------------------------------------------------------------
	void				SetRect(int iRow, int iCol, float fOffset);
	//--------------------------------------------------------------------------------------
	// 시간에 따른 이미지 변환 함수
	//--------------------------------------------------------------------------------------
	void				Update();
	//--------------------------------------------------------------------------------------
	// 레이아웃 및 쉐이더 생성
	//--------------------------------------------------------------------------------------
	/*HRESULT			LoadShaderAndInputLayout(T_STR vertexShaderName = NULL,
		T_STR PixelShaderName = NULL, T_STR geometryShaderName = NULL);*/
	//--------------------------------------------------------------------------------------
	// Rect값 반환 함수
	//--------------------------------------------------------------------------------------
	TVector2			GetDrawRect(int iUV);
public:
	Sprite();
	~Sprite();
};

