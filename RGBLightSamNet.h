#pragma once
#include "RGBLight.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

namespace AutoLib{

AUTOMALIB_API class MRGBLightSamNet : public MRGBLight
{

public:
	AUTOMALIB_API MRGBLightSamNet(MBase *pB, CString ID, CString strN, int ConnectID, int StationID, int Channel);
	AUTOMALIB_API virtual ~MRGBLightSamNet();
	AUTOMALIB_API bool	SetOn(bool blOn);
	AUTOMALIB_API bool	Active();
	AUTOMALIB_API bool	GetValue(int *R, int *G, int *B);
protected:
	double m_MaxCurrent;
	double m_MinCurrent;

};
};// AutoLib


