
#pragma once
#include <windows.h>
#include "Base.h"
#include "VisionImage.h"

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
// MVisionBase ©R¥O¥Ø¼Ð
namespace AutoLib{
class MVisionImage;
AUTOMALIB_API class MVisionBase
{
public:
	AUTOMALIB_API MVisionBase(MBase* pParent=NULL);
	AUTOMALIB_API virtual ~MVisionBase();
	AUTOMALIB_API virtual bool GetImage(MVisionImage *pImage){return false;};
	AUTOMALIB_API virtual bool PutImage(MVisionImage *pImage){return false;};
	AUTOMALIB_API virtual void Draw(void *pDisp) {};
protected:
	MBase *m_pParent;

};
}

