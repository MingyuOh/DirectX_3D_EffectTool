#pragma once
#include <windows.h>

class Timer
{
private:
	//--------------------------------------------------------------------------------------
	// Ÿ�̸� ����
	//--------------------------------------------------------------------------------------
	LARGE_INTEGER	m_Frequency;			// �ʴ� ���ļ� 
	LARGE_INTEGER	m_Current;				// ���� �ð�
	LARGE_INTEGER   m_Frame;				// ���� �������� �ð� üũ (��� �귯���� �ð�)
	float			m_fSecPerFrame;			// ������ ��� �ð�
	
	LARGE_INTEGER	m_FPS;					// FPS üũ Ÿ�̸�
	int				m_iFramePerSecond;		// �ʴ� ������
	int				m_iFPSElapse;			// �ʴ� ����� ������
	//--------------------------------------------------------------------------------------
	// �̺�Ʈ ����
	//--------------------------------------------------------------------------------------

public:
	//--------------------------------------------------------------------------------------
	// �����Լ� ����� ������
	//--------------------------------------------------------------------------------------
	bool	Init();
	bool	Frame();
	bool	Render();
	bool	Release();

	//--------------------------------------------------------------------------------------
	// ����� �ð��� ���� ���� �Լ�
	//--------------------------------------------------------------------------------------
	void	Reset();
	void	Start();
	void	Stop();
	bool	IsStarted() const;

	//--------------------------------------------------------------------------------------
	// Get�Լ�
	//--------------------------------------------------------------------------------------
	float	GetElapsedTime();
	int		GetFPS();
	float	GetSPF();
public:
	Timer();
	~Timer();
};
