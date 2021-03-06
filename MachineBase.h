#pragma once
#pragma warning( disable : 4091)
#include "Registry.h"
#include "Tool.h"
#include "ADOConnection.h"
#include "Unit.h"
#include "Pilot.h"
#include "Error.h"
#include "Motor.h"
#include "Valve.h"
#include "IO.h"
#include "User.h"
#include "ButtonEvent.h"
#include "DESEncrypt.h"
#include <map>
#define _CRT_SECURE_NO_WARNINGS
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#define WM_MACHINEMESSAGE WM_USER+100
#define WM_BUTTONEVENT WM_USER+200

using namespace std;
namespace AutoLib {
	typedef void(*ButtonEventCallFunc)(MButtonEvent* pEvent);
	AUTOMALIB_API class MachineBase :
		public MUnit
	{
	public:
		enum ButtonKeyIndex {
			bkiStart,
			bkiStop,
			bkiReset,
			bkiSelect,
			bkiHome,
		};
		AUTOMALIB_API MachineBase(CWnd *pWnd);
		AUTOMALIB_API virtual ~MachineBase();
		AUTOMALIB_API virtual void ShowMessage(MMessage *pMessage);
		AUTOMALIB_API virtual void ErrorRegister(int intErrorCode, CString strDescripe);				//錯誤註冊
		AUTOMALIB_API virtual void ErrorHappen(MError *pError);
		AUTOMALIB_API virtual void Cycle(const double dblTime);
		AUTOMALIB_API virtual bool Init();
		AUTOMALIB_API virtual void ChangeLanguage();
		AUTOMALIB_API virtual void SetRecordLog(bool bLog);
		AUTOMALIB_API virtual void SetHomeComplete(bool bComplete);
		AUTOMALIB_API virtual void ShutDown();
		AUTOMALIB_API virtual void Stop();
		AUTOMALIB_API virtual bool AutoStart();
		//-----------建立主Thread以提供所有物件步序----------------
		static UINT DoThread(void *);
		//------------以下是Machine共通的成員-------
		AUTOMALIB_API virtual bool GetRecordLog();
		AUTOMALIB_API virtual double GetScanTime();
		AUTOMALIB_API virtual bool isEStop() { return false; };
		AUTOMALIB_API virtual void ResetEMG();
		AUTOMALIB_API virtual bool isInterLock() { return false; };
		AUTOMALIB_API virtual bool ScanSystemAlarm(bool bSendError) { return false; };
		AUTOMALIB_API virtual bool isResetAlarm() { return false; };
		AUTOMALIB_API virtual MMotor* AddMotor(MMotor* pMotor);
		AUTOMALIB_API virtual MValve* AddValve(MValve* pValve);
		AUTOMALIB_API virtual MIO* AddIO(MIO* pIO);
		AUTOMALIB_API virtual MTimer* AddTimer(MTimer* pTimer);
		AUTOMALIB_API virtual int GetMotorCount();
		AUTOMALIB_API virtual int GetValveCount();
		AUTOMALIB_API virtual int GetIOCount();
		AUTOMALIB_API virtual int GetTimerCount();
		AUTOMALIB_API virtual MMotor* GetMotor(int index);
		AUTOMALIB_API virtual MValve* GetValve(int index);
		AUTOMALIB_API virtual MIO* GetIO(int index);
		AUTOMALIB_API virtual MTimer* GetTimer(int index);
		AUTOMALIB_API virtual CString GetAppPath();
		AUTOMALIB_API virtual CString GetAppName();
		AUTOMALIB_API virtual bool LoadSystemData();
		AUTOMALIB_API virtual bool SetLanguageFile(CString strFileName);
		AUTOMALIB_API virtual bool SetRecipeFile(CString strFileName);
		AUTOMALIB_API virtual bool SetProductionFile(CString strFileName);
		AUTOMALIB_API virtual bool SetMachineFile(CString strFileName);

		AUTOMALIB_API virtual bool OpenMachineDB();
		AUTOMALIB_API virtual bool OpenProductionDB();
		AUTOMALIB_API virtual bool OpenRecipeDB();
		AUTOMALIB_API virtual bool CloseMachineDB();
		AUTOMALIB_API virtual bool CloseProductionDB();
		AUTOMALIB_API virtual bool CloseRecipeDB();
		AUTOMALIB_API virtual bool SaveMachineData(MBase *pC,bool bAllChildsSave = false);
		AUTOMALIB_API virtual bool LoadMachineData(MBase *pC, bool bAllChildsSave = false);
		AUTOMALIB_API virtual CString GetLanguageFileName();
		AUTOMALIB_API virtual CString GetMachineName();
		AUTOMALIB_API virtual CString GetMachineDataPath();
		AUTOMALIB_API virtual CString GetLanguageDataPath();
		AUTOMALIB_API virtual CString GetProductionDataPath();
		AUTOMALIB_API virtual CString GetRecipeDataPath();
		AUTOMALIB_API virtual CString GetMachineDataName();
		AUTOMALIB_API virtual CString GetProductionDataName();
		AUTOMALIB_API virtual CString GetRecipeDataName();
		AUTOMALIB_API virtual CString ReadSystemIniData(CString strSection, CString strKey, CString strDefault = _T(""));
		AUTOMALIB_API virtual void WriteSystemIniData(CString strSection, CString strKey,CString strData);
		AUTOMALIB_API virtual bool SaveRecipeData(MBase *pC, bool bAllChildsSave = false);
		AUTOMALIB_API virtual bool LoadRecipeData(MBase *pC, bool bAllChildsSave = false);
		AUTOMALIB_API virtual void SetMachineState(MPilot::PilotState state);
		AUTOMALIB_API virtual void MachineStop();	//給UI呼叫停機
		AUTOMALIB_API virtual MPilot* GetPilot();	//取Pilot
		AUTOMALIB_API virtual void OnCreateComplete();
		AUTOMALIB_API virtual double GetTacTime();
		AUTOMALIB_API virtual void UpdateTacTime();
		AUTOMALIB_API bool isInitComplete();
		AUTOMALIB_API bool LoadUsers();
		AUTOMALIB_API bool SaveUser(DUser *pUser);
		AUTOMALIB_API bool Login(CString strName, CString strPassword);
		AUTOMALIB_API BOOL GetRightByIndex(CString strIndex,CString & strName);
		AUTOMALIB_API CArray<DUser*>* GetUsers();
		AUTOMALIB_API void CreateIO() {};
		AUTOMALIB_API void CreateMotor() {};
		AUTOMALIB_API void CreateValve() {};
		AUTOMALIB_API void CreateTimer() {};
		AUTOMALIB_API void CreateRight() {};
		AUTOMALIB_API CString GetErrorDescript(int intErrorCode);				//取得錯誤說明
		AUTOMALIB_API void SetSpeedRate(double dblSpeedRate);
		AUTOMALIB_API double GetSpeedRate();
		AUTOMALIB_API void SetTimerUnit(bool bSec);
		AUTOMALIB_API bool GetTimerUnit();
		AUTOMALIB_API void AddEventListen(CWnd* pWnd);
		AUTOMALIB_API void DelEventListen(CWnd* pWnd);
		AUTOMALIB_API void SendButtonEvent(MButtonEvent* pEvent,MButtonEvent::ButtonEvenCode code);
		AUTOMALIB_API void ScanButtonEvent();
		AUTOMALIB_API void BackupData(bool bStart);
		AUTOMALIB_API void SetPauseOnError(bool bPause); //設定當發生報警時是否通知要暫停
		AUTOMALIB_API bool GetPauseOnError();			//取得當發生報警時是否通知要暫停
		AUTOMALIB_API unsigned long long GetUnLockExpireCode();	//取得要解鎖的號碼
		AUTOMALIB_API bool ExpiredUnLock(unsigned long long Code, unsigned long long Key);
		AUTOMALIB_API int RefreshExpireDayCount();
		bool m_bErrorHappen;	//是否有異常發生
		bool m_bMachineStop;	//UI是否呼叫停機
		bool m_bInitComplete;	//初始化完成
		double m_dblScanTime;
		CString m_strMachineName;
		CString m_strMachineDB;
		CString m_strRecipeDB;
		CString m_strProductionDB;
		CString m_strLanguageFile;
		CString m_strCompanyName;
		vector<MError *> m_Errors;
		CArray<MMotor*> m_Motors;
		CArray<MValve*> m_Valves;
		CArray<MIO*> m_IOs;
		CArray<MTimer*> m_Timers;
		CArray<DUser*> m_Users;
		CADOConnection m_cnnMachine;
		CADOConnection m_cnnRecipe;
		CADOConnection m_cnnProduction;
		MPilot *m_pPilot;
		CWnd* m_pMainFrame;
		CIniFile m_iniLang;
		CRegistry m_RegTool;
		DUser* m_pLoginUser;
		CArray<UserRight*> m_UserRights;
		std::map<int, CString> m_ErrorRegisters;
		HANDLE m_hMachineThread;
	protected:
		CArray<MButtonEvent*> m_ButtonEvents;
		CArray<CWnd*> m_EventWndListens;
		bool m_bResetSystemAlarm;
		double m_dblTactime;
		int m_intDayOfDataKeep;

	private:
		LARGE_INTEGER m_nTacStartTime, m_nFrequency;
		void ClearErrors();
		CRITICAL_SECTION m_csMachineCycle;
		CRITICAL_SECTION m_csEventLock;
		DESEncrypt m_DES;
		DWORD m_pThread;
		bool m_bResetEMG;
		double m_dblSpeedRate;
		CString m_strDataBaseProvider;
		CString m_strMachineDataPath, m_strRecipeDataPath, m_strProductionDataPath;
		CString m_strStartBackupPath, m_strShutDownBackupPath,m_strLanguageDataPath;
		int m_intOldState, m_intOldStep,m_intStateBeforeError;
		bool m_bTimerUnitSec;
		bool m_bPauseOnError;
		CTime m_ctUpdateExpire;
	};
}
