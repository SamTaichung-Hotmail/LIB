
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include<string>
#include <math.h>					
#include "ComPort.h"
#include <afxmt.h>

using namespace std;
#include <math.h>
#include "Base.h"				
#include "Motor.h"				
#include "MotionLib.h"
#define MaxRecvBufferSize 1024

namespace AutoLib{
	AUTOMALIB_API class MMotorCopley : public MMotor
	{
	public:
		AUTOMALIB_API MMotorCopley(MBase *pB,CString MotorID,CString strName,MMotionLib* pMotion,CString strU,int ErrorCodeBase);
		AUTOMALIB_API ~MMotorCopley();
		AUTOMALIB_API void Cycle(const double dblTime);
		AUTOMALIB_API void StepCycle(const double dblTime);
		AUTOMALIB_API double GetLastDist();

		static UINT DoThread(void *);
		enum ErrorCode {
			ecComportNotOpen=MMotor::ErrorCode::errOtherMotorStart,
		};
		enum ComPortStep {
			cpsInit,
			cpsIdle,
			cpsWaitResponse,
			cpsEnd,
		};
		enum InitStep {
			isStart,
			isSetBaudRate9600,
			isWaitSBR9600,
			isTestSend9600,
			isWaitTest9600,
			isSetBaudRate115200,
			isWaitSBR115200,
			isTestSend115200,
			isWaitTest115200,
			isComplete,
		};
		enum STEP {
			stpSetSpeed = OtherMotorStepStart,
			stpWaitSpeedSet,
			stpSetRptSpeed,
			stpCallRptFunction,
		};
		enum CopleyStateCode {
			cscDisable,
			cscCurrentLoopByProg,
			cscCurrentLoopByAnalog,
			cscCurrentLoopByPWM_DIR,
			cscCurrentLoopByInternalFun,
			cscCurrentLoopByUV,
			cscVelocityLoopByProg = 11,
			cscVelocityLoopByAnalog,
			cscVelocityLoopByPWM_DIR,
			cscVelocityLoopByInternalFun,
			cscPositionLoopByTrajectory = 21,
			cscPositionLoopByAnalog,
			cscPositionLoopByPulseDir,
			cscPositionLoopByInternalFun,
			cscPositionLoopByCamTable,
			cscPositionLoopByCanOpenOrECAT = 30,
			cscStepPositionByTrajectory,
			cscStepPositionByAnalog,
			cscStepPositionByPulseDir,
			cscStepPositionByInternalFun,
			cscStepPositionByCamTable,
			cscStepVelocityByAnalog,
			cscStepByCanOpenOrECAT = 40,
			cscDiagnosticUseOnly = 42,
		};
		enum CopleyCommandCode {
			cccSetCurrent = 0x02,
			cccSetAnalogScaleFactor = 0x19,			//Amount of 10V,Unit:0.01A
			cccSetAnalogOffset = 0x1A,				//Units:mV
			cccSetState = 0x24,
			cccSetAnalogDeadBand = 0x26,			//Units:mV
			cccSetCurrentRampLimit = 0x6A,
			cccSetBaudRate = 0x90,
			cccSetServoConfiguration = 0xA8,		//0:Increment on Rising Edge,4096:Falling Edge
			cccSetServoScalingFactor = 0xA9,		//counts/pulse
			cccSetServoMaxVelocity = 0xCB,			//Units: 0.1 counts/second
			cccSetServoMaxAccRate = 0xCC,			//Units: 10 counts/second2
			cccSetServoMaxDecRate = 0xCD,			//Units: 10 counts/second2
			cccSetServoAbortDecRate = 0xCF,			//Units: 10 counts/second2
			cccSetHomingMethold = 0xC2,
			cccFastVelocity = 0xC3,					//Units: 0.1 counts/second
			cccSlowVelocity = 0xC4,					//Units: 0.1 counts/second
			cccSlowAccDec = 0xC5,					//Units: 10 counts/second2
			cccHomeOffset = 0xC6,					//Units: counts
			cccCurrentLimit = 0xC7,					//Units: 0.01A
			cccCurrentDelayTime = 0xBF,				//Units: ms
			cccPositiveSoftLimit = 0xB8,			//Units: counts
			cccNegativeSoftLimit = 0xB9,			//Units: counts
		};
		enum CopleyHomeMode {
			chmSetCurrentPositionAsHome = 512,
			chmNextIndex_Positive = 544,
		};
		enum PollingCommand {
			pcActualCurrent,
			pcActualPos,
			pcPollingCount,
		};
		enum SetCommand {
			pcInit,
			pcReset,
			pcSetParameter,
			pcSetRegister,
			pcCallFunction,
		};
		enum FunctoinID {
			fidHome=1,
			fidPress = 2,
			fidAMove = 3,
			fidRMove = 4,
		};
		AUTOMALIB_API bool Init();
		AUTOMALIB_API bool ResetALM();				//Reset ALM
		AUTOMALIB_API void ComCycle(const double dblTime);
		AUTOMALIB_API bool CallFunc(FunctoinID FuncID);
		AUTOMALIB_API bool SetParameter(int intParameterID, int Value);
		AUTOMALIB_API bool SetRegister(int intRegID, int Value);
		AUTOMALIB_API bool isComIdle();
		AUTOMALIB_API double GetCurrent();
		AUTOMALIB_API bool SetCurrent(double dblCurrent);

		AUTOMALIB_API bool isComOpen();
		AUTOMALIB_API void SetComport(MComPort* pCom);

	private:
		DWORD m_pThread;
		MComPort* m_pComPort;
		CEvent m_Event;
		ComPortStep m_cpStep;
		double m_dblScanTime;
		double m_dblRecvTimeOut;
		double m_dblStartSpeed, m_dblAccTime, m_dblMaxSpeed, m_dblDesTime, m_dblPos;
		string m_strRecv;
		double m_dblCoefficent;
		PollingCommand m_pcPolling;
		double m_dblValue[pcPollingCount];
		SetCommand m_scSetCommand;
		int m_intRegID;
		int m_intRegValue;
		bool m_bSetCommand;
		bool m_bWaitRespond;
		int m_intCopleyErrorCode;
		bool m_bShutDown;
		int m_intPort;
		int m_intBaud;
		CString m_strParity;
		int m_intByteSize;
		float m_fStopBit;
		InitStep m_isStep;
		InitStep m_isRetStep;
		FunctoinID m_fidMoveID;
	private:
		int m_intCount;
	};


}//namespace AutoLib
