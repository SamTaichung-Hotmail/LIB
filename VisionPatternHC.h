
#pragma once
#include "VisionPattern.h"
#include "VisionImageHC.h"
#include "Coordinate.h"
#include "HalconCpp.h"
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;
using namespace std;

namespace AutoLib{
class MVisionPatternHC : public MVisionPattern
{
public:
	AUTOMAVHC_API MVisionPatternHC();
	AUTOMAVHC_API virtual ~MVisionPatternHC();
	AUTOMAVHC_API virtual bool GetImage(MVisionImage *pImage);
	AUTOMAVHC_API virtual bool PutImage(MVisionImage *pImage);
	AUTOMAVHC_API virtual bool Load();
	AUTOMAVHC_API virtual bool Save();
	AUTOMAVHC_API virtual void SetMinContrast(long contrast);
	AUTOMAVHC_API virtual long GetMinContrast();
	AUTOMAVHC_API virtual int GetMinRegionCount();
	AUTOMAVHC_API virtual void SetGapCheck(bool bAutoContrast);
	AUTOMAVHC_API virtual bool GetGapCheck();
	AUTOMAVHC_API virtual void SetMinGapAngle(double dblAngle);
	AUTOMAVHC_API virtual double GetMinGapAngle();
	HRegion m_hShapeModelTrans;
	HImage m_hImage, m_hImageReduced;
	HTuple m_hModel;
	MVisionImageHC *m_pImagePattern;
	HRegion m_hRectangle;
private:
	bool m_bGapCheck;
	double m_dblMinGapAngle;
	int m_Contrast;
	int m_MinContrast;
};
}

