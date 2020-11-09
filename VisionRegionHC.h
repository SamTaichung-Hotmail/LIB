
#pragma once
#include "VisionRegion.h"
#include "Coordinate.h"
#include "HalconCpp.h"
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;
using namespace std;

namespace AutoLib{
class MVisionRegionHC : public MVisionRegion
{
public:
	AUTOMAVHC_API MVisionRegionHC();
	AUTOMAVHC_API virtual ~MVisionRegionHC();
	AUTOMAVHC_API virtual void Draw(void *pDisp);
private:
};
}

