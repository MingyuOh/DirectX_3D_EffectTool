#pragma once
#include <windows.h>

class Timer
{
private:
	//--------------------------------------------------------------------------------------
	// 타이머 변수
	//--------------------------------------------------------------------------------------
	LARGE_INTEGER	m_Frequency;			// 초당 주파수 
	LARGE_INTEGER	m_Current;				// 현재 시간
	LARGE_INTEGER   m_Frame;				// 이전 프레임의 시간 체크 (계속 흘러가는 시간)
	float			m_fSecPerFrame;			// 프레임 경과 시간
	
	LARGE_INTEGER	m_FPS;					// FPS 체크 타이머
	int				m_iFramePerSecond;		// 초당 프레임
	int				m_iFPSElapse;			// 초당 경과된 프레임
	//--------------------------------------------------------------------------------------
	// 이벤트 변수
	//--------------------------------------------------------------------------------------

public:
	//--------------------------------------------------------------------------------------
	// 엔진함수 사용자 재정의
	//--------------------------------------------------------------------------------------
	bool	Init();
	bool	Frame();
	bool	Render();
	bool	Release();

	//--------------------------------------------------------------------------------------
	// 경과한 시간에 대한 지원 함수
	//--------------------------------------------------------------------------------------
	void	Reset();
	void	Start();
	void	Stop();
	bool	IsStarted() const;

	//--------------------------------------------------------------------------------------
	// Get함수
	//--------------------------------------------------------------------------------------
	float	GetElapsedTime();
	int		GetFPS();
	float	GetSPF();
public:
	Timer();
	~Timer();
};

