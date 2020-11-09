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
		int m_intCheckGapAlgorithm;
		bool m_bGapCheck;
		double m_dblGapStartAngle, m_dblGapEndAngle;
		double m_dblMinGapAngle;
		DCoordinate m_cdGapStartPoint;
		DCoordinate m_cdGapEndPoint;
		HObject m_hoContours;
		//double m_dblLineFunctionPa, m_dblLineFunctionPb, m_dblLineFunctionPc;
		double m_dblLineX, m_dblLineY, m_dblLineAngRad, m_dblLineAngDeg;
		bool m_bFitLine;
		bool m_bDxfMatch;
		double m_dblObjectScale, m_dblObjectLength1, m_dblObjectLength2;
	};
}