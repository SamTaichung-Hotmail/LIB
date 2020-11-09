#pragma once
#include "Coordinate.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
	class DRectangle
	{
	public:
		AUTOMALIB_API DRectangle();
		AUTOMALIB_API DRectangle(DCoordinate P1, DCoordinate P2, DCoordinate P3, DCoordinate P4);
		AUTOMALIB_API ~DRectangle(void);
		AUTOMALIB_API DCoordinate GetCenterPoint();
		AUTOMALIB_API void GetPoint(DCoordinate& P1, DCoordinate& P2, DCoordinate& P3, DCoordinate& P4);
		AUTOMALIB_API void SetPoint(DCoordinate& P1, DCoordinate& P2, DCoordinate& P3, DCoordinate& P4);
		AUTOMALIB_API DRectangle Rotation(double dblAngle, DCoordinate dcRotationCenter, DCoordinate::RotationType RT = DCoordinate::RotationType::RotationXY);
		AUTOMALIB_API DRectangle Move(DCoordinate dcMove);
	protected:
		DCoordinate m_P1,m_P2,m_P3,m_P4;
	};
}