#pragma once
#include "Box.h"

class SkyBox :public Box
{
public:
	//--------------------------------------------------------------------------------------
	// 텍스처 배열 초기화
	//--------------------------------------------------------------------------------------
	bool		 SetTextureArray();
	//--------------------------------------------------------------------------------------
	// 스카이 박스 렌더링
	//--------------------------------------------------------------------------------------
	virtual bool Render(ID3D11DeviceContext* pContext);
public:
	SkyBox();
	virtual ~SkyBox();
};

