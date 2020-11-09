#pragma once
#include "VisionMatchResult.h"
#include "HalconCpp.h"

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;
namespace AutoLib {
	AUTOMAVHC_API class MVisionMatchResultHC:public MVisionMatchResult
	{
	public:
		AUTOMAVHC_API MVisionMatchResultHC(DCoordinate dcXYS,double Score,double Scale);
		AUTOMAVHC_API ~MVisionMatchResultHC(void);
		HTuple m_htHomMat2D;
		HRegion m_hCheckRegion;
		bool m_bGapCheck;
		double m_dblGapStartAngle, m_dblGapEndAngle;
		double m_dblMinGapAngle;
		DCoordinate m_cdGapStartPoint;
		DCoordinate m_cdGapEndPoint;
	};
}