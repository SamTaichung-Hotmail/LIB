#pragma once
#pragma warning( disable : 4091)
#include "IO.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
AUTOMALIB_API class MButtonEvent
{
public:
	enum ButtonEvenCode {
		becNone,
		becClick,
		becLongPress,
		becOff,
	};
	AUTOMALIB_API MButtonEvent(MIO *pIO,int intKeyIndex);
	AUTOMALIB_API ~MButtonEvent(void);
	AUTOMALIB_API void Reset(void);
	AUTOMALIB_API ButtonEvenCode GetEventCode(void);
	AUTOMALIB_API MIO* GetEventIO(void);
	AUTOMALIB_API int GetKeyIndex(void);
private:
	LARGE_INTEGER m_nStartTime, m_nStopTime, m_nFrequency;
	ButtonEvenCode m_EventCode;
	MIO *m_pIOButton;
	int m_intKeyIndex;
	bool m_bPressed;
	bool m_bLongPressed;
	bool m_bLastPressed;
};
}//namespace AutoLib