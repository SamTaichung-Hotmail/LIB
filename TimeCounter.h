
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
	AUTOMALIB_API virtual bool isTimeOut(void);		//�ˬd��Timer�O�_�p�ɧ���
	AUTOMALIB_API virtual void SetInterval(double dblInterval);		//�]�wTimer�ɶ�
	AUTOMALIB_API virtual double GetInterval();		//�]�wTimer�ɶ�
	AUTOMALIB_API virtual double GetRemanderTime();
	AUTOMALIB_API virtual double GetCountingTime();
	AUTOMALIB_API virtual LARGE_INTEGER GetStartTime();
	AUTOMALIB_API virtual void Start();
	AUTOMALIB_API virtual void Stop();
protected:
	double m_dblInterval;			//�]�w�n�p�ɪ��ɶ�(���Gms)
private:
	LARGE_INTEGER m_nStartTime, m_nStopTime, m_nFrequency;
	bool m_bTimerStart;
	double m_dblTimeCount;
};

}//namespace AutoLib
