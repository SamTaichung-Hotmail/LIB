#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "MotionLib.h"
// MMotion
namespace AutoLib {
	AUTOMALIB_API class MMotion
	{
	public:
		enum MotionType {
			Linear,
			Arc,
		};
		AUTOMALIB_API MMotion(MMotionLib *pLib);
		AUTOMALIB_API ~MMotion();
		AUTOMALIB_API virtual bool Motion()=0;
	protected:
		MMotionLib *m_pLib;
	};

}
