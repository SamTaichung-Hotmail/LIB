#pragma once
#pragma warning( disable : 4091)
#include <math.h>					
#include "MotionLib.h"
#include "ComPort.h"
#include <afxmt.h>
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#define MaxRecvBufferSize 1024
using namespace std;
namespace AutoLib {
	AUTOMALIB_API class MMotionLibCPASC :
		public MMotionLib
	{
	public:
		static UINT DoThread(void *);
		enum ComPortStep {
			cpsInit,
			cpsIdle,
			cpsAMove,
			cpsWaitResponse,
			cpsEnd,
		};
		AUTOMALIB_API MMotionLibCPASC(MBase *pB, CString MotorID, CString strName,MComPort *pComPort);
		AUTOMALIB_API ~MMotionLibCPASC();
		AUTOMALIB_API bool Init(MMotor* pMotor);
		bool m_bShutDown;
		AUTOMALIB_API void ComCycle(const double dblTime);

	protected:
		AUTOMALIB_API virtual bool AMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime,double dblPos);
		//AUTOMALIB_API virtual bool AMove2(MMotor* pMotor,
		//	double dblStartSpeed, double dblAccTime,
		//	double dblPos1, double dblSpeed1,
		//	double dblPos2, double dblSpeed2, double dblDesTime);
		//AUTOMALIB_API virtual bool RMove(MMotor* pMotor,
		//	double dblStartSpeed, double dblAccTime,
		//	double dblMaxSpeed, double dblDesTime, double dblDistance);
		//AUTOMALIB_API virtual bool VMove(MMotor* pMotor,
		//	double dblStartSpeed, double dblAccTime,
		//	double dblMaxSpeed);
		//AUTOMALIB_API virtual bool Stop(MMotor* pMotor, double dblDesTime);
		//AUTOMALIB_API virtual bool EStop(MMotor* pMotor);
		//AUTOMALIB_API virtual bool Home(MMotor* pMotor,
		//	double dblStartSpeed, double dblAccTime,
		//	double dblMaxSpeed, double dblOffset);
		//AUTOMALIB_API virtual bool isInp(MMotor* pMotor);				//馬達是否Inposition(定位訊號On)
		//AUTOMALIB_API virtual bool isOrg(MMotor* pMotor);				//馬達是否在原點上
		//AUTOMALIB_API virtual bool isEMG(MMotor* pMotor);				//馬達是否緊急停止中
		//AUTOMALIB_API virtual bool isEZ(MMotor* pMotor);				//馬達是否在EZ訊號上
		//AUTOMALIB_API virtual bool isPLim(MMotor* pMotor);				//馬達是否在正極限訊號上
		//AUTOMALIB_API virtual bool isMLim(MMotor* pMotor);				//馬達是否在負極限訊號上
		//AUTOMALIB_API virtual bool isSVOn(MMotor* pMotor);				//馬達是否Servo On
		//AUTOMALIB_API virtual bool isALM(MMotor* pMotor);				//是否ALM
		//AUTOMALIB_API virtual bool isRDY(MMotor* pMotor);				//是否ALM
		//AUTOMALIB_API virtual bool isMotion(MMotor* pMotor);			//是否馬達正在動	
		//AUTOMALIB_API virtual bool GetSpeed(MMotor* pMotor, double *pSpeed);
		//AUTOMALIB_API virtual bool GetPosition(MMotor* pMotor, double *pSpeed);
		//AUTOMALIB_API virtual void SetPosition(MMotor* pMotor, double Pos);	//設定位置
		//AUTOMALIB_API virtual bool GetCommand(MMotor* pMotor, double *pSpeed);//目前位置
		//AUTOMALIB_API virtual void SetCommand(MMotor* pMotor, double Pos);	//設定位置
		//AUTOMALIB_API virtual bool GetEncoder(MMotor* pMotor, double *pSpeed);//目前位置
		//AUTOMALIB_API virtual void SetEncoder(MMotor* pMotor, double Pos);	//設定位置
		//AUTOMALIB_API virtual WORD GetIOStatus(MMotor* pMotor);
		//AUTOMALIB_API virtual bool SetSVOn(MMotor* pMotor, bool isOn);	//設定是否要Server On
		//AUTOMALIB_API virtual bool SetDO(MMotor* pMotor, bool isOn);	//設定是否要Do On
		//AUTOMALIB_API virtual bool SetRST(MMotor* pMotor, bool isOn);
		//AUTOMALIB_API virtual bool GetDI(MMotor* pMotor);	//是否DI On
		//AUTOMALIB_API virtual void SetRingCount(MMotor* pMotor, bool bRing, double dblLenPerCycle);
		//AUTOMALIB_API virtual bool SetEMGLogic(MMotor* pMotor, bool bLogic);
		DWORD m_pThread;
		MComPort* m_pComPort;
		CEvent m_Event;
		ComPortStep m_cpStep;
		double m_dblScanTime;
		double m_dblRecvTimeOut;
		double m_dblStartSpeed,m_dblAccTime,m_dblMaxSpeed,m_dblDesTime,m_dblPos;
		byte m_byteRecv[MaxRecvBufferSize];
		int m_intRecvCount;
	};
}
