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
	class MVisionMatchResult
	{
	public:
		AUTOMALIB_API MVisionMatchResult(DCoordinate dcXYS,double Score,double Scale);
		AUTOMALIB_API ~MVisionMatchResult(void);
		AUTOMALIB_API double GetScore();
		AUTOMALIB_API double GetScale();
		DCoordinate m_MatchPoint;
		DCoordinate m_ImageCenter;
		DRectangle m_MatchRectangle;
		MVisionRegion m_CheckRegion;
		double m_dblScore;
		double m_dblScale;
		double m_dblFitCircleRadius;	
		bool m_bCheckArea;
		MCCD* m_pCCD;
		DCoordinate m_dcFitCircleCenter;//傳回找到的圓及圓心到Mark回傳點的角度
		int m_intAreaForCheck;
		int m_intAreaForJudgeStart;
		int m_intAreaForJudgeEnd;
		CString m_strShow;
		int m_intErrorCode;
	};
}