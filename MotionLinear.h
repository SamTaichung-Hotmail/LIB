#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Motion.h"
// MMotion
namespace AutoLib {
	AUTOMALIB_API class MMotionLinear:public MMotion
	{
	public:
		AUTOMALIB_API MMotionLinear(MMotionLib *pLib);
		AUTOMALIB_API ~MMotionLinear();
		AUTOMALIB_API virtual bool Motion()=0;
	protected:
	};

}
