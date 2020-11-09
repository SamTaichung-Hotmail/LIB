
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "VisionBase.h"
#include "Coordinate.h"
namespace AutoLib{
class MVisionGrabber;
class MVisionImage
{
public:
	enum ImageType {
		itUnknow,
		itHalCon,
	};
	AUTOMALIB_API MVisionImage(ImageType itType,MVisionGrabber *pGrabber=NULL);
	AUTOMALIB_API virtual ~MVisionImage();
	AUTOMALIB_API virtual long GetImageHeight(){return 0;};
	AUTOMALIB_API virtual long GetImageWidth() { return 0; };
	AUTOMALIB_API virtual DCoordinate GetCenter() { return DCoordinate(); };
	AUTOMALIB_API virtual void * GetImageBuff() { return NULL; };
	AUTOMALIB_API virtual MVisionGrabber * GetGrabber();
	AUTOMALIB_API virtual void SetGrabber(MVisionGrabber* pGrabber);
	AUTOMALIB_API virtual ImageType GetImageType();
protected:
	ImageType m_itType;
	MVisionGrabber *m_pGrabber;
};
}

