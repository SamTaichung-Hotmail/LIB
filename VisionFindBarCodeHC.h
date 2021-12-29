#pragma once
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
#include "VisionFindBarCode.h"
#include "VisionImageHC.h"
#include "VisionGrabberHC.h"
#include "VisionBarCodeResult.h"
namespace AutoLib {
	AUTOMAVHC_API class MVisionFindBarCodeHC : public MVisionFindBarCode
	{
	public:
		AUTOMAVHC_API MVisionFindBarCodeHC();
		AUTOMAVHC_API virtual ~MVisionFindBarCodeHC();
		AUTOMAVHC_API int FindBarCode(MVisionImage *pImage);
	protected:

	};
}
