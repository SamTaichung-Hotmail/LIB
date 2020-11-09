#pragma once
#pragma warning( disable : 4091)

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Base.h"				
#define bit_RDY			0x0001
#define bit_ALM			0x0002
#define bit_PEL			0x0004
#define bit_MEL			0x0008
#define bit_ORG			0x0010
#define bit_DIR			0x0020
#define bit_EMG			0x0040
#define bit_PCS			0x0080
#define bit_ERC			0x0100
#define bit_EZ			0x0200
#define bit_Latch		0x0800
#define bit_SD			0x1000
#define bit_INP			0x2000
#define bit_SVON		0x4000
namespace AutoLib{
	class MMotor;
	AUTOMALIB_API class MMotionLib : public MBase
	{
	public:
		enum CompartFunction{
			cfDisable,
			cfFIFO,
			cfFunction,
			cfTable,
		};
		AUTOMALIB_API MMotionLib(MBase *pParent,CString strID,CString strName);
		AUTOMALIB_API virtual ~MMotionLib();
		AUTOMALIB_API virtual bool Init() { return MBase::Init(); };
		AUTOMALIB_API virtual bool Init(MMotor* pMotor)=0;
		AUTOMALIB_API virtual bool Stop(MMotor* pMotor, double dblDesTime)=0; //減速停止
		AUTOMALIB_API virtual bool EStop(MMotor* pMotor)=0; //緊急停止
		AUTOMALIB_API virtual bool ZeroMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime) = 0;
		AUTOMALIB_API virtual bool AMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime, double dblPos) = 0;
		AUTOMALIB_API virtual bool AMove2(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblPos1,double dblSpeed1,
			double dblPos2,double dblSpeed2, double dblDesTime) = 0;
		AUTOMALIB_API virtual bool RMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime, double dblMove)=0;
		AUTOMALIB_API virtual bool VMove(MMotor* pMotor, double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed){ return true; };
		AUTOMALIB_API virtual bool Home(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblOffset) = 0;
		AUTOMALIB_API virtual bool GotoLimit(MMotor* pMotor, bool isP, bool bSlow = true){ return true; };
		AUTOMALIB_API virtual bool isMotion(MMotor* pMotor);			//是否馬達正在動	
		AUTOMALIB_API virtual bool isHoming(MMotor* pMotor);			//馬達是否在復歸中
		AUTOMALIB_API virtual bool isInp(MMotor* pMotor);				//馬達是否Inposition(定位訊號On)
		AUTOMALIB_API virtual bool isOrg(MMotor* pMotor);				//馬達是否在原點上
		AUTOMALIB_API virtual bool isEMG(MMotor* pMotor);				//馬達是否緊急停止中
		AUTOMALIB_API virtual bool isEZ(MMotor* pMotor);				//馬達是否在EZ訊號上
		AUTOMALIB_API virtual bool isPLim(MMotor* pMotor);				//馬達是否在正極限訊號上
		AUTOMALIB_API virtual bool isMLim(MMotor* pMotor);				//馬達是否在負極限訊號上
		AUTOMALIB_API virtual bool isSVOn(MMotor* pMotor);				//馬達是否Servo On
		AUTOMALIB_API virtual bool isALM(MMotor* pMotor);				//是否ALM
		AUTOMALIB_API virtual bool isRDY(MMotor* pMotor);				//是否ALM
		AUTOMALIB_API virtual bool GetDI(MMotor* pMotor);				//是否DI ON
		AUTOMALIB_API virtual bool GetSpeed(MMotor* pMotor, double *pSpeed)=0;//目前速度
		AUTOMALIB_API virtual double GetLastDist(MMotor* pMotor) { return 0; };//目前位置
		AUTOMALIB_API virtual bool GetPosition(MMotor* pMotor, double *pSpeed) = 0;//目前位置
		AUTOMALIB_API virtual void SetPosition(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API virtual bool GetCommand(MMotor* pMotor, double *pSpeed) = 0;//目前位置
		AUTOMALIB_API virtual void SetCommand(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API virtual bool GetEncoder(MMotor* pMotor, double *pSpeed) = 0;//目前位置
		AUTOMALIB_API virtual void SetEncoder(MMotor* pMotor, double Pos);	//設定位置
		AUTOMALIB_API virtual bool SetSVOn(MMotor* pMotor, bool isOn);	//設定是否要Server On
		AUTOMALIB_API virtual double GetCurrent(MMotor* pMotor);	//設定是否要Server On
		AUTOMALIB_API virtual bool SetCurrent(MMotor* pMotor, double dblCurrent);	//設定是否要Server On
		AUTOMALIB_API virtual int GetALMNo(MMotor* pMotor);
		AUTOMALIB_API virtual WORD GetIOStatus(MMotor* pMotor)=0;
		AUTOMALIB_API virtual int GetStatusCode(MMotor* pMotor);		//取得狀態碼
		AUTOMALIB_API virtual bool SetDO(MMotor* pMotor, bool isOn) { return false; };	
		AUTOMALIB_API virtual bool SetRST(MMotor* pMotor, bool isOn) { return false; };
		AUTOMALIB_API virtual bool SetCompareMethod(MMotor* pMotor, int Method) { return false; };
		AUTOMALIB_API virtual bool SetAutoCompare(MMotor* pMotor, CompartFunction func) { return false; };
		AUTOMALIB_API virtual bool SetCompareMethod(MMotor* pMotor, int Source, int Method){ return false; };
		AUTOMALIB_API virtual bool SetCompareOut(MMotor* pMotor, int Logic, unsigned long DutyCount){ return false; };
		AUTOMALIB_API virtual bool BuildCompareFunction(MMotor* pMotor, double Start, double End, double Interval){ return false; };
		AUTOMALIB_API virtual bool BuildCompareTable(MMotor* pMotor, double *pTable, int count){ return false; };
		AUTOMALIB_API virtual bool GetCompareData(MMotor* pMotor, unsigned long *pTriggerCount, unsigned long *pTriggerPoint, double *pTriggerData){ return false; }
		AUTOMALIB_API virtual void SetRingCount(MMotor* pMotor, bool bRing, double dblLenPerCycle);
		AUTOMALIB_API virtual bool SetEMGLogic(MMotor* pMotor, bool bLogic);
		AUTOMALIB_API virtual bool ChangeSpeedOnFly(MMotor* pMotor, double dblSpeed, double dblAccTime) { return false; };
		AUTOMALIB_API virtual bool LineRMove(MMotor** pMotorAry, int MotorCount, double *pRMoveAry,
			double StartVel, double MaxVel, double AccTime, double DesTime, MMotor** ppWaitMotorAry, short WaitMotorCount,bool bConstSpeed) {return false;};
		AUTOMALIB_API virtual bool ArcRMove(MMotor* pXMotor, MMotor* pYMotor, double Cx, double Cy, double Ex, double Ey,
			short DIR, double StrVel, double MaxVel, double Tacc, double Tdec, MMotor** ppWaitMotorAry, short WaitMotorCount) {
			return false;
		};
		AUTOMALIB_API virtual int GetLastError(MMotor* pMotor) { return 0; };
		AUTOMALIB_API virtual int GetFreeBufferSize(MMotor* pMotor) { return 0; };
	};

}//namespace AutoLib
