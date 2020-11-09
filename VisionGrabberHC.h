
#pragma once
#include "VisionGrabber.h"
#include "VisionLib.h"
#include "CCD.h"
#include "VisionImageHC.h"
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionGrabberHC : public MVisionGrabber
{
public:
	AUTOMAVHC_API MVisionGrabberHC(MVisionLib *pLib);
	AUTOMAVHC_API virtual ~MVisionGrabberHC();
	AUTOMAVHC_API virtual bool ConnectCCD(const ConnectType CCDType,MCCD* pCCD);
	AUTOMAVHC_API virtual bool GetImage(MVisionImage* pImage);
	AUTOMAVHC_API virtual bool SetExposureTime(double dblTime){return false;};
	AUTOMAVHC_API virtual bool GetExposureTime(double *pdblTime){return false;};
	AUTOMAVHC_API virtual bool SoftTrigger();
	HTuple  m_hAcqHandle;
protected:
};
}

