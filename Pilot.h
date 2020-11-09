
#pragma once
#include "Base.h"
#include "Flash.h"
#include "PulseIO.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib{
	AUTOMALIB_API class MPilot : public MBase
	{
	public:
		AUTOMALIB_API MPilot(MBase *pB,CString strID,CString strName);
		AUTOMALIB_API virtual ~MPilot();
		AUTOMALIB_API virtual void Stop() {};
		AUTOMALIB_API virtual void EStop(const bool isES) {};
		AUTOMALIB_API virtual bool isIDLE();
		AUTOMALIB_API virtual void SystemAlarm(const bool isSystemAlarm) {};
		AUTOMALIB_API virtual void InterLock(const bool isInterLock) {};
		AUTOMALIB_API virtual void LoadMachineData(CADOConnection * pC, bool bAllChildsLoad = true);
		AUTOMALIB_API virtual void SaveMachineData(CADOConnection *pC, bool bAllChildsLoad);
		AUTOMALIB_API virtual void SetRecordLog(bool bLog);	//設定Log記錄器
															//--------------------------------------------
		enum PilotState {
			INITIAL,
			IDLE,
			HOMING,
			PAUSE_STOP,
			ERROR_ON_AUTO,
			ERROR_ON_HOMING,
			ERROR_ON_MANUAL,
			EMERGENCY_STOP,
			AUTOMATIC_RUN,
			CYCLE_STOP,
			DRY_RUN,
			MAINTENANCE_RUN,
			MANUAL_RUN,
			UNKNOW,
		};
		//--------------------------------------------
		MFlash *m_pFHRed;		//紅燈
		MFlash *m_pFHGreen;		//綠燈
		MFlash *m_pFHYellow;	//黃燈
		MPulseIO *m_pPSBuzz;	//蜂鳴器

		AUTOMALIB_API void SetState(PilotState ps);
		AUTOMALIB_API void SetPrevState();
		AUTOMALIB_API PilotState GetState();
		AUTOMALIB_API CTime GetStateStartTime();
		AUTOMALIB_API CTimeSpan GetStateTimeSpen(PilotState ps);
		AUTOMALIB_API CString GetStateName(PilotState ps);
		AUTOMALIB_API int GetRLightSet(PilotState ps);
		AUTOMALIB_API int GetGLightSet(PilotState ps);
		AUTOMALIB_API int GetYLightSet(PilotState ps);
		AUTOMALIB_API int GetBuzzSet(PilotState ps);
		AUTOMALIB_API void SetRLightSet(PilotState ps,int intSV);
		AUTOMALIB_API void SetGLightSet(PilotState ps, int intSV);
		AUTOMALIB_API void SetYLightSet(PilotState ps, int intSV);
		AUTOMALIB_API void SetBuzzSet(PilotState ps, int intSV);
	protected:
		int m_RLight[UNKNOW],m_GLight[UNKNOW],
			m_YLight[UNKNOW],m_Buzz[UNKNOW];
		CTimeSpan m_StateTimeSpan[UNKNOW]; 
		CTime m_ctStateStartTime;
		PilotState m_PilotState,m_OldState;
	};
}//namespace AutoLib

