
#pragma once
#include "VisionImage.h"

#include "HalconCpp.h"

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;
namespace AutoLib{
class MVisionGrabberHC;
class MVisionImageHC : public MVisionImage
{
public:
	AUTOMAVHC_API MVisionImageHC(MVisionGrabberHC *pGrabber=NULL);
	AUTOMAVHC_API virtual ~MVisionImageHC();
	AUTOMAVHC_API virtual long GetImageHeight();
	AUTOMAVHC_API virtual long GetImageWidth();
	AUTOMAVHC_API virtual DCoordinate GetCenter();
	AUTOMAVHC_API virtual void * GetImageBuff() { return NULL; };
	HImage m_hImage;
protected:
};
}

