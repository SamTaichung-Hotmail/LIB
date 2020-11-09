#pragma once
#include <math.h>					
#include "MotionLib.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
using namespace std;
namespace AutoLib {
	AUTOMALIB_API class MMotionLib6045 :
		public MMotionLib
	{
	public:
		AUTOMALIB_API MMotionLib6045(MBase *pB, CString MotorID, CString strName);
		AUTOMALIB_API ~MMotionLib6045();
		AUTOMALIB_API bool Init(MMotor* pMotor);
		
	protected:
		AUTOMALIB_API virtual int GetALMNo(MMotor* pMotor);
		AUTOMALIB_API virtual bool ZeroMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime);
		AUTOMALIB_API virtual bool AMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime,double dblPos);
		AUTOMALIB_API virtual bool AMove2(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblPos1, double dblSpeed1,
			double dblPos2, double dblSpeed2, double dblDesTime);
		AUTOMALIB_API virtual bool RMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime, double dblDistance);
		AUTOMALIB_API virtual bool VMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed);
		AUTOMALIB_API virtual bool Stop(MMotor* pMotor, double dblDesTime);
		AUTOMALIB_API virtual bool EStop(MMotor* pMotor);
		AUTOMALIB_API virtual bool Home(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblOffset);
		AUTOMALIB_API virtual bool isInp(MMotor* pMotor);				//馬達是否Inposition(定位訊號On)
		AUTOMALIB_API virtual bool isOrg(MMotor* pMotor);				//馬達是否在原點上
		AUTOMALIB_API virtual bool isEMG(MMotor* pMotor);				//馬達是否緊急停止中
		AUTOMALIB_API virtual bool isEZ(MMotor* pMotor);				//馬達是否在EZ訊號上
		AUTOMALIB_API virtual bool isPLim(MMotor* pMotor);				//馬達是否在正極限訊號上
		AUTOMALIB_API virtual bool isMLim(MMotor* pMotor);				//馬達是否在負極限訊號上
		AUTOMALIB_API virtual bool isSVOn(MMotor* pMotor);				//馬達是否Servo On
		AUTOMALIB_API virtual bool isALM(MMotor* pMotor);				//是否ALM
		AUTOMALIB_API virtual bool isRDY(MMotor* pMotor);				//是否ALM
		AUTOMALIB_API virtual bool isMotion(MMotor* pMotor);			//是否馬達正在動	
		AUTOMALIB_API virtual bool GetSpeed(MMotor* pMotor, double *pSpeed);
		AUTOMALIB_API virtual bool GetPosition(MMotor* pMotor, double *pSpeed);
		AUTOMALIB_API virtual void SetPosition(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API virtual bool GetCommand(MMotor* pMotor, double *pSpeed);//目前位置
		AUTOMALIB_API virtual void SetCommand(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API virtual bool GetEncoder(MMotor* pMotor, double *pSpeed);//目前位置
		AUTOMALIB_API virtual void SetEncoder(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API virtual WORD GetIOStatus(MMotor* pMotor);
		AUTOMALIB_API virtual bool SetDO(MMotor* pMotor, bool isOn);
		AUTOMALIB_API virtual bool SetRST(MMotor* pMotor, bool isOn);
		AUTOMALIB_API virtual bool SetSVOn(MMotor* pMotor, bool isOn);	//設定是否要Server On
		AUTOMALIB_API virtual bool SetAutoCompare(MMotor* pMotor, CompartFunction func); //0:disable 1:fifo 2:function 3:table
		AUTOMALIB_API virtual bool SetCompareMethod(MMotor* pMotor, int Source, int Method);
		AUTOMALIB_API virtual bool SetCompareOut(MMotor* pMotor, int Logic, unsigned long DutyCount);
		AUTOMALIB_API virtual bool BuildCompareFunction(MMotor* pMotor, double Start, double End, double Interval);
		AUTOMALIB_API virtual bool BuildCompareTable(MMotor* pMotor, double *pTable, int count);
		AUTOMALIB_API virtual bool GetCompareData(MMotor* pMotor, unsigned long *pTriggerCount, unsigned long *pTriggerPoint, double *pTriggerData);
		AUTOMALIB_API virtual void SetRingCount(MMotor* pMotor, bool bRing, double dblLenPerCycle);
		AUTOMALIB_API virtual bool ChangeSpeedOnFly(MMotor* pMotor, double dblSpeed, double dblAccTime);
		AUTOMALIB_API virtual bool LineRMove(MMotor** pMotorAry, int MotorCount, double *pRMoveAry,
			double StartVel, double MaxVel, double AccTime, double DesTime, MMotor** ppWaitMotorAry = NULL, short WaitMotorCount = 0,bool bConstSpeed=false);
		AUTOMALIB_API virtual bool ArcRMove(MMotor* pXMotor, MMotor* pYMotor, double Cx, double Cy
			, double Ex, double Ey, short DIR, double StrVel, double MaxVel, double Tacc, double Tdec, MMotor** ppWaitMotorAry = NULL, short WaitMotorCount = 0);
		AUTOMALIB_API virtual double GetLastDist(MMotor* pMotor);
		AUTOMALIB_API int GetFreeBufferSize(MMotor* pMotor);

	};
}
