#pragma once
#include "Object.h"

//--------------------------------------------------------------------------------------
// �� ������ ����ü
//--------------------------------------------------------------------------------------
struct SceneFrame
{
	int iFristFrame;
	int iLastFrame;
	int iFrameSpeed;
	int iTickPerFrame;
};

//--------------------------------------------------------------------------------------
// ���̽� �ε��� ����ü
//--------------------------------------------------------------------------------------
struct Face_Index
{
	int iIndex[3];
	int	iSubMtrl;
};

//--------------------------------------------------------------------------------------
// �븻 ����ü
//--------------------------------------------------------------------------------------
struct VertexNormal
{
	TVector3 vFace;
	TVector3 vVertex[3];
};

//--------------------------------------------------------------------------------------
// ���͸��� ����ü
//--------------------------------------------------------------------------------------
struct TexMap
{
	int iType;
	T_STR name;
};

//--------------------------------------------------------------------------------------
// ���͸��� ����ü
//--------------------------------------------------------------------------------------
struct GeometryMaterial
{
	ComPtr<ID3D11ShaderResourceView>	m_pSRV;
	vector<TexMap>						m_texMap;
	vector<GeometryMaterial>			subMaterial;
	int									iNumSubMaterial;
};

//--------------------------------------------------------------------------------------
// �ִϸ��̼� Ʈ�� ����ü
//--------------------------------------------------------------------------------------
struct Animtrack
{
	int iTick;
	TVector3 vPos;
	TQuaternion vRot;
};

//--------------------------------------------------------------------------------------
// ������Ʈ ������ ����ü
//--------------------------------------------------------------------------------------
struct GeomObjectData
{
	//--------------------------------------------------------------------------------------
	// Vertex / Face / Texture / Color ���� / MESH_MTLID
	//--------------------------------------------------------------------------------------
	int						m_iMaterialRef;
	int						m_iNumVertex;		 // ���ؽ� 
	int						m_iNumFace;
	int						m_iNumTexVertex;	 // �ؽ���
	int						m_iNumTexFace;
	int						m_iNumColorVertex;	 // �÷�
	int						m_iNumColorFace;
	//--------------------------------------------------------------------------------------
	// ��� / �θ� / Ŭ���� �̸�
	//--------------------------------------------------------------------------------------
	wstring					m_szNodeName;
	wstring					m_szParentName;
	wstring					m_szClassName;
	//--------------------------------------------------------------------------------------
	// HELPEROBJECT �ٿ���ڽ� MIN / MAX
	//--------------------------------------------------------------------------------------
	TVector3				m_vMin;
	TVector3				m_vMax;
	//--------------------------------------------------------------------------------------
	// �� ����
	//--------------------------------------------------------------------------------------
	SceneFrame				m_Scene;
	//--------------------------------------------------------------------------------------
	// ���ؽ� ����Ʈ
	//--------------------------------------------------------------------------------------
	vector<TVector3>		m_VertexArray;
	//--------------------------------------------------------------------------------------
	// ���̽� �ε��� ����Ʈ
	//--------------------------------------------------------------------------------------
	vector<Face_Index>		m_FaceArray;
	//--------------------------------------------------------------------------------------
	// �ؽ�Ʈ ���ؽ� ����Ʈ
	//--------------------------------------------------------------------------------------
	vector<TVector3>		m_TexVertexArray;
	//--------------------------------------------------------------------------------------
	// �ؽ�Ʈ ���̽� ����Ʈ
	//--------------------------------------------------------------------------------------
	vector<Face_Index>		m_TexFaceArray;
	//--------------------------------------------------------------------------------------
	// �÷� ���ؽ� ����Ʈ
	//--------------------------------------------------------------------------------------
	vector<TVector3>		m_ColorVertexArray;
	//--------------------------------------------------------------------------------------
	// �÷� ���̽� ����Ʈ
	//--------------------------------------------------------------------------------------
	vector<Face_Index>		m_ColorFaceArray;
	//--------------------------------------------------------------------------------------
	// �븻 ����Ʈ
	//--------------------------------------------------------------------------------------
	vector<VertexNormal>	m_FaceNormalArray;
	//--------------------------------------------------------------------------------------
	// �ִϸ��̼� Ʈ��
	//--------------------------------------------------------------------------------------
	vector<Animtrack>		m_PosTrack;
	vector<Animtrack>		m_RotTrack;
	vector<Animtrack>		m_ScaleTrack;
	//--------------------------------------------------------------------------------------
	// �ִϸ��̼� ���
	//--------------------------------------------------------------------------------------
	TMatrix					m_matCaculation;
	TMatrix					m_matTrans;
	TMatrix					m_matScale;
	TMatrix					m_matRotation;
	TQuaternion				m_qRotation;
	TQuaternion				m_qScale;
};


class GeomObj :public Object
{
public:
	//--------------------------------------------------------------------------------------
	// ������Ʈ ������
	//--------------------------------------------------------------------------------------
	GeomObjectData				m_Object;
	//--------------------------------------------------------------------------------------
	// �θ� ��ü / �ε���
	//--------------------------------------------------------------------------------------
	GeomObj*					m_pParentObj;
	int							m_iParentID;
	//--------------------------------------------------------------------------------------
	// ������͸��� ������ ���Ǵ� ����Ʈ
	//--------------------------------------------------------------------------------------
	typedef vector<PNCT_VERTEX> SUBVERTEXLIST;
	vector<SUBVERTEXLIST>		m_subVertexList;
	typedef vector<DWORD>		SUBINDEXLIST;
	vector<SUBINDEXLIST>		m_subIndexList;
	vector<SUBVERTEXLIST>		m_subUniqueVertexList;
	//--------------------------------------------------------------------------------------
	// ��Ƽ ���� ����
	//--------------------------------------------------------------------------------------
	vector<ID3D11Buffer*>		m_VBArray;
	//--------------------------------------------------------------------------------------
	// ��Ƽ �ε��� ����
	//--------------------------------------------------------------------------------------
	vector<ID3D11Buffer*>		m_IBArray;
public:
	//-----------------------------------------------------------------------------------
	// ���� ���� ����
	//--------------------------------------------------------------------------------------
	HRESULT			CreateVertexBuffer();
	//--------------------------------------------------------------------------------------
	// �ε��� ���� ����
	//--------------------------------------------------------------------------------------
	HRESULT			CreateIndexBuffer();
	//--------------------------------------------------------------------------------------
	// ��� ���� ����
	//--------------------------------------------------------------------------------------
	HRESULT			CreateConstantBuffer();
	//--------------------------------------------------------------------------------------
	// ������͸��� ���� ����
	//--------------------------------------------------------------------------------------
	void			SetUniqueBuffers(vector<PNCT_VERTEX>& vertexArray, int iSub);
	//--------------------------------------------------------------------------------------
	// �ߺ� ���� üũ
	//--------------------------------------------------------------------------------------
	int				isEqualVertexList(vector<PNCT_VERTEX>& UniqueVertexArray, PNCT_VERTEX& vertex);
	//--------------------------------------------------------------------------------------
	// ����� ������ �Լ�
	//--------------------------------------------------------------------------------------
	bool			Render(ID3D11DeviceContext* pContext);
public:
	GeomObj();
	~GeomObj();
};