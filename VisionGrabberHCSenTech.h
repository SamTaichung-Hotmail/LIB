
#pragma once
#include "VisionGrabberHC.h"
#include "VisionImageHC.h"
#include "VisionLibSenTech.h"
#include "STCamD.h"
#include <list>
#ifdef AUTOMASENTECH_EXPORTS
#define AUTOMASENTECH_API __declspec(dllexport)
#else
#define AUTOMASENTECH_API __declspec(dllimport)
#endif
using namespace HalconCpp;

namespace AutoLib{
class MVisionGrabberHCSenTech : public MVisionGrabberHC
{
public:
	static UINT DoThread(void * pGrabber);
	AUTOMASENTECH_API MVisionGrabberHCSenTech(MVisionLib *pLib);
	AUTOMASENTECH_API virtual ~MVisionGrabberHCSenTech();
	AUTOMASENTECH_API virtual bool GetImage(MVisionImage* pImage);
	AUTOMASENTECH_API virtual bool ConnectCCD(const ConnectType CCDType, MCCD* pCCD);
	AUTOMASENTECH_API virtual bool SetExposureTime(double dblTime);
	AUTOMASENTECH_API virtual bool GetExposureTime(double *pdblTime);
	AUTOMASENTECH_API virtual bool SetTriggerMode(bool bOn);
	AUTOMASENTECH_API virtual bool IsGrabbing();
	AUTOMASENTECH_API virtual bool StartGrabber();
	AUTOMASENTECH_API virtual bool StopGrabber();
	AUTOMASENTECH_API virtual unsigned int GetStatus();
	AUTOMASENTECH_API virtual bool SoftTrigger();
	AUTOMASENTECH_API virtual unsigned int GetReadyNumOfBuffer();
	AUTOMASENTECH_API virtual unsigned int GetTotalNumOfBuffer();
	AUTOMASENTECH_API virtual bool GetLineInStatus();
	AUTOMASENTECH_API virtual bool PushImage(PBYTE pImageBuff);
protected:
	bool m_bStartGrabber;
	HANDLE m_hCamera;
	bool m_bSoftTrigger;
	HANDLE m_hThread;
	DWORD m_pThread;
	bool m_bShutDown;
	CRITICAL_SECTION m_csLock;
	std::list<PBYTE> m_Images;
};
}

