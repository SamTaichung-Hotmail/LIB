#pragma once
#pragma warning( disable : 4091)
#include "Timer.h"
#include "IO.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

namespace AutoLib {
AUTOMALIB_API class MFlash : public MBase
{
	enum STEP {
		stpBlink,
		stpOn,
		stpOff,
	};
public:
	AUTOMALIB_API MFlash(MBase *pB,CString strID,CString strName);
	~MFlash();
	//-------------------override--------------------------
	AUTOMALIB_API void StepCycle(const double dblTime);
	//-------------------member function--------------------
	AUTOMALIB_API void DoOn(void);
	AUTOMALIB_API void DoOff(void);
	AUTOMALIB_API void DoBlink(void);

	MTimer *m_pTMOn;	//控制Blink On時間用的Timer
	MTimer *m_pTMOff;	//控制Blink Off時間用的Timer
	MIO *m_pIO;		//用來控制的I/O
private:
	bool m_bBlink;
};
}//namespace AutoLib

