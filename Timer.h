
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Base.h"
#include "TimeCounter.h"
namespace AutoLib{
AUTOMALIB_API class MTimer : public MBase
{
public:
	enum TimerType {
		ttNodefine,
		ttTimeOut,
		ttStable,
	};
	AUTOMALIB_API MTimer(MBase *pB, CString strID, CString strName, double dblTime, TimerType ttType = ttNodefine);
	AUTOMALIB_API virtual ~MTimer();
	//---------------------------------------------------------------------------
	AUTOMALIB_API virtual void Stop();
	AUTOMALIB_API virtual void SaveMachineData(CADOConnection * pC, bool bAllChildsSave = true);
	AUTOMALIB_API virtual void LoadMachineData(CADOConnection * pC, bool bAllChildsLoad = true);
	//----------------------------------------------------------------------------
	AUTOMALIB_API virtual bool isTimeOut(void);		//檢查此Timer是否計時完成
	AUTOMALIB_API virtual void SetInterval(double dblInterval);		//設定Timer時間
	AUTOMALIB_API virtual double GetInterval();		//設定Timer時間
	AUTOMALIB_API virtual double GetRemanderTime();
	AUTOMALIB_API virtual double GetCountingTime();
	AUTOMALIB_API virtual void Start();
	AUTOMALIB_API TimerType GetType();
	AUTOMALIB_API void SetIntervalToDefault();
protected:
	CTimeCounter m_tcTimer;
	TimerType m_ttType;
	double m_dblDefInterval;
};

}//namespace AutoLib
