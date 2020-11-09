#pragma once
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
#include "VisionMatch.h"
#include "VisionPatternHC.h"
#include "VisionImageHC.h"
#include "VisionGrabberHC.h"
#include "VisionMatchResultHC.h"
#include "VisionMatchResults.h"
namespace AutoLib {
	AUTOMAVHC_API class MVisionMatchHC : public MVisionMatch
	{
	public:
		enum MatchErrorCode {
			mecNoError,
			mecFitGapNG,
			mecFitCircleNG,
			mecMatchPatternNG,
			mecOverlayNG,
			mecParameterNG,
		};
		enum RingOverlayPolarity {
			ropDark,
			ropLight,
		};
		AUTOMAVHC_API MVisionMatchHC();
		AUTOMAVHC_API virtual ~MVisionMatchHC();
		AUTOMAVHC_API int Match(MVisionImageHC *pImage, MVisionPatternHC *pPattern, bool bFaulAddToResult = false);
		AUTOMAVHC_API MVisionMatchResults *GetMatchResults();
		AUTOMAVHC_API void SetRingOverlayCheck(bool bCheck, int intRingOLThreshold, RingOverlayPolarity intRingOLPolarity);
		AUTOMAVHC_API void GetRingOverlayCheck(bool& bCheck, int& intLevelFilterStart, RingOverlayPolarity& intLevelFilterEnd);
		HObject m_hDraw;
		int m_intGapScanPixelCount;
	protected:
		double m_dblMatchTime;
		HSystem m_hSystem;
		HHomMat2D m_hMatrix;
		HTuple m_hTuple;
		MVisionMatchResults m_Results;
		HRegion m_hRectangle;
		int FitGap(HImage hImage, double cx, double cy, double dblRadius, double ScanWidth, MVisionMatchResultHC* pResult);
		int FitCircle(HImage hImage, double cx, double cy, double dblRadius, double ringwidth, HTuple &hRows, HTuple &hCols, HTuple &hRadius);
		void AreaCheck(MVisionImageHC *pImage, MVisionPatternHC *pPattern,MVisionMatchResultHC* pResult);
		bool m_bOverlayCheck;
		int m_intRingOLThreshold;
		RingOverlayPolarity m_intRingOLPolarity;
	};
}
