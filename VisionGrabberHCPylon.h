
#pragma once
#include "VisionGrabberHC.h"
#include "VisionImageHC.h"
#include "VisionLibPylon.h"
#include <pylon/PylonIncludes.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/ImageFormatConverter.h>
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif

using namespace Pylon;
using namespace Basler_GigECameraParams;

namespace AutoLib{
class MVisionGrabberHCPylon : public MVisionGrabberHC
{
public:
	AUTOMAVHC_API MVisionGrabberHCPylon(MVisionLib *pLib);
	AUTOMAVHC_API virtual ~MVisionGrabberHCPylon();
	AUTOMAVHC_API virtual bool GetImage(MVisionImage* pImage);
	AUTOMAVHC_API virtual bool ConnectCCD(const ConnectType CCDType, MCCD* pCCD);
	AUTOMAVHC_API virtual bool SetExposureTime(double dblTime);
	AUTOMAVHC_API virtual bool GetExposureTime(double *pdblTime);
	AUTOMAVHC_API virtual CInstantCamera* GetCamera();
	AUTOMAVHC_API virtual bool SetTriggerMode(bool bOn);
	AUTOMAVHC_API virtual bool IsGrabbing();
	AUTOMAVHC_API virtual bool StartGrabber();
	AUTOMAVHC_API virtual bool StopGrabber();
	AUTOMAVHC_API virtual unsigned int GetStatus();
	AUTOMAVHC_API virtual bool SoftTrigger();
	AUTOMAVHC_API virtual unsigned int GetReadyNumOfBuffer();
	AUTOMAVHC_API virtual unsigned int GetTotalNumOfBuffer();
	AUTOMAVHC_API virtual bool GetLineInStatus();
protected:
	Pylon::CBaslerGigEInstantCamera m_Camera;
	Pylon::CImageFormatConverter m_Converter;
};
}

