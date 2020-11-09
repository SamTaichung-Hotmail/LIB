
#pragma once
#include "VisionGrabber.h"
#include "VisionImageHC.h"
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionGrabberPy : public MVisionGrabber
{
public:
	AUTOMAVHC_API MVisionGrabberPy();
	AUTOMAVHC_API virtual ~MVisionGrabberPy();
	AUTOMAVHC_API virtual bool ConnectCCD(const ConnectType CCDType);
	AUTOMAVHC_API virtual bool GetImage(MVisionImage* pImage);
	AUTOMAVHC_API virtual bool SetExposureTime(double dblTime){return false;};
	AUTOMAVHC_API virtual bool GetExposureTime(double *pdblTime){return false;};
protected:

};
}

