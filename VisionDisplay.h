
#pragma once
#include <windows.h>
#include "VisionImage.h"

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
// MVisionDisplay ©R¥O¥Ø¼Ð
namespace AutoLib{
class MVisionImage;
AUTOMALIB_API class MVisionDisplay
{
public:
	AUTOMALIB_API MVisionDisplay();
	AUTOMALIB_API virtual ~MVisionDisplay();
	AUTOMALIB_API virtual bool GetImage(MVisionImage *pImage){return false;};
	AUTOMALIB_API virtual bool PutImage(MVisionImage *pImage){return false;};
};
}

