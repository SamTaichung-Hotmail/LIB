
#pragma once
#include "VisionGrabberHC.h"
#include "VisionImageHC.h"
#include "VisionLibPylon.h"
#include <pylon/PylonIncludes.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/ImageFormatConverter.h>
#ifdef AUTOMAPYLON_EXPORTS
#define AUTOMAPYLON_API __declspec(dllexport)
#else
#define AUTOMAPYLON_API __declspec(dllimport)
#endif

using namespace Pylon;
using namespace Basler_GigECameraParams;

namespace AutoLib{
class MVisionGrabberHCPylon : public MVisionGrabberHC
{
public:
	AUTOMAPYLON_API MVisionGrabberHCPylon(MVisionLib *pLib);
	AUTOMAPYLON_API virtual ~MVisionGrabberHCPylon();
	AUTOMAPYLON_API virtual bool GetImage(MVisionImage* pImage);
	AUTOMAPYLON_API virtual bool ConnectCCD(const ConnectType CCDType, MCCD* pCCD);
	AUTOMAPYLON_API virtual bool SetExposureTime(double dblTime);
	AUTOMAPYLON_API virtual bool GetExposureTime(double *pdblTime);
	AUTOMAPYLON_API virtual CInstantCamera* GetCamera();
	AUTOMAPYLON_API virtual bool SetTriggerMode(bool bOn);
	AUTOMAPYLON_API virtual bool IsGrabbing();
	AUTOMAPYLON_API virtual bool StartGrabber();
	AUTOMAPYLON_API virtual bool StopGrabber();
	AUTOMAPYLON_API virtual unsigned int GetStatus();
	AUTOMAPYLON_API virtual bool SoftTrigger();
	AUTOMAPYLON_API virtual unsigned int GetReadyNumOfBuffer();
	AUTOMAPYLON_API virtual unsigned int GetTotalNumOfBuffer();
	AUTOMAPYLON_API virtual bool GetLineInStatus();
protected:
	Pylon::CBaslerGigEInstantCamera m_Camera;
	Pylon::CImageFormatConverter m_Converter;
};
}

