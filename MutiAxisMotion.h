#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include <stack>
#include "Motor.h"	
#include "MotionLib.h"	
#include "Motion.h"	
// MMutiAxisMotion
namespace AutoLib {
	AUTOMALIB_API class MMutiAxisMotion:public MBase
	{
	public:
		enum STEP {
			StartArc,
		};
		enum ScanStep {
			StartScan,
			CheckMotion,
			EndScan,
		};
		static UINT MMutiAxisMotion::DoThread(void * pM);
		AUTOMALIB_API MMutiAxisMotion(MBase *pB, CString strID, CString strName, int ErrorCodeBase = -1);
		AUTOMALIB_API ~MMutiAxisMotion();
		AUTOMALIB_API virtual bool ArcRMove(MMotor* pX, MMotor *pY, double CX, double CY, double EX, double EY, bool bCW, bool bContinueMode);
		AUTOMALIB_API virtual bool LineRMove(MMotor** pMotorAry, int MotorCount, double* pRMoveAry, bool bAccSpeed, bool bDesSpeed, MMotor** ppWaitMotorAry=NULL, short WaitMotorCount=0,bool bConstSpeed=false);
		AUTOMALIB_API virtual bool LineRMove(MMotor** pMotorAry, int MotorCount, double* pRMoveAry, double StartSpeed, double EndSpeed,double dblAccTime,double dblDecTime,MMotor** ppWaitMotorAry = NULL, short WaitMotorCount = 0, bool bConstSpeed = false);
		AUTOMALIB_API virtual int GetBufferCount();
		AUTOMALIB_API virtual bool PushMotionToBuffer(MMotion* pMotion);
		AUTOMALIB_API virtual bool BufferMotionStart();
		double m_dblScanTime;
	protected:
		ScanStep m_ScanStep;
		DWORD m_pThread;
		MMotion *m_pMotion;
		virtual bool ScanBuffer(const double dblTime);
		std::stack<MMotion*> m_stkMotionBuffer;
	};

}
