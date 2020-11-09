
#pragma once
#include "VisionBinary.h"
#include "VisionImageHC.h"

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
// MVisionBase ©R¥O¥Ø¼Ð
namespace AutoLib{
	AUTOMAVHC_API class MVisionBinaryHC:public MVisionBinary
	{
	public:
		AUTOMAVHC_API MVisionBinaryHC();
		AUTOMAVHC_API virtual ~MVisionBinaryHC();
		AUTOMAVHC_API virtual bool GetImage(MVisionImage *pImage);
		AUTOMAVHC_API virtual bool PutImage(MVisionImage *pImage);
	private:
		MVisionImageHC *m_pImageInput;
		MVisionImageHC m_ImageOutput;
	};
}

