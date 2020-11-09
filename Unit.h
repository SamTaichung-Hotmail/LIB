#pragma once

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
// MCard
#include "Lock.h"				
namespace AutoLib{
	AUTOMALIB_API class MUnit : public MLock
	{
	public:
		enum AutoRunMode {
			DryRun,		//空跑模式
			NormalRun,	//正常模式
		};
		AUTOMALIB_API MUnit(MUnit *pParent,CString strID,CString strName, int ErrorCodeBase=-1);
		AUTOMALIB_API virtual ~MUnit();
		AUTOMALIB_API virtual bool AutoStart();
		AUTOMALIB_API virtual void AutoStop();
		AUTOMALIB_API virtual void CycleStop();
		AUTOMALIB_API virtual void CycleContinue();
		AUTOMALIB_API virtual void SetAutoRunMode(AutoRunMode mode);
		AUTOMALIB_API virtual AutoRunMode GetAutoRunMode();
		AUTOMALIB_API virtual bool GetAutoEnd();
		AUTOMALIB_API virtual bool GetCycleStop();
		AUTOMALIB_API virtual bool GetHomeComplete();
		AUTOMALIB_API virtual bool Home();
		AUTOMALIB_API virtual void OnStartProduction(void * pData=NULL);
		AUTOMALIB_API virtual void OnEndProduction(void * pData=NULL);
		AUTOMALIB_API virtual void ShutDown();
		AUTOMALIB_API virtual void SetVirtualMode(bool bVirtualMode);
		AUTOMALIB_API virtual bool GetVirtualMode();
		AUTOMALIB_API bool CheckKeyPro();
		AUTOMALIB_API short GetExpireDayCount();
		AUTOMALIB_API void SetExpireDayCount(short intDayCount);
		AUTOMALIB_API WORD GetUnLockMemberID();
		AUTOMALIB_API void SetUnLockMemberID(WORD uID);
	protected:
		AUTOMALIB_API virtual void SetHomeComplete(bool bHomeComplete);
		AUTOMALIB_API void SetMachineID(CString strMachineID);	//設定機台型號
		bool m_bVirtualMode;	//虛擬模式
		bool m_bAutoEnd;		//自動生產結束
		bool m_bCycleStop;		//循環停止
		bool m_bHomeComplete;	//此機構是否回Home完成
		bool m_bShutDown;
		int m_intExpiredDayCount;
		CArray<MUnit*> m_Units;
		std::map<void *,CString> m_mapDataName; //參數指標對應名稱
		AutoRunMode m_AutoRunMode;
		CString m_strMachineID;
		WORD m_wdKeyLevel[3];
		bool m_bRDKeyPro;
	};

}//namespace AutoLib
