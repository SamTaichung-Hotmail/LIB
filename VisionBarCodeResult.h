#pragma once
#include "Coordinate.h"
#include "Rectangle.h"
#include "CCD.h"
#include "VisionPattern.h"
#include "VisionRegion.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
	class MVisionBarCodeResult
	{
	public:
		AUTOMALIB_API MVisionBarCodeResult();
		AUTOMALIB_API ~MVisionBarCodeResult(void);
		AUTOMALIB_API void SetCodeText(CString strCode);
		AUTOMALIB_API CString GetCodeText();
	protected:
		CString m_strCode;
		MVisionRegion m_Region;
	};
}