#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "VisionBase.h"
namespace AutoLib {
	class MVisionRegion : public MVisionBase
	{
	public:
		enum RegionType {
			rtRectangle,
			rtCircle,
			rtEllipse,
			rtCrossPoint,
			rtCircleRing,
			rtOther,
		};
		AUTOMALIB_API MVisionRegion();
		AUTOMALIB_API virtual ~MVisionRegion();
		AUTOMALIB_API RegionType GetType();
		AUTOMALIB_API void SetType(RegionType);
		AUTOMALIB_API void SetRange(double X1, double Y1, double X2, double Y2);
		AUTOMALIB_API void GetRange(double& X1, double& Y1, double& X2, double& Y2);
		AUTOMALIB_API void Offset(double X, double Y);
		AUTOMALIB_API void SetCenter(double X, double Y);
		AUTOMALIB_API void GetCenter(double& X, double& Y);
		AUTOMALIB_API double GetHight();
		AUTOMALIB_API double GetWidth();
		AUTOMALIB_API void SetRingWidth(double dblRingWidth);
		AUTOMALIB_API double GetRingWidth();
		AUTOMALIB_API void SetColor(COLORREF Color);
		AUTOMALIB_API void SetLineWidth(int intWidth);
		AUTOMALIB_API int GetLineWidth();
		AUTOMALIB_API COLORREF GetColor();
	protected:
		double m_X1, m_X2, m_Y1, m_Y2;
		RegionType m_RegionType;
		double m_RingWidth;
		COLORREF m_Color;
		int m_intLineWidth;
	};
}
