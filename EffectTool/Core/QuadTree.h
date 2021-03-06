#pragma once
#include "MapLOD.h"

class QuadTree : public MapLOD
{
private:
	Node*			m_pRootNode;
	queue<Node*>	m_QuadTreeQueue;
	int				m_iMaxDepthLimit;
	int				m_iMinDivideSize;
	int				m_iMaxDepth;
	int				m_iNodeCount;
	int				m_iNumRow;
	int				m_iNumCol;
public:
	enum QUADTREECORNER { TOP_LEFT = 0, TOP_RIGHT = 1, BOTTOM_LEFT = 2, BOTTOM_RIGHT = 3, };
public:
	//--------------------------------------------------------------------------------------
	// Create Node
	//--------------------------------------------------------------------------------------
	Node*			CreateNode(Node* pParent, float fTopLeft, float fTopRight, float fBottomLeft, float fBottomRight);
	//--------------------------------------------------------------------------------------
	// Delete Node
	//--------------------------------------------------------------------------------------
	bool			DeleteNode(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Build
	//--------------------------------------------------------------------------------------
	bool			Build(float fWidth, float fHeight);
	//--------------------------------------------------------------------------------------
	// Create QuadTree
	//--------------------------------------------------------------------------------------
	virtual bool	BuildTree(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Divide space
	//--------------------------------------------------------------------------------------
	virtual bool	SubDivide(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Set neighbor node
	//--------------------------------------------------------------------------------------
	void			SetNeighborNode(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Find neighbor node
	//--------------------------------------------------------------------------------------
	void			FindNeighborNode(Node* pNode);
	//--------------------------------------------------------------------------------------
	// Find node
	//--------------------------------------------------------------------------------------
	Node*			FindNodeInQuadTree(Node* pNode, Object* object);
	//--------------------------------------------------------------------------------------
	// Add object in quadtree
	//--------------------------------------------------------------------------------------
	bool			AddInQuadTree(Node* pNode, Object* pObject);
	//--------------------------------------------------------------------------------------
	// Delete an object from the list of objects in a node
	//--------------------------------------------------------------------------------------
	bool			DeleteObject(Node* pNode, Object* pObject);
	//--------------------------------------------------------------------------------------
	// Update
	//--------------------------------------------------------------------------------------
	bool			UpdateQuadTree(Object* pObject);
	//--------------------------------------------------------------------------------------
	// Split size calculation function
	//--------------------------------------------------------------------------------------
	DWORD			CheckSize(DWORD dwSize);
	//--------------------------------------------------------------------------------------
	// Render
	//--------------------------------------------------------------------------------------
	bool			Render();
	//--------------------------------------------------------------------------------------
	// Release
	//--------------------------------------------------------------------------------------
	bool			Release();
	//--------------------------------------------------------------------------------------
	// Set Function
	//--------------------------------------------------------------------------------------
	void			SetMaxDepth(int iDepth);
	void			SetRootNode(Node* pNode);
	void			SetRowCount(const int iRowNum);
	void			SetColumnCount(const int iColNum);
	//--------------------------------------------------------------------------------------
	// Get Function
	//--------------------------------------------------------------------------------------
	Node*			GetRootNode();
	vector<RECT>	GetLeafNodePosition();
	int				GetMaxDepth();
	int				GetRowCount();
	int				GetColumnCount();
	int				GetMinDivideSize();
	int				GetMaxDepthLimit();
public:
	QuadTree();
	~QuadTree();
};

