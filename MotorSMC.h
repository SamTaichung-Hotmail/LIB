
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
using namespace std;
#include <math.h>
#include "Base.h"				
#include "Motor.h"				
#include "MotionLib.h"

namespace AutoLib{
	AUTOMALIB_API class MMotorSMC : public MMotor
	{
	public:
		AUTOMALIB_API MMotorSMC(MBase *pB,CString MotorID,CString strName,MMotionLib* pMotion,CString strU,int ErrorCodeBase);
		AUTOMALIB_API virtual ~MMotorSMC();
		AUTOMALIB_API virtual void StepCycle(const double dblTime);	
		AUTOMALIB_API virtual void Stop();
		AUTOMALIB_API virtual bool Init();
		AUTOMALIB_API virtual bool Home();
	private:
		double m_dblDelayTime;
	};


}//namespace AutoLib
