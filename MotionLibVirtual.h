#pragma once
#pragma warning( disable : 4091)
#include <math.h>					
#include "MotionLib.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
using namespace std;
namespace AutoLib {
	AUTOMALIB_API class MMotionLibVirtual :
		public MMotionLib
	{
		enum Step {
			stpDone,
			stpAcc,
			stpDec,
			stpHiSpeed,
		};
		struct VirtualMotionData{
			bool m_bAMove;
			double m_dblMaxSpeed, m_dblStartSpeed;
			double m_dblAccTime, m_dblDesTime;
			double m_dblPos;
		};
		struct VirtualMotorData {
			double m_dblLastDist, m_dblTargetPos, m_dblCalSpeed;
			double m_dblMaxSpeed, m_dblStartSpeed;
			double m_dblAccTime,m_dblDesTime;
			double m_dblPos;
			Step m_mvStep;
			bool m_bSVOn;
			bool m_bRingCount;
			double m_dblLenPerCycle;
			CArray<VirtualMotionData> m_MotionDatas;
		};
	public:
		AUTOMALIB_API MMotionLibVirtual(MBase *pB, CString MotorID, CString strName, int AxisCount);
		AUTOMALIB_API ~MMotionLibVirtual();
		AUTOMALIB_API bool Init(MMotor* pMotor);
		AUTOMALIB_API void Cycle(const double dblTime);
		AUTOMALIB_API bool isMotion(MMotor* pMotor);
		AUTOMALIB_API bool GetSpeed(MMotor* pMotor,double *pSpeed);
		AUTOMALIB_API bool GetPosition(MMotor* pMotor, double *pPosition);
		AUTOMALIB_API void SetPosition(MMotor* pMotor, double Pos);
		AUTOMALIB_API bool GetCommand(MMotor* pMotor, double *pPosition);
		AUTOMALIB_API void SetCommand(MMotor* pMotor, double Pos);
		AUTOMALIB_API bool GetEncoder(MMotor* pMotor, double *pPosition);
		AUTOMALIB_API void SetEncoder(MMotor* pMotor, double Pos);
		AUTOMALIB_API bool isOrg(MMotor* pMotor);
		AUTOMALIB_API WORD GetIOStatus(MMotor* pMotor);
		AUTOMALIB_API bool SetDO(MMotor* pMotor, bool isOn);			//設定是否要Do On
		AUTOMALIB_API bool SetSVOn(MMotor* pMotor,bool isOn);		//設定是否要SVOn
		AUTOMALIB_API bool isSVOn(MMotor* pMotor);							//馬達是否Servo On
		AUTOMALIB_API void SetRingCount(MMotor* pMotor, bool bRing, double dblLenPerCycle);
		AUTOMALIB_API virtual bool LineRMove(MMotor** pMotorAry, int MotorCount, double *pRMoveAry,
			double StartVel, double MaxVel, double AccTime, double DesTime , MMotor** ppWaitMotorAry = NULL, short WaitMotorCount = 0);
		AUTOMALIB_API virtual bool ArcRMove(MMotor* pXMotor, MMotor* pYMotor, double Cx, double Cy,
			double Ex, double Eyshort ,short DIR, double StrVel, double MaxVel, double Tacc, double Tdec,
			MMotor** ppWaitMotorAry = NULL, short WaitMotorCount = 0);

	protected:
		bool ZeroMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime);
		bool AMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime,double dblPos);
		bool AMove2(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblPos1, double dblSpeed1,
			double dblPos2, double dblSpeed2, double dblDesTime);
		bool RMove(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblDesTime, double dblMove);
		bool Stop(MMotor* pMotor, double dblDesTime);
		bool EStop(MMotor* pMotor);
		bool Home(MMotor* pMotor,
			double dblStartSpeed, double dblAccTime,
			double dblMaxSpeed, double dblOffset);
		bool VMove(MMotor* pMotor, bool isP, double sp = 0) { return true; };
		bool GotoLimit(MMotor* pMotor, bool isP, bool bSlow = true) { return true; };
		int GetMotorIndex(MMotor* pMotor);
		int m_intMotorInitCount;
		CArray<VirtualMotorData*> m_AxisArray;
		map<MMotor*, int> m_mapMotorIndex;
	};
}
