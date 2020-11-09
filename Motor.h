
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
using namespace std;
#include <math.h>
#include "Base.h"				
#include "Timer.h"				
#include "IO.h"				
#include "MotionLib.h"
#include "TimeCounter.h"
#ifndef PI
	#define PI 3.141592654
#endif

namespace AutoLib{
	class MMotorCalculate;
	AUTOMALIB_API class MMotor : public MBase
	{
	public:
		enum MotorSpeedSelect
		{
			mssHiSpeed,
			mssLoSpeed
		};
		enum AMoveReferenceSource {
			arsEncorder,
			arsCommand, 
			arsCountSource,
		};
		friend MMotorCalculate;
		friend MMotionLib;
		AUTOMALIB_API MMotor(MBase *pB,CString MotorID,CString strName,MMotionLib* pMotion,CString strU,int ErrorCodeBase);
		AUTOMALIB_API virtual ~MMotor();
		//----------------------------------------------------------------------
		AUTOMALIB_API virtual bool Init();
		AUTOMALIB_API virtual void Cycle(const double dblTime);
		AUTOMALIB_API virtual void StepCycle(const double dblTime);
		AUTOMALIB_API virtual void EStop(const bool isES);
		AUTOMALIB_API virtual void Stop();
		AUTOMALIB_API virtual bool GetAllowToPause();				//�O�_�i�H�Ȱ��ʧ@
		AUTOMALIB_API virtual void SaveMachineData(CADOConnection * pC, bool bAllChildsSave = true);
		AUTOMALIB_API virtual void LoadMachineData(CADOConnection * pC, bool bAllChildsLoad = true);
		//------------------------------------------------------------------------
		AUTOMALIB_API virtual void SetCalObject(MMotorCalculate *pMC);
		AUTOMALIB_API virtual MMotorCalculate* GetCalObject(){return m_pMotorCalculate;};
		AUTOMALIB_API virtual bool ZeroMove(double StartSpeed = 0, double MaxSpeed = 0);  //sp:�t��,�w�]0�O��m_intSpeedSelect=0��m_HiSpeed,m_intSpeedSelect=1�ɬ�m_LoSpeed
		AUTOMALIB_API virtual bool AMove(double Pos, double StartSpeed = 0, double MaxSpeed = 0);  //sp:�t��,�w�]0�O��m_intSpeedSelect=0��m_HiSpeed,m_intSpeedSelect=1�ɬ�m_LoSpeed
		AUTOMALIB_API virtual bool AMove2(double Pos1, double Pos2,bool bAccSpeed=true);  //sp:�t��,�w�]0�O��m_intSpeedSelect=0��m_HiSpeed,m_intSpeedSelect=1�ɬ�m_LoSpeed
		AUTOMALIB_API virtual double GetAMoveTarget() { return m_dblAMove; };
		AUTOMALIB_API virtual bool RMove(double Distance, double StartSpeed = 0, double MaxSpeed = 0);  //sp:�t��,�w�]0�O��m_intSpeedSelect=0��m_HiSpeed,m_intSpeedSelect=1�ɬ�m_LoSpeed
		AUTOMALIB_API virtual double GetRMoveDistance() { return m_dblRMove; };
		AUTOMALIB_API virtual bool RPulse(int r=1);
		AUTOMALIB_API virtual bool GotoP(bool bSlow=true);//0831 ���� P Limit
		AUTOMALIB_API virtual bool GotoM(bool bSlow=true);//0831 ���� M Limit
		AUTOMALIB_API virtual bool ExitLimit();			//0831 ���} Limit
		AUTOMALIB_API virtual bool Home();				//�_�k
		AUTOMALIB_API virtual bool isMotion();			//�O�_���F���b��
		AUTOMALIB_API virtual bool isHoming();			//���F�O�_�b�_�k��
		AUTOMALIB_API virtual bool isInp();				//���F�O�_Inposition(�w��T��On)
		AUTOMALIB_API virtual bool isOrg();				//���F�O�_�b���I�W
		AUTOMALIB_API virtual bool isEMG();				//���F�O�_��氱�
		AUTOMALIB_API virtual bool isEZ();				//���F�O�_�bEZ�T���W
		AUTOMALIB_API virtual bool isPLim();				//���F�O�_�b�������T���W
		AUTOMALIB_API virtual bool isMLim();				//���F�O�_�b�t�����T���W
		AUTOMALIB_API virtual bool isSVOn();				//���F�O�_Servo On
		AUTOMALIB_API virtual bool isALM();					//�O�_ALM
		AUTOMALIB_API virtual bool isRDY();					//�O�_RDY
		AUTOMALIB_API virtual bool ResetALM();				//Reset ALM
		AUTOMALIB_API virtual double GetLastDist();//�ثe��m
		AUTOMALIB_API virtual double GetPosition();			//�ثe��m
		AUTOMALIB_API virtual double GetCommandPos();		//�ثe��m
		AUTOMALIB_API virtual double GetEncoderPos();		//�ثe��m
		AUTOMALIB_API virtual double GetSpeed();			//�ثe�t��
		AUTOMALIB_API virtual void SetPosition(double);		//�]�w��m
		AUTOMALIB_API virtual bool SetSVOn(bool isOn);		//�]�w�O�_�nServer On
		AUTOMALIB_API virtual bool SetCurrent(double dblCurrent);
		AUTOMALIB_API virtual double GetCurrent(); 
		AUTOMALIB_API virtual WORD GetIOStatus();			//���o�b������/RDY/Alm/Org...
		AUTOMALIB_API virtual int GetALMNo(); //���oALM�X
		AUTOMALIB_API virtual int GetStatusCode(){ return 0; }; //���o���A�X
		AUTOMALIB_API virtual bool GetMotorHomeComplete(void);
		AUTOMALIB_API virtual void SetMotorHomeComplete(bool bComplete);
		AUTOMALIB_API virtual bool VMove(double p, bool bMove);
		AUTOMALIB_API virtual double TransPosToPulse(double Pos); //�����m��Pulse���
		AUTOMALIB_API virtual bool ChangeSpeedOnFly(double dblSpeed, double dblAccTime);
		AUTOMALIB_API bool Repeat();
		AUTOMALIB_API bool Segment();
		AUTOMALIB_API bool SoftLimitCheck(double dbPos);
		AUTOMALIB_API bool SetOperateSpeed(int SpeedSelect); //0�GHiSpeed 1:LoSpeed
		AUTOMALIB_API void SetSpeedRate(double dblRate); //1=100% 0.5=50%
		AUTOMALIB_API double GetSpeedRate(); //1=100% 0.5=50%
		AUTOMALIB_API MMotionLib* GetMotionLib();
		AUTOMALIB_API void SetRingCount(bool bRing, double dblLenPerCycle);
		AUTOMALIB_API void SetAMoveReference(AMoveReferenceSource arsSource);
		AUTOMALIB_API AMoveReferenceSource GetAMoveReference();
		AUTOMALIB_API virtual int GetFreeBufferSize();
		AUTOMALIB_API virtual bool GetAlarmLatched();
		AUTOMALIB_API virtual void ResetAlarmLatched();
		AUTOMALIB_API virtual bool GetSVOffLatched();
		AUTOMALIB_API virtual void ResetSVOffLatched();
		MTimer *m_pTMHome;
		CTimeCounter m_tmDoOn;
		CTimeCounter m_tmHomeStable;
		bool m_bMoveDir;
		double m_dblTargetPos,m_dblStartSpeed;
		double m_dblSpeedRate;
		double m_FASpeed,m_HiSpeed,m_LoSpeed,m_HomeSpeed,m_HiAccTime,m_P1,m_P2,m_Delay,m_JogPitch,
				m_HiDesTime,m_LoAccTime,m_LoDesTime,m_HomeAccTime,m_HomeDesTime,m_HomeOffset,
				m_Repeat,m_RepeatDir,m_PMax,m_MMax,m_UnitRev,m_PulseRev,m_Coefficient;
		bool m_AxisDir,m_HomeDir,m_SVOnLogic,m_ALMLogic,m_OrgLogic,m_PLimLogic,m_MLimLogic
			, m_INPLogic, m_INPEnable, m_SDLogic, m_LTCLogic, m_EncoderLogic,m_EZLogic,m_RSTLogic,m_ERCLogic,m_RDYLogic;
		bool m_bSCurve;
		bool m_bHomeTurnOnDo;
		long m_intSpeedSelect, m_intPitchSelect, m_HomeMode, m_RepeatCount;
		int m_intSegmentCount;
		unsigned short m_CardID,m_ConnectID,m_StationID,m_AxisID;
		int m_PulseMode, m_CountSource, m_ALMMode, m_EZCount, m_SDMode, m_LTCMode, m_EncoderMode, m_AMoveSource;
		CString m_Unit;
		CTimeCounter m_tcRepeat;
		enum RSTSTEP{
					StartRstOn,
					RstComplete,
		};
		enum STEP {
					STARTHOME,
					PREHOME,
					WAITDO,
					WAITHOME,
					STARTHOMEOFFSET,
					WAITHOMEOFFSET,
					WAITHOMECOMPLETE,
					HomeNotSafe,
					STARTRPulse,
					STARTRMOVE,
					STARTZeroMOVE,
					STARTAMOVE,
					STARTAMOVE2,
					WaitMotionDone,
					STARTVMOVE,
					WAITVMOVE,
					STARTREPEAT,
					WAITPOS,
					WAITTIMER,
					GOTOP,
					WAITLIMITP,
					GOTOM,
					WAITLIMITM,
					EXITLIMIT,
					WAITEXITLIMIT,
					StartSegment,
					OtherMotorStepStart,

		};	//0830 �W�[ GOTOP(M), WAITLIMITP(M), EXITLIMIT, WAITEXITLIMIT
		enum ErrorCode
		{
			errNoError,
			errAMoveError,
			errRMoveError,
			errGoLimitError,
			errExitLimitError,
			errHomeError,
			errHomeTimeOut,
			errLimitCheck,
			errNotSafe,
			errAlarm,
			errNotSVon,
			errPLimError,
			errNLimError,
			errZeroMoveError,
			errOtherMotorStart=50,
		};
	protected:
		MMotionLib *m_pMotionLib; //���b�ϥΪ�Motion Lib
		ErrorCode m_ErrorCode;
		double m_dblAMove, m_dblAMove2,m_dblRMove,m_dblMaxSpeed;
		int m_nJogDir;//�T�ʤ�V
		int m_intR;
		bool m_isSVOn,m_bHomeComplete,m_bGotoMSlow,m_bResetALM;
		AMoveReferenceSource m_arsSource;
		int m_intRstStep;
		MMotorCalculate *m_pMotorCalculate;
		CString m_CLastError,m_ELastError;
		CTimeCounter m_tmRstOn, m_tmRstOff;
		int m_intRetStep;
		bool m_bAccSpeed;
	private:
		int m_intCount;
		double m_dblEventScanTime;
		int m_intAlarmRetry;
		int m_intSVOffRetry;
		bool m_bAlarmLatched;
		bool m_bSVOffLatched;
	protected:
		MError* OnError(ErrorCode code, int RetryStep,CString strReason=_T(""));
	};

	class MMotorCalculate
	{
	public:
		MMotorCalculate(void){};
		~MMotorCalculate(void){};
		virtual double GetPosition(MMotor* pM);	//�ǤJ���F����X��m
		virtual double CalPosition(MMotor* pM,double p){return p;};			//�ǤJ��m����X���F�q
		virtual double CalAMove(MMotor* pM,double p){return p;};			//�p��nAMove����m
		virtual double CalRMove(MMotor* pM,double r){return r;};			//�p��nRMove����m
	};
	//-------------------------����----------------------------------------------

	class MMotorSita:public MMotorCalculate
	{
	public:
		MMotorSita(double r):m_dblR(r){};
		~MMotorSita(void){};
		virtual double GetPosition(MMotor* pM)
			{return 180/PI*atan(MMotorCalculate::GetPosition(pM)/m_dblR);};		//�ǤJ���F����X��m
		virtual double CalPosition(MMotor* pM,double p)
			{return tan(p/180*PI)*m_dblR;};										//�ǤJ��m����X���F�q
		virtual double CalAMove(MMotor* pM,double p)
			{return CalPosition(pM,p);};										//�p��nAMove����m
		virtual double CalRMove(MMotor* pM,double r)
			{return CalPosition(pM,r+GetPosition(pM))-MMotorCalculate::GetPosition(pM);};//�p��nRMove����m
	private:
		double m_dblR;
	};
}//namespace AutoLib
