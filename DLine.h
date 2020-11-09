#pragma once
#pragma warning( disable : 4091)

#include "Coordinate.h"
#include <Math.h>
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
AUTOMALIB_API class DLine
{
public:
	AUTOMALIB_API DLine(void);
	AUTOMALIB_API ~DLine(void);
	AUTOMALIB_API double GetOrientation(DCoordinate::AngleType atType=DCoordinate::AngleType::AngleXY);
	AUTOMALIB_API DLine Rotation(const double dblS);
	AUTOMALIB_API double GetLength(){return sqrt((PA.x-PB.x)*(PA.x-PB.x)+(PA.y-PB.y)*(PA.y-PB.y));};
	AUTOMALIB_API DCoordinate GetCenter(){return DCoordinate((PA.x+PB.x)/2,(PA.y+PB.y)/2,0,0);};
	AUTOMALIB_API double GetLineSlope();
	AUTOMALIB_API double GetMidLineSlope();
	AUTOMALIB_API bool IsMidLineSlopeInfinite(){return (m_MiddleLineVertical);};
	AUTOMALIB_API bool IsLineSlopeInfinite(){return (m_LineVertical);};
	AUTOMALIB_API DCoordinate CalOffset(DLine dlTarget,DCoordinate dcRotationCenter);
	DCoordinate PA, PB;
private:
	bool m_LineVertical;	// 線PA,PB垂直.
	bool m_MiddleLineVertical;	// 中垂線垂直.
};
}//namespace AutoLib