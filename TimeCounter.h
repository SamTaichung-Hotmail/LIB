
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Base.h"
namespace AutoLib{
AUTOMALIB_API class CTimeCounter
{
public:
	AUTOMALIB_API CTimeCounter(double dblInterval=0);
	AUTOMALIB_API virtual ~CTimeCounter();
	AUTOMALIB_API virtual bool isTimeOut(void);		//檢查此Timer是否計時完成
	AUTOMALIB_API virtual void SetInterval(double dblInterval);		//設定Timer時間
	AUTOMALIB_API virtual double GetInterval();		//設定Timer時間
	AUTOMALIB_API virtual double GetRemanderTime();
	AUTOMALIB_API virtual double GetCountingTime();
	AUTOMALIB_API virtual LARGE_INTEGER GetStartTime();
	AUTOMALIB_API virtual void Start();
	AUTOMALIB_API virtual void Stop();
protected:
	double m_dblInterval;			//設定要計時的時間(單位：ms)
private:
	LARGE_INTEGER m_nStartTime, m_nStopTime, m_nFrequency;
	bool m_bTimerStart;
	double m_dblTimeCount;
};

}//namespace AutoLib
