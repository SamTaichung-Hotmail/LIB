#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif 
#include "VisionBase.h"
#include "VisionRegion.h"
#include "VisionBarCodeResult.h"
namespace AutoLib {
	class MVisionFindBarCode : public MVisionBase
	{
	public:
		AUTOMALIB_API MVisionFindBarCode();
		AUTOMALIB_API virtual ~MVisionFindBarCode();
		AUTOMALIB_API virtual int FindBarCode(MVisionImage *pImage)=0;
		AUTOMALIB_API int GetResultCount(void);
		AUTOMALIB_API MVisionBarCodeResult* GetResult(int index);
		AUTOMALIB_API void ClearAllResults();
	protected:
		std::vector<MVisionBarCodeResult*> m_Results;
	};
}
