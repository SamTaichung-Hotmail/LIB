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

	MTimer *m_pTMOn;	//����Blink On�ɶ��Ϊ�Timer
	MTimer *m_pTMOff;	//����Blink Off�ɶ��Ϊ�Timer
	MIO *m_pIO;		//�Ψӱ��I/O
private:
	bool m_bBlink;
};
}//namespace AutoLib

