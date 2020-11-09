#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "VisionBase.h"
#include "VisionRegion.h"
namespace AutoLib {
	class MVisionMatch : public MVisionBase
	{
	public:
		AUTOMALIB_API MVisionMatch();
		AUTOMALIB_API virtual ~MVisionMatch();
		AUTOMALIB_API void SetMinScore(double dblScore);
		AUTOMALIB_API double GetMinScore();
		AUTOMALIB_API void SetStartAngle(double dblAngle);
		AUTOMALIB_API double GetStartAngle();
		AUTOMALIB_API void SetEndAngle(double dblAngle);
		AUTOMALIB_API double GetEndAngle();
		AUTOMALIB_API void SetStartScale(double dblScale);
		AUTOMALIB_API double GetStartScale();
		AUTOMALIB_API void SetEndScale(double dblScale);
		AUTOMALIB_API double GetEndScale();
		AUTOMALIB_API void SetMaxOverlap(double dblOverlap);
		AUTOMALIB_API double GetMaxOverlap();
		AUTOMALIB_API void SetGreediness(double dblGreediness);
		AUTOMALIB_API double GetGreediness();
		AUTOMALIB_API void SetNumLevels(int intNumLevels);
		AUTOMALIB_API double GetNumLevels();
		AUTOMALIB_API void SetMaxMatchNum(int MaxNum);
		AUTOMALIB_API int GetMaxMatchNum();
	protected:
		int m_intMaxNum;
		double m_dblMinScore;
		double m_dblStartAngle;
		double m_dblEndAngle;
		double m_dblStartScale;
		double m_dblEndScale;
		double m_dblMaxOverlap;
		double m_dblGreediness;
		int m_intNumLevels;
	};
}
