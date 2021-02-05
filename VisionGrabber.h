
#pragma once
#include "VisionBase.h"
#include "VisionLib.h"
#include "CCD.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionGrabber : public MVisionBase
{
public:

	enum ConnectType{
		ct_File,
		ct_DirectShow,
		ct_BaslerGigaEtherNet,
		ct_USB,
	};
	AUTOMALIB_API MVisionGrabber(MVisionLib* pLib);
	AUTOMALIB_API virtual ~MVisionGrabber();
	AUTOMALIB_API virtual bool GetImage(MVisionImage* pImage) = 0;
	AUTOMALIB_API virtual bool SetExposureTime(double dblTime){return false;};
	AUTOMALIB_API virtual bool GetExposureTime(double *pdblTime){return false;};
	AUTOMALIB_API virtual bool SetTriggerMode(bool bOn);
	AUTOMALIB_API virtual bool IsGrabbing(){ return false; };
	AUTOMALIB_API virtual bool StartGrabber(){ return false; };
	AUTOMALIB_API virtual bool StopGrabber(){ return false; };
	AUTOMALIB_API virtual unsigned int GetStatus(){ return 0; };
	AUTOMALIB_API virtual unsigned int GetReadyNumOfBuffer(){ return 0; };
	AUTOMALIB_API virtual unsigned int GetTotalNumOfBuffer(){ return 0; };
	AUTOMALIB_API virtual bool GetLineInStatus(){ return false; }
	AUTOMALIB_API virtual ConnectType GetConnectType(){return m_ConnectType;}
	AUTOMALIB_API virtual bool ConnectCCD(const ConnectType CCDType, MCCD* pCCD);
	AUTOMALIB_API virtual MCCD* GetConnectCCD();
	AUTOMALIB_API virtual void SetConnectCCD(MCCD* pCCD);
	AUTOMALIB_API virtual bool GetPixelSize(long& lWidth, long& lHeight);
	AUTOMALIB_API virtual bool GetMirror();
	AUTOMALIB_API virtual void SetMirror(bool bMirror);
protected:
	bool m_bStartAcquisition;
	bool m_bTriggerMode;
	MCCD* m_pCCD;
	MVisionLib* m_pLib;
	ConnectType m_ConnectType;
	long m_lWidth, m_lHeight;
	bool m_bMirror;
};
}

