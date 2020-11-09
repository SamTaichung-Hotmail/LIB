
#pragma once


// MPulseIO ©R¥O¥Ø¼Ð
#include "IO.h"
#include "Timer.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib{	
	class MPulseIO : public MBase
{
	enum STEP {
		stpPulseOn,
		stpWaitTimeOff,
	};
public:
	AUTOMALIB_API MPulseIO(MBase *pB,CString strID,CString strName);
	AUTOMALIB_API virtual ~MPulseIO();
	AUTOMALIB_API void Pulse();
	AUTOMALIB_API void StepCycle(const double dblTime);
	AUTOMALIB_API bool GetIOValue();
	AUTOMALIB_API void SetIOValue(bool blV);
	AUTOMALIB_API void SetOnTime(double dbTimer);
	MIO * m_pIO;
	MTimer *m_pOnTimer;
};

}//namespace AutoLib
