#pragma once
#ifdef AUTOMADMC3000_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "MotionLib.h"
namespace AutoLib {
	AUTOMALIB_API class MMotionLibDMC3000 :
		public MMotionLib
	{
	public:
		AUTOMALIB_API MMotionLibDMC3000(MBase *pParent, CString strID, CString strName);
		AUTOMALIB_API ~MMotionLibDMC3000();
		AUTOMALIB_API bool Init(MMotor* pMotor);
	protected:
		AUTOMALIB_API int GetALMNo(MMotor* pMotor);
		AUTOMALIB_API bool ZeroMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime);
		AUTOMALIB_API bool AMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime, double dblPos);
		AUTOMALIB_API bool AMove2(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblPos1, double dblSpeed1,
			double dblPos2, double dblSpeed2, double dblDesTime);
		AUTOMALIB_API bool RMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime, double dblMove);
		AUTOMALIB_API virtual bool VMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed);
		AUTOMALIB_API bool Stop(MMotor* pMotor, double dblDesTime); //減速停止
		AUTOMALIB_API bool EStop(MMotor* pMotor); //緊急停止
		AUTOMALIB_API bool Home(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblOffset);
		AUTOMALIB_API bool isInp(MMotor* pMotor);				//馬達是否Inposition(定位訊號On)
		AUTOMALIB_API bool isOrg(MMotor* pMotor);				//馬達是否在原點上
		AUTOMALIB_API bool isEMG(MMotor* pMotor);				//馬達是否緊急停止中
		//AUTOMALIB_API bool isEZ(MMotor* pMotor);				//馬達是否在EZ訊號上
		AUTOMALIB_API bool isPLim(MMotor* pMotor);				//馬達是否在正極限訊號上
		AUTOMALIB_API bool isMLim(MMotor* pMotor);				//馬達是否在負極限訊號上
		AUTOMALIB_API bool isSVOn(MMotor* pMotor);				//馬達是否Servo On
		AUTOMALIB_API bool isALM(MMotor* pMotor);				//是否ALM
		AUTOMALIB_API bool isRDY(MMotor* pMotor);				//是否RDY
		AUTOMALIB_API bool isMotion(MMotor* pMotor);			//是否馬達正在動	
		AUTOMALIB_API bool GetSpeed(MMotor* pMotor, double *pSpeed);//目前速度
		AUTOMALIB_API bool GetPosition(MMotor* pMotor, double *pSpeed);//目前位置
		AUTOMALIB_API void SetPosition(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API bool GetCommand(MMotor* pMotor, double *pSpeed);//目前位置
		AUTOMALIB_API void SetCommand(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API bool GetEncoder(MMotor* pMotor, double *pSpeed);//目前位置
		AUTOMALIB_API void SetEncoder(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API WORD GetIOStatus(MMotor* pMotor);
		//AUTOMALIB_API bool SetDO(MMotor* pMotor, bool isOn);
		AUTOMALIB_API bool SetRST(MMotor* pMotor, bool isOn);
		AUTOMALIB_API bool SetSVOn(MMotor* pMotor, bool isOn);	//設定是否要Server On
		//AUTOMALIB_API bool SetAutoCompare(MMotor* pMotor, CompartFunction func) { return false; };
		//AUTOMALIB_API bool SetCompareMethod(MMotor* pMotor, int Method) { return false; };
		//AUTOMALIB_API bool SetCompareOut(MMotor* pMotor, int Logic, unsigned long DutyCount) { return false; };
		//AUTOMALIB_API bool BuildCompareFunction(MMotor* pMotor, double Start, double End, double Interval) { return false; };
		//AUTOMALIB_API bool BuildCompareTable(MMotor* pMotor, double *pTable, int count) { return false; };
		//AUTOMALIB_API bool GetCompareData(MMotor* pMotor, unsigned long *pTriggerCount, unsigned long *pTriggerPoint, double *pTriggerData) { return false; }
		//AUTOMALIB_API void SetRingCount(MMotor* pMotor, bool bRing, double dblLenPerCycle);
		//AUTOMALIB_API bool ChangeSpeedOnFly(MMotor* pMotor, double dblSpeed, double dblAccTime) { return false; };
		//AUTOMALIB_API bool LineRMove(MMotor** pMotorAry, int MotorCount, double *pRMoveAry,
		//	double StartVel, double MaxVel, double AccTime, double DesTime, MMotor** ppWaitMotorAry, short WaitMotorCount, bool bConstSpeed) {
		//	return false;
		//};
		//AUTOMALIB_API bool ArcRMove(MMotor* pXMotor, MMotor* pYMotor, double Cx, double Cy, double Ex, double Ey,
		//	short DIR, double StrVel, double MaxVel, double Tacc, double Tdec, MMotor** ppWaitMotorAry, short WaitMotorCount) {
		//	return false;
		//};
		//AUTOMALIB_API double GetLastDist(MMotor* pMotor) { return 0; };//目前位置
		//AUTOMALIB_API int GetFreeBufferSize(MMotor* pMotor) { return 0; };





		//AUTOMALIB_API bool GotoLimit(MMotor* pMotor, bool isP, bool bSlow = true) { return true; };
		//AUTOMALIB_API bool isHoming(MMotor* pMotor);			//馬達是否在復歸中
		//AUTOMALIB_API bool GetDI(MMotor* pMotor);				//是否DI ON
		//AUTOMALIB_API int GetStatusCode(MMotor* pMotor);		//取得狀態碼
		//AUTOMALIB_API bool SetCompareMethod(MMotor* pMotor, int Source, int Method) { return false; };
		//AUTOMALIB_API bool SetEMGLogic(MMotor* pMotor, bool bLogic);
		//AUTOMALIB_API int GetLastError(MMotor* pMotor) { return 0; };
	};
}
