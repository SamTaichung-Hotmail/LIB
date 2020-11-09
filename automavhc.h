#pragma once
#include "afxwin.h"
#include "VisionRegion.h"
#include "HalconCpp.h"

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;

namespace AutoLib {
	AUTOMAVHC_API void GenRegion(MVisionRegion *pVRegion, HRegion* pHRegion);
}

