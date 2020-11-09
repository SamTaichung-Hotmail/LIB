
#pragma once
#include "CCD.h"
#include "HalconCpp.h"

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;

namespace AutoLib{
class MCCDHC : public MCCD
{
public:
	AUTOMAVHC_API MCCDHC(MBase *pParent, CString strID, CString strName, CString strUnit);
	AUTOMAVHC_API virtual ~MCCDHC();
	AUTOMAVHC_API virtual bool Calibrate(CString strPathFile,CCDTYPE ccdType=MCCD::CCDTYPE::ccdBaslerACA1300);
	AUTOMALIB_API virtual bool Calibrate(DCoordinate MX1, DCoordinate MX2, DCoordinate MY1, DCoordinate MY2,
		DCoordinate CCDX1, DCoordinate CCDX2, DCoordinate CCDY1, DCoordinate CCDY2);
	AUTOMAVHC_API virtual DCoordinate GetMechanical(DCoordinate cdCCD); //取得換算到機構座標
	AUTOMAVHC_API virtual DCoordinate GetCCDCoodinate(DCoordinate cdMechanical); //取得換算到CCD座標
protected:
	HTuple m_hv_CameraParameters, m_hv_CameraPose;
};
}

