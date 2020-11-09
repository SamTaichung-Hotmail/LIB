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
	AUTOMALIB_API class MMotionArc :public MMotion
	{
	public:
		AUTOMALIB_API MMotionArc(MMotionLib *pLib);
		AUTOMALIB_API ~MMotionArc();
		AUTOMALIB_API virtual bool Motion()=0;
	protected:
	};

}
