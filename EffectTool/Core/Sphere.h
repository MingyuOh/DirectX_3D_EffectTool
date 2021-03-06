#pragma once
#include "Shape.h"

class Sphere :public Shape
{
public:
	//--------------------------------------------------------------------------------------
	// 정점 버퍼 생성
	//--------------------------------------------------------------------------------------
	bool			CreateVertexData() override;
	HRESULT			CreateVertexBuffer() override;
	//--------------------------------------------------------------------------------------
	// 인덱스 버퍼 생성
	//--------------------------------------------------------------------------------------
	bool			CreateIndexData() override;
	HRESULT			CreateIndexBuffer() override;
	//--------------------------------------------------------------------------------------
	// Sphere 정점 생성 함수
	//--------------------------------------------------------------------------------------
	void			MakeSphereVertex(vector<TVector3>& VertexArray, UINT sliceCount, float fRadius);
	//--------------------------------------------------------------------------------------
	// Sphere 생성 함수
	//--------------------------------------------------------------------------------------
	void			CreateSphere(UINT Slice, float fRadius);
	//--------------------------------------------------------------------------------------
	// 렌더링 재정의 함수
	//--------------------------------------------------------------------------------------
	bool			Render(ID3D11DeviceContext* pContext) override;
public:
	Sphere();
	virtual ~Sphere();
};

