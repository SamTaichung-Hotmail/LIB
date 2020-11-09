
#pragma once
#include <windows.h>
#include "VisionBase.h"

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
// MVisionBase ©R¥O¥Ø¼Ð
namespace AutoLib{
class MVisionImage;
AUTOMALIB_API class MVisionBinary:public MVisionBase
{
public:
	AUTOMALIB_API MVisionBinary();
	AUTOMALIB_API virtual ~MVisionBinary();
	AUTOMALIB_API virtual bool GetImage(MVisionImage *pImage){return false;};
	AUTOMALIB_API virtual bool PutImage(MVisionImage *pImage) { return false; };
	AUTOMALIB_API virtual void SetThresholdValue(int intLow, int intHi);
	AUTOMALIB_API virtual void GetThresholdValue(int &intLow, int &intHi);
protected:
	int m_intLowThreshold, m_intHiThreshold;
};
}

